/*
  Pgm: Assign7-A
  Name: Lilith Freed (laf65)
  Purpose: Calculate various statistic variables based on user input.

*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int SIZE = 100;

void numbers(int []);
void sum(int []);
void avg(int []);
void biggest(int []);
void mode(int []);
void howMany(int []);
void median(int []);

int main()
{
    int frequency[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        frequency[i] = 0;
    }

    cout << "Welcome to Stats Array!\n"
         << "These are your choices:\n"
         << "N- Numbers\nS- Sum of all\n"
         << "A- Average of all\nB-Biggest of all\n"
         << "F- Most frequent of all\n"
         << "H- How many numbers\n"
         << "M- median of all\n"
         << "Q- Quit\n" << endl;

    char selection = 0;
    do
    {
        cin >> selection;

        switch(selection)
        {
            case 'n':
            case 'N':
                numbers(frequency);
                break;
            case 's':
            case 'S':
                sum(frequency);
                break;
            case 'a':
            case 'A':
                avg(frequency);
                break;
            case 'b':
            case 'B':
                biggest(frequency);
                break;
            case 'f':
            case 'F':
                mode(frequency);
                break;
            case 'h':
            case 'H':
                howMany(frequency);
                break;
            case 'm':
            case 'M':
                median(frequency);
                break;
            case 'q':
            case 'Q':
                cout << "END" << endl;
                break;
            default:
                cout << "Not a valid command." << endl;
        }

    } while(selection != 'q' && selection != 'Q');

    return 0;
}

// FUNCTION BLOCK //

/* Adds the occurence of a number to the frequency array.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs "OK" to the screen after completing the task */
void numbers(int frequency[])
{
    int number;
    cin >> number;

    if(number > 99 || number < 0)
    {
        cout << "OK" << endl;
        return;
    }
    else
    {
        frequency[number]++;
        cout << "OK" << endl;
    }

    return;
}

/* Sums all numbers in the array.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs the sum to the screen after completing the task
             (the sum is 0 if there are no numbers in the array) */
void sum(int frequency[])
{
    int sum = 0;

    for(int i = 0; i < SIZE; i++)
    {
        sum += frequency[i] * i;
    }

    cout << sum << endl;

    return;
}

/* Calculates the average of all input numbers read so far.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs average to the screen if numbers have been read
             outputs "ERROR" if no numbers have been read yet */
void avg(int frequency[])
{
    int sum = 0, numCount = 0;

    for(int i = 0; i < SIZE; i++)
    {
        sum += frequency[i] * i;
        numCount += frequency[i];
    }

    if(numCount == 0)
    {
        cout << "ERROR" << endl;
        return;
    }
    else
    {
        cout << sum / numCount << endl;
    }

    return;
}

/* Outputs the maximum value in the current array.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs the maximum value in the array
             outputs "ERROR" if no numbers have been read */
void biggest(int frequency[])
{
    for(int i = SIZE - 1; i >= 0; i--)
    {
        if(frequency[i] > 0)
        {
            cout << i << endl;
            return;
        }
    }

    cout << "ERROR" << endl;
    return;
}

/* Outputs the mode of the current array.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs the mode of the array
             outputs "ERROR" if no numbers have been read */
void mode(int frequency[])
{
    int maxFreq = 0, mode = 0;

    for(int i = 0; i < SIZE; i++)
    {
        if(frequency[i] > maxFreq)
        {
            mode = i;
            maxFreq = frequency[i];
        }
    }

    if(maxFreq > 0)
    {
        cout << mode << endl;
        return;
    }
    else
    {
        cout << "ERROR" << endl;
    }

    return;
}

/* Outputs how many numbers have been read so far.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs how many numbers have been read */
void howMany(int frequency[])
{
    int howMany = 0;

    for(int i = 0; i < SIZE; i++)
    {
        howMany += frequency[i];
    }

    cout << howMany << endl;

    return;
}

/* Outputs the median of the current array.
   pre-cond: the int[] frequency array has been initialized
   postcond: outputs the median of the array
             outputs "ERROR" if no numbers have been read */
void median(int frequency[])
{
    int numRead = 0;

    for(int i = 0; i < SIZE; i++)
    {
        if(frequency[i] > 0)
        {
            numRead++;
        }
    }

    if(numRead == 0)
    {
        cout << "ERROR" << endl;
        return;
    }
    else
    {
        int counter = 0;
        int medIndex = numRead - (numRead / 2);

        for(int i = 0; i < SIZE; i++)
        {
            if(frequency[i] > 0)
            {
                counter++;

                if(counter == medIndex)
                {
                    cout << i << endl;
                    return;
                }
            }
        }
    }
}
