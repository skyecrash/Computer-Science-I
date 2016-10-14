/*
  Pgm: Assign4-A
  Name: Lilith Freed (laf65)
  Purpose: Play Rock, Paper, Scissors, Lizard, and Spock
           1 = Rock, 2 = Paper, 3 = Scissors, 4 = Lizard, 5 = Spock

*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

// Function declarations.
int getUserChoice();
int getComputerChoice();
void determineWinner(int userChoice, int computerChoice);
void displayChoice(int choice);

int main()
{
    bool isTie = true;

    // Will continue playing while the result is a tie.
    do
    {
         // Get choices for game.
        int computerChoice = getComputerChoice();
        int userChoice = getUserChoice();

        // Display computer's choice.
        displayChoice(computerChoice);

        // Will not execute determineWinner if it is a tie.
        if (computerChoice == userChoice)
        {
            cout << "It's a tie! Choose your weapon again.\n\n";
            isTie = true;
        }
        else
        {
           // Determine winner of a non-tie match.
           determineWinner(userChoice, computerChoice);
           isTie = false;
        }

    } while(isTie);

    return 0;
}

// FUNCTION BLOCK //

/* Determines the computer's choice of weapon using seeded rand().
   pre-cond: user is playing a game of RPSLS
   postcond: returns int representing the computer's choice. */
int getComputerChoice()
{
    srand(time(0));
    return 1 + rand() % 5;
}

/* Determines the user's choice via keyboard input.
   pre-cond: computer has made their choice
             displays menu, takes input + validates
   postcond: returns int representing the player's choice */
int getUserChoice()
{
    bool loopFlag = true;
    int userChoice = 0;

    do
    {
        cout << "Here are your weapons.\n"
             << "[1] Rock\n"
             << "[2] Paper\n"
             << "[3] Scissors\n"
             << "[4] Lizard\n"
             << "[5] Spock\n"
             << "Choose one (using the number): ";

        cin >> userChoice;

        // Ensure entry is a number.
        // Ensure entry is a number 1-5.
        if ((cin.fail()) || userChoice <= 0 || userChoice > 5)
        {
            cout << "\nPlease enter a valid choice (a number from 1 - 5).\n\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            loopFlag = false;
        }

    } while (loopFlag);

    return userChoice;
}

/* Determines the winner of a RPSLS game using two int inputs representing
   the choices of the player, and displays a message indicating the winner.
   pre-cond: takes two ints representing the player and computer choice
             evaluates matchup to see what beats what
   postcond: displays who won the matchup and returns to main*/
void determineWinner(int userChoice, int computerChoice)
{
    // If-else block will determine what beats what.
    // It will display "Rock beats Scissors", etc.
    // Will NOT specify whether user or computer won
    // 10 if statements is already pushing it
    if ((userChoice == 1 && computerChoice == 5) || (userChoice == 5 && computerChoice == 1))
    {
        cout << "Spock vaporizes Rock. Cool.\n";
    }
    else if ((userChoice == 1 && computerChoice == 4) || (userChoice == 4 && computerChoice == 1))
    {
        cout << "Rock crushes Lizard. Hope I don't see any guts.\n";
    }
    else if ((userChoice == 1 && computerChoice == 3) || (userChoice == 3 && computerChoice == 1))
    {
        cout << "Rock smashes Scissors. How unfair.\n";
    }
    else if ((userChoice == 1 && computerChoice == 2) || (userChoice == 2 && computerChoice == 1))
    {
        cout << "Paper covers Rock. I guess learning suffocates us all.\n";
    }
    else if ((userChoice == 2 && computerChoice == 5) || (userChoice == 5 && computerChoice == 2))
    {
        cout << "Paper disproves Spock. How illogical.\n";
    }
    else if ((userChoice == 2 && computerChoice == 4) || (userChoice == 4 && computerChoice == 2))
    {
        cout << "Lizard eats Paper. He'll have writing coming out of his... never mind.\n";
    }
    else if ((userChoice == 2 && computerChoice == 3) || (userChoice == 3 && computerChoice == 2))
    {
        cout << "Scissors cuts Paper. Ouch.\n";
    }
    else if ((userChoice == 3 && computerChoice == 5) || (userChoice == 5 && computerChoice == 3))
    {
        cout << "Spock smashes Scissors. They made fun of his ears.\n";
    }
    else if ((userChoice == 3 && computerChoice == 4) || (userChoice == 4 && computerChoice == 3))
    {
        cout << "Scissors decapitate Lizard. Long live the king.\n";
    }
    else if ((userChoice == 4 && computerChoice == 5) || (userChoice == 5 && computerChoice == 4))
    {
        cout << "Lizard poisons Spock. Should have brought some antidote.\n";
    }

    return;
}

/* Displays a given computer choice for a RPSLS game.
   pre-cond: takes an int representing the computer's choice
   postcond: displays the computer's choice in words and returns to main */
void displayChoice(int choice)
{
    switch(choice)
    {
        case 1:
          cout << "The computer chose Rock.\n";
          break;
        case 2:
          cout << "The computer chose Paper.\n";
          break;
        case 3:
          cout << "The computer chose Scissors.\n";
          break;
        case 4:
          cout << "The computer chose Lizard.\n";
          break;
        case 5:
          cout << "The computer chose Spock.\n";
          break;
        default:
          cout << "Something went wrong.\n";
          break;
    }

    return;
}
