#include <iostream>
int linearSearch(int arr[],int beg,int end,int item)
{
	for(int i = beg;i < end; i++)
		if(item == arr[i])
			return i;
	return -1;
}
int main()
{
	int n;
	std::cout<<"Enter the number of elements : ";
	std::cin>>n;
	int arr[n];
	std::cout<<"Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		std::cin>>arr[i];
	int item;
	std::cout<<"Enter the element to be searched : ";
	std::cin>>item;
	int index = linearSearch(arr,0,n,item);
	if(index == -1)
		std::cout<<"Element not found"<<std::endl;
	else
		std::cout<<"Element found at index "<<index<<std::endl;
	return 0;
}
