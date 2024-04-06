Node* merge2sortedLL_package(Node* temp1, Node* temp2) {
    Node* dummy = new Node();
    Node* temp = dummy;

    while (temp1 != nullptr && temp2 != nullptr) {
        int a = stoi(temp1->Package);
        int b = stoi(temp2->Package);
        if (a <= b) {
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

Node* findMiddleElement_package(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->link != nullptr && fast->link->link != nullptr) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow;
}

Node* Sortbypackage(Node* head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }

    Node* middle = findMiddleElement_package(head);
    Node* rightHead = head;
    Node* leftHead = middle->link;
    middle->link = nullptr;

    leftHead = Sortbypackage(leftHead);
    rightHead = Sortbypackage(rightHead);

    return merge2sortedLL_package(leftHead, rightHead);
}
