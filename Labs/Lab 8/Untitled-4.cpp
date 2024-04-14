#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(const string& word) {
    stack<char> letters;

    // Push each letter onto the stack
    for (char c : word) {
        letters.push(c);
    }

    // Pop each letter from the stack and compare with the original word
    for (char c : word) {
        if (c != letters.top()) {
            return false;
        }
        letters.pop();
    }

    return true;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word)) {
        cout << "The word is a palindrome.\n";
    } else {
        cout << "The word is not a palindrome.\n";
    }

    return 0;
}
