#ifndef GETWORD_HPP
#define GETWORD_HPP

/* The getWord function receives a int for the starting
   index of a word and a string sentence to parse through.
   precond: i, sentence have been initialized
   postcond: returns a string that is the word transcr. from the sent.
             i is the index of the non-alpha char following the word
*/

std::string getWord(int &i, std::string sentence)
{
    std::string word = "";

    do
    {
        // appends the alpha char to the word
        // for each iteration
        word += sentence.substr(i, 1);
        i++;

    } while(std::isalpha(sentence[i]));

    return word;
}
#endif // GETWORD_HPP
