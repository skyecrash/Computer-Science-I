#ifndef TRANSCRSENT_HPP
#define TRANSCRSENT_HPP
#include "getWord.hpp"
#include "toPigLatin.hpp"

/* The transcrSent function takes one string parameter
   (a sentence) and outputs the Pig Latin version.
   precond: the string parameter has been initialized
   postcond: returns the word converted to Pig Latin
*/


void transcrSent(std::string sentence)
{
    int i = 0;

    // moves along sentence until end has been reached
    while(i < sentence.length())
    {
        // if the char is punc/space, write it to line
        if(!(std::isalpha(sentence[i])))
        {
            std::cout << static_cast<char>(sentence[i]);
            i++;
        }
        else
        {
            // toPigLatin takes word from getWord and converts.
            // i is updated to the index of the non-alpha char
            // following the word translated.
            std::cout << toPigLatin(getWord(i, sentence));
        }
    }

    std::cout << std::endl;
}
#endif // TRANSCRSENT_HPP
