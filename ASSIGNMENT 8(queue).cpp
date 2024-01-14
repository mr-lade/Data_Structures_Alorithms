#include<iostream>
using namespace std;
#define SIZE 10
class food
{
	public:
		int cid;
		string name;
};
class node
{
	public:
	int pid;
	string pname;
	node *next;
	node()
	{
		next=NULL;
	}
};
class queue
{
	food c[SIZE];
	int front,rear;
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		bool isempty()
		{
			if(front==-1 && rear==-1)
            	return true;
			else
				return false;
		}
		bool isfull()
		{
			if(rear==SIZE-1)
			    return true;
			else
				return false;
		}
		void enque (int id,string cname);
		void dequeue();
        void display();
};
class Queue
 {
    public:
 		node *front,*rear;
 		Queue()
 		{
 			front=NULL;
 			rear=NULL;
		 }
		bool isEmpty()
	    {
		 	if(front==NULL && rear==NULL)
		 	{
		 		return true;
		    }
			else
			{
			 	return false;
			}
     	}
		void enqueue(int id,string name);
		void dequeue();
		void display();
	
 };
 class booking
{
	node *front,*rear;
	public:
		booking()
		{
			front=NULL;
			rear=NULL;
		}
		bool isEmpty()
		{
			if(front==NULL && rear==NULL)
			    return true;
			else
			    return false;
				    
		}
		void enqueue(int id,string name);
		void denqueue();
		void display();
};
class Booking{
	food c[SIZE];
	public:
	    int f,r;
	    Booking()
	    {
		    f=-1;
		    r=-1;
	    }
	    bool isEmpty()
	    {
		    if(f==-1 && r==-1)
		        return true;
	        else 
		        return false;   
	    }
	    bool isFull()
	    {
		    if((r+1)%SIZE==f)
		        return true;
		    else
		        return false;   
	    }
	    void enqueue(int id, string cname);
	    void dequeue();
	    void display();
};
void queue::enque(int id, string cname)
{
	if(!isfull())
	{
		if(isempty())
		{
			front++;
		}
		rear++;
		c[rear].cid=id;
		c[rear].name=cname;
		}
	else
		cout<<"\nwait till previous orders are finished";
}
void queue::dequeue()
{
	if(!isempty())
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			cout<<"order of "<<c[front].cid<<":"<<c[front].name<<" is completed";
			front++;
		}
	}cout<<"\n";
}
void queue::display()
{
	if(!isempty())
    {
    	cout<<"\nOrder-ID  \t\tName";
		for(int i=front;i<=rear;i++)
	    {
	    	cout<<"\n"<<c[i].cid<<"\t\t"<<c[i].name;
		}
		}
	else 
	{
		cout<<"No orders to show."<<endl;
	}cout<<"\n";
}

 void Queue::enqueue(int id, string name)
 {
	node *temp;
	temp=new node();
	cout<<"Enter the ORDER-id and the name of the customer\n";
	temp->pid=id;
	temp->pname=name;
	cin>>temp->pid>>temp->pname;
	if(isEmpty())
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
void Queue::dequeue()
{
	node *p,*temp;
	if(!isEmpty())
	{
		cout<<"\nOrder is done for"<<front->pid<<" :"<<front->pname;
		if(front==rear){
		 	temp=front;
		 	delete(temp);
		 	front=NULL;
		 	rear=NULL;
		}
		else{
			temp=front;
			front=front->next;
			delete(temp);
		}
	}
	else{
		cout<<"no Orders is pending";
	}cout<<"\n";
}
void Queue::display()
{
	node *p;
	if(!isEmpty())
	{
		p=front;
		cout<<"\nOrder-ID  \t\tName";
		while(p!=NULL)
		{
			cout<<"\n "<<p->pid<<"\t\t"<<p->pname;
			p=p->next;
		}
	}
	else
	{
		cout<<"no Orders to display";
	}cout<<"\n";
}
void booking::enqueue(int id,string name)
{
	node *temp;
	temp=new node();
	temp->pid=id;
	temp->pname=name;
	cout<<"Enter customer name and ORDER no. :  ";
	cin>>temp->pname>>temp->pid;
	temp->next=temp;
	if(isEmpty())
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=rear->next;
		rear->next=front;
	}
}
void booking::denqueue()
{
	if(!isEmpty())
	{
		node *temp;
		if(front==rear)
		{
			cout<<"\n ORDER done for "<<front->pid<<":"<<front->pname;
			temp=front;
			front=NULL;
			rear=NULL;
			delete (temp);
		}
		else
		{
			temp=front;
			front=front->next;
			rear->next=front;
			delete(temp);
		}
	}
	else
		 cout<<"\n no Orders is pending ";		
}
void booking::display()
{
	if(!isEmpty())
	{
		cout<<"\n customer waiting for ORDER are as follows";
		node *p;
		p=front;
		cout<<"\nOrder-ID  \t\tName";
		do
		{
    		cout<<"\n "<<p->pid<<"\t\t"<<p->pname;
    		p=p->next;
		}while(p!=front);
	}
	else
		cout<<"\n No customer waiting for order";
}
void Booking::enqueue(int id, string cname)
{
    if(!isFull())
	{
		if(isEmpty())
			f=0;
			r=(r+1)%SIZE;  
			c[r].cid=id;
			c[r].name=cname; 
	}
	else
		cout<<"\n wait till previous order get completed "<<endl;
}
void Booking::dequeue()
{
	if(!isEmpty())
	{
		if(f==r)
	    {
		   	cout<<"\n Order DONE FOR "<<c[f].cid<<":"<<c[f].name;
		    f=-1;
		   	r=-1;
		}
		else
		{
		   	cout<<"\n Order DONE FOR "<<c[f].cid<<":"<<c[f].name;
		   	f=(f+1)%SIZE;
		}
	}
	else
		cout<<"\n no customer is waiting for order "<<endl;
}
void Booking::display()
{  
	int i; 
	if(!isEmpty())
	{
		cout<<"\n People Waiting for order "<<endl;
		cout<<"\nORDER-ID \t\tName";
		if(r>=f)
		{
		    for(int i=f;i<=r;i++)
			cout<<"\n"<<c[i].cid<<"\t\t"<<c[i].name;
		}
		else
		{
		    for(i=f;i<SIZE;i++)
		    	cout<<c[i].cid<<"\t\t"<<c[i].name;
		    for(i=0;i<=r;i++)
				cout<<c[i].cid<<"\t\t"<<c[i].name;    
		}
	}
	else
		cout<<"\n No people waiting for order ";
}
int main()
{
	queue q1;
	Queue q2;
	booking q3;
	Booking q4;
	int ch,ch1,id;
	string name;
	do
	{
	    cout<<"\n1. array \n2. linked list \n3. circular queue linked list \n4. circular queue using array";
	    cout<<"\nEnter your choice";
	    cin>>ch;
	    switch(ch)
	    {
		    case 1:
			    do
	            {
				    cout<<"\n1. Enqueue \n2. Dequeue \n3. Display";
	                cout<<"\nEnter your choice";
	                cin>>ch;
	                switch(ch)
	                {
		                case 1:
			                cout<<"Enter the ORDER-ID & name\n";
			                cin>>id>>name;
			                q1.enque(id, name);
                        break;
		                case 2:
			                q1.dequeue();
			            break;
		                case 3:
		                    q1.display();
			            break;	
	                }cout<<"Press 1 to continue\n";
	                cin>>ch1;
               }while(ch1==1);
		    break;
		    case 2:
				do
	            {
	                cout<<"\n1. Enqueue \n2. Dequeue \n3. Display";
	                cout<<"\nEnter your choice";
	                cin>>ch;
                    switch(ch)
                 	{
                		case 1:
                			q2.enqueue(id, name);
                		break;
                		case 2:
                			q2.dequeue();
            			break;
                		case 3:
                		    q2.display();	
                	}cout<<"Press 1 to continue\n";
                	cin>>ch1;
               }while(ch1==1);
			break;
			case 3:
				do
	            {
	                cout<<"\n1. Enqueue \n2. Dequeue \n3. Display";
	                cout<<"\nEnter your choice";
	                cin>>ch;
                    switch(ch)
                 	{
                		case 1:
                			q3.enqueue(id, name);
                		break;
                		case 2:
                			q3.denqueue();
            			break;
                		case 3:
                		    q3.display();	
                	}cout<<"Press 1 to continue\n";
                	cin>>ch1;
               }while(ch1==1);
			break;
			case 4:
				do
	            {
				    cout<<"\n1. Enqueue \n2. Dequeue \n3. Display";
	                cout<<"\nEnter your choice";
	                cin>>ch;
	                switch(ch)
	                {
		                case 1:
			                cout<<"Enter the Order id & name\n";
			                cin>>id>>name;
			                q4.enqueue(id, name);
                        break;
		                case 2:
			                q4.dequeue();
			            break;
		                case 3:
		                    q4.display();
			            break;	
	                }cout<<"Press 1 to continue\n";
	                cin>>ch1;
               }while(ch1==1);
		    break;
	   }cout<<"\nPress 1 to continue\n";
	    cin>>ch1;
    }while(ch1==1);
	return 0;
}
