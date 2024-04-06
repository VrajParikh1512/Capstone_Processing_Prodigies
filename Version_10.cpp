Node* merge2sortedLL_id(Node* temp1, Node* temp2) {
    Node* dummy = new Node();
    Node* temp = dummy;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->Id <= temp2->Id) {
            temp->link = temp1;
            temp = temp1;
            temp1 = temp1->link;
        }
        else {
            temp->link = temp2;
            temp = temp2;
            temp2 = temp2->link;
        }
    }

    if (temp1 == nullptr) {
        temp->link = temp2;
    }
    else if (temp2 == nullptr) {
        temp->link = temp1;
    }

    return dummy->link;
}

Node* findMiddleElement_id(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->link != nullptr && fast->link->link != nullptr) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow;
}

Node* mergeSort_id(Node* head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }

    Node* middle = findMiddleElement_id(head);
    Node* rightHead = head;
    Node* leftHead = middle->link;
    middle->link = nullptr;

    leftHead = mergeSort_id(leftHead);
    rightHead = mergeSort_id(rightHead);

    return merge2sortedLL_id(leftHead, rightHead);
}
