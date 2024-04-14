#include <iostream>

int main() {
  int var = 10;

  // Declare pointers
  int* ptrVar = &var;  // ptrVar points to the address of var
  int** pPtrVar = &ptrVar;  // pPtrVar points to the address of ptrVar

  // Print initial values
  std::cout << "Contents of var: " << var << std::endl;
  std::cout << "Address of var: " << &var << std::endl;

  std::cout << "Contents of ptrVar: " << ptrVar << std::endl;
  std::cout << "Address of ptrVar: " << &ptrVar << std::endl;
  std::cout << "Value pointed to by ptrVar: " << *ptrVar << std::endl;

  std::cout << "Contents of pPtrVar: " << pPtrVar << std::endl;
  std::cout << "Address of pPtrVar: " << &pPtrVar << std::endl;
  std::cout << "Value pointed to by pPtrVar: " << *pPtrVar << std::endl;

  // Another level of pointers
  int*** ppPtrVar = &pPtrVar;

  std::cout << "Contents of ppPtrVar: " << ppPtrVar << std::endl;
  std::cout << "Address of ppPtrVar: " << &ppPtrVar << std::endl;
  std::cout << "Value pointed to by ppPtrVar: " << *ppPtrVar << std::endl;

  return 0;
}
