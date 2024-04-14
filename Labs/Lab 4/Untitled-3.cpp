#include <iostream>

using namespace std;

// Define a Node structure to hold an integer
struct Node {
    int data;
    Node* next;
};

// Function to delete the top node of a linked list
Node* deleteTopNode(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Top node deleted successfully." << endl;
    }
    return head;
}

// Function to delete intermediate nodes of a linked list
Node* deleteIntermediateNodes(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "No intermediate nodes to delete." << endl;
        return head;
    }
    Node* temp = head->next;
    Node* prev = head;
    while (temp != nullptr && temp->next != nullptr) {
        Node* delNode = temp;
        prev->next = temp->next;
        temp = temp->next;
        delete delNode;
    }
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    // Create linked list of integers: 1, 2, 3, 4, 5, 6
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{6, nullptr}}}}}};
    cout << "Original linked list: ";
    printList(head);

    // Delete the top node
    head = deleteTopNode(head);
    cout << "Linked list after deleting the top node: ";
    printList(head);

    // Delete intermediate nodes
    head = deleteIntermediateNodes(head);
    cout << "Linked list after deleting intermediate nodes: ";
    printList(head);

    // Free dynamically allocated memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
