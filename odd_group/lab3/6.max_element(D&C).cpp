#include <iostream>
#include <climits>
int count = 0;
int maxElement(int arr[], int beg, int end)
{
	if(end - beg == 1)
	{
		count++;
		return arr[beg];
	}

	int mid = (beg + end) / 2;
	int leftMax = maxElement(arr, beg, mid);
	int rightMax = maxElement(arr, mid, end);
	count++;
	return (leftMax > rightMax)? leftMax: rightMax;
}
int main()
{
	int n;
	std::cout << "Enter the size of array : ";
	std::cin >> n;
	int a[n];
	std::cout << "Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		std::cin >> a[i];
	std::cout << "The largest element is "<< maxElement(a,0,n) <<" and the number of comparisions is " << count << std::endl;
	return 0;
}