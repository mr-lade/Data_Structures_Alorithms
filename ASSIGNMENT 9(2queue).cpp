#include<iostream>
#include<stdlib.h>
#define SIZE 5

using namespace std;
class customer
{
	public:
	int cid;
	string cname;
};
class booking
{
	customer arr[SIZE];
	int front,rear;
	public:
		booking()
		{
			front=-1;
			rear=-1;
		}
		void insertatfront(int, string);
		void insertatrear(int,string);
		void deleteatfront();
		void deleteatend();
		void get_front();
		void get_rear();
		bool isFull();
		bool isEmpty();
		void display();
};
void booking::insertatfront(int id,string name)
{
	if(isFull())
	{
		cout<<"\nWaiting queue is full";
	}
	else
	{
		if(isEmpty())
		{
			front=rear=0;
		}
		else
		{
			front=(SIZE +(front-1))%SIZE;
		}
		arr[front].cid=id;
		arr[front].cname=name;
	}
}

void booking::insertatrear(int id,string name)
{
	if(isFull())
	{
		cout<<"\n Waiting Queue full";
	}
	else
	{
		if(isEmpty())
		{
			front=rear=0;
		}
		else
		{
			rear=(rear+1)%SIZE;
		}
		arr[rear].cid=id;
		arr[rear].cname=name;
	}
}
void booking::deleteatfront()
{
	if(isEmpty())
	{
		cout<<"No customer is waiting";
	}
	else
	{
		cout<<"\n Booking done for"<<arr[front].cid<<":"<<arr[front].cname;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%SIZE;
		}
	}
}
void booking::deleteatend()
{
	if(isEmpty())
	{
		cout<<"\n Customer waiting in queue";
	}
	else
	{
		cout<<"\n Bookikng done for"<<arr[rear].cid<<":"<<arr[rear].cname;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			rear=(SIZE+(rear-1))%SIZE;
		}
	}
}
bool booking :: isEmpty()
{
	if(front==-1&&rear==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool booking::isFull()
{
	if(front==(rear+1)%SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void booking :: get_front()
{
	if(isEmpty())
	{
		cout<<"\n no customer waiting in queue";
	}
	else
	{
		cout<<"\n"<<arr[front].cid<<" "<<arr[front].cname;
	}
}
void booking :: get_rear()
{
	if(isEmpty())
	{
		cout<<"\n no customer waiting in queue";
	}
	else
	{
		cout<<"\n"<<arr[rear].cid<<" "<<arr[rear].cname;
	}
}
void booking::display()
{
	int i;
	if(!isEmpty())
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				cout<<"\n"<<arr[i].cid<<":"<<arr[i].cname;
			}
		}
		else
		{
			for(i=front;i<SIZE;i++)
			{
				cout<<"\n"<<arr[i].cid<<":"<<arr[i].cname;
			}
			for(i=0;i<=rear;i++)
			{
				cout<<"\n"<<arr[i].cid<<":"<<arr[i].cname;			
			}
		}
	}
	else
	{
		cout<<"\n No customer waitingfor booking";
	}
}

int main()
{
	booking b;
	int ch,ch1,id;
	string name;
	do{
		cout<<"\n1. Insert at Rear \n2. Insert at front \n3. delete at rear \n4. delete at front \n5. get front \n6. get rear";
		cout<<"\n7. Display \n Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\n Enter the id & Name for booking";
			       cin>>id>>name;
			       b.insertatrear(id,name);
			       break;
		    case 2:
		    	cout<<"\n Enter the id & Name for booking";
			    cin>>id>>name;
			    b.insertatfront(id,name);
			    break;
			
			case 3:
				b.deleteatend();
				break;
		
			case 4:
				b.deleteatfront();
		     	break;
			case 5:
				b.get_front();
		    		break;
			case 6:
				b.get_rear();
		    	break;
			case 7:
				b.display();
				break;
		}cout<<"press 1 to continue";
		cin>>ch1;
	}while(ch1=1);
	return 0;
}
