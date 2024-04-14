#include <iostream>

using namespace std;

int main() {
    float principal, rate, time, simpleInterest;

    cout << "Enter principal, rate, and time: ";
    cin >> principal >> rate >> time;

    float *ptr = &principal;
    simpleInterest = *ptr * rate * time / 100;

    cout << "Simple Interest: " << simpleInterest << endl;

    return 0;
}
