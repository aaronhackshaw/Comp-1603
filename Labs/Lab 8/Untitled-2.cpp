#include <iostream>
#include <string>

using namespace std;

// Define a structure for the stack node
struct StackNode {
    int data;
    StackNode* next;
};

// Function prototypes for stack operations
void push(StackNode*& top, int value);
int pop(StackNode*& top);
bool isEmpty(StackNode* top);
int sumFx(StackNode*& top);

// Function to check if the given infix expression has mismatched brackets
bool isBalanced(const string& expr) {
    StackNode* stack = nullptr;

    for (char bracket : expr) {
        if (bracket == '(') {
            push(stack, 1);
        } else if (bracket == ')') {
            if (isEmpty(stack)) {
                return false; // Unmatched closing bracket
            }
            pop(stack);
        }
    }

    return isEmpty(stack); // True if all brackets are matched, false otherwise
}

// Function to push a value onto the stack
void push(StackNode*& top, int value) {
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Function to pop a value from the stack
int pop(StackNode*& top) {
    if (!isEmpty(top)) {
        int value = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    return -1; // Or any suitable value indicating stack underflow
}

// Function to check if the stack is empty
bool isEmpty(StackNode* top) {
    return top == nullptr;
}

// Function to calculate the sum of f(x) for each integer x popped from the stack
int sumFx(StackNode*& top) {
    int sum = 0;
    while (!isEmpty(top)) {
        int x = pop(top);
        sum += (2 * x + 1);
    }
    return sum;
}

int main() {
    // 1. Test isBalanced function
    string expr;
    cout << "Enter an infix expression (without spaces): ";
    cin >> expr;
    if (isBalanced(expr)) {
        cout << "The expression has balanced brackets.\n";
    } else {
        cout << "The expression has mismatched brackets.\n";
    }

    // 2. Test sumFx function
    StackNode* stack = nullptr;
    cout << "Pushing integers onto the stack...\n";
    for (int i = 1; i <= 7; ++i) {
        push(stack, i);
        cout << "Pushed: " << i << endl;
    }
    int sum = sumFx(stack);
    cout << "Sum of f(x) for each integer x popped from the stack: " << sum << endl;

    return 0;
}
