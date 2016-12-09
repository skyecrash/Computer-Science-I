/*
  Pgm: Assign8-A
  Name: Lilith Freed (laf65)
  Purpose: Process a file containing sentences and convert them
           to Pig Latin.
  Copyright Lilith Freed, All Rights Reserved

*/

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <iomanip>
#include <cctype>
#include "transcrSent.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    ifstream inputFile("ASSGN8-A.txt");

    if(!inputFile.fail())
    {
        string sentence = "";

        while(!(std::getline(inputFile, sentence, '\n').eof()))
        {
            cout << sentence << endl;
            transcrSent(sentence);
        }
    }
    else
    {
        cout << "The file did not open properly! Program ending.\n";
    }

    return 0;
}
