#include<iostream>
using namespace std;
class node{
  public:
  int roll;
  int cgpa;
  string name;
  node*next;
  node()
  {
  next=NULL;
 }
};
class linkedlist{
	node*head;
	public:
	linkedlist()
	{
		head=NULL;
	}
void create()
{
	node*temp=NULL;
	node*p=NULL;
	int ch=1;
	while(ch!=0)
	{
	if(head==NULL)
	{
		node*temp=new(node);
		cout<<"enter the roll no:";
		cin>>temp->roll;
		cout<<"enter the cgpa:";
		cin>>temp->cgpa;
		cout<<"enter the name:";
		cin>>temp->name;
		temp->next=head;
		head=temp;
		p=head;
	}
	else
	{
		node*temp=new(node);
		cout<<"\nenter the roll no:";
		cin>>temp->roll;
		cout<<"enter the cgpa:";
		cin>>temp->cgpa;
		cout<<"enter the name:";
cin>>temp->name;
temp->next=NULL;
p->next=temp;
p=temp;

}
cout<<"\n press to continue 1 or to exit 0\n";
cin>>ch;
}
}
void display()
{
node*v=NULL;
v=head;
if(head==NULL){
return;
}
else{
cout<<"\n student data is:";
while(v!=NULL)
{
cout<<"Rollno. :"<<v->roll<<" ";
cout<<"CGPA: "<<v->cgpa<<" ";
cout<<"Name: "<<v->name<<" ";
v=v->next;
}
}
cout<<"data  is empty";
}
void insert_begning()
{
node *temp=new(node);
cout<<"enter the roll";
cin>>temp->roll;
cout<<"enter the name";
cin>>temp->name;
cout<<"enter the cgpa";
cin>>temp->cgpa;
temp->next=head;
head=temp;
}
void insert_last()
{
node*p;
p=head;
node*temp=new(node);
cout<<"enter the roll";
cin>>temp->roll;
cout<<"enter the name";
cin>>temp->name;
cout<<"enter the cgpa";
cin>>temp->cgpa;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
}
void insert_inbetween()
{
int position;
node*temp=new(node);
node*p;
p=head;
cout<<"\nenter the position";
cin>>position;
for(int i=0;i<position-1;i++)
{
p=p->next;
}
cout<<"enter the roll";
cin>>temp->roll;
cout<<"enter the name";
cin>>temp->name;
cout<<"enter the cgpa";
cin>>temp->cgpa;
temp->next=p->next;
p->next=temp;
}
void  update()
{
node*temp=head;
int pos;
cout<<"\n enter the position to update";
cin>>pos;
for(int i=0;i<pos;i++)
{
temp=temp->next;
}
cout<<"enter the roll";
cin>>temp->roll;
cout<<"enter the name";
cin>>temp->name;
cout<<"enter the cgpa";
cin>>temp->cgpa;
}
void reverse()
{
   node *p=NULL;
   node*q=NULL;
   node*r=NULL;
   q=head;
   r=head->next;
   while(q!=NULL)
   {
       q->next=p;
       p=q;
       q=r;
       if(q!=NULL)
       {
           r=r->next;
       }
       head=p;
   }
}


void sort(){
 int swap;
 node *p,*q,*temp;
 temp = new node();
 q = head;
 while(q->next != NULL){
 p =head;
 swap = 0;
 while(p ->next != NULL){
 if(p -> roll > p ->next -> roll){
 temp->roll = p -> roll;
 p -> roll = p ->next -> roll;
 p ->next -> roll = temp -> roll;
 temp->name = p->name;
 p->name = p->next->name;
 p->next->name = temp->name;
 swap = 1;
 }
 p = p ->next;
 }
 if(swap == 1){
 break;
 }
 q = q -> next;
 }
 cout <<"\n\nSorted Succesfully"<<endl;
}


void search()
{
node*temp,*p;
int x,flag=0;
cout<<"enter the roll no to be searched";
cin>>x;
if(head==NULL)
{
cout<<"\nList is empty:";
return;
}
temp=new node();
p=head;
while(p!=NULL)
{
if(p-> roll ==x)
{
flag=1;
break;
}
p=p->next;
}
if(flag==1)
{
cout<<"student is present";
temp->next=p->next;
p->next=temp;
}
else{
cout<<"\nstudent is not found";
}
}
/*void delet()
{
if(head==NULL)
{
cout<<"\n list is empty";
return;
}
int r;
cout<<"\n enter the roll no u want to delete";
cin>>r;
node*p,*prev;
int flag=0;
p= head;
while(p!=NULL)
{
if(p->roll==r)
{
if(p=head)
{
head=head->next;
p->next=NULL;
delete(p);
}
else
{
prev->next=p->next;
p->next=NULL;
delete(p);

}
flag=1;

}
if(flag==0)
cout<<"\nroll no not found";
else{
cout<<"\n deleted suscessfully";
}*/
void delet()
{   int x,flag=0 ;
	cout<<"Enter the Roll no. you want to Delete";
	cin>>x;
	node *prev,*p;
	if(head==NULL)
	{
		cout<<"\n Linked list empty";
		return;
	}
	if( head->roll==x)
	{
		p=head;
		head=head->next;
		delete(p);
		return ;
	}
	p=head;
	while(p!=NULL)
	{
		if(p->roll==x)
		{
			flag=1;
			break;
		}
		prev=p;
		p=p->next;
	}
	if(flag==1)
	{
		prev->next=p->next;
		delete(p);
	}
	else
	{
		cout<<"Roll no. you want to delete is not present ";
	}
}

};
int main()
{
int ch,ch1;
linkedlist sll;
sll.create();
sll.display();
do{

cout<<"\n enter ur choice\n 1 insert\n 2 insert at last\n 3 insert in between\n 4 update\n 5reverse\n 6 sorting of roll no\n 7 search the student\n 8 delete ";
cin>>ch;
switch(ch)
{
case 1:
sll.insert_begning();
cout<<"\n new student data is";
sll.display();
break;
  case 2:
  sll.insert_last();
  cout<<"\nnew student data is";
  sll.display();
  break;
  case 3:
  sll.insert_inbetween();
  cout<<"\n new student data is";
  sll.display();
  break;
  case 4:
  sll.update();
  cout<<"\nupdated data is";
  sll.display();
  break;
  case 5:
  sll.reverse();
  cout<<"\nreverse data is";
  sll.display();
  break;
  case 6:
  sll.sort();
  cout<<"\n sorted roll no  is:";
  sll.display();
 break;
 case 7:
  sll.search();
 break;
 case 8:
 	sll.delet();
 	sll.display();
 
  break;
}
cout<<"\nPress 1 to continue";
cin>>ch1;
}while(ch1==1);
return 0;
}
