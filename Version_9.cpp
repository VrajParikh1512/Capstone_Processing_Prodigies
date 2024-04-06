void acceptance_rate(Node* head)
{
    Node* p = head;
    string str;
    cout << "Enter the name of the company: ";
	getline(cin,str);
	cout<<str;
    double R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    while (p != nullptr)
    {
		if(str == p->Company)
		{
			if(p->r1)
			R1++;

			if(p->r2)
			R2++;

			if(p->r3)
			R3++;

			if(p->r4)
			R4++;

			if(p->r5)
			R5++;
		}
        p = p->link;
    }

	cout<<R1<<R2<<R3<<R4<<R5<<endl;
    double ar2,ar3,ar4,ar5;
	ar2 = (R2/R1)*100;
	cout<<"Net acceptance rate in Round 2: "<<ar2<<endl;
	ar3 = (R3/R1)*100;
	cout<<"Net acceptance rate in Round 3: "<<ar3<<endl;
	ar4 = (R4/R1)*100;
	cout<<"Net acceptance rate in Round 4: "<<ar4<<endl;
	ar5 = (R5/R1)*100;
	cout<<"Net acceptance rate in Round 5: "<<ar5<<endl;
}

void advice(Node *q)
{
	if(q->ar2>=70)
	{
		cout<<"The candidate has a good chance of qualifying Round 2 of"<<q->Company<<"with basic preparation. "
	}
	if(q->ar2<70 && q->ar2>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying Round 2 of"<<q->Company<<" and should focus more on Round 2. "
	}
	if(q->ar2<40 && q->ar2>=10)
	{
		cout<<"The candidate should focus and prepare for this round very diligently as Round 2 of"<<q->Company<<" is tough and if the candidate is able to clear this round,he will be very close to selection. "
	}
	if(q->ar3>=70)
	{
		cout<<"The candidate has a good chance of qualifying Round 3 of"<<q->Company<<"with basic preparation. "
	}
	if(q->ar3<70 && q->ar3>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying Round 3 of"<<q->Company<<" and should focus more on Round 3. "
	}
	if(q->ar3<40 && q->ar3>=10)
	{
		cout<<"The candidate should focus and prepare for this round very diligently as Round 3 of"<<q->Company<<" is tough and if the candidate is able to clear this round,he will be very close to selection. "
	}
	if(q->ar4>=70)
	{
		cout<<"The candidate has a good chance of qualifying HR Round of"<<q->Company<<"with basic preparation. "
	}
	if(q->ar4<70 && q->ar4>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying HR Round of"<<q->Company<<" and should focus more on his communication skills. "
	}
	if(q->ar4<40 && q->ar4>=10)
	{
		cout<<"The candidate must focus on building his overall personality and enhance his communication skill as"<<q->Company<<"   lais much emphasis on the HR Round. "
	}
	if(q->ar5>=70)
	{
		cout<<"The candidate has a good chance of qualifying Final Round of"<<q->Company<<"with basic preparation. "
	}
	if(q->ar5<70 && q->ar5>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying Final Round of"<<q->Company<<" and should focus more on Final Round. "
	}
	if(q->ar5<40 && q->ar5>=10)
	{
		cout<<"The candidate should focus and prepare for this round very diligently as Final Round of"<<q->Company<<" is tough and if the candidate is able to clear this round,he will be very close to selection. "
	}
}