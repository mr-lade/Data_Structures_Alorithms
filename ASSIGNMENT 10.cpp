#include<iostream>
using namespace std;
class sort{
	public:
	int s[10];
	void quicksort(int l , int r);
	int partition( int l , int r);
	void insertion_sort(int size); 
	int input();
	void display(int x);
};
void sort::quicksort( int l , int r)
{
	int i,x;
	if(l<r)
	{
		int p = partition( l,r);
		quicksort(l,p-1);
		quicksort(p+1,r);
		
	}
}
int sort::partition(int l,int r)
	{
		int i,j,temp;
		int p=s[l];
		i=l+1;
		j=r;
		while(i<j){
			while(s[i]<=p && i<j){
				i++;
			}
			while(s[j]>p){
				j--;
			}
		    if(i<j)
		    {
		    	temp=s[i];
		    	s[i]=s[j];
		    	s[j]=temp;
		    	p++;
			}
		}
		temp=s[l];
		s[l]=s[j];
		s[j]=temp;
		return j;
	}
void sort::insertion_sort(int size) 
{
   int key, j;
   for(int i = 1; i<size; i++) 
   {
      key = s[i];
      j = i;
      while(j > 0 && s[j-1]>key) 
	  {
        s[j] = s[j-1];
         j--;
      }
      s[j] = key;  
   }
}
int sort::input()
{
	int x,i;
	cout<<"Enter the number of years you want \n";
	cin>>x;
	for(i=0;i<x;i++){
		cin>>s[i];
	}
	return x;
}
void sort::display(int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		cout<<s[i]<<"\n";
	}
}
int main()
{
	sort s[10];
	int i,x,ch;
    x=s[i].input();
	cout<<"-----------unsorted array------------\n";
	s[i].display(x);
	cout<<"\n1. quick sort \n2. insertion sort \nEnter your choice \n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			s[i].quicksort(0,x-1);
			break;
		case 2:
			s[i].insertion_sort(x);
			break;
	}
	cout<<"-----------Sorted array--------------\n";
    s[i].display(x);
	return 0;
	
}
