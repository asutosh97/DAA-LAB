#include <iostream>
#include <vector>
unsigned long long INFINITY = 0;
std::vector<int> bellman_ford(std::vector< std::pair<int, std::pair<int, int> > > wt, int s, int n)
{
	std::vector<int> distance(n+1, INFINITY);
	distance[s] = 0;
	int u, v;
	for(int i = 1; i < n; i++)
	{
		for(int i = 0; i < wt.size(); i++)
		{
			u = wt[i].second.first;
			v = wt[i].second.second;

			if(distance[v] > distance[u] + wt[i].first)
				distance[v] = distance[u] + wt[i].first;

			if(distance[u] > distance[v] + wt[i].first)
				distance[u] = distance[v] + wt[i].first;
		}
	}
	return distance;
}
int main()
{
	int n;
    std::cout<<"Enter the number of vertices : ";
    std::cin>>n;
    std::vector< int > adj_list[100];
    int e;
    std::cout<<"Enter the number of edges : ";
    std::cin>>e;
    std::vector< std::pair<int, std::pair<int, int> > > wt;
    int u,v,w;
    for(int i = 0;i < e; i++)
    {
        std::cout<<"Enter edge : ";
        std::cin>>u>>v;
        std::cout<<"Enter the weight : ";
        std::cin>>w;
        wt.push_back(std::make_pair(w, std::make_pair(u, v)));
        INFINITY += w;
    }
    INFINITY += 1;
    int s;
    std::cout<<"Enter the source vertex : ";
   	std::cin>>s;
    std::vector<int> distance = bellman_ford(wt, s, n);
    std::cout<<"The distances of vertices from source vertex are as follows : ";
    for(int i = 1;i <= n; i++)
    	std::cout<<"Distance of "<<i<<" vertex from source = "<<distance[i]<<std::endl;
    return 0;
}