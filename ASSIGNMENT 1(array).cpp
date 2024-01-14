#include<iostream>
//#include<stdlib.h>	
using namespace std;
class laptop{
	public:
	string name;
	int model;
	string ram;
		laptop()
		{
			cout<<"Constructor call"<<endl;
	}
		void getdata(){
			cout<<"\nEnter  name: "<<endl;
			cin>>name;
			cout<<"Enter model no: "<<endl;
			cin>>model;
			cout<<"Enter ram: "<<endl;
			cin>>ram;
		}
		void display();
};
void laptop::display()
{
	
	cout<<name<<"\t"<<model<<"\t\t"<<ram<<"\t"<<endl;
}
int main()
{
	int n,ch,ch1,flag,id,i,j;
	laptop lap[20];
	do{
		cout<<"\n----------MENU-----------";
		cout<<"\n1.Accept\n2.Display\n3Insert\n4.Delete\n5>Update\n6.Search\n7.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
	
		switch(ch)
		{
			case 1: cout<<"Enter the no of laptops: ";
					cin>>n;
					for(int i=0;i<n;i++)
				{
					lap[i].getdata();
				}
				break;
			case 2:	cout<<"Student info:"<<endl;
					cout<<"\nName\t"<<"model\t"<<"\tram"<<endl;
					for(i=0;i<n;i++)
					{
						lap[i].display();
					}
					break;
			case 3: int pos;
					cout<<"Enter the position where you want to add laptop details";
					cin>>pos;
					for(int i=n-1;i>=pos-1;i--)
					{
						lap[i+1]=lap[i];
					}
					lap[pos-1].getdata();
					n++;
					break;
			case 4: cout<<"Enter the model no you want to delete";
					cin>>id;
					flag=0;
					for(i=0;i<n;i++)
					{
						if(lap[i].model==id)
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					cout<<"model no not found";
					else{
						for(int j=i;j<n-1;j++)
						{
							lap[j]=lap[j+1];
						}
						n--;
					}
					break;
			case 5: cout<<"Enter the model no to update";
					cin>>id;
					flag=0;
					for(i=0;i<n;i++)
					{
						if(lap[i].model==id)
						{
							flag=1;
							lap[i].getdata();
							break;
						}  
					}
					if(flag==0)
					cout<<"model not found";
					else
					cout<<"Modified ";
					break;
			case 6:	cout<<"Enter the model no to search";
					cin>>id;
					flag=0;
					for(i=0;i<n;i++)
					{
						if(lap[i].model==id)
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					cout<<"model no not found"<<endl;
					else
					cout<<"model no found at index: "<<i<<endl;
					break;
			case 7:exit(0);

			default: cout<<"Wrong choice";
		}
		cout<<"\nPress 1 to continue";
		cin>>ch1;
	}while(ch1==1);
	return 0;
}
