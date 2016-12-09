#ifndef DISPLAYARRAY_HPP
#define DISPLAYARRAY_HPP

/* Takes the pointer to the array to be displayed, the
   number of elements in the array, and displays them
   in a row, each separated by spaces.
   precond: the int[], int have been initialized
   postcond: displays the elements of the given array
*/

void displayArray(int *arr, int numElems)
{
    for(int i = 0; i < numElems; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

#endif // DISPLAYARRAY_HPP
