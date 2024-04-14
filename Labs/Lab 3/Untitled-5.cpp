#include <iostream>
#include <cstdlib>

using namespace std;

// Define a Node structure to hold an integer
struct Node {
    int data;
    Node* next;
};

// Function to create a linked list of integers
Node* createLinkedList() {
    Node* head = nullptr;
    Node* prev = nullptr;
    int value;
    cout << "Enter integers (terminate by -1): ";
    cin >> value;
    while (value != -1) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
        cin >> value;
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

// Function to find the sum of numbers in the linked list
int findSum(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// Function to return the product of even integers in the linked list
int findProductOfEvens(Node* head) {
    int product = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data % 2 == 0) {
            product *= temp->data;
        }
        temp = temp->next;
    }
    return product;
}

int main() {
    // Create linked list
    Node* head = createLinkedList();

    // Print linked list
    cout << "Linked list: ";
    printLinkedList(head);

    // Find and print the sum of numbers in the linked list
    int sum = findSum(head);
    cout << "Sum of numbers in the linked list: " << sum << endl;

    // Find and print the product of even integers in the linked list
    int product = findProductOfEvens(head);
    cout << "Product of even integers in the linked list: " << product << endl;

    // Free dynamically allocated memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
