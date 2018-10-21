#include<iostream>
#include<string.h>
#define size 50
using namespace std;
class stack
{
	char s[size],op[size];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		void push(char sym);
		int pop();
		int prec(char sym);
		void infixtopostfix(char inf[]);
};
void stack::push(char sym)
{
	if(top==size-1)
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		top++;
		s[top]=sym;
	}
}
int stack::pop()
{
	char temp;
	if(top==-1)
	{
		cout<<"underflow"<<endl;
	}
	else
	{
		temp=s[top];
		top--;
		return temp;	
	}
	
}
int stack::prec(char sym)
{
	if(sym=='(' || sym==')')
		return 0;
	else if(sym=='+' || sym=='-')
		return 1;
	else if(sym=='*' || sym=='/')
		return 2;
	else if(sym=='^')
		return 3;	
}
void stack::infixtopostfix(char inf[])
{
	int length,j=0;
	length=strlen(inf);
	for(int i=0;i<length;i++)
	{
		if(inf[i]!='+' && inf[i]!='-' && inf[i]!='*' && inf[i]!='/' && inf[i]!='^' && inf[i]!='(' && inf[i]!=')')
		{
			op[j++]=inf[i];
		}
		else
		{
			if(inf[i]!='(' && inf[i]!=')')
			{
				if(top==-1)
				{
					push(inf[i]);	
				}
				else
				{
					if(prec(inf[i])<=prec(s[top]))
					{
						while(prec(inf[i])<=prec(s[top]))
						{
							op[j++]=pop();
						}
					}
					push(inf[i]);
				}
			}
			else
			{
				if(inf[i]=='(')
					push(inf[i]);
				else if(inf[i]==')')
				{
					char temp;
					temp=pop();
					while(temp!='(')
					{
						op[j++]=temp;
						temp=pop();
					}
				}
			}
		}
	}
	while(top!=-1)
	{
		op[j++]=pop();
	}
	cout<<op<<endl;
}
int main()
{
	char inf[size];
	cin>>inf;
	stack s;
	s.infixtopostfix(inf);
	return 0;
}
