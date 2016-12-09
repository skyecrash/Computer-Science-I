/*
  Pgm: Assign9-B
  Name: Lilith Freed (laf65)
  Purpose: Declare an array, then use the newCopy function to
           add one to the array's size.
  Copyright Lilith Freed, All Rights Reserved

*/

#include <iostream>
#include <cstdlib>
#include <memory>
#include <cctype>
#include "newCopy.hpp"
#include "displayArray.hpp"

const int SIZE = 5;

int main()
{
    int myNumbers[SIZE] = {18, 27, 3, 14, 95};
    displayArray(myNumbers, SIZE);

    std::unique_ptr<int[]> newNumbers = newCopy(myNumbers, SIZE);
    displayArray(newNumbers.get(), SIZE + 1);

    return 0;
}
