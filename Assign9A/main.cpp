/*
  Pgm: Assign9-A
  Name: Lilith Freed (laf65)
  Purpose: Reverses the order of the characters in a series of c-strings.
  Copyright Lilith Freed, All Rights Reserved

*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "reverseString.hpp"

using namespace std;

int main()
{
  // these are the test cases
  char str1[] = "time";
  char str2[] = "straw";
  char str3[] = "deliver";
  char str4[] = "star";
  char str5[] = "knits";


  cout << "The strings before reversing: " << endl;
  cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;

  reverseString(str1);
  reverseString(str2);
  reverseString(str3);
  reverseString(str4);
  reverseString(str5);

  cout << "The strings after reversing: " << endl;
  cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;

  return 0;
}

