/*
  Pgm: ASSGN2-B
  Name: Lilith Freed (laf65)
  Purpose: This program will convert a miles per hour pace into minutes per mile.

*/

#include <iostream>
using namespace std;

int main()
{
  char YN = 'Y';

  while (YN == 'Y') {

      double milesPerHour;

      // Input miles per hour
      cout << "Enter speed in miles per hour: ";
      cin >> milesPerHour; // Get MPH.

      // Compute inverse, (hours per mile)
      double hoursPerMile = 1.0 / milesPerHour;

      // Convert to minutes per mile (60 seconds/hour * hoursPerMile)
      double minutesPerMile = 60 * hoursPerMile;

      // Extract minutes by converting to an integer, cutting off decimal
      int minutesPace = static_cast<int>(minutesPerMile);

      // Seconds is the remaining number of minutes * 60
      double secondsPace = (minutesPerMile - minutesPace) * 60;

      cout << "\n" << milesPerHour << " miles per hour is a pace of "
           << minutesPace << " minutes and " << secondsPace << " seconds.\n" << endl;

      cout << "\nDo you want to try again? (Y/N)" << endl;
      cin.ignore();
      cin.get(YN);
  }

  return 0;

}
