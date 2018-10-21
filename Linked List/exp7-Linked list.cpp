#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *ptr,*front,*rear;
void ins(int n)
{
	struct node *f;
	int i=0;
	while(i<n)
	{
		if(front==NULL)
		{
			f=new node;
			cin>>f->data;
			f->next=NULL;
			front=f;
			rear=front;
		}
		else
		{
			f=new node;
			cin>>f->data;
			rear->next=f;
			f->next=front;
			rear=rear->next;
		}
		i++;
	}
	
}
void del()
{
	if(front==NULL)
		cout<<"underflow"<<endl;
	else
	{
		ptr=front;
		front=front->next;
		rear->next=front;
		delete ptr;
	}
}
void disp()
{
	ptr=front;
	do{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=front);
}
int main()
{
	int ch,n;
	cout<<"enter 1 to insert, 2 to delete, 3 to display and 4 to stop"<<endl;
	cin>>ch;
	front=NULL;
	while(ch!=4)
	{
		switch(ch)
		{
			case 1: cout<<"enter the no of elements of list"<<endl;
					cin>>n;
					ins(n);
					break;
			case 2: del();
					break;
			case 3: disp();
		}
		cout<<"enter your choice again"<<endl;
		cin>>ch;
	}
	return 0;
}
