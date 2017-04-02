#include <iostream>
int max(int arr[], int n)
{
	int L = arr[0];
	for(int i = 1;i < n; i++)
	{
		if(arr[i] > L)
			L = arr[i];
	}
	return L;
}
int main()
{
	int n;
	std::cin>>n;
	int arr[n];
	for(int i = 0;i < n; i++)
		std::cin>>arr[i];

	int best[n];
	best[0] = 1;
	for(int i = 1;i < n; i++)
	{
		best[i] = 1;
		int temp = 0;
		for(int j = i-1; j >= 0; j--)
			if(arr[i] % arr[j] == 0)
				temp = (best[j] > temp)? best[j] : temp;
		best[i] += temp;
	}
	std::cout<<max(best, n)<<std::endl;
	return 0;
}