#include<iostream>
using namespace std;
void ins(int a[],int n)
{
	int temp,j;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void insert(int a[],int n,int no)
{
	int i=0;
	int j;
	while(i<n)
	{
		if(a[i]>no&&no<a[i-1])
		{
			for(j=n;j>=i;j--)
			{
				a[j]=a[j-1];
			}
			a[j]=no;
			break;
		}
		else {
		if(i==n)
		{
			a[n]=no;
		}
		}
	i++;
	}
}
int main()
{
	int a[50];
	int n,no;
	cout<<"size of array: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ins(a,n);
	cout<<"enter the no. to be inserted: ";
	cin>>no;
	insert(a,n,no);
	for(int i=0;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}

