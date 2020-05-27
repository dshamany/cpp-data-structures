// DEMO: Selection Sort

#include <iostream>

int iA[10] = {3, 6, 9, 7, 0, 8, 2, 1, 5, 4};

// swap function
void swap (int& n1, int& n2){
    auto tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void sort(int *arr, const int &size)
{  
    int min_idx; // this handle moves along the array

    // loop from the beginning to the size-1 to ensure array is within bounds
    // to search for the next element
    for (int i = 0; i < size-1; i++){
        // grab the current location index
        min_idx = i;

        // loop through second element to the end
        for (int j = i+1; j < size; j++){
            if (arr[min_idx] > arr[j]){
                // capture the smaller value
                min_idx = j;
            }

        }
        // swap with initial value index (i)
        swap(arr[min_idx], arr[i]);
    }
}


int main(int argc, char const *argv[])
{
    puts("Before:");
    for (auto& e : iA)
        printf("%d ", e);
    puts("");

    sort(iA, 10);

    puts("After:");
    int size = 0;
    for (auto& e : iA){
        size++;
        printf("%d \n", e);
    }
    puts("");

    printf("Array Size: %lu\n", sizeof(iA)/sizeof(iA[0]));
    printf("Array Size: %lu\n", getSize(iA));
    return 0;
}
