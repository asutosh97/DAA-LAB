#include <iostream>
int main()
{
    int n;
    std::cout << "Enter the number of matrices available : ";
    std::cin >> n;
    int p[n+1];
    p[1] = 1;
    p[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        p[i] = 0;
        for(int k = 1; k <= i-1 ; k++)
        {
            p[i] += p[k] * p[i - k];
        }
    }
    std::cout<<"Total number of possible ways to parenthesize : "<<p[n]<<std::endl;
    return 0;
}
