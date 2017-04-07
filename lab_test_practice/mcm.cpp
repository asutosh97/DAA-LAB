#include <iostream>
int** dynamic2D(int row,int column)
{
	int** array = new int*[row];
	int i;
	for(i = 0;i < column;i++)
		array[i] = new int[column];
	return array;
}
void MCM_Parent(int **S, int i, int j)
{
	if(i == j)
		std::cout<<"A["<<i<<"]";
	else
	{
		std::cout<<"(";
		MCM_Parent(S, i, S[i][j]);
		MCM_Parent(S, S[i][j]+1, j);
		std::cout<<")";
	}
}
int main()
{
	int n;
	std::cout<<"Enter the number of matrices :- ";
	std::cin>>n;
	int a[n+1];
	std::cout<<"Enter the dimension array of size "<<n+1<<":";
	for(int i = 0; i < n+1; i++)
		std::cin>>a[i];

	int **M = dynamic2D(n+1, n+1);
	int **S = dynamic2D(n+1, n+1);

	for(int i = 1;i <= n; i++)
	{
		M[i][i] = 0;
		S[i][i] = 0;
	}

	for(int d = 1; d <= n - 1; d++)
	{
		for(int i = 1; i <= n - d; i++)
		{
			int j = i + d;
			M[i][j] = std::numeric_limits<int>::max();
			for(int k = i; k < j; k++)
			{
				if (M[i][j] > M[i][k] + M[k+1][j] + a[i-1]*a[k]*a[j])
				{
					M[i][j] = M[i][k] + M[k+1][j] + a[i-1]*a[k]*a[j];
					S[i][j] = k;
				}
			}
		}
	}
	std::cout<<"The minimum number of multiplications is :-> "<<M[1][n]<<std::endl;
	std::cout<<"The Parenthesizing is as follows :-> ";
	MCM_Parent(S, 1, n);
	std::cout<<std::endl;
	return 0;
}