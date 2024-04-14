#include <iostream>
#include <cstdlib>

using namespace std;

// Define a Node structure to hold an integer
struct Node {
    int data;
    Node* next;
};

// Function to create a linked list with the integers 1, 2, and 3
Node* createLinkedList() {
    Node* head = nullptr;
    for (int i = 3; i > 0; --i) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to print elements of a linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create and print a linked list with the integers 1, 2, and 3
    Node* head = createLinkedList();
    cout << "Linked list with integers: ";
    printLinkedList(head);
    return 0;
}
