#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

Node* arraytoLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover= head;
    for (int i=1; i<arr.size(); i++){
        Node* temp= new Node(arr[i]);
        mover->next = temp;
        mover= temp;
    }
    return head;
}

Node* merge2sortedLL(Node* temp1, Node* temp2){
    Node* dummy = new Node (-1);
    Node* temp= dummy;
   
   while (temp1!=nullptr && temp2 != nullptr){
    if (temp1->data <= temp2->data){
        temp->next= temp1;
        temp= temp1;
        temp1= temp1->next;
    }
    else{
        temp->next = temp2;
        temp= temp2;
        temp2 = temp2->next;
    }
    
    if (temp1==nullptr){
        temp->next = temp2;
    }
    else if (temp2 == nullptr){
        temp->next = temp1;
    }
}
return dummy->next;
}

Node* findmiddleelement(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next != nullptr && fast->next->next!= nullptr){
        fast = fast->next->next;
        slow= slow->next;
    }
  return slow;  
}

Node* sortaLL(Node* head){
    if (head==nullptr || head->next==nullptr){
        return head;
    }
    
   Node* middle= findmiddleelement(head);
    
    Node* righthead = head;
    Node* lefthead = middle->next;
    middle->next= nullptr;
    
    lefthead= sortaLL(lefthead);
    righthead= sortaLL(righthead);
    
    return merge2sortedLL(lefthead, righthead);
    
}

int main (){
    
    vector<int> arr1= {17, 19, 11, 3, 16, 1, 7, 18, 31, 12};
    Node* head;
    
    head = arraytoLL(arr1);
    
    cout<<"The Unsorted Linked List is:- ";
    for(Node* current= head; current!= nullptr; current= current->next){
        cout<<current->data<<" ";
    }
    
    head = sortaLL(head);
    
    cout<<"\n";
    
    cout<<"The Sorted Linked List is:- ";
    for(Node* current= head; current!= nullptr; current= current->next){
        cout<<current->data<<" ";
    }
    
    return 0;
    
}
