#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float radius, area;

    cout << "Enter radius: ";
    cin >> radius;

    float *ptr = (float*)malloc(sizeof(float));
    *ptr = M_PI * radius * radius;

    area = *ptr;
    cout << "Area of circle: " << area << endl;

    free(ptr);

    return 0;
}
