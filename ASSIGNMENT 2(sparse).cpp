#include<iostream>
using namespace std;
class sprase{
	int arr[10][10];
	int sp[20][3];
	int row;		
	int col;
	int n;
	public:
		
		sprase()
		{
			n=0;
		}
		void accept()
		{
			int i,j;
			cout<<"Enter the no. of rows & column";
			cin>>row>>col;
			cout<<"enter the elements";
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					cin>>arr[i][j];
				}
			 } 
		}
		void convert();
		void display();
		sprase add(sprase s2);
		sprase transpose();
		sprase multiply(sprase s2);
};

void sprase::convert()
{
	int i,j,k=1;
	sp[0][0]=row;
	sp[0][1]=col;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(arr[i][j]!=0)
			{
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=arr[i][j];
				n++;
				k++;
			}
		}
	}sp[0][2]=k-1;
}  
sprase sprase::add(sprase s2){
      sprase s3;
      s3.sp[0][0] = row;
      s3.sp[0][1] = col;
	  if(row != s2.row || col != s2.col){
          cout<<"row or column are not same!!\n";
           return s3;
    }
    else{
      int i=1,j=1,k=1;
      while (i<=n && j<=s2.n)
      {
          if(sp[i][0]==s2.sp[j][0] && sp[i][1] == s2.sp[j][1]){
              s3.sp[k][0] = sp[i][0];
              s3.sp[k][1] = sp[i][1];
              s3.sp[k][2] = sp[i][2] + s2.sp[j][2];
              i++;
              j++;
              k++;

          }
          else if(sp[i][0] == s2.sp[j][0]){
              if(sp[i][1] < s2.sp[j][1]){
                  s3.sp[k][0] = sp[i][0];
                  s3.sp[k][1] = sp[i][1];
                  s3.sp[k][2] = sp[i][2];
                  i++;
                  k++;
              }else{
                  s3.sp[k][0] = s2.sp[j][0];
                  s3.sp[k][1] = s2.sp[j][1];
                  s3.sp[k][2] = s2.sp[j][2];
                  j++;
                  k++;
              }
          }
          else{
		  		if(sp[i][0]<s2.sp[j][0]){
                  s3.sp[k][0] = sp[i][0];
                  s3.sp[k][1] = sp[i][1];
                  s3.sp[k][2] = sp[i][2];
                  i++;
                  k++;
              }
              else{
                  s3.sp[k][0] = s2.sp[j][0];
                  s3.sp[k][1] = s2.sp[j][1];
                  s3.sp[k][2] = s2.sp[j][2];
                  j++;
                  k++;
              }
          }
      }
          
          while(i<=n){
              s3.sp[k][0] = s2.sp[i][0];
			  s3.sp[k][1] = s2.sp[i][1];
			  s3.sp[k][2] = s2.sp[i][2];
			  i++;
              k++;
          }
          while(j<=s2.n){
          	s3.sp[k][0] = s2.sp[j][0];
            s3.sp[k][1] = s2.sp[j][1];
            s3.sp[k][2] = s2.sp[j][2];
		  	j++;
		  	k++;
		  }
          s3.sp[0][2] = k-1;
          s3.n = k-1;
          cout<<"Addition of two sparse matrix is:--> \n";
      return s3;
}
}
   
sprase sprase::multiply(sprase s2)
{
	sprase s5;
	int t1=1,t2=1,t3=1,sum=0,i,j;
	if(sp[0][1]!=s2.sp[0][0])
	{
		cout<<"\nCannot multiply";
		return s5;
	}
	s5.sp[0][0]=sp[0][0];
	s5.sp[0][1]=s2.sp[0][1];
	
	s2=s2.transpose();
	
	for(i=0;i<sp[0][0];i++)
	{
		for(j=0;j<s2.sp[0][1];j++)
		{
			sum=0;
			t1=1;
			t2=1;
			int flag1=0,flag2=0;
			while(t1<=sp[0][2])  
			{
				if(sp[t1][0]==i)
				{
					flag1=1;
					break;
				}
				t1++;
			}
			while(t2<=s2.sp[0][2])   
			{
				if(s2.sp[t2][0]==j)
				{
					flag2=1;
					break;
				}
				t2++;
			}
			if(flag1==1 && flag2==1)
			{
				while(sp[t1][0]==i && s2.sp[t2][0]==j)
				{
					if(sp[t1][1]==s2.sp[t2][1])
					{
						sum=sum+sp[t1][2]*s2.sp[t2][2];
						t1++;
						t2++;
					}
					else if(sp[t1][1]<s2.sp[t2][1])
						t1++;
					else
						t2++;
				}
				if(sum>0)
				{
					s5.sp[t3][0]=i;
					s5.sp[t3][1]=j;
					s5.sp[t3][2]=sum;
					t3++;
				}
			}
		}
	}
	s5.sp[0][2]=t3-1;
	s5.n=t3-1;
	return s5;
}
   
sprase sprase::transpose()
{
	sprase s4;
	s4.sp[0][0]=sp[0][0];
	s4.sp[0][1]=sp[0][1];
	s4.sp[0][0]=sp[0][2];
	int i,j,k=1;
	for(i=0;i<col;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==sp[j][1])
			{
				s4.sp[k][0]=sp[j][1];
				s4.sp[k][1]=sp[j][0];
				s4.sp[k][2]=sp[j][2];
				k++;
			}
		}
	}
	s4.sp[0][2]=k-1;
	s4.n=n;
	return s4;
}

void sprase::display()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<sp[i][j]<<" ";
		}
		cout<<"\n";
}
}



int main()
{
	sprase s1,s2,s3,s4,s5;
	int ch,ch1;
	s1.accept();
	s1.convert();
	s2.accept();
	s2.convert();
	cout<<"sparse matrix 1\n";
	s1.display();
	cout<<"sparse matrix 2\n";
	s2.display();
	do
	{
		cout<<"\n 1. addition \n 2. transpose \n 3. multiplication";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s3=s1.add(s2);
				cout<<"Addition of both the matrix\n";
				s3.display();
				break;
			case 2:
					cout<<"transpose of 1st matrix is\n";
	                s4=s1.transpose();
	                s4.display();
	                cout<<"transpose of 2nd matrix is\n";
	                s4=s2.transpose();
	                s4.display();
	                break;
	        case 3:
	        		cout<<"Multilication of the matrix is\n";
                 	s5=s1.multiply(s2);
                	s5.display();
	        	break;
		}cout<<"Press 1 to continue";
		cin>>ch1;
		
	}while(ch1=1);


	return 0;
}
