#include <iostream>
#define DIAGONAL 2
#define UP 1
#define LEFT 0

// ABCBDAB
// BDCABA
int** dynamic2D(int row,int column)
{
	int** array = new int*[row];
	int i;
	for(i = 0;i < column;i++)
		array[i] = new int[column];
	return array;
}
void print_LCS(int **B, std::string X, int i, int j)
{
	if(i == 0 || j == 0)
		return;
	if(B[i][j] == DIAGONAL)
	{
		print_LCS(B, X, i-1, j-1);
		std::cout<<X[i-1];
	}
	else if(B[i][j] == UP)
		print_LCS(B, X, i-1, j);
	else
		print_LCS(B, X, i, j-1);
}
void LCS(std::string X, std::string Y)
{
	int m = X.size();
	int n = Y.size();
	int **C = dynamic2D(m+1, n+1);
	int **B = dynamic2D(m+1, n+1);
	for(int i = 0;i <= m; i++){
		C[i][0] = 0;
	}

	for(int j = 1; j <= n; j++)
		C[0][j] = 0;

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(X[i-1] == Y[j-1])
			{
				C[i][j] = C[i-1][j-1]+1;
				B[i][j] = DIAGONAL;
			}
			else
			{
				if(C[i-1][j] > C[i][j-1])
				{
					C[i][j] = C[i-1][j];
					B[i][j] = UP;
				}
				else
				{
					C[i][j] = C[i][j-1];
					B[i][j] = LEFT;
				}
			}
		}
	}
	std::cout<<"The length of LCS is :- "<<C[m][n]<<std::endl;
	std::cout<<"And the stirng is :- ";
	print_LCS(B, X, m, n);
	std::cout<<std::endl;
}
int main()
{
	std::string a, b;
	std::cout<<"Enter string 1 :- ";
	std::cin>>a;
	std::cout<<"Enter string 2 :- ";
	std::cin>>b;
	LCS(a, b);
	return 0;
}