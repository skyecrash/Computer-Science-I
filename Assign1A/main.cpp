/*
  Pgm: Assign6-A
  Name: Lilith Freed (laf65)
  Purpose: Process a file containing data from a Farmer's Market, and
           write a new output file based on the information.

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

bool readAndWrite(ifstream&, ofstream&, int&, float&);
void createHeader(ofstream&);

int main()
{
    ifstream inputFile;
    inputFile.open("ASSGN6-A.txt");

    if(!inputFile.fail())
    {
        cout << "Reading file...\n";

        bool eof = false; // tracks the end of inputFile
        int itemTotal = 0; // grand total of quantity of items
        float priceTotal = 0.0; // grand total of price of items

        ofstream outputFile("FarmersMarketReport.txt"); // output file

        createHeader(outputFile); // tacks header to output file

        // calls the function that writes into file while the EOF is not reached
        while(!eof)
        {
            eof = readAndWrite(inputFile, outputFile, itemTotal, priceTotal);
        }

        // tacks the grand total to the end of the file
        outputFile << std::setw(25) << std::left << "Grand Total:" << itemTotal << " items totaling $" << priceTotal;

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

/* Reads the given input filestream and writes to the given output filestream.
   pre-cond: takes a properly opened input filestream, a properly opened output filestream,
             and the grand total for item quantity and price
   postcond: returns if the input filestream has reached the end of the file, and updates
             the grand totals for item quantity and price */
bool readAndWrite(ifstream& inputFile, ofstream& outputFile, int& itemTotal, float& grandTotal)
{
    // vars to hold input file items
    string name, item;
    int quantity;
    float price;

    // input from the input file
    std::getline(inputFile, name, ',');
    inputFile >> quantity;
    inputFile >> item;
    inputFile >> price;

    // updating grand totals
    grandTotal += quantity * price;
    itemTotal += quantity;

    // writing the formatted file output
    outputFile << std::setw(25) << std::left << name + ":" << quantity << " " << item
               << " @" << std::fixed << std::setprecision(2) << price
               << " each totaling $" << quantity * price << endl << endl;

    // ignores excess spaces
    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // returns for end of file
    if(inputFile.eof())
    {
        return true;
    }
    else
    {
        return false;
    }
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
