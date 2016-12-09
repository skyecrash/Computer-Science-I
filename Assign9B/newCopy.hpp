#ifndef NEWCOPY_HPP
#define NEWCOPY_HPP

/* Takes the pointer to the array to be expanded, the size
   of that array, and creates a new array one element larger
   than the size with all elements of the input shifted to the right.
   The first element is 0.
   precond: the int[], int have been initialized
   postcond: returns the unique_ptr of the new, larger array
*/

std::unique_ptr<int[]> newCopy(int* oldArray, int numElems)
{
    std::unique_ptr<int[]> newArray(new int[numElems + 1]);
    newArray[0] = 0;

    for(int i = 1; i < numElems + 1; i++)
    {
        newArray[i] = oldArray[i - 1];
    }

    return newArray;
}

#endif // NEWCOPY_HPP
