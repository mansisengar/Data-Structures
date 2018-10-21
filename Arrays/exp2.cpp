#include<iostream>
using namespace std;
int search(int arr[],int n,int e)
{
	for(int i=0;i<n;i++)
	{
		if(e==arr[i])
			return i;
	}
	return -1;
}
int main()
{
	int arr[50],n,e,ind;
	cout<<"enter no of elements you want to insert"<<endl;
	cin>>n;
	cout<<"enter elements of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the element to search"<<endl;
	cin>>e;
	ind=search(arr,n,e);
	if(ind==-1)
		cout<<"element is not present in the array "<<endl;
	else
		cout<<"element is present at index "<<ind<<" in the array ";
	return 0;
}
