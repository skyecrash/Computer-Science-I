/*
    Pgm: Project 2
    Name: Lilith Freed (laf65)
    Purpose: Process ballots for the hospital elections
             and determine the winner(s).
    Copyright Lilith Freed, All Rights Reserved
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

const int BALLOTS = 100;
const int AMENDS = 10;

int readVotes(char [][AMENDS], string [], ifstream&);
int writeVotes(char [][AMENDS], string [], ofstream&);
void countVotes(char [][AMENDS], string [], int, int);

int main()
{
    char amendVotes[BALLOTS][AMENDS];
    string presVotes[BALLOTS];

    ifstream ballots("BallotsHospital.txt");

    if(!ballots.fail())
    {
        ofstream counted("counted.txt");
        int totalBallots = readVotes(amendVotes, presVotes, ballots);
        int goodBallots = writeVotes(amendVotes, presVotes, counted);
        countVotes(amendVotes, presVotes, goodBallots, totalBallots);

        counted.close();
    }

    ballots.close();

    return 0;
}

// FUNCTION BLOCK //

/* Reads the given ballot ifstream into the char and string arrays.
   pre-cond: takes a properly opened input filestream and declared
             arrays of strings and chars
   postcond: returns the total number of ballots in the file */
int readVotes(char amendVotes[][AMENDS], string presVotes[], ifstream &ballots)
{
    int totalBallots = 0, i = 0, lastID = 0, currentID = 0;

    while(!((ballots >> currentID).eof()))
    {
        if(currentID != lastID)
        {
            for(int j = 0; j < AMENDS; j++)
            {
                ballots >> amendVotes[i][j];
            }

            std::getline(ballots, presVotes[i], '\n');
            i++;
        }
        else
        {
            ballots.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        totalBallots++;
        lastID = currentID;
    }

    return totalBallots;
}

/* Writes the arrays of votes into an output file.
   pre-cond: takes a properly opened output filestream, and declared
             and initialized arrays of string and chars
   postcond: returns the number of good ballots that were counted */
int writeVotes(char amendVotes[][AMENDS], string presVotes[], ofstream &counted)
{
    int goodBallots = 0, i = 0;

    while(amendVotes[i][0] == 'Y' || amendVotes[i][0] == 'N')
    {
        for(int j = 0; j < AMENDS; j++)
        {
            counted << static_cast<char>(amendVotes[i][j]);
        }

        counted << presVotes[i] << endl;

        goodBallots++;
        i++;
    }

    return goodBallots;
}

/* Counts the votes and determine winners.
   pre-cond: takes two declared and initialized arrays of strings
             and chars, and two ints for good and total ballot counts
   postcond: returns after writing to output the winners of the election */
void countVotes(char amendVotes[][AMENDS], string presVotes[], int goodBallots, int totalBallots)
{
    cout << goodBallots << " hospital staff voted in this election using " << totalBallots
         << " ballots." << endl;
    int y, n;

    // counts all the votes for the amends and outputs results
    // counts by columns
    for(int j = 0; j < AMENDS; j++)
    {
        y = 0;
        n = 0;

        for(int i = 0; i < goodBallots; i++)
        {
            (amendVotes[i][j] == 'Y') ? y++ : n++;
        }

        // calculates ratio in cout to determine pass/fail and output accordingly
        // static cast to double to ensure value returned has floating point
        //
        cout << "Amendment #" << j + 1 << " " << (((y / static_cast<double>(goodBallots)) >= .75) ? "passes (" : "fails (")
             << y << " Y, " << n << " N) - " << std::setprecision(1) << std::fixed;

        if(y / static_cast<double>(goodBallots) >= .75)
        {
            cout << "75.0% met" << endl;
        }
        else
        {
            cout << (y / static_cast<double>(goodBallots)) * 100 << "% is not a majority" << endl;
        }
    }

    int theNewGuy = 0, thePres = 0;

    // counts the votes for pres
    for(int i = 0; i < goodBallots; i++)
    {
        (presVotes[i] == "The New Guy") ? theNewGuy++ : thePres++;
    }

    cout << "President (most votes): " << ((theNewGuy > thePres) ? "The New Guy" : "The President")
         << " (with " << ((theNewGuy > thePres) ? theNewGuy : thePres) << " votes)" << endl
         << "Vice President: " << ((theNewGuy > thePres) ? "The President" : "The New Guy")
         << " (with " << ((theNewGuy > thePres) ? thePres : theNewGuy) << " votes)" << endl;


}
