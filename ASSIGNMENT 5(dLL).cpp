#include<iostream>
using namespace std;
class node
{
	public:
		int rollno;
		int marks;
		node *next,*prev;
		node()
		{
			next=NULL;
			prev=NULL;
		}
};
class marklist
{
	node *head;
	public:
		marklist()
		{
			head=NULL;
		}
		int create();
		void display();
		void sort(int n);
		void merge(marklist p1,marklist p2);
		
};

int marklist::create()
{
	node *p,*temp;
	int ch,n=0;
	do
	{
		temp=new node();
		cout<<"\nEnter the the roll no:\n";
		cin>>temp->rollno;
		cout<<"Enter the marks of the students\n";
		cin>>temp->marks;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;
		}
		n++;
		cout<<"Press 1 to add more\n";
		cin>>ch;
	}while(ch==1);
	return n;
	
}

void marklist::display()
{
	node *p;
	if(head==NULL)
	{
		cout<<"No students to display";
	}
	else
	{
		p=head;
		cout<<"---------------student marks---------------";
		cout<<"\nRoll no."<<"\t marks";
		while(p!=NULL)
		{
			cout<<"\n"<<p->rollno<<"\t\t"<<p->marks;
			p=p->next;
		}
	}
}

void marklist::sort(int n)
{
	node *q,*ptr1,*ptr2,*temp;
	int i;
	for(i=1;i<n;i++)
	{
		q=head;
		while(q->next!=NULL)
		{
			if(q->marks<q->next->marks)
			{
				ptr1=q;
				ptr2=q->next;
				temp=ptr2->next;
				if(ptr1->prev!=NULL)
				{
					ptr1->prev->next=ptr2;
				}
			    else
			    {
			    	head=ptr2;
				}
			    ptr2->next=ptr1;
			    ptr2->prev=ptr1->prev;
			    ptr1->next=temp;
			    ptr1->prev=ptr2;
			    if(temp!=NULL)
			    {
			        temp->prev=ptr1;
				}
				q=ptr2;
			}
			q=q->next;
		}
	}
}

void marklist::merge(marklist p1,marklist p2)
{
	node *p,*q,*r;
	p=p1.head;
    q=p2.head;
	if(p1.head==NULL && p2.head==NULL)
	{
		return;
	}
	else if(p1.head==NULL)
	{
		head==p2.head;
		return;
	}
	else if(p2.head==NULL)
	{
		head==p1.head;
		return;
	}
	else
	{
    	if(p->marks>=q->marks)
    	{
    		head=p;
    		p=p->next;
		}
		else
		{
			head=q;
			q=q->next;
		}
		r=head;
		{
			while(p!=NULL && q!=NULL)
			{
				if(p->marks>=q->marks)
				{
					r->next=p;
					p->prev=r;
					p=p->next;
					r=r->next;
				}
				else
				{
					r->next=q;
					q->prev=r;
					q=q->next;
					r=r->next;
				}
			}
			if(p==NULL)
			{
				r->next=q;
				q->prev=r;
			}
			if(q==NULL)
			{
				r->next=p;
				p->prev=r;
			}
	}
	}
	
}

int main()
{
	marklist p1,p2,p3;
	int n1,n2;
	n1=p1.create();
	cout<<"1st list of marks\n";
	p1.display();
	p1.sort(n1);
	cout<<"\nSorted marks of 1st list\n";
	p1.display();
	cout<<"\nENTER THE DETAILS OF SECOND LIST";
	n2=p2.create();
	cout<<"\n2nd list of marks\n";
	p2.display();
	p2.sort(n2);
	cout<<"\nSorted marks of 2nd list\n";
	p2.display();
	cout<<"\nMerged list\n";
    p3.merge(p1,p2);
    p3.display();
	return 0;
}
