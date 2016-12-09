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

int readVotes(char [][AMENDS], string [], int [], ifstream&, int&);
void writeVotes(char [][AMENDS], string [], int [], ofstream&, int);
void countVotes(char [][AMENDS], string [], int, int);

int main()
{
    ifstream ballots("BallotsHospital.txt");

    if(!ballots.fail())
    {
        char amendVotes[BALLOTS][AMENDS];
        string presVotes[BALLOTS];
        int ID[BALLOTS];
        int totalBallots = 0;

        ofstream counted("counted.txt");

        int goodBallots = readVotes(amendVotes, presVotes, ID, ballots, totalBallots);
        writeVotes(amendVotes, presVotes, ID, counted, goodBallots);
        countVotes(amendVotes, presVotes, goodBallots, totalBallots);

        counted.close();
    }

    ballots.close();

    return 0;
}

// FUNCTION BLOCK //

/* Reads the given ballot ifstream into the char and string arrays.
   pre-cond: takes a properly opened input filestream, declared
             arrays of strings, chars, and ints, and an initialized int&
   postcond: returns the number of good ballots in the file, updates the
             number of total ballots */
int readVotes(char amendVotes[][AMENDS], string presVotes[], int ID[], ifstream &ballots, int &totalBallots)
{
    int i = 0, lastID = -1, currentID = 0, goodBallots = 0;

    while(!((ballots >> currentID).eof()))
    {
        if(currentID != lastID)
        {
            ID[i] = currentID;

            for(int j = 0; j < AMENDS; j++)
            {
                ballots >> amendVotes[i][j];
            }

            std::getline(ballots, presVotes[i], '\n');
            i++;
            goodBallots++;
        }
        else
        {
            ballots.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        totalBallots++;
        lastID = currentID;
    }

    return goodBallots;
}

/* Writes the arrays of votes into an output file.
   pre-cond: takes a properly opened output filestream, declared
             and initialized arrays of strings, chars, and ints,
             and one initialized int
   postcond: counted.txt contains the non-cheat ballots */
void writeVotes(char amendVotes[][AMENDS], string presVotes[], int ID[], ofstream &counted, int goodBallots)
{
    for(int i = 0; i < goodBallots; i++)
    {
        counted << ID[i];

        for(int j = 0; j < AMENDS; j++)
        {
            counted << static_cast<char>(amendVotes[i][j]);
        }

        counted << presVotes[i] << endl;
    }
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
