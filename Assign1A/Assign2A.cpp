/*
  Pgm: ASSGN2-A
  Name: Lilith Freed
  Purpose: This program will determine whether a college class room
  is in violation of fire law regulations.

*/
#include <iostream>
#include <iomanip>

using namespace std;

//capacity for classrooms
const int LH312 = 42;  //Leigh Hall room 312
const int CAS41 = 44;  //College of Arts and Sciences room 41
const int KH133 = 38;  //Kolbe Hall room 133

int main()
{
    //continue condition
    int cont = 1;

    // Runs menu selection until user decides to quit
    while (cont == 1) {

        //holds classroom selection
        int select = 0;

        cout << "Select a room.\n"
             << "[1] Leigh Hall room 312\n[2] College of Arts and Sciences room 41\n[3] Kolbe Hall room 133\n" << endl;
        cin >> select;

        if (select >= 1 && select <=3)
        {
            int enrolled = 0;
            cout << "\nWhat is the total enrollment for your class?\n" << endl;
            cin >> enrolled;

            /* Series of ifs display the message that correspond with the room selection.
               and enrollment total. */
            if (select == 1 && enrolled <= LH312)
            {

            cout << "\nYou're safe! You can have "
                 << LH312 - enrolled << " more people in your class.\n" << endl;

            }
            else if (select == 2 && enrolled <= CAS41) {

                cout << "\nYou're safe! You can have "
                     << CAS41 - enrolled << " more people in your class.\n" << endl;

            }
            else if (select == 3 && enrolled <= KH133)
            {

                cout << "\nYou're safe! You can have "
                     << KH133 - enrolled << " more people in your class.\n" << endl;

            }
            else
            {

                cout << "\nYOU SHALL NOT CLASS.\n" << endl;
            }
        }
        else
        {

            cout << "\nPlease enter a valid input. (1, 2, 3)\n" << endl;
        }

        // (1/0) ==> (Y/N)
        cout << "Do you want to try again? (1/0)\n" << endl;
        cin >> cont;
    }

    return 0;
}
