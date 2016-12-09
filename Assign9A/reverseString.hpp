#ifndef REVERSESTRING_HPP
#define REVERSESTRING_HPP

/* Takes a c-string and reverses the order of its characters.
   precond: c-string is initialized
   postcond: the order of the characters in the c-string is reversed
*/

void reverseString(char str[])
{
    char *frontPtr, *backPtr;
    frontPtr = str;
    backPtr = &str[strlen(str) - 1];

    for(int i = 0; i < strlen(str) / 2; i++)
    {
        char temp = *frontPtr;
        *frontPtr = *backPtr;
        *backPtr = temp;
        frontPtr++;
        backPtr--;
    }
}

#endif // REVERSESTRING
