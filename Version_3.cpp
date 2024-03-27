#include<bits/stdc++.h>
using namespace std;

//Linked list for the data of the students
struct Node{
    char id[9];
    string name;
    string email;
    char interview_date[10];
    bool interview_status;
    char start_time[8];
    char end_time[8];
    string programe;
    int contact_no[10];
    int whatsapp_no[10];
    int alt_no[10];
    string skype_id;
    struct Node *link;
};

//print the data in all node
void traversel(struct Node* q)
{
    while(q->link!=NULL)
    {
        for(int j=0;q->name[j]!='\0';j++)
        {
            cout<<q->name[j];
        }
        cout<<" ";
        for(int j=0;q->interview_date[j]!='\0';j++)
        {
            cout<<q->interview_date[j];
        }
        cout<<" ";
        // for(int j=0;q->interview_status[j]!='\0';j++)
        // {
        //     cout<<q->interview_status[j];
        // }
        cout<< q->interview_status;
        cout<<" ";
        for(int j=0;q->start_time[j]!='\0';j++)
        {
            cout<<q->start_time[j];
        }
        cout<<" ";
        for(int j=0;q->end_time[j]!='\0';j++)
        {
            cout<<q->end_time[j];
        }
        cout<<" ";
        for(int j=0;j<9;j++)
        {
            cout<<q->id[j];
        }
        cout<<" ";
        for(int j=0;q->email[j]!='\0';j++)
        {
            cout<<q->email[j];
        }
        cout<<" ";
        for(int j=0;q->programe[j]!='\0';j++)
        {
            cout<<q->programe[j];
        }
        cout<<" ";
        for(int j=0;j<10;j++)
        {
            cout<<q->contact_no[j];
        }
        cout<<" ";
        for(int j=0;j<10;j++)
        {
            cout<<q->whatsapp_no[j];
        }
        cout<<" ";
        for(int j=0;j<10;j++)
        {
            cout<<q->alt_no[j];
        }
        cout<<" ";
        for(int j=0;q->skype_id[j]!='\0';j++)
        {
            cout<<q->skype_id[j];
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
        int j=0,k=0,l=0;
        string Name = "";
        string Email = "";
        char Interview_date[10];
        bool Interview_status;
        char Start_time[8];
        char End_time[8];
        string Programme = "";
        int Contact_no[10];
        int Whatsapp_no[10];
        int Alt_no[10];
        string Skype_id = ""; 
        string Id = "";

        getline(file,str);
        for(int i=1;i<str.length();i++)
        {
            if(str[i]==',')
            {
                l++;
                j=0;
            }
            else if(l==1)
            {
                Name[j]=str[i];
                j++;
            }
            else if(l==2){
                Interview_date[j]=str[i];
                j++;
            }
            else if(l==3){
                Interview_status = str[i];
                j++;
            }
            else if(l==4){
                Start_time[j]=str[i];
                j++;
            }
            else if(l==5){
                End_time[j]=str[i];
                j++;
            }
            else if(l==6){
                Id[j]=str[i];
                j++;
            }
            else if(l==7){
                Email[j]=str[i];
                j++;
            }
            else if(l==8){
                Programme[j]=str[i];
                j++;
            }
            else if(l==9){
                Contact_no[j]=str[i];
                j++;
            }
            else if(l==10){
                Whatsapp_no[j]=str[i];
                j++;
            }
            else if(l==11){
                Alt_no[j]=str[i];
                j++;
            }
            else if(l==12){
                Skype_id[j]=str[i];
                j++;
            }
        }

        for(int i=0;Name[i]!='\0';i++)
        {
            p->name[k]=Name[i];
            k++;
        }
        k=0;
        for(int i=0;i<10;i++)
        {
            p->interview_date[i]=Interview_date[i];  
            k++;
        }
        k=0;
        p->interview_status = Interview_status;
        for(int i=0;i<8;i++)
        {
            p->name[i]=Start_time[i];
            k++;  
        }
        k=0;
        for(int i=0;i<8;i++)
        {
            p->name[i]=End_time[i];
            k++;  
        }
        k=0;
        for(int i=0;i<9;i++)
        {
            p->id[i]=Id[i];
            k++;  
        }
        k=0;
        for(int i=0;Email[i]!='\0';i++)
        {
            p->email[i]=Email[i];
            k++;  
        }
        k=0;
        for(int i=0;Programme[i]!='\0';i++)
        {
            p->programe[i]=Programme[i];
            k++;  
        }
        k=0;
        for(int i=0;Contact_no[i]!='\0';i++)
        {
            p->contact_no[i]=Contact_no[i];
            k++;  
        }
        k++;
        for(int i=0;Whatsapp_no[i]!='\0';i++)
        {
            p->whatsapp_no[i]=Whatsapp_no[i];
            k++;  
        }
        k=0;
        for(int i=0;Alt_no[i]!='\0';i++)
        {
            p->alt_no[i]=Alt_no[i];
            k++;  
        }
        k=0;
        for(int i=0;Skype_id[i]!='\0';i++)
        {
            p->skype_id[i]=Skype_id[i];
            k++;  
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