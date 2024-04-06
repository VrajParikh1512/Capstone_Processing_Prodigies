void mean_package(Node* q){
    int count=0,sum=0,pkg;
    while(q!=NULL){
     pkg=stoi(q->Package);
     sum+=pkg;
     count++;
     q=q->link;
    }cout<<"Mean Package = "<<(sum/count)<<endl;
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

int findLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->link;
    }
    return length;
}

void Median_package(Node* head){
    int l=findLength(head);
    Sortbypackage(head);
    Node* temp=findMiddleElement_id(head);
    if(l%2!=0){
        int p1=stoi(temp->Package);
        int p2=stoi(temp->link->Package);
        cout<<"Median Package = "<<(p1+p2)/2<<endl;
    }else{
        cout<<"Median Package = "<<temp->Package<<endl;
    }
}
