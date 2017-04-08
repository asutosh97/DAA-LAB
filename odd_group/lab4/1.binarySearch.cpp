#include <iostream>
int binarySearch(int arr[],int beg,int end,int item)
{
	if(end == beg)
	{
		if(arr[beg] == item)
			return beg;
		else
			return -1;
	}
	int mid = (beg + end) / 2;
	if(item <= arr[mid])
		binarySearch(arr,beg,mid,item);
	else
		binarySearch(arr,mid+1,end,item);
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
	int index = binarySearch(arr,0,n-1,item);
	if(index == -1)
		std::cout<<"Element not found"<<std::endl;
	else
		std::cout<<"Element found at index "<<index<<std::endl;
	return 0;
}
