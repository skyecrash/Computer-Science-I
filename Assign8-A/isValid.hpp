#ifndef ISVALID_HPP
#define ISVALID_HPP

/* The isValid function takes one string parameter and checks to see
   if it is a valid word. (e.g. all its characters are letters)
   precond: the string is declared and initialized
   postcond: returns a bool that is true if the word is valid and
             false otherwise
*/

bool isValid(const string &str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if(!isalpha(str[i]))
     {
       return false;
     }
   }
   return true;
}

#endif // ISVALID_HPP
