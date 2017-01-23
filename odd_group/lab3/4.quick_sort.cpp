//random element as pivot
#include <iostream>
#include <cstdlib>
#include <ctime>
int partition(int a[],int beg,int end)
{
	srand((unsigned)time(NULL));
	int random_pivot = beg + rand() % (end - beg);
	std::swap(a[random_pivot],a[beg]);
	int x = a[beg];
	int i = beg,j;
	for(j = beg + 1;j < end; j++)
		if(a[j] < x)
			std::swap(a[++i],a[j]);
	std::swap(a[beg],a[i]);
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