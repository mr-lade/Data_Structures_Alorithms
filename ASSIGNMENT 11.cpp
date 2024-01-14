#include <iostream>
#include<math.h>

using namespace std;


class SearchElement
{
    public:
    void sentinalSearch(int Marks[], int n, int key);
    int BinarySearch(int Marks[], int low, int high, int key);
    int FibonacciSearch(int Marks[], int n, int key);
};

void SearchElement::sentinalSearch(int Marks[], int n, int key)
{
    int last=Marks[n-1];
    Marks[n-1]=key;
    int i=0;
    while(Marks[i]!=key)
    {
        i++;
    } 
    Marks[n-1]=last; 
    if(i<n-1 || Marks[n-1]==key)
    {
        cout<<key<<" is fount at index "<<i<<endl;
    }
    else
    {
        cout<<"\n"<<key<<" is Not present in the marklist\n";
    }
}

int SearchElement::BinarySearch(int Marks[], int l, int h, int key)
{
    if(h>=l)
    {
        int mid=(l+h)/2;
        if(Marks[mid]==key)
        {
            return mid;
        }
        else if(Marks[mid]>key)
        {
            return BinarySearch(Marks, l, mid-1,key);
        }
        else if(Marks[mid]<key)
        {
            return BinarySearch(Marks,mid+1,h,key);
        }
    }
    
    return -1;
}


int SearchElement::FibonacciSearch(int Marks[], int n, int key)
{
    int fb_prev1=1,fb_prev2=0;
    int fb_curr=fb_prev1+fb_prev2;
    int offset=-1;
    while(fb_curr<n)
    {
        fb_prev2=fb_prev1;
        fb_prev1=fb_curr;
        fb_curr=fb_prev1+fb_prev2;
    }
    
    while(fb_curr>1)
    {
        int i=min(offset+fb_prev2, n-1);
        if(Marks[i]<key)
        {
            fb_curr=fb_prev1;
            fb_prev1=fb_prev2;
            fb_prev2=fb_curr- fb_prev1;
            offset=i;
        }
        
        else if(Marks[i]>key)
        {
            fb_curr=fb_prev2;
            fb_prev1 = fb_prev1- fb_prev2;
            fb_prev2 = fb_curr - fb_prev1;
        }
        else
        {
            return i;
        }
        
    }
    if (fb_prev1 && Marks[offset +1] == key)
        return (offset + 1);
    return -1;
}

int main()
{
    int Marks[100],n,key,ch,ch1;
    SearchElement s1;
    cout<<"\nEnter number of students in a division : ";
	cin>>n;
	cout<<"Enter their Marks\n";
	for(int i=0;i<n;i++)
	{
	    cin>>Marks[i];
	}
	cout<<"Entered marks are :\n";
	for(int i=0;i<n;i++)
	{
	    cout<<Marks[i]<<endl;
	}
	do
	{
	    cout<<"Enter the marks of student that needs to be search : ";
	    cin>>key;
    	cout<<"\n1:Sentinal Search\n2:Binary Search\n3:Fibonacci Search";
    	cout<<"\nEnter your choice : ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			s1.sentinalSearch(Marks,n,key);
    			break;
    		case 2:
        		{
    				int val=s1.BinarySearch(Marks,0,n-1,key);
    				if(val>-1)
    					cout<<"\n"<<key<<" Entered marks found at index "<<val<<endl;
    				else
    					cout<<"\n"<<key<<" we could not find the marks in the marklist\n";	
        		}		
				break;
			case 3:
    			{
    				int val=s1.FibonacciSearch(Marks, n,key);	
    				if(val>-1)
    					cout<<"\n"<<key<<"  Entered marks found at index "<<val<<endl;
    				else
    					cout<<"\n"<<key<<" we could not find the marks in the marklist\n";	
    			}		
				break;		
		}
		cout<<"Press 1 to continue : ";
    	cin>>ch1;
	}while(ch1==1);
    return 0;
}

