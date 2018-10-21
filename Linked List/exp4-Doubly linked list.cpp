#include<iostream>
using namespace std;
struct node{
    int data;
    node *next,*prev;};  
class linked_list{
    node *start;
    public:
    linked_list(){
        start=NULL;}
    void add_new_node(int n){
        node *new_node=new node;
        node *ptr;
        new_node->data=n;
        if(start==NULL){
        new_node->next=NULL;
        //new_node->prev=ptr;
        start=new_node;
    }
    else{
    	
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=NULL;
        new_node->prev=ptr;}}
 void insert_beg(int p){
		node *ptr=new node;
		ptr->data=p;
		ptr->next=start;
		start->prev=ptr;
		start=ptr;
	}
  void insert_end(int r){
  	node *ptr;
	  node *ptr1=new node;
  	  ptr1->data=r;
  	  ptr1->next=NULL;
  	  ptr=start;
  	  while(ptr->next!=NULL)
  	  ptr=ptr->next;
  	  ptr->next=ptr1;
  	  ptr1->prev=ptr;
  }	   
void display(){
    node *ptr;
    ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
void insert_after(int a,int b){
		node *ptr;
		node *ptr1=new node;
	ptr1->data=b;
	ptr=start;
	while(ptr->data!=a){
	ptr=ptr->next;
	}
	ptr1->next=ptr->next;
	ptr1->prev=ptr;
	ptr->next->prev=ptr1;
	ptr->next=ptr1;
}
void delete_node(int x){
	int flag=0;
	node *ptr,*temp,*preptr;
	ptr=start;
	while(ptr!=NULL){
	if(ptr->data==x){
	 flag=1;
	}
	ptr=ptr->next;
	}
	if(flag==1){
	cout<<"Deletion possible"<<endl;
	ptr=start;
	while(ptr->data!=x){
	preptr=ptr;
	ptr=ptr->next;
	}
	temp=ptr;
	temp->next=ptr->next;
	temp->next->prev=preptr;
	preptr->next=temp->next;
	delete ptr;
}
else{
cout<<"Element not present in the list";
exit(1);
}
}
void search(int y){
	int flag=0;
	node *ptr;
	ptr=start;
	while(ptr!=NULL){
		if(ptr->data==y){
			flag=1;
			break;}
	ptr=ptr->next;	}
	if(flag==1)
	cout<<"Element present in the list";
	else
	cout<<"Element not found!";}};
int main(){
    int ch;
    int p,q,r,s,t;
	linked_list l;
    l.add_new_node(1);
    l.add_new_node(2);
    l.add_new_node(3);
    l.add_new_node(4);
    cin>>ch;
    switch(ch){
    	case 1:cout<<"add at beginning:";
               cin>>p;
    		   cout<<"add at end:";
    		   cin>>q;
               cout<<"add at middle:";
    		   cin>>r;
			   l.insert_beg(p);
               l.insert_end(q);
               l.insert_after(2,r);
               l.display();
               break;
	    case 2:l.display();
		       cout<<"Enter element to be deleted from the list:";
    		   cin>>p;
		       l.delete_node(p);
	           l.display();
	           break;
	    case 3:cout<<"Enter element to be searched in the list:";
               cin>>t;
		       l.search(t);
	    	   break;
	    case 4:cout<<"The linked list is:";
		       l.display();
		       break;	   
	}
	}
