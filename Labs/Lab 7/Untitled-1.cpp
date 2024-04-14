#include <iostream>
using namespace std;

// Node structure
struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

// Function to insert char in order
Node* insertInOrder(Node* top, char key) {
    Node* newNode = new Node(key);

    if (top == nullptr || key < top->data) {
        newNode->next = top;
        return newNode;
    }

    Node* curr = top;
    while (curr->next != nullptr && curr->next->data < key) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    return top;
}

// Function to print linked list
void printList(Node* top) {
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    Node* top = nullptr;

    char chars[] = {'c', 'd', 'b', 'e', 'a', 'f'};
    int n = sizeof(chars) / sizeof(chars[0]);

    for (int i = 0; i < n; ++i) {
        top = insertInOrder(top, chars[i]);
    }

    cout << "Linked List: ";
    printList(top);

    return 0;
}
