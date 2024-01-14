#include<iostream>
using namespace std;
class loan{
	public:
		float p,i,n,e;
		float t;
		int a[10];
		void get_data();
		float calculation();
};

void loan::get_data()
{
	cout<<"Enter the principle amount:";
	cin>>p;
	cout<<"Enter the rate of intrest(in%) : ";
	cin>>i;
	cout<<"enter the time duration in years :";
	cin>>n;
	cout<<"Enter the Emi amount : ";
	cin>>e;
}

float loan::calculation()
{
	for(int s=1;s<=n;s++)
	{
		if(n>0){
			a[0]=p;
			a[s]=a[s-1]*(1+(i/100))-(e*12);
			cout<<"Amount to be give in "<<s<<" year is : "<<a[s]<<"\n";
		}
	}
	return 1;
}

int main()
{
	loan l;
	int ch,ch1,ch2;
	do {
		cout<<"Which type of loan do you wanna find";
		cout<<"\n------------------------------------------------------\n";
		cout<<"\n1. Educational loan \n2. Housing loan \n3. Car loan \n4. Property loan \n5. Personal loan";
		cout<<"\n------------------------------------------------------\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				l.get_data();
				l.calculation();
				break;
			case 2:
				l.get_data();
				l.calculation();
				break;
			case 3:
				l.get_data();
				l.calculation();
				break;
			case 4:
				l.get_data();
				l.calculation();
				break;
			case 5:
				l.get_data();
				l.calculation();
				break;
		}
		cout<<"\n Press 1 to continue";
		cin>>ch;
	}while(ch==1);
	return 0;
}
