#include <iostream>
#include <climits>
int count = 0;
int max_element(int a[],int size)
{
	int l = 0;
	for(int i = 1;i < size; i++)
	{
		if(a[i] > a[l])
			l = i;
		count++;
	}
	return l;
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
	int pos = max_element(a,n);
	std::cout<<"The largest element is "<<a[pos]<<" and the number of comparisions is "<<count<<std::endl;
	return 0;
}