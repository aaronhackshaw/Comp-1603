Node* getNth(Node* head, int n) {
    if (head == nullptr)
        return nullptr;

    Node* current = head;
    int count = 1;
    while (current->next != nullptr && count < n) {
        current = current->next;
        count++;
    }
    return current;
}


void duplicate(Node* list1, Node* list2) {
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data == list2->data) {
            cout << list1->data << " ";
        }
        list1 = list1->next;
    }
    cout << endl;
}


Node* makeString(const string& word) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (char c : word) {
        Node* newNode = new Node{c, nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}


Node* appendString(Node* s1, Node* s2) {
    if (s1 == nullptr)
        return s2;
    if (s2 == nullptr)
        return s1;

    Node* current = s1;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = s2;
    return s1;
}
