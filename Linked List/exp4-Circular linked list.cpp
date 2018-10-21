#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;}; 
class circular_list{
    node *start;
    public:
    circular_list(){
        start=NULL;}
void add_node(int n){
		node *new_node=new node;
		node *ptr;
		new_node->data=n;
	if(start==NULL){
		new_node->next=new_node;
		start=new_node;}
	else{
		ptr=start;
		while(ptr->next!=start)
			ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;}}
	void insert_beg(int p){
		node *ptr;
		node *ptr1=new node;
		ptr1->data=p;
		ptr=start;
		while(ptr->next!=start)
		ptr=ptr->next;
		ptr->next=ptr1;
		ptr1->next=start;
		start=ptr1;}
	void insert_end(int r){
		node *ptr;
		node *ptr1=new node;
	ptr1->data=r;
	//ptr1->next=NULL;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=ptr1;
	ptr1->next=start;}
	void insert_after(int a,int b){
		node *ptr,*preptr;
		node *ptr1=new node;
	ptr1->data=b;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=a){
	preptr=ptr;
	ptr=ptr->next;}
	preptr->next=ptr1;
	ptr1->next=ptr;}
		void display(){
		node *ptr;
		ptr=start;
		while(ptr->next!=start){
			cout<<ptr->data<<endl;
			ptr=ptr->next;}
		cout<<ptr->data<<endl;}
	void search(int a){
		int flag=0;
		node *ptr;
		ptr=start;
		while(ptr->next!=start){
			if(ptr->data==a){
			flag=1;
			break;}
			ptr=ptr->next;}
		if(ptr->data==a){
			flag=1;}
		if(flag==1)
		cout<<"Element present in the list"<<endl;
		else
		cout<<"Element not present in the list"<<endl;}
	void delete_node(int n){	
	int flag=0;
		node *ptr,*preptr,*temp;
		ptr=start;
		while(ptr->next!=start){
			if(ptr->data==n)
			flag=1;
			ptr=ptr->next;}
		if(ptr->data==n){
			flag=1;}
	if(flag==1){
	cout<<"Deletion possible"<<endl;
	ptr=start;
	while(ptr->data!=n){
	preptr=ptr;
	ptr=ptr->next;}
	//temp=ptr;
	preptr->next=ptr->next;
	delete ptr;}
else{
cout<<"Element not present in the list";
exit(1);}}
};
int main(){
    int ch;
    int p,q,r,s,t;
	circular_list l;
    l.add_node(1);
    l.add_node(2);
    l.add_node(3);
    l.add_node(4);
    cin>>ch;
    switch(ch){
    	case 1:cout<<"inserted at the beginning:";
               cin>>p;
    		   cout<<"inserted at the end:";
    		   cin>>q;
               cout<<"inserted at the middle:";
    		   cin>>r;
			   l.insert_beg(p);
               l.insert_end(q);
               l.insert_after(2,r);
               l.display();
               break;
	    case 2:l.display();
		       cout<<"Enter element to be deleted:";
    		   cin>>p;
		       l.delete_node(p);
	           l.display();
	           break;
	    case 3:cout<<"Enter element to be searched:";
               cin>>t;
		       l.search(t);
	    	   break;
	    case 4:cout<<"The linked list is:";
		       l.display();
		       break;}}

