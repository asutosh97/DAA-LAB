//last element as pivot
#include <iostream>
#include <cstdlib>
#include <ctime>
int partition(int a[],int beg,int end)
{
	int x = a[end - 1];
	int i = beg-1,j;
	for(j = beg;j < end-1; j++)
		if(a[j] < x)
			std::swap(a[++i],a[j]);
	i++;
	std::swap(a[end-1],a[i]);
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
	std::cout<<"Enter the size of array : ";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		std::cin>>a[i];
	quick_sort(a,0,n);
	std::cout<<"The elements after sorting are : ";
	for(int i = 0;i < n; i++)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;
	return 0;
}
