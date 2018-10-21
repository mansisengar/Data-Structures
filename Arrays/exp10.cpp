#include<iostream>
using namespace std;
void merge(int arr1[],int arr2[],int arr3[],int n,int n1){
        int i=0,j=0,temp[n+n],k=0;
        while(i<n&&j<n1){
            if(arr1[i]<arr2[j]){
                temp[k]=arr1[i];
                k++;
                i++;
            }
            else{temp[k]=arr2[j];
                k++;
                j++;
            }
        }
        while(i<n){ temp[k]=arr1[i];
                k++;
                i++;
        }
         while(j<n1){ temp[k]=arr2[j];
                k++;
                j++;
        }
        for(int z=0;z<n+n1;z++)
            arr3[z]=temp[z];
    
}
void select(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int small=a[i];
		int pos=i;
		int j=i+1;
		int temp;
		while(j<n)
		{
			if(a[j]<small)
			{
				small=a[j];
				pos=j;
			}
			j++;
		}
		if(pos!=i)
		{
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
}
int main()
{
	int a[50],b[50],c[50];
	int n,n1;
	int j=0;
	cout<<"enter number of elements:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"enter no of elements:\n";
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>b[i];
	}
	select(a,n);
	select(b,n1);
	cout<<"sorted: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"sorted: "<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<b[i]<<endl;
	}
	merge(a,b,c,n,n1);
	cout<<"merged list"<<endl;
	for(int i=0;i<n+n1;i++)
	{
		
		cout<<c[i]<<endl;
	}
}  

