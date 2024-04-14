#include <iostream>
#include <cstdlib>

using namespace std;

// Function to print elements of an integer array using pointers
void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " "; // Accessing array elements using pointers
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i); // Accepting values using pointers
    }

    cout << "Array elements: ";
    printArray(arr, n); // Printing array elements using pointers

    // Freeing dynamically allocated memory
    delete[] arr;

    return 0;
}
