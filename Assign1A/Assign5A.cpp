/*
  Pgm: Assign55-A
  Name: Lilith Freed (laf65)
  Purpose: Let the user enter a number, and determine if it is prime.

*/

#include<iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;

int getInput();
bool isPrime(int);

int main()
{
    char cont = 'Y'; // continue condition
    int num = 0; // this stops from a redeclaration on every iteration

    do
    {
        num = getInput();

        if(isPrime(num))
        {
            cout << "This number is prime!\n";
        }
        else
        {
            cout << "This number is not prime.\n";
        }

        cout << "Would you like to continue? (Y/N): ";
        cin.ignore();
        cin.get(cont);

    } while(cont == 'Y' || cont == 'y');
}

/* Receives and validates user input.
   pre-cond: user is entering a number at the keyboard
   postcond: returns an int that is the user's valid input */
int getInput()
{
    int val = 0;
    int loopFlag = true;

    do
    {
        cout << "Please enter a number: ";
        cin >> val;

        if(cin.fail() || val < 1)
        {
            cout << "This is not a valid number. Please enter again.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            loopFlag = true;
        }
        else
        {
            loopFlag = false;
        }
    } while(loopFlag);

    return val;
}

/* Determines if a given number is prime.
   pre-cond: num is a valid integer
   postcond: returns true if the number is prime, and false otherwise */
bool isPrime(int num)
{
    // 2 is a special case (even and prime)
    if (num == 2)
    {
        return true;
    }
    // Checks for special non-prime nums and even numbers.
    else if(num == 1 || num % 2 == 0 )
    {
        return false;
    }
    else
    {
        int i = 2;

        // Checks if num is factorable.
        while (i < (num / 2))
        {
            if(num % i == 0)
            {
                return false;
            }

            i++;
        }
    }

    return true;
}
