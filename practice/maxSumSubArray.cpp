/*
Program that finds the maximum sum subarray 
*/

#include <iostream>
int main()
{
	int size;
	std::cout << "Enter the size of the array : ";
	std::cin >> size;
	int arr[size];
	std::cout << "Enter the elements of the array : ";
	for(int i = 0; i < size; i++)
		std::cin >> arr[i];

	int maxSum = 0;
	int currSum = 0;
	int lastMaxIndex = -1;

	for(int i = 0;i < size; i++)
	{
		currSum += arr[i];

		if(currSum < 0)
			currSum = 0;

		if(currSum > maxSum)
		{
			maxSum = currSum;
			lastMaxIndex = i;
		}
	}

	int firstMaxIndex, tempSum = 0;
	for(int i = lastMaxIndex; i >= 0; i--)
	{
		tempSum += arr[i];

		if(tempSum == maxSum)
		{
			firstMaxIndex = i;
			break;
		}
	}

	std::cout << "The maximum sum subarray is from " << firstMaxIndex << " to " << lastMaxIndex << " and the maximum sum is : " << maxSum << std::endl;
	return 0;
}