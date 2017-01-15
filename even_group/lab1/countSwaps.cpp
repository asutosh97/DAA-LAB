#include <iostream>
#include <climits>
using namespace std;
int mergeCount(int a[],int beg,int mid,int end)
{
	int n1 = (mid - beg);
	int n2 = (end - mid);
	int b[n1+1],c[n2+1];

	int count = 0;

	for(int i = beg,j = 0;i < mid; i++,j++)
		b[j] = a[i];
	b[n1] = INT_MAX;

	for(int i = mid,j = 0;i < end; i++,j++)
		c[j] = a[i];
	c[n2] = INT_MAX;

	int i = 0,j = 0;
	for(int k = beg;k < end;k++)
	{
		if(b[i] <= c[j])
			a[k] = b[i++];
		else
		{
			a[k] = c[j++];
			count += (n1 - i);
		}
	}
	return count;
}
int mergeSortCount(int a[],int beg,int end)
{
	// when single element array
	if(end - beg <= 1)
		return 0;
	
	int mid = (beg+end)/2;
	return mergeSortCount(a,beg,mid) + mergeSortCount(a,mid,end) + mergeCount(a,beg,mid,end);
}
int main()
{
	int n;
	cout<<"Enter the number of elements in the array : ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements in the array : ";
	for(int i = 0;i < n; i++)
		cin>>a[i];

	cout<<"Number of inversions required is : "<<mergeSortCount(a,0,n)<<endl;
	return 0;
}