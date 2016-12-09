/*
   COPYRIGHT (C) 2016 Lilith Freed. All rights reserved.
   CSI project
   Author.  Lilith Freed laf65
   Version. 1.01 12.07.2016
*/

#include <iostream>
#include <iomanip>
#include <fstream>


using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

const int FLOOR_ARRAY_SIZE = 5;
const int ROOM_ARRAY_SIZE = 8;

//	Transfers are represented by T.
//	The Check outs are represented by a C.
//	Nurse work stations are represented by a W.
//	Occupied rooms are represented by an asterisk O.
//	A vacant room is represented by a blank V.
//	The utility rooms are represented by an X.

const char VACANT = 'V';
const char CHECKOUT = 'C';
const char OCCUPIED = 'O';
const char NURSE_STATION = 'W';
const char TRANSFER = 'T';
const char UTILITY = 'X';
const char INVALID = '@';

// These functions will work in their current form. You must use them. You may add functions but
// don't remove them. Complete the pre and post condition comments.

//Function prototypes
/*
Precond: the 2-d char array has been initialized
Postcond: the output stream shows the status of all the rooms in the hospital in a grid
*/
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
Precond: the 2-d char array has been declared and beds.txt properly opened
Postcond: the hospitalFloors array contains the initial data from beds.txt
*/
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], ifstream &beds);


/*
Precond: the 2-d char array has been initialized
Postcond: all the rooms marked with the status C have been set to the status V
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &numVacancies);

/*
Precond: the 2-d char array has been initialized, and all checkouts have been performed
Postcond: all rooms marked with the status T have been set to the status V
          all rooms marked T have found new rooms, which are now marked with the status O
          returns a dynamic array of pointers representing the vacancies after transfer
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int numVacancies);

/*
Precond: All params have been initialized. The first has been verified. The second is greater than 0.
Postcond: The new patients have been allocated to the last vacancy in the vacancies array
*/
void newPatient(int, int &, char **);

/*
 Precond: The given int has been initialized.
 Postcond: The int returned is the input for the number of vacancies to fill.
*/
int newPatientInput(int);



int main()
{
    char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE];
    ifstream beds("Beds.txt");

    if(!beds.fail())
    {
        // Load the grid and print.
        readGrid(hospitalFloors, beds);
        printGrid(hospitalFloors);
        cout << "Grid loaded" << endl;

        // Complete transfers and checkouts.
        int numVacancies = 0;
        checkOuts(hospitalFloors, numVacancies);
        char** vacancies = tranfers(hospitalFloors, numVacancies);
        printGrid(hospitalFloors);
        cout << "Checkouts and transfers completed" << endl;

        // Take all new patients until all vacancies are filled
        // or the user quits.
        while(numVacancies > 0)
        {
            int nurseInput = newPatientInput(numVacancies);
            if(nurseInput == 0)
            {
                cout << "\nEnding program.\n" << endl;
                return 4;
            }
            else
            {
                newPatient(nurseInput, numVacancies, vacancies);
                printGrid(hospitalFloors);
                cout << "New patient updates completed" << endl;
            }
        }

        cout << "\n*** No more rooms are available today ***\n";
    }
    else
    {
        cout << "Unable to open the specified file. (Beds.txt)\n"
             << "Terminating program.";
        return 4;
    }

    return 4;
}

/* Reads Beds.txt and populates hospitalFloors accordingly. */
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], ifstream &beds)
{
    int room; // to hold the int read from the file
    for(int i = 0; i < FLOOR_ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ROOM_ARRAY_SIZE; j++)
        {
            // take input from beds.txt
            beds >> room;
            beds.ignore();
            switch(room)
            {
                case 0:
                    hospitalFloors[i][j] = 'V';
                    break;
                case 1:
                    hospitalFloors[i][j] = 'C';
                    break;
                case 2:
                    hospitalFloors[i][j] = 'O';
                    break;
                case 3:
                    hospitalFloors[i][j] = 'W';
                    break;
                case 4:
                    hospitalFloors[i][j] = 'T';
                    break;
                case 5:
                    hospitalFloors[i][j] = 'X';
                    break;
                default:
                    hospitalFloors[i][j] = '@';
                    break;
            }
        }
    }
}

/* Prints the current state of hospitalFloors to cout. */
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    // dividing dash line
    cout << '\n' << std::setfill('-') << std::setw(16) << '\n';

    for(int i = 0; i < FLOOR_ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ROOM_ARRAY_SIZE; j++)
        {
            cout << static_cast<char>(hospitalFloors[i][j]) << " ";
        }

        cout << endl;
    }

    cout << std::setfill('-') << std::setw(16) << '\n';
}

/* Executes all checkouts in hospitalFloors. Counts the vacancies
   and modifies numVacancies accordingly. */
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &numVacancies)
{
    for(int i = 0; i < FLOOR_ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ROOM_ARRAY_SIZE; j++)
        {
            if(hospitalFloors[i][j] == 'C')
            {
                hospitalFloors[i][j] = 'V';
                numVacancies++;
            }
            else if(hospitalFloors[i][j] == 'V')
            {
                numVacancies++;
            }
        }
    }
}

/* Builds the array of pointers to vacancies, executes the transfers.
   Returns the array of pointers to vacancies. */
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int numVacancies)
{
    // Build the array of pointers. Index v iterates thru vacancies
    // Start from the back in both arrays.
    char** vacancies = new char*[numVacancies];
    int v = numVacancies - 1;
    for(int i = FLOOR_ARRAY_SIZE - 1; i >= 0; i--)
    {
        for(int j = ROOM_ARRAY_SIZE - 1; j >= 0; j--)
        {
            if(hospitalFloors[i][j] == 'V')
            {
                vacancies[v] = &hospitalFloors[i][j];
                v--;
            }
        }
    }

    // Execute transfers.
    // Start with the first transfer and the last vacancy.
    v = numVacancies - 1;
    for(int i = 0; i < FLOOR_ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ROOM_ARRAY_SIZE; j++)
        {
            if(hospitalFloors[i][j] == 'T')
            {
                *vacancies[v] = 'O'; // old vacancy assigned to be occupied
                hospitalFloors[i][j] = 'V'; // marks transfer as vacant
                vacancies[v] = &hospitalFloors[i][j]; // assigns pointed to newly vacated transfer
                v--; // decrements for next vacancy
            }
        }
    }

    return vacancies;
}

/* Adds the new patient(s) to the addresses in vacancies. */
void newPatient(int nurseInput, int &numVacancies, char ** vacancies)
{
    for(int i = numVacancies - 1; i > ((numVacancies - 1) - nurseInput); i--)
    {
        *vacancies[i] = 'O';
        vacancies[i] = nullptr; // erases vacancy
    }

    numVacancies -= nurseInput; // subtracts the number of patients added
}

/* Takes input from the user and verifies that it is within the given bounds. */
int newPatientInput(int numVacanies)
{
    int nurseInput = 0; // user input
    bool failFlag = true; // tracks fail condition
    do
    {
        cout << "\nPlease enter the number of new patients, from one up to " << numVacanies << " (Enter 0 to Quit): ";
        cin >> nurseInput;

        // quits if 0
        if(nurseInput == 0)
        {
            return 0;
        }
        // ensures input is an int and not less than 1 or greater than the number of vacancies
        else if(cin.fail() || nurseInput < 1 || nurseInput > numVacanies)
        {
            cout << "Please enter a valid integer from one to " << numVacanies << "." << endl;
        }
        else
        {
            failFlag = false;
        }
    } while(failFlag);

    return nurseInput;
}
