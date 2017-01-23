#include <iostream>
#include <climits>
int count = 0;
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
	{
		count++;
		a[k] = (b[i] < c[j])?b[i++]:c[j++];
	}
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
	std::cout<<"Enter the size of array : ";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		std::cin>>a[i];
	merge_sort(a,0,n);
	std::cout<<"The largest element is "<<a[n-1]<<" and the number of comparisions is "<<count<<std::endl;
	return 0;
}