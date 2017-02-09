#include <iostream>

int B[100][100];
void print_LCS(std::string X, int i, int j)
{
    if(i == 0 || j == 0)
        return;

    if(B[i][j] == 2)
    {
        print_LCS(X,i-1,j-1);
        std::cout<<X[i-1];
    }
    else if(B[i][j] == 1)
        print_LCS(X,i-1,j);
    else
        print_LCS(X,i,j-1);
}
void LCS_Length(std::string X, std::string Y)
{
    int m = X.length();
    int n = Y.length();

    int C[m+1][n+1];
    for(int i = 0;i <= m; i++)
        C[i][0] = 0;

    for(int j = 1;j <= n; j++)
        C[0][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(X[i-1] == Y[j-1])
            {
                C[i][j] = C[i-1][j-1]+1;
                B[i][j] = 2;
            }
            else
            {
                if(C[i-1][j] >= C[i][j-1])
                {
                    C[i][j] = C[i-1][j];
                    B[i][j] = 1;
                }
                else
                {
                    C[i][j] = C[i][j-1];
                    B[i][j] = 0;
                }
            }
        }
    }
    std::cout<<"The length of longest common subsequence is : "<<C[m][n]<<std::endl;
    std::cout<<"And the longest common subsequence is : ";
    print_LCS(X, m, n);
}
int main()
{
    std::string a,b;
    std::cout<<"Enter two sequences : "<<std::endl;
    std::cin>>a>>b;
    LCS_Length(a,b);
    return 0;
}
