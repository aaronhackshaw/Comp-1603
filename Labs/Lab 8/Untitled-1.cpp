#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the given infix expression has mismatched brackets
bool isBalanced(const string& expr) {
    stack<char> brackets;

    for (char bracket : expr) {
        if (bracket == '(') {
            brackets.push(bracket);
        } else if (bracket == ')') {
            if (brackets.empty()) {
                return false; // Unmatched closing bracket
            }
            brackets.pop();
        }
    }

    return brackets.empty(); // True if all brackets are matched, false otherwise
}

int main() {
    string expression;
    cout << "Enter an infix expression (without spaces): ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The expression has balanced brackets.\n";
    } else {
        cout << "The expression has mismatched brackets.\n";
    }

    return 0;
}
