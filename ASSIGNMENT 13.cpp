#include<iostream>
#include<string.h>
using namespace std;
char temp[20];
void combination(char *str, int r,int index)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		temp[index]=str[i];
		if(r-1==index)
		{
			cout<<"\t"<<temp;
		}
		else
		{
			combination(str,r,index+1);
		}
	}
}
int main()
{
	char str[20];
	int r;
	cout<<"\n Enter the string to generate all the combination";
	cin>>str;
	for(r=1;r<=strlen(str);r++)
	    combination(str,r,0);
	    
	return (0);
}
