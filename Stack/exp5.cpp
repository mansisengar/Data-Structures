#include<iostream>
using namespace std;
class stack{
	int a[50],top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int num);
		void pop();
		void disp();
};
void stack::push(int num)
{
	if(top==50-1) 
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		top++;
		a[top]=num;
	}
}
void stack::pop()
{
	if(top==-1)
	{
		cout<<"underflow"<<endl;
	}
	else
	{
		top--;
	}
}
void stack::disp()
{
	for(int i=top;i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n,num,ch;
	stack s;
	cout<<"enter 1 to push, 2 to pop, 3 to display, 4 to stop"<<endl;
	cin>>ch;
	while(ch!=4)
	{
		switch(ch)
		{
			case 1: cout<<"enter the no of elements "<<endl;
					cin>>n;
					for(int i=0;i<n;i++)
					{
						cin>>num;
						s.push(num);
					}
					break;
			case 2: s.pop();
					break;
			case 3: s.disp();
		}
		cout<<"enter your choice again"<<endl;
		cin>>ch;
	}
	return 0;
}
