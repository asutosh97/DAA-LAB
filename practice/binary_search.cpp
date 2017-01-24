#include <iostream>
int binarySearch(int a[],int beg,int end,int item)
{
	//	if one element is present in the array
	if(end - beg == 1)
	{
		if(a[beg] == item)
			return (beg+1);
		else
			return 0;
	}
	else
	{
		int mid = (beg + end)/2;
		if(item < a[mid])
			return binarySearch(a,beg,mid,item);
		else
			return binarySearch(a,mid,end,item);
	}
}
int main()
{
	int n;
	std::cout<<"Enter the number of elements in the array : ";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		std::cin>>a[i];
	int item;
	std::cout<<"Enter the item to be searched : ";
	std::cin>>item;
	int pos = binarySearch(a,0,n,item);
	if(pos)
		std::cout<<"Item found at position : "<<pos<<std::endl;
	else
		std::cout<<"Element not found"<<std::endl;
	return 0;
}