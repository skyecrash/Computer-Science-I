/*
  Pgm: Assign7-B
  Name: Lilith Freed (laf65)
  Purpose: Process a file containing data from a Farmer's Market.
           Sort items alphabetically, then give the item totals.

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

const int SIZE = 28; // 28 farms on ASSGN6-A.txt

void read(ifstream&, string []);
void alphaSort(string []);
void createHeader(ofstream&);
void write(ofstream&, string []);

int main()
{
    ifstream inputFile;
    inputFile.open("ASSGN6-A.txt");

    if(!inputFile.fail())
    {
        cout << "Reading file...\n";
        string items[SIZE];
        read(inputFile, items); // reads data from file

        alphaSort(items); // sorts the items alphabetically

        ofstream outputFile("FarmersMarketReport2.txt"); // output file

        createHeader(outputFile); // tacks header to output file
        write(outputFile, items); // writes info to output file

        // closes both files
        inputFile.close();
        outputFile.close();

        cout << "Task complete.\n";
    }
    else
    {
        cout << "The file did not open properly! Program ending.\n";
    }

    return 0;
}

// FUNCTION BLOCK //

/* Reads the given input filestream to an array.
   pre-cond: takes a properly opened input filestream, and an initialized
             array of strings
   postcond: returns the array of strings read from the file */
void read(ifstream& inputFile, string items[])
{
    int i = 0;

    // reading input, ignoring everything but item name
    while(!(inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ',')).eof())
    {
        // run ignore twice to get rid of space + number
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ' ');

        inputFile >> items[i];
        i++;
    }

}

/* Sorts the list of items alphabetically via a bubble sort.
   pre-cond: takes an initialized array of string values
   postcond: array is sorted alphabetically upon return */
void alphaSort(string items[])
{
    bool swap; // to indicate if items have been swapped

    do
	{
	    swap = false;
		for(int i = 0; i < (SIZE - 1); i++)
		{
			if(items[i] > items[i + 1])
			{
				std::swap(items[i], items[i + 1]);
				swap = true;
			}
		}
	} while(swap);
}

/* Writes to the output file.
   pre-cond: takes a properly opened output filestream
             and a SORTED array of item contributions.
   postcond: returns after writing the information to the file */
void write(ofstream& outputFile, string items[])
{
    int numLoad = 1;
    string prevItem = items[0];
    string currentItem;
    int total = 0;

    for(int i = 1; i < SIZE; i++)
    {
        if(prevItem != items[i])
        {
            outputFile << numLoad << (numLoad > 1 ? " loads" : " load")
                       << " of " << items[i - 1] << (numLoad > 1 ? " were" : " was")
                       << " delivered" << endl;
            numLoad = 1;
            prevItem = items[i];
            total++;
        }
        else
        {
            numLoad++;
        }
    }

    outputFile << "\nThere were " << total << " items contributed to this week\'s event." << endl;
}

/* Creates a preset header for the output file.
   pre-cond: takes a properly opened output filestream
   postcond: returns to the main function once writing is complete */
void createHeader(ofstream& outputFile)
{
    outputFile << std::setfill('=') << std::setw(65) << " " << endl
               << "=" << std::setfill(' ') << std::setw(42) << std::right
               << "FARMER\'S MARKET INVENTORY" << std::setw(21) << "=" << endl
               << std::setfill('=') << std::setw(65) << " " << std::setfill(' ') << endl;
    return;
}
