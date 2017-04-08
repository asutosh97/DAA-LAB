#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
int main()
{
	int amount, n;
	std::cout<<"Enter the amount : ";
	std::cin>>amount;
	std::cout<<"Enter the number of denominations available : ";
	std::cin>>n;
	std::vector<int> cost(n);
	std::cout<<"Enter the values of denominations : ";
	for(int i = 0;i < n; i++)
		std::cin>>cost[i];

	int numberOfWays[n+1][amount+1];

	for(int j = 0;j <= amount; j++)
		numberOfWays[0][j] = 0;

	for(int i = 0;i <= n; i++)
		numberOfWays[i][0] = 1;

	for(int i = 1;i <= n; i++)
	{
		for(int j = 1;j <= amount; j++)
		{
			if(cost[i-1] <= j)
				numberOfWays[i][j] = numberOfWays[i-1][j] + numberOfWays[i][j - cost[i-1]];
			else
				numberOfWays[i][j] = numberOfWays[i-1][j];
		}
	}
	for(int i = 0;i <= n; i++)
	{
		for(int j = 0;j <= amount; j++)
			std::cout<<numberOfWays[i][j];
		std::cout<<std::endl;
	}
	std::cout<<"Total number of ways : "<<numberOfWays[n][amount]<<std::endl;
	return 0;
}