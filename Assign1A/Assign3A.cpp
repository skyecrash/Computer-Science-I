/*
  Pgm: Assign3-A
  Name: Lilith Freed (laf65)
  Purpose: Displaying a rectangle of x's based on use input.

*/

#include <iostream> // for I/O stream operations
#include <iomanip> // for providing parametric manipulators ops
#include <limits> // for providing elements with the characteristics of arithmetic types

using std::cout;
using std::cin;
using std::endl;

int main()
{
    // initialize vars for input
    int width = 0, length = 0;

    bool loopFlag = true;

    do
    {
        cout << "Enter two positive integers no greater than 75." << endl
             << "Separate them by a single space.\n";

        cin >> width >> length;

        // Ensure integer is positive.
        // Ensure integer is not greater than 75.
        if ((cin.fail()) || width <= 0 || length <= 0 || width > 75 || length > 75)
        {
            cout << "\nThe width and length must be a positive integer "
                 << "no greater than 75.\nPlease enter valid data.\n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            loopFlag = false;
        }

    } while (loopFlag);

    for (int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++) {

            cout << "X";

        }

        cout << endl;
    }

    return 0; //ends program
}
