#include <iostream>
#include <vector>
#include <queue>
int noOfEdges(std::vector<int> adj_list[], int n)
{
	int count = 0;
	for(int i = 1;i <= n; i++)
	{
		for(int j = 0;j < adj_list[i].size(); j++)
		{
			count++;
		}
	}
	return count/2;
}
int main()
{
    int n, m, u, v;
    std::cout<<"Enter the number of vertices : ";
    std::cin>>n;
    std::vector<int>adj_list[100];
    std::cout<<"Enter number edges : ";
    std::cin>>m;
    while(m--)
    {
        std::cout<<"Enter edge : ";
        std::cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    std::cout<<"Total number of edges : "<<noOfEdges(adj_list, n)<<std::endl;
    return 0;
}
