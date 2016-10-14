/*
  Pgm: ASSGN1-B  Name: Lilith Freed
  Purpose: This program will compute the monetary value of quarters, nickles, and dimes
  entered by the user.

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int quarters, nickles, dimes;
    double total;

    cout << "Enter the number of quarters, nickles, and dimes, in that order.\nSeparate them by a single space." << endl;
    cin >> quarters >> nickles >> dimes;

    // computes the total monetary value
    total = quarters * .25 + nickles * .05 + dimes * .1;

    // prints the total with two decimal places always to the right
    cout << "The monetary value of your coins is $" << setprecision(2) << fixed << total << endl;

    return 0;
}
