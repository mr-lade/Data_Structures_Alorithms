#include<iostream>
using namespace std;
int inter2(int a[],int b[],int s1, int s2)
{
	int k,j,n=0;
	for(j=0;j<s1;j++)
	{
		for(k=0;k<s2;k++)
		{
			if(a[j]==b[k])
			{
				n++;
			}
		}
	}
	return n;
}
int inter3(int a[],int b[],int c[],int s1, int s2,int s3)
{
	int i,k,j,n=0;
	for(j=0;j<s1;j++)
	{
		for(k=0;k<s2;k++)
		{
			for(i=0;i<s3;i++)
			{
				if(a[j]==b[k] && a[j]==c[i] && b[k]==c[i])
			    {
				n++;
			    }
			}
		}
	}
	return n;
}
int main()
{
	int x,y,z;
	int total;
	cout<<"Enter the the size of the cricket team";
	cin>>x;
	int a[x];
	cout<<"Enter the roll no, enroll for crickect team";
	for(int i=0;i<x;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the the size of the kabadi team";
	cin>>y;
	int b[y];
	cout<<"Enter the roll no, enroll for kabadi team";
	for(int i=0;i<y;i++)
	{
		cin>>b[i];
	}
	cout<<"Enter the the size of the volleyball team";
	cin>>z;
	int c[z];
	cout<<"Enter the roll no, enroll for volleyball team";
	for(int i=0;i<z;i++)
	{
		cin>>c[i];
	}
	total=x+y+z-inter2(a,b,x,y)-inter2(a,c,x,z)-inter2(c,b,z,y)+inter3(a,b,c,x,y,z);
	cout<<"Total number of players among all sports is: "<<total;
	return 0;
}
