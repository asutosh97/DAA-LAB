#include <iostream>
int main()
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int n;
		std::cin>>n;
		int arr[n];
		for(int i = 0;i < n; i++)
			std::cin>>arr[i];

		int ans = n;
		int temp = 1;
		for(int i = 1;i < n; i++)
		{
			if(arr[i-1] <= arr[i])
				ans += temp++;
			else
				temp = 1;
		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}