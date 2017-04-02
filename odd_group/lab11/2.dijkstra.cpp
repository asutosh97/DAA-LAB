#include <iostream>
#include <queue>
#include <map>
unsigned long long INFINITY = 0;
std::vector<int> dijkstra(std::vector<int> adj_list[], std::map< std::pair<int, int>, int > wt, int s, int n)
{
	std::vector<int> distance(n+1, INFINITY);
	std::vector<bool> visited(n+1, false);
	distance[s] = 0;
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > > Q;
	Q.push(std::make_pair(0, s));
	int u, v;
	while(!Q.empty())
	{
		u = Q.top().second;
		Q.pop();
		visited[u] = true;
		for(int i = 0;i < adj_list[u].size(); i++)
		{
			v = adj_list[u][i];
			if(visited[v] == false && (distance[v] > distance[u] + wt[std::make_pair(u, v)]))
			{
				distance[v] = distance[u] + wt[std::make_pair(u, v)];
				Q.push(std::make_pair(distance[v], v));
			}
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
    std::map< std::pair<int, int>, int > wt;
    int u,v,w;
    for(int i = 0;i < e; i++)
    {
        std::cout<<"Enter edge : ";
        std::cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        std::cout<<"Enter the weight : ";
        std::cin>>w;
        wt[std::make_pair(u, v)] = w;
        wt[std::make_pair(v, u)] = w;
        INFINITY += w;
    }
    INFINITY += 1;
    int s;
    std::cout<<"Enter the source vertex : ";
   	std::cin>>s;
    std::vector<int> distance = dijkstra(adj_list, wt, s, n);
    std::cout<<"The distances of vertices from source vertex are as follows : ";
    for(int i = 1;i <= n; i++)
    	std::cout<<"Distance of "<<i<<" vertex from source = "<<distance[i]<<std::endl;
    return 0;
}