/*
  Pgm: Assign4-B
  Name: Lilith Freed (laf65)
  Purpose: Compute the estimate of a square root to the precision of 10^-4.

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
float mySquareRoot(float num);
void firstPositiveTen();
float receiveInput();

int main()
{
    // Takes user input and stores it
    float num = receiveInput();

    // Calculates the estimate and prints it to cout
    float squareRoot = mySquareRoot(num);
    cout << "The estimated square root is: " << squareRoot << endl;

    // Conducts a test using the first ten positive integers
    cout << "Now testing the first ten positive integers...\n";
    firstPositiveTen();

    return 0;
}

/* Computes the estimate of a square root for a float between 1 and 100
   to the precision of 10^-4 using the bisection method.
   pre-cond: takes a float number between 1 and 100
             performs the bisection method on this number
   postcond: returns the estimated value */
float mySquareRoot(float num)
{
    float lower = 0.1, upper = 10.1, root = 0, sign = 0;

    // Executes the bisection method 20 times
    // Uses function f(x) = num - x^2
    for(int i = 0; i < 20; i++)
    {
        // Computes iteration's root estimate
        // Determines f(lower) * f(root)
        root = (lower + upper) / 2;
        sign = (num - lower * lower) * (num - root * root);

        // Sets upper/lower depending on value of sign
        if (sign < 0)
        {
            upper = root;
        }
        else
        {
            lower = root;
        }
    }

    return root;
}

/* Runs a test loop to calculate the estimated value of the first ten
   positive integers.
   pre-cond: mySquareRoot() computes the estimated value
             loops 10 times for the first 10 numbers
   postcond: displays each estimate on its own line in cout*/
void firstPositiveTen()
{
    for(int i = 1; i <= 10; i++)
    {
        cout << "The estimated square root of " << i << " is "
             << mySquareRoot(i) << endl;
    }
    return;
}

/* Receives the input from the user and validates it.
   pre-cond: user inputs data from the keyboard
             validates to ensure value is a real number and between 1 and 100
   postcond: returns valid input (a real float number between 1 and 100) */
float receiveInput()
{
    bool loopFlag = true; // flag for loop
    float num = 0; // stores user input

    do
    {
        cout << "Please enter a real number between 1 and 100: ";
        cin >> num;

        if(cin.fail() || num < 1 || num > 100)
        {
            cout << "\nInvalid data. Try again.\n\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            loopFlag = true;
        }
        else
        {
            loopFlag = false;
        }

    } while(loopFlag);

    return num;
}


