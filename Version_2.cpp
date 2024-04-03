#include<bits/stdc++.h>
using namespace std;

//Linked list for the data of the students
struct Node{
    char id[9];
    string name;
    struct Node *link;
};

//print the data in all node
void traversel(struct Node* q)
{
    while(q->link!=NULL)
    {
        for(int i=0;q->name[i]!='\0';i++)
        {
            cout<<q->name[i];
        }
        cout<<" ";
        for(int j=0;j<9;j++)
        {
            cout<<q->id[j];
        }
        cout<<endl;
        q=q->link;
    }
}

//Store the file data into the Linked list
void Store_data(struct Node* head)
{
    struct Node *p = new struct Node;
    head=p;
    ifstream file;
    file.open("data.csv");
    string str;
    while(file.good())
    {
        int j=0,k=0;
        string st1 = "";
        string st2 = "";
        getline(file,str);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==',')
            {
                continue;
            }
            else if(isalpha(str[i]))
            {
                st1[j]=str[i];
                j++;
            }
            else if(isalnum(str[i]))
            {
                st2[k]=str[i];
                k++;
            }
        }
        for(int i=0;st1[i]!='\0';i++)
        {
            p->name[i]=st1[i];  
        }
        for(int o=0;o<9;o++)
        {
            p->id[o]=st2[o];
        }
        struct Node *node = new struct Node;
        p->link=node;
        p=p->link;
    }
    traversel(head);                      //print the data in all nodes of Linked list
    file.close();
}

int main()
{
    struct Node *head;
    Store_data(head);                     //Store the file data into the Linked list
}
