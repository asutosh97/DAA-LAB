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

	int c[amount+1];

	for(int i = 0;i <= amount; i++)
		c[i] = INT_MAX - 1;

	c[0] = 0;

	for(int i = 0;i < n; i++)
	{
		for(int j = 1;j <= amount; j++)
		{
			if(cost[i] <= j)
			{
				if(((c[j - cost[i]] + 1) < c[j]))
				{
					c[j] = (c[j - cost[i]] + 1);
				}
			}
		}
	}		
	std::cout<<"The minimum number of coins required to form "<<amount<<" is "<<c[amount]<<std::endl;
	return 0;
}