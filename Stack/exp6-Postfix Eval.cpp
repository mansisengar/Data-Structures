#include<iostream>
#define size 100
using namespace std;
class stack
{
	int st[size],top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int num);
		int pop();
		
};
void stack::push(int num)
{

	if(top==size-1)
	{
		cout<<"overflow";
	}
	else
	{
		top++;
		st[top]=num;
	}
}
int stack::pop()
{
	int temp;
	if(top==-1)
	{
		cout<<"underflow";
	}
	else
	{
		temp=st[top];
		top--;
		return temp;
	}
}
int main()
{
	int n1,n2,res,num,n;

	stack s;
	char exp[100],*e;
	cout<<"enter expression "<<endl;
	cin>>exp;
	e=exp;
	while(*e!='\0')
	{
		if(isdigit(*e))
		{
			//cout<<*e<<endl;
			num=*e-48;
			//cout<<num<<endl;
			s.push(num);
		}
		else
		{

			n1=s.pop();
			n2=s.pop();
			//cout<<n1<<n2<<endl;
			switch(*e)
			{
				case '+':
					res=n2+n1;
					s.push(res);
					break;
				case '-':
					res=n2-n1;
					s.push(res);
					break;
				case '*':
					res=n2*n1;
					s.push(res);
					break;
				case '/':
					res=n2/n1;
					s.push(res);
					break;
				case '^':
					res=n2^n1;
					s.push(res);
			
			}

		}
		e++;		
	}
	cout<<res<<endl;
	return 0;
}
