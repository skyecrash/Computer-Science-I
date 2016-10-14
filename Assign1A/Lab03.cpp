/*
  Pgm: Data Validation (lab3)
  Name: Lilith Freed (laf65)
  Purpose: Learning exercise on data validation.

*/

#include <iostream> // for I/O stream operations
#include <iomanip> // for providing parametric manipulators ops
#include <limits> // for providing elements with the characteristics of arithmetic types

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double organisms = 0.00; // holds # of organisms

    bool loopFlag = true; // control flag for the loop



    return 0; //ends program
}

/* What does the using std::…, do for us, and why would we use this instead of using std namespace?
   By including using std:: instead of the entire namespace, we limit the number of functions our program "saves" for use
   and improve code performance.

   What about cin.fail() for console input?
   cin.fail() is a function that returns false whenever there is an error in the input stream (data mismatch, etc), and returns true otherwise.

   What was a short-circuit evaluation?
   A short-circuit evaluation/test is one that only requires the information to the left of a boolean operator to be completed.
   The or expression in the if, for example, will finish evaluating if the cin.fail() returns true, because that value of true means the
   expression will return a value of true no matter what the value of the condition on the right is. This can help make a program faster overall.

   What about the parameters for ignore, the numeric limits and streamsize?
   <std::streamsize> is a type that designates the current size of an input or output stream buffer. Applying std::numeric_limits to this type
   allows us to find certain arithmetic properties of the streamsize, such as the maximum number of characters located within. ::max() therefore
   obtains the size of the input buffer, and passes that on to the .ignore function to tell it how many characters to pass over and throw away.
   Once that many characters have been skipped, it then stops at the newline character, the second parameter of the ignore function. */
