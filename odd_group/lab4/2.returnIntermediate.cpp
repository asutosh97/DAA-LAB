#include <iostream>
int main()
{
	int n;
	std::cout<<"Enter the number of elements in the array : ";
	std::cin>>n;
	int arr[n];
	std::cout<<"Enter the elements : ";
	for(int i = 0;i < n; i++)
		std::cin>>arr[i];
	
	int min,max,mid;
	min = max = mid = arr[0];
	
	for(int i = 1;i < n; i++)
	{
		if(arr[i] <= min)
			min = arr[i];
		else if(arr[i] >= max)
			max = arr[i];
		else
			mid = arr[i];
	}
	if(mid == min)
		std::cout<<"No intermediate element found "<<std::endl;
	else
		std::cout<<"An intermediate element is : "<<mid<<std::endl; 
	return 0;
}
