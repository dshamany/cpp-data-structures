// Demo: Arrays
// This is to demonstrate how arrays work
// and how to pass them to functions

#include <iostream>

// arrays are passed as references because
// C++ doesn't allow an entire array to
// be passed to a function
void func(int arr[], const int size){
    for (int i = 0; i < size; ++i){
        arr[i] = -arr[i];
    }
}

int main(int argc, char const *argv[])
{
    // This is one way to declare an array
    int iA[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // The above style declaration warrants that
    // we retrieve the size of the array below
    int iA_size = sizeof(iA)/sizeof(iA[0]);

    // We can still use range based loops
    // to print a C-Style array
    for (auto& e : iA){
        printf(" %d ", e);
    }
    puts("");
    
    // Call function to ensure it is referenced
    // the function returns void
    func(iA, iA_size);

    // Since it's passed by reference to func()
    // printing the results will print the
    // transformed array
    for (auto& e : iA){
        printf("%d ", e);
    }
    puts("");
    
    return 0;
}
