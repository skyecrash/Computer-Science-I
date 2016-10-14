/*
  Pgm: Assign3-A
  Name: Lilith Freed (laf65)
  Purpose: Displaying a rectangle of x's based on use input.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    // initialize vars for input
    string name = "", noun = "", bodyPart = "", verb = "";
    int number = 0;

    //data input block
    cout << "Enter a proper first name: ";
    cin >> name;

    cout << "Enter a plural noun: ";
    cin >> noun;

    cout << "Enter the name of a body part: ";
    cin >> bodyPart;

    cout << "Enter a verb: ";
    cin >> verb;

    cout << "Enter some random integer: ";
    cin >> number;

    // the story in all its glory
    cout << "\nThe famous explorer " << name << " had nearly given up a life-long "
         << "quest to find the Lost City of " << noun << " when one day the "
         << noun << " found the explorer.\n\n"
         << "Surrounded by " << number << " " << noun << ", a tear came to "
         << name << "'s " << bodyPart << ". After all this time, the"
         << " quest was finally over. And then, the " << noun << " promptly devoured "
         << name << ".\n\n"
         << "The moral of the story? Be careful what you " << verb << " for.\n\n";

    return 0;
}
