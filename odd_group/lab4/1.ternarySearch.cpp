#include <iostream>
int ternarySearch(int arr[],int beg,int end,int item)
{
	if(end == beg)
	{
		if(arr[beg] == item)
			return beg;
		else
			return -1;
	}
	int step = (end - beg) / 3;
	int mid1 = beg + step;
	int mid2 = mid1 + step;
	
	if(item <= arr[mid1])
		return ternarySearch(arr,beg,mid1,item);
	else if(item <= arr[mid2])
		return ternarySearch(arr,mid1+1,mid2,item);
	else
		return ternarySearch(arr,mid2+1,end,item);
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
	int index = ternarySearch(arr,0,n-1,item);
	if(index == -1)
		std::cout<<"Element not found"<<std::endl;
	else
		std::cout<<"Element found at index "<<index<<std::endl;
	return 0;
}
