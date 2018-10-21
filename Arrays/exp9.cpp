#include<iostream>
using namespace std;
class quicksort{
	int arr[20],g;
public:
	quicksort(int a[],int h)
	{
		int i;
		g=h;
		for(i=0;i<=h;i++)
		arr[i]=a[i];
		//for(i=0;i<=h;i++)
	//	cout<<arr[i]<<endl;	
	}
	int divide(int low,int high)
	{
	int pivot, index, t,i;
	index = low;
	pivot = high;
	for(i=low; i < high; i++)
	{
		if(arr[i]<arr[pivot])
		{
			t=arr[i];
			arr[i]=arr[index];
			arr[index]=t;
			index++;
		}
	}
	t=arr[pivot];
			arr[pivot]=arr[index];
			arr[index]=t;
	return index;
	}
void sort(int l,int h)
{
		
	if(l<h){
	
	int i=divide(l,h);
	sort(l,i-1);
	sort(i+1,h);
	
	}
	
	}
	void disp(){
		int i,j;
		for(i=0;i<=g;i++)
		cout<<arr[i]<<endl;
	}
};
int main(){
	int arr[100];
	int n,i;
	cin>>n;
	cout<<"ENTER ELEMENTS:\n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<<"USING QUICK SORT:\n";
	quicksort qq(arr,n-1);
	qq.sort(0,n-1);
	qq.disp();
}
