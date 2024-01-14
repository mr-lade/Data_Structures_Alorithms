#include<iostream>
using namespace std;
class node
{
public:
int exp;
int coeff;
node *next;
node()
{
next=NULL;
}
};

class poly
{
node *head;
public:
poly()
{
head=NULL;
}
void create();
void display();
void sorted_insert(node *temp);
void addition(poly p1,poly p2);
void multiply(poly p1,poly p2);
};

void poly :: create()
{
node *temp;
int ch;
do
{
temp=new node();
cout<<"\n Enter the  exponent";
cin>>temp->exp;
cout<<"\n Enter the  coefficient";
cin>>temp->coeff;
temp->next=temp;
sorted_insert(temp);
cout<<"\n Press 1 to add more term in the polynomial or else press 0";
cin>>ch;
}
while(ch==1);
}

void poly::sorted_insert(node *temp)
{
node *p,*prev;
if(head==NULL)
{
head=temp;
}
else
{
if(temp->exp>head->exp)
{
p=head;
while(p->next!=head)
p=p->next;
p->next=temp;
temp->next=head;
head=temp;
}
else
{
p=head;
while(1)
{
if(p->exp==temp->exp)
{
p->coeff=p->coeff+temp->coeff;
delete(temp);
break;
}
else if(p->exp<temp->exp || p->next==head)
{
if(p->exp<temp->exp)
{
prev->next=temp;
temp->next=p;
break;
}
else
{
temp->next=p->next;
p->next=temp;
break;
}
}
else
{
prev=p;
p=p->next;
}
}
}
}

}

void poly::display()
{
node *p;
cout<<"\n";
if(head==NULL)
cout<<"\n Polynomial is Empty";
else
{
p=head;
do
{
if(p->next!=p)
cout<<p->coeff<<" X ^"<<p->exp<<"+";
p=p->next;
}while(p->next!=head);
cout<<p->coeff<<" X ^"<<p->exp<<"=0";
}
}

void poly::addition(poly p1,poly p2)
{
if(p1.head==NULL && p2.head==NULL)
{
return;
}
node *p,*temp;
p=p1.head;
do
{
temp=new node();
temp->exp=p->exp;
temp->coeff=p->coeff;
temp->next=temp;
sorted_insert(temp);
p=p->next;
}while(p!=p1.head);
p=p2.head;
do
{
temp=new node();
temp->exp=p->exp;
temp->coeff=p->coeff;
temp->next=temp;
sorted_insert(temp);
p=p->next;
}while(p!=p2.head);
}

void poly:: multiply(poly p1,poly p2)
{
if(p1.head==NULL && p2.head==NULL)
{
return;
}
node *r,*s,*temp;
r=p1.head;
do
{
s=p2.head;
do
{
temp=new node();
temp->exp=r->exp+s->exp;
temp->coeff=r->coeff*s->coeff;
temp->next=temp;
sorted_insert(temp);
s=s->next;
}while(s!=p2.head);

r=r->next;
}while(r!=p1.head);

}
int main()
{
poly p1,p2,p3,p4;
p1.create();
p1.display();
p2.create();
p2.display();
cout<<"\n Addition of two polynomial is";
p3.addition(p1,p2);
p3.display();
cout<<"\n Multiplication of two polynomial is";
p4.multiply(p1,p2);
p4.display();
};

