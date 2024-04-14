#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};


// Function to insert a character in order into a linked list
Node* insertInOrder(Node* top, char key) {
    Node* newNode = new Node{key, nullptr};
    if (top == nullptr || key < top->data) {
        newNode->next = top;
        return newNode;
    }

    Node* current = top;
    while (current->next != nullptr && current->next->data < key) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return top;
}

// Function to merge two sorted linked lists
Node* mergeSorted(Node* list1, Node* list2) {
    Node dummy{0, nullptr};
    Node* tail = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes of list1 or list2
    tail->next = (list1 != nullptr) ? list1 : list2;

    return dummy.next;
}

// Function to print the elements of a linked list
void printList(Node* top) {
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    // Create a new linked list with characters 'l', 'i', 'g', 'h', 'j', 'k'
    Node* newList = nullptr;
    char chars[] = {'l', 'i', 'g', 'h', 'j', 'k'};
    for (char c : chars) {
        newList = insertInOrder(newList, c);
    }

    // Print the new list
    cout << "New list after insertion: ";
    printList(newList);

    // Merge newList with the list created in question 1
    Node* list1 = new Node{1, new Node{2, new Node{3, nullptr}}}; // Assuming this is the list from question 1
    Node* mergedList = mergeSorted(list1, newList);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    // Free memory (deallocate nodes)
    Node* current = mergedList;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
