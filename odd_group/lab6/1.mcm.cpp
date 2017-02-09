#include <iostream>
#include <climits>

int S[100][100];

void MCM_Parent(int i, int j)
{
    if(i == j)
        std::cout<<"A"<<i<<" ";
    else
    {
        std::cout<<"(";
        MCM_Parent(i, S[i][j] );
        MCM_Parent(S[i][j]+1, j);
        std::cout<<")";
    }
}

void MCM(int dimensions[], int n)
{
    int M[n+1][n+1];
    for(int i = 1;i <= n; i++)
    {
        M[i][i] = 0;
        S[i][i] = 0;
    }


    for(int d = 1; d <= n - 1; d++)
    {
        for(int i = 1;i <= n - d; i++)
        {
            int j = i + d;
            int min = INT_MAX;
            int kmin = -1;
            for(int k = i; k < j; k++)
            {
                if(M[i][k] + M[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j] < min)
                {
                    min = M[i][k] + M[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];
                    kmin = k;
                }
            }
            M[i][j] = min;
            S[i][j] = kmin;
        }
    }
    std::cout << "The minimum number of scalar multiplications required to perform the matrix multiplication is : " << M[1][n] << std::endl;
    std::cout << "And the corresponding order is : ";
    MCM_Parent(1,n);
    std::cout<<std::endl;
}


int main()
{
    int n;
    std::cout << "Enter the number of matrices : ";
    std::cin >> n;
    int dimensions[n+1];
    for(int i = 0;i <= n; i++)
        std::cin >> dimensions[i];
    MCM(dimensions,n);
    return 0;
}
