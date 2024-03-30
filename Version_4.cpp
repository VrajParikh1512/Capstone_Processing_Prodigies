#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node{
    // char sr_no;
    string Name = "";
    string Email = "";
    string Interview_date="";
    string Interview_status="";
    string Start_time="";
    string End_time="";
    string Programme = "";
    string Contact_no;
    string Whatsapp_no;
    string Alt_no;
    string Skype_id = ""; 
    string Id = "";
    struct Node *link;
};

void traversel(struct Node* q)
{
    while(q != NULL)
    {
        // cout << q->sr_no << " ";
        cout << q->Name << " ";
        cout << q->Interview_date << " ";
        cout << q->Interview_status << " ";
        cout << q->Start_time << " ";
        cout << q->End_time << " ";
        cout << q->Id << " ";
        cout << q->Email << " ";
        cout << q->Programme << " ";
        cout << q->Contact_no << " ";
        cout << q->Whatsapp_no << " ";
        cout << q->Alt_no << " ";
        cout << q->Skype_id << endl;
        q = q->link;
    }
}

void Store_data(struct Node* &head)
{
    ifstream file;
    file.open("data.csv");
    string str;
    Node* p = nullptr;
    Node* temp = nullptr;
    head = nullptr;

    while(getline(file, str))
    {
        p = new Node;
        stringstream inputstring(str);

        getline(inputstring,p->sr_no , ',');
        // p->sr_no = stoi(str);

        getline(inputstring, p->Name, ',');
        getline(inputstring, p->Interview_date, ',');
        getline(inputstring, p->Interview_status, ',');
        getline(inputstring, p->Start_time, ',');
        getline(inputstring, p->End_time, ',');
        getline(inputstring, p->Id, ',');
        getline(inputstring, p->Email, ',');
        getline(inputstring, p->Programme, ',');
        getline(inputstring, p->Contact_no, ',');
        getline(inputstring, p->Whatsapp_no, ',');

        getline(inputstring, p->Alt_no, ',');
        getline(inputstring, p->Skype_id, ',');

        p->link = nullptr;

        if (head == nullptr) {
            head = p;
            temp = p;
        } else {
            temp->link = p;
            temp = temp->link;
        }

        // Debug output
        // cout << "DEBUG: Contact_no: " << p->Contact_no << ", Whatsapp_no: " << p->Whatsapp_no << ", Alt_no: " << p->Alt_no << endl;
    }

    traversel(head);                      
    file.close();
}

int main()
{
    struct Node *head = nullptr;
    Store_data(head);                    
}
