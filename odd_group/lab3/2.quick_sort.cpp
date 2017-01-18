#include <iostream>
#include <cstdlib>
using namespace std;
int partition(int a[],int beg,int end)
{
	int x = a[beg];
	int i = beg,j;
	for(j = beg + 1;j < end; j++)
		if(a[j] < x)
			swap(a[++i],a[j]);
	swap(a[beg],a[i]);
	return i;
}
void quick_sort(int a[],int beg,int end)
{
	if(end - beg <= 1)
		return;
	int q = partition(a,beg,end);
	quick_sort(a,beg,q);
	quick_sort(a,q+1,end);
}
int main()
{
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		cin>>a[i];
	quick_sort(a,0,n);
	cout<<"The elements after sorting are : ";
	for(int i = 0;i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}