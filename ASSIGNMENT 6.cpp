#include<iostream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>
#define SIZE 9
using namespace std;
class Stack
{
	public:
		string st[SIZE];
		int top;
		stack()
		{
			top=-1;
		}
		int isempty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		int isfull()
		{
			if(top==SIZE-1)
				return 1;
			else
				return 0;
		}
		void push(string x)
		{
			if(isfull())
			{
				cout<<"\nStack is full and can not push anything!  ";
				return;
			}
			top++;
			st[top]=x;
		}
		std::string pop()
		{
			if(isempty())
			{
			cout<<"\nStack is Empty and can not pop anything!  ";
			return "-999";
			}
			std::string x=st[top];
			top--;
			return x;
		}
};

class Expression
{
	public:
		string postfix,prefix;
		string infix;
		Stack s;
		
		bool isoperator(char x)
		{
			if(x=='+' || x=='-' || x=='*'|| x=='/'|| x=='^')
				return true;
			else
				return false;
		}
		
		int precedance(string op)
		{
			if(op=="+" || op=="-")
				return 1;
			else if(op=="*" || op=="/")
				return 2;
			else if(op=="^")
				return 3;
			else
				return 0;
		}
		
		void infix_to_postfix()
		{
			cout<<"Enter the infix expression to generate postfix\n";
			cin>>infix;
			
			for (int i=0;i<infix.length();i++)
			{
				if((infix[i]>='a' && infix [i]<='z') || (infix[i]>='A' && infix [i]<='Z'))
				{
					postfix=postfix+infix[i];
				}
				else if(infix[i]=='(')
				{
					s.push("(");
				}
				else if(infix[i]==')')
				{
					while((!s.isempty()) && (s.st[s.top]!="("))
					{
						string t=s.pop();
						postfix=postfix+t;
					}
					
					if(s.st[s.top]=="(")
					{
						s.pop();
					}
					
				}
				else
				{	
					while((!s.isempty()) && precedance(string(1,infix[i]))<= precedance(s.st[s.top]))
					{
						string t=s.pop();
						postfix=postfix+t;
					}
					s.push(string(1,infix[i]));
				}
			}
			
			while(!(s.isempty()))
			{
				string t=s.pop();
				postfix=postfix+t;
			}
			
			cout<<"\nInfix Expression";
			cout<<infix;
			cout<<"\nPostfix Expression";
			cout<<postfix<<"\n";
		}
		 void postfix_to_prefix()
        {
        	cout<<"Enter Postfix Expression: ";
        	cin>>postfix;
        	for(int i=0;i<postfix.length();i++)
        	{
        		if(isoperator(postfix[i]))
        		{
        			string op2=s.pop();
        			string op1=s.pop();
        			string temp=postfix[i]+op1+op2;
        			s.push(temp);
        			
				}
				else
				{
					s.push(string(1,postfix[i]));
				}
			}
			prefix=s.pop();
			cout <<"\nPostfix Expression: "<<postfix;
			cout<<"\nPREFIX EXPRESSION:"<<prefix;
			
		}
		
		void postfix_evaluation()
		{
			cout<<"Enter postfix expression :";
 	        cin>>postfix;
 	        for(int i=0;i<postfix.length();i++)
 	        {
 		        if(isoperator(postfix[i]))
 		       {
		            string op2=s.pop();
		 	        string op1=s.pop();
		 	        stringstream ob1(op1);
		 	        stringstream  ob2(op2);
		 	        int op_1,op_2;
		 	        ob1>>op_1;
		          	ob2>>op_2;
		 	        int temp;
		 	        if(postfix[i]=='+')
		 	        {
		 		        temp=op_1+op_2;
			        }
			        else if(postfix[i]=='-')
		 	        {
		 		        temp=op_1-op_2;
			        }
			        else if(postfix[i]=='*')
		 	        {
		 		        temp=op_1*op_2;
			        }
			        else if(postfix[i]=='/')
		 	        {
		 		        temp=op_1/op_2;
			        }
			        else
			            temp=pow(op_1,op_2);
		 
		            stringstream ob3;
		            ob3<<temp;
		            string x=ob3.str();
		            s.push(x);
	            }   
	            else{
	             	if(isdigit(postfix[i]))
	 	            { 
	                    s.push(string(1,postfix[i]));
	                  }
                    }
           }
            cout<<"Result of Postfix Evaluation is: ";
            string result=s.pop();
 	        cout<<result<<endl;
	}
};

int main()
{
	Expression e;
	int ch,ch1;
	do
	{
		cout<<"\n 1.Infix-Postfix \n 2.Postfix-Prefix \n 3.Postfix-Evaluation";
		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				e.infix_to_postfix();
				break;	
			case 2:
				e.postfix_to_prefix();
				break;	
			case 3:
			    e.postfix_evaluation();
				break;
		}cout<<"\nPress 1 to continue\n";
		cin>>ch1;
	}while(ch1=1);
	
	return 0;
}
