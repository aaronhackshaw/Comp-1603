#include <iostream>
#include <string>

using namespace std;

// Define a Node structure to hold a letter
struct Node {
    char data;
    Node* next;
};

// Function to create a linked list of letters
Node* createLinkedList() {
    Node* head = nullptr;
    Node* prev = nullptr;
    char letter;
    cout << "Enter letters (terminate by '*'): ";
    cin >> letter;
    while (letter != '*') {
        Node* newNode = new Node;
        newNode->data = letter;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
        cin >> letter;
    }
    return head;
}

// Function to delete the entire linked list to free memory
void deleteLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to compare a string with the linked list
bool compareStringWithList(Node* head, const string& target) {
    Node* temp = head;
    for (char letter : target) {
        if (temp == nullptr || temp->data != letter) {
            return false;
        }
        temp = temp->next;
    }
    return temp == nullptr; // Ensure linked list is exhausted
}

int main() {
    // Create linked list of letters
    Node* head = createLinkedList();

    // Read string from user
    string target;
    cout << "Enter a string to compare with the linked list: ";
    cin >> target;

    // Compare the string with the linked list
    bool isEqual = compareStringWithList(head, target);
    if (isEqual) {
        cout << "The string is equal to the linked list." << endl;
    } else {
        cout << "The string is not equal to the linked list." << endl;
    }

    // Free dynamically allocated memory
    deleteLinkedList(head);

    return 0;
}
