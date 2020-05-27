// Demo: Merge Sort

#include <iostream>

// merges subarrays
// first subarray arr[l...m]
// second consists of arr[m+1...r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    // parameters: left, middle, right

    int n1 = m - l + 1; // size of left subarray
    int n2 = r - m;     // size of right array;

    // declare temp subarrays
    int L[n1], R[n2];

    // split array into temp subarrays
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // merge subarrays
    i = j = 0; // initial index of left and right subarrays
    k = l; // initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining L[] elements if any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // copy remaining R[] elements if any
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// mergeSort() contains order of operation
void mergeSort(int arr[], int l, int r){
    if (l < r){
        // calculate middle point
        // avoids overflow compared to (l+r)/2
        int m = (l+r)/2;

        // sort left through middle
        mergeSort(arr, l, m);
        // sort middle+1 through right
        mergeSort(arr, m+1, r);
        // merge the array
        merge(arr, l, m, r);
    }
}

int main(int argc, char const *argv[])
{
    int iA[] = { 12, 11, 13, 5, 8, 6, 42, 55, 102 };
    int size = sizeof(iA)/sizeof(iA[0]);

    puts("initial Array:");
    for (auto& e: iA){
        printf("%d ", e);
    }
    mergeSort(iA, 0, size-1);

    puts("\nSorted Array:");
    for (auto& e : iA){
        printf("%d ", e);
    }
    puts("");

    return 0;
}
