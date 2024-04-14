Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


int numPairs(Node* list1, Node* list2, int sum) {
    int count = 0;
    while (list1 != nullptr) {
        Node* temp = list2;
        while (temp != nullptr) {
            if (list1->data + temp->data == sum)
                count++;
            temp = temp->next;
        }
        list1 = list1->next;
    }
    return count;
}


Node* unionL(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            tail->next = head2;
            head2 = head2->next;
        } else {
            tail->next = head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;

    return dummy->next;
}


Node* intersection(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        } else {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return dummy->next;
}
