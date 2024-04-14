#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

int x = 10;
cout<< "Address of x:"<< &x <<endl;

int *ptr = new int;
*ptr = 20;
cout << "Address of ptr: " <<ptr << endl;

int *ptr2 = (int*)malloc(sizeof(int));  // Using malloc
*ptr2 = 30;
cout << "Address of ptr2: " << ptr2 << endl;

return 0;
}
