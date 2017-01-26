#include <iostream>
int karySearch(int arr[],int beg,int end,int item,int k)
{
	//	if less than k elements is present in the array
	if(end - beg <= k - 2)
	{
		for(int i = beg;i <= end ; i++)
			if(arr[i] == item)
				return (i+1);
		return 0;
	}
	else
	{
		int prev = beg;
		int noOfElements = (end - beg + 1);
		int step = noOfElements/k;
		int next = prev + step - 1;
		for(int i = 1;i < k; i++)
		{
			if(item <= arr[next])
				return karySearch(arr,prev,next,item,k);
			prev = next + 1;
			next = next + step;
		}
		return karySearch(arr,prev,end,item,k);
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
	int k;
	std::cout<<"Enter the value of k : ";
	std::cin>>k;
	int pos = karySearch(a,0,n-1,item,k);
	if(pos)
		std::cout<<"Item found at position : "<<pos<<std::endl;
	else
		std::cout<<"Element not found"<<std::endl;
	return 0;
}