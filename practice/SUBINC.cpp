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

		int table[n][n];
		int ans = n;
		for(int j = 0;j < n; j++)
		{
			table[0][j] = 1;
		}

		for(int i = 1;i < n; i++)
		{
			for(int j = i;j < n; j++)
			{
				if(table[i-1][j-1] == 1 && arr[j-1] <= arr[j])
				{
					table[i][j] = 1;
					ans++;
				}
				else
					table[i][j] = 0;
			}
		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}