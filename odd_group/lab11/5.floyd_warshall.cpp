#include <iostream>
#define INFINITY 1000
int main()
{
	int n, e;
    std::cout<<"Enter the number of vertices : ";
    std::cin>>n;
    int i, j, k;
    int W[n+1][n+1];
    for(int i = 1;i <= n; i++)
    	for(int j = 1;j <= n; j++)
    			W[i][j] = INFINITY;

    std::cout<<"Enter the number of edges : \n";
    std::cin>>e;

    int u, v, w;
    for(int i = 1;i <= e; i++)
    {
    	std::cout<<"Enter edge : ";
        std::cin>>u>>v;
        std::cout<<"Enter the weight : ";
        std::cin>>w;
        W[u][v] = w;
    }

    for(int k = 1;k <= n; k++)
    	for(int i = 1;i <= n; i++)
    		for(int j = 1;j <= n; j++)
    			W[i][j] = std::min(W[i][j], W[i][k] + W[k][j]);


    for(int i = 1;i <= n; i++)
    {
    	for(int j = 1;j <= n; j++)
    	{
    		std::cout<<W[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }
    return 0;
}