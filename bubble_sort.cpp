#include <iostream>

int iA[10] = {3, 6, 9, 7, 0, 8, 2, 1, 5, 4};

void printArray(int* arr, const int size){
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    puts("");
}

void sort(int *arr, const int size)
{
    // add flag to know when sorting is over
    bool didSwap = true;
    // we don't know how many times we need to swap
    // we only know when to stop
    while (didSwap)
    {
        // set didSwap to false so we ensure fresh start
        didSwap = false;
        // start at i = 1 to check for previous value
        for (int i = 1; i < size; i++)
        {
            // compare current element to previous
            // swap if needed
            if (arr[i] < arr[i - 1])
            {
                // swap data
                auto tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                // inform our flag that we swapped
                didSwap = true;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    sort(iA, 10);
    printArray(iA, 10);
    return 0;
}
