#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class parity
{
	int i,j,counter=0;
	string s;
	int a[50];
	public:
	void insert();
	void search();
	
};
void parity::insert()
{
	cout<<"\n enter the string: \n";
	cin>>s;
}
void parity::search(){
	int n=s.length();
	for(i=0;i<n;i++)
	{
		int value=int(s[i]);
		j=0;
		while(value>0)
		{
			int p=value%2;
			a[j]=p;
			value/=2;
			j++;
		}
		reverse(a,a+j);
		for(int i=0;i<j;i++)
		{
			cout<< a[i];
			if(a[i]==1){
			    counter++ ;	
			}
		}
	}
	if(counter%2==0)
	{
		cout<<"\n EVEN PARITY\n";
			}
			else
			{
				cout<<"\n odd parity";
			}
}
int main(){
	cout<<"\n PROGRAM FOR PARITY CHECKER:\n";
	parity p ;
	p.insert();
	p.search();
}
