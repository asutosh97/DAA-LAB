/*
4. Write a program to implement C(n, r) using Dynamic programming approach.
*/

#include <iostream>
int main()
{
	int n,r;
	std::cout<<"Enter the value of n and r : ";
	std::cin>>n>>r;
	int combinations[n+1][r+1];
	for(int i = 1;i <= n; i++)
	{
		for(int j = 0;j <= r && j <= i; j++)
		{
			if(j == 0 || i == j)
				combinations[i][j] = 1;
			else
				combinations[i][j] = combinations[i-1][j] + combinations[i-1][j-1];
		}

	}
	std::cout<<"The value of C("<<n<<","<<r<<") is "<<combinations[n][r]<<std::endl;
	return 0;
}