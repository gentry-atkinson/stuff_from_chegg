// C++ program to sort an array of integers in ascending order using selection sort

#include <iostream>

using namespace std;

/**
* Function that takes as inputs an array of integers and its size
* and sorts the array elements in ascending order using selection sort.
*/
void selectionSort(int sortingArray[], int SIZE)
{
    // loop from first element to second last element of array(inclusive)
    for(int i=0;i<SIZE-1;i++)
    {
        // find the index of minimum element of the array starting from index i
        // the index of minimum element should be initialized to i not 0
        int min_index = i;

        // loop from i+1 to end of array, to find the index of (i+1)th minimum element starting from index i
        for(int j=i+1;j<SIZE;j++){
            // jth element of array is less than min_index-th element, update min_index to j
            if(sortingArray[j] < sortingArray[min_index]){
                min_index = j; // element at index j is less than min_index, not 0, hence min_index should be set to j
            }
        }

        // swap the elements at index min_index and i, so that (i+1)th minimum element is inserted in its correct index
        int temp = sortingArray[min_index];
        sortingArray[min_index] = sortingArray[i];
        sortingArray[i] = temp;
    }
}

int main(int argc, char** argv)
{
    // test the selectionSort function
    int a[] = {5, 8, 3, 5, 1, 2, 9, 4, 7};
    selectionSort(a, 9);
    for(int i=0;i<9;i++)
        cout << a[i] << ' ';

    return 0;
}

// end of program