#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
class doubly{
	struct node *head,*tail;
	public:
		doubly()
		{
			head=NULL;
			tail=NULL;
		}
		void ins(int val);
		void insertbeg(int val);
		void insertend(int val);
		void insertbw(int val,int e);
		void del(int val);
		void search(int val);
		void display();
};
void doubly::ins(int val)
{
	struct node *f;
	f=new node;
	f->data=val;
	if(head==NULL && tail==NULL)
	{
		f->next=NULL;
		f->prev=NULL;
		head=f;
		tail=f;
	}
	else
	{
		f->next=NULL;
		f->prev=tail;
		tail->next=f;
		tail=tail->next;
	}
}
void doubly::insertbeg(int val)
{
	struct node *f;
	f=new node;
	f->data=val;
	f->next=head;
	f->prev=NULL;
	head->prev=f;
	head=f;
}
void doubly::insertend(int val)
{
	struct node *f;
	f=new node;
	f->data=val;
	f->next=NULL;
	f->prev=tail;
	tail->next=f;
	tail=f;
}
void doubly::insertbw(int val,int e)
{
	struct node *ptr,*f;
	f=new node;
	f->data=val;
	ptr=head;
	while(ptr->data!=e)
	{
		ptr=ptr->next;
	}
	f->next=ptr->next;
	ptr->next->prev=f;
	f->prev=ptr;
	ptr->next=f;
}
void doubly::del(int val)
{
	struct node *temp,*ptr;
	ptr=head;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->prev->next=temp;
	temp->prev=ptr->prev;
	ptr->next=NULL;
	ptr->prev=NULL;
	delete ptr;
}
void doubly::search(int val)
{
	struct node *ptr;
	int count=1;
	ptr=head;
	while(ptr->data!=val && ptr!=NULL)
	{
		ptr=ptr->next;
		count++;
	}
	if(ptr!=NULL)
	cout<<"element is at "<<count<<" position"<<endl;	
	else
	cout<<"no element found in linked list "<<endl;
}
void doubly::display()
{
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

int main()
{
	int n,ch,val,ch2,e;
	doubly d;
	cout<<"enter no of elements of list"<<endl;
	cin>>n;
	cout<<"Enter elements into list"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		d.ins(val);
	}
	cout<<"enter 1 to insert new element, 2 to delete, 3 to search, 4 to display and 5 to stop "<<endl;
	cin>>ch;
	while(ch!=5)
	{
		switch(ch)
		{
			case 1: cout<<"enter 1 to insert at beginning, 2 to insert at end and 3 for insertion in between"<<endl;
					cin>>ch2;
					cout<<"enter value ";
					cin>>val;
					if(ch2==1)
					{
						d.insertbeg(val);
					}
					else if(ch2==2)
					{
						d.insertend(val);
					}
					else
					{
						cout<<"enter the element after which you want to insert "<<endl;
						cin>>e;
						d.insertbw(val,e);
					}
					break;
			case 2: cout<<"enter the element you want to delete"<<endl;
					cin>>val;
					d.del(val);
					break;
			case 3: cout<<"enter the element you want to search"<<endl;
					cin>>val;
					d.search(val);
					break;
			case 4: d.display();
		}
		cout<<"enter choice again "<<endl;
		cin>>ch;
	}
}
