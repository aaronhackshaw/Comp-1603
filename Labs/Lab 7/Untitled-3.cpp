#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

int data[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (!isFull()) {
        data[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    } else {
        cout << "Stack Overflow! Cannot push " << value << " onto the stack." << endl;
    }
}

int pop() {
    if (!isEmpty()) {
        int poppedValue = data[top--];
        cout << "Popped " << poppedValue << " from the stack." << endl;
        return poppedValue;
    } else {
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
        return -1; // Signifies failure
    }
}

int main() {
    // Pushing three numbers onto the stack
    push(5);
    push(10);
    push(15);

    // Removing two numbers and checking if their sum is even
    int num1 = pop();
    int num2 = pop();
    int sum = num1 + num2;
    if (sum % 2 == 0) {
        cout << "Sum of " << num1 << " and " << num2 << " is even." << endl;
    } else {
        cout << "Sum of " << num1 << " and " << num2 << " is odd." << endl;
    }

    // Attempting to remove two more numbers
    pop();
    pop(); // This will result in Stack Underflow

    return 0;
}
