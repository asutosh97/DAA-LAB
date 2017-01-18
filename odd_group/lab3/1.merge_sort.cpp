#include <iostream>
#include <climits>
using namespace std;
void merge(int a[],int beg,int mid,int end)
{
	int n1 = mid - beg;
	int n2 = end - mid;
	int b[n1+1],c[n2+1];

	int i,j,k;
	for(k = beg,i = 0;i < n1; i++,k++)
		b[i] = a[k];
	b[n1] = INT_MAX;

	for(j = 0;j < n2; j++,k++)
		c[j] = a[k];
	c[n2] = INT_MAX;

	i = j = 0;
	for(k = beg;k < end; k++)
		a[k] = (b[i] < c[j])?b[i++]:c[j++];
}
void merge_sort(int a[],int beg,int end)
{
	if(end - beg <= 1)
		return;
	int mid = (beg + end) / 2;
	merge_sort(a,beg,mid);
	merge_sort(a,mid,end);
	merge(a,beg,mid,end);
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
	merge_sort(a,0,n);
	cout<<"The elements after sorting are : ";
	for(int i = 0;i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}