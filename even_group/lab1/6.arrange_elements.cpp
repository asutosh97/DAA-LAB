/*
arrange prime elements before, then odd, then even
*/


#include <iostream>
bool isprime(int n)
{
	bool status=true;
	for(int i=2;i<n;i++)
	{
		if(n%i == 0)
		{
			status=false;
			break;
		}
	}
	return status;
}
int main()
{
	int size;
	std::cout<<"enter the size : ";
	std::cin>>size;
	int arr[size];
	std::cout<<"Enter the numbers : ";
	for(int i=0;i<size;i++)
		std::cin>>arr[i];
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(isprime(arr[i]))
		{
			std::swap(arr[i],arr[j]);
			j++;
		}
	}
	for(int i=j;i<size;i++)
	{
		if(arr[i]%2 != 0)
		{
			std::swap(arr[i],arr[j]);
			j++;
		}
	}
	
	std::cout<<"Rearranged array is : ";
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<"  ";
	}
	std::cout<<std::endl;
	return 0;
}
