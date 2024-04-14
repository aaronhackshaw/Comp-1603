#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For tolower
using namespace std;

bool isPalindrome(const string& word) {
    stack<char> charStack;

    // Pushing characters onto the stack
    for (char ch : word) {
        if (isalpha(ch)) { // Only push letters onto the stack
            charStack.push(tolower(ch)); // Convert to lowercase for case-insensitive comparison
        }
    }

    // Checking if the word is a palindrome
    for (char ch : word) {
        if (isalpha(ch)) {
            char poppedChar = charStack.top();
            charStack.pop();
            if (tolower(ch) != poppedChar) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word)) {
        cout << "The word \"" << word << "\" is a palindrome." << endl;
    } else {
        cout << "The word \"" << word << "\" is not a palindrome." << endl;
    }

    return 0;
}
