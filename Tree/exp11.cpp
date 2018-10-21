#include<iostream>
using namespace std;
struct node
{
	node *left,*right;
	int data;
};
void create(node **root)
{
	node *t,*q;
	node *p=new node;
	cin>>p->data;
	p->left=p->right=NULL;
	if(*root==NULL)
	{
		*root=p;
	}
	else
	{
		t=*root;
		while(t!=NULL)
		{
			q=t;
			if(t->data>p->data)
			{
				t=t->left;
			}
			else
			{
				t=t->right;
			}
		}
		if(q->data>p->data)
		{
			q->left=p;
		}
		else{
			q->right=p;
		}
	}
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else {
		cout<<root->data<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else {
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}
void postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else {
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<endl;
	}
}
void del1(node *root,int item)
{
	node *p,*t,*m;
	int temp;
	p=root;
	while(p!=NULL&&p->data!=item)
	{
		t=p;
		if(p->data>item)
		{
			p=p->left;
		}
		else {
		p=p->right;
		}
	}
	if(p->left==NULL&&p->right==NULL)
	{	
	    if(t->left==p)
	          t->left=NULL;
	    else{
	    	t->right=NULL;
		}      
	  delete(p);
	}
	else if(p->left!=NULL||p->right!=NULL)
		{
			if(p->left!=NULL)
		{
			t->left=p->left;
			p->left=NULL;
		}
		else if(p->right!=NULL)
		{
			t->right=p->right;
			p->right=NULL;
		}
		delete(p);
	}
else {
	t=p->right;
	while(t->left!=NULL)
	{
		m=t;
		t=t->left;
	}
	temp=p->data;
	p->data=t->data;
	if(t->right==NULL)
	{
		m->left=NULL;
		delete(t);
	}
	else{
		m->left=t->right;
		t->right=NULL;
		delete(t);
	}
}
}
int main()
{
	node *root;
	root=NULL;
	char ch;
	int n;
	cout<<"1. insertion"<<endl<<"2. treversing"<<endl<<"3. deletion"<<endl;
	do{cout<<"choose a case";
	cin>>n;
	switch(n)
		{
			case 1:
				int k;
				cin>>k;
			for(int i=0;i<k;i++)
			{
				create(&root);
			}
				break;
			case 2:
				cout<<"preorder:"<<endl;
							preorder(root);
						cout<<"inorder:"<<endl;
							inorder(root);
						cout<<"postorder:"<<endl;
							postorder(root);
							break;
			case 3:
				int item;
				cin>>item;
				del1(root,item);
				break;
		}
		cout<<"press y to continue";
		cin>>ch;
	}while(ch!='n');
}

