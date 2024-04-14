#include <iostream>
#include <cctype>

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

// Function to count the number of vowels in the linked list
int countVowels(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        char letter = toupper(temp->data);
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
            count++;
        }
        temp = temp->next;
    }
    return count;
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

int main() {
    // Create linked list of letters
    Node* head = createLinkedList();

    // Count and print the number of vowels in the linked list
    int vowelCount = countVowels(head);
    cout << "Number of vowels in the linked list: " << vowelCount << endl;

    // Free dynamically allocated memory
    deleteLinkedList(head);

    return 0;
}
