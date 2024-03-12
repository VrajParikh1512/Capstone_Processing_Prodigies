#include<bits/stdc++.h>
using namespace std;

struct Node{
    string id[9];
    string name;
    struct Node *link;
};

int main()
{
    struct Node *head;
    struct Node *p = new struct Node;
    head=p;
    ifstream file;
    file.open("s.csv");
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
                // cout<<" ";
                continue;
            }
            else if(isalpha(str[i]))
            {
                st1[j]=str[i];
                // cout<<st1[j];
                j++;
            }
            else if(isalnum(str[i]))
            {
                st2[k]=str[i];
                // cout<<st2[k];
                k++;
            }
        }
        // cout<<endl;
        for(int i=0;st1[i]!='\0';i++)
        {
            p->name[i]=st1[i];
            cout<<p->name[i];
        }
        cout<<" ";
        for(int o=0;o<9;o++)
        {
            p->id[o]=st2[o];
            cout<<p->id[o];
        }
        cout<<endl;
        struct Node *node = new struct Node;
        p->link=node;
        p=p->link;

    }
    struct Node* q=head;
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
    file.close();
}