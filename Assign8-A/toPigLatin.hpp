#ifndef TOPIGLATIN_HPP
#define TOPIGLATIN_HPP


/* The toPigLatin function takes a string word and
   converts it to the Pig Latin cipher.
   precond: the string parameter contains only letters
   postcond: returns the word converted to Pig Latin
*/

std::string toPigLatin(std::string word)
{
    if(word.length() == 1)
    {
        return word + "AY";
    }
    else
    {
        return word.substr(1, word.length() - 1) + word.substr(0, 1) + "AY";
    }
}

#endif // TOPIGLATIN_HPP
