// Calculate the minimum and maximum in an array using divide and conquer

#include <iostream>
#include <climits>

struct minmax{
	int min;
	int max;
};
minmax minimax(int arr[],int beg,int end)
{
	if(end - beg == 1)
	{
		minmax temp;
		temp.min = temp.max = arr[beg];
		return temp;
	}
	else if(end - beg == 2)
	{
		minmax temp;
		if(arr[beg] < arr[beg + 1])
		{
			temp.min = arr[beg];
			temp.max = arr[beg+1];
		}
		else
		{
			temp.min = arr[beg+1];
			temp.max = arr[beg];
		}
		return temp;
	}
	else
	{
		minmax temp;
		int mid = (beg + end) / 2;
		minmax leftHalf = minimax(arr,beg,mid);
		minmax rightHalf = minimax(arr,mid,end);
		if(leftHalf.min < rightHalf.min)
			temp.min = leftHalf.min;
		else
			temp.min = rightHalf.min;
		if(leftHalf.max > rightHalf.max)
			temp.max = leftHalf.max;
		else
			temp.max = rightHalf.max;
		return temp;
	}
}
int main()
{
	int size;
	std::cout << "Enter the number of elements : ";
	std::cin >> size;
	int arr[size];
	std::cout << "Enter the elements of the array : ";
	for(int index = 0; index < size; index++)
		std::cin >> arr[index];
	minmax x = minimax(arr,0,size);
	std::cout << "The maximum element is " << x.max << " and the minimum is " << x.min << std::endl;
	return 0;
}