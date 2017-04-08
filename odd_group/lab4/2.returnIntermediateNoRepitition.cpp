#include <iostream>
#include <algorithm>
int main()
{
	int n;
	std::cout<<"Enter the number of elements in the array : ";
	std::cin>>n;
	int arr[n];
	std::cout<<"Enter the elements : ";
	for(int i = 0;i < n; i++)
		std::cin>>arr[i];
		
	std::sort(arr,arr+ 3);
	std::cout<<"an intermediate element is : "<<arr[1]<<std::endl;
	return 0;
}
