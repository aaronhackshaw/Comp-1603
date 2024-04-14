#include <iostream>
#include <cstdlib> // For malloc and free
using namespace std;

int main() {
  // Allocate memory for ptr
  int* ptr = (int*)malloc(sizeof(int));
  if (ptr == nullptr) {
    cerr << "Error allocating memory for ptr." << std::endl;
    return 1;
  }

  // Set the value pointed to by ptr
  *ptr = 22;

  // Allocate memory for pPtr
  int** pPtr = (int**)malloc(sizeof(int*));
  if (pPtr == nullptr) {
    cerr << "Error allocating memory for pPtr." << std::endl;
    free(ptr); // Free previously allocated memory
    return 1;
  }

  // Assign ptr to pPtr (now pPtr points to ptr)
  *pPtr = ptr;

  // Print information about ptr
  cout << "Contents of ptr: " << *ptr << std::endl;
  cout << "Address of ptr: " << ptr << std::endl;

  // Print information about pPtr
  cout << "Contents of pPtr: " << *pPtr << std::endl; // Prints the value of ptr
  cout << "Address of pPtr: " << pPtr << std::endl;
  cout << "Value pointed to by pPtr (**pPtr): " << **pPtr << std::endl;

  // Free allocated memory
  free(ptr);
  free(pPtr);

  return 0;
}
