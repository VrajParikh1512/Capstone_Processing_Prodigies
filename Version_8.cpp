#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	string sr_no="";
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
	string Package = "";
	string Company = "";
	bool r1 = false;
	bool r2 = false;
	bool r3 = false;
	bool r4 = false;
	bool r5 = false;
	Node *link;
};

void traversel(Node* q)
{
	while(q != NULL)
	{
		cout << q->sr_no << " ";
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
		cout << q->Skype_id << " ";
		cout << q->Company << " ";
		cout << q->Package << " LPA ";
		cout << q->r1 << " ";
		cout << q->r2 << " ";
		cout << q->r3 << " ";
		cout << q->r4 << " ";
		cout << q->r5 << endl;
		q = q->link;
	}
}

void search_node_by_name(Node* q){
	int count=0;
    string temp;
    cout<<"Enter Name you want to search for :";
    getline(cin,temp);
    while(q!=NULL){
        if(q->Name==temp){
			count++;
        cout << q->sr_no << " ";
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
        cout << q->Skype_id << " ";
		cout << q->r1 << " ";
		cout << q->r2 << " ";
		cout << q->r3 << " ";
		cout << q->r4 << " ";
		cout << q->r5 << endl;
		q=q->link;
        }else{q=q->link;
        }
    }if(count == 0){
                cout<<"Name not found"<<endl;
            }

}

void search_node_by_ID(Node* q){
	int count=0;
    string temp;
    cout<<"Enter ID of student you want to search for :";
    getline(cin,temp);
    while(q!=NULL){
        if(q->Id==temp)
		{
		count++;
        cout << q->sr_no << " ";
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
        cout << q->Skype_id << " ";
		cout << q->r1 << " ";
		cout << q->r2 << " ";
		cout << q->r3 << " ";
		cout << q->r4 << " ";
		cout << q->r5 << endl;
        q=q->link;
        }
        else{q=q->link;
        }
    }
	if(count==0)
	{
        cout<<"Id not found"<<endl;
    }

}

void search_node_by_Company(Node* q){
	int count=0;
    string temp;
    cout<<"Enter company name you want to search for:";
    getline(cin,temp);
    while(q!=NULL){
        if(q->Company==temp)
		{
		count++;
        cout << q->sr_no << " ";
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
        cout << q->Skype_id << " ";
		cout << q->r1 << " ";
		cout << q->r2 << " ";
		cout << q->r3 << " ";
		cout << q->r4 << " ";
		cout << q->r5 << endl;
        q=q->link;
        }
        else{q=q->link;
        }
    }
	if(count==0)
	{
        cout<<"Company name not found"<<endl;
    }

}

struct Node* Store_data(Node* &head,const string &filename, Node* last)
{
	ifstream file;
	file.open(filename);

    if (!file) 
    {
    cout << "Unable to open file "<< filename << endl;
    return last;
    }

	//storing the round number
	bool round = true;
	string str1 = "";
  	getline(file,str1,',');

	string str;
	//get company name in string cmpy
	string cmpy;
	getline(file,str);
	getline(file,str);
	getline(file,str);
	stringstream getcmp(str);
	getline(getcmp,cmpy,',');
	while(cmpy[0]!='[')
	{
		getline(getcmp,cmpy,',');
	}

	// Skip lines until "Sr. No." is encountered
	string desiredString = "Sr. No.";
	while (getline(file, str)) 
	{
		if (str.find(desiredString) != string::npos)
		break;
	}

	//store the data of the student in the element of the node respectivelty
	while(getline(file, str))
	{
		Node* p = new Node;
		stringstream inputstring(str);
        string st;
	
		getline(inputstring, p->sr_no , ',');
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
		getline(inputstring, p->Package, ',');
        p->Company = cmpy.substr(1, cmpy.length() - 2);

    	if(str1 == "Interview Schedule - Round 1")
	    {
	    	p->r1 = true;
 	    }
    	else if(str1 == "Interview Schedule - Round 2")
	    {
		    p->r2 = true;
    	}
	    else if(str1 == "Interview Schedule - Round 3")
    	{
 	    	p->r3 = true; 
    	}
	    else if(str1 == "Interview Schedule - HR Round")
	    {
 		    p->r4 = true;
    	}
	    else if(str1 == "Interview Schedule - Final Selection")
	    {
		    p->r5 = true;
	    }

		p->link = nullptr;

		if (head == nullptr) {
            head = p;
        } else {
            last->link = p;
        }
        last = p; 
    }
    file.close();
    return last;
}

void freeList(Node* head) 
{
    while (head != nullptr) 
	{
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

int main()
{
	struct Node *head = nullptr;
	struct Node *last = nullptr;
	last = Store_data(head,"data1.csv",last);
	last = Store_data(head,"data2.csv",last);
	last = Store_data(head,"data3.csv",last);
	last = Store_data(head,"data4.csv",last);
	last = Store_data(head,"data5.csv",last);
	last = Store_data(head,"data6.csv",last);
	last = Store_data(head,"data7.csv",last);
	last = Store_data(head,"data8.csv",last);
	last = Store_data(head,"data9.csv",last);
	last = Store_data(head,"data10.csv",last);
	// traversel(head);

	while(1)
	{
		cout<<"Select the operation you want to perform:"<<endl;
		cout<<"1. Search a student placement data using 'Student name'."<<endl;
		cout<<"2. Search a student placement data using 'Student ID'."<<endl;
		cout<<"3. Search students placement data using 'Company name'."<<endl;
		cout<<"4. Sort the data of students according to their 'Student ID'."<<endl;
		cout<<"5. Sort the data of students according to the 'package'"<<endl;
		cout<<"6. Exit/Donot want to perform any operation"<<endl;
        
		int n;
		cout<<endl<<"Enter the number of operation which you want to perform: ";
		cin>>n; 

		switch(n)
		{
			case 1:
			cin.ignore();
			search_node_by_name(head);
			break;
	
			case 2:
			cin.ignore();
			search_node_by_ID(head);
			break;

			case 3:
			cin.ignore();
			search_node_by_Company(head);
			break;
	
			case 4:
			//sort using id
			cout<<"Inside 4\n";
			break;
	
			case 5:
			//sort using the package
			cout<<"Inside 5\n";
			break;

			case 6:
			//exit the code
			cout<<"Inside 6\n";
			exit(1);

			default:
			//select from 1-6;
			break;
		}
	}

	freeList(head);
	return 0;
}