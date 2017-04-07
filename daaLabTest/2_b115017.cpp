#include <iostream>
#include <vector>
#include <queue>
#include <map>
std::string BFS(std::vector< int > adj_list[], std::map< std::pair<int, int>, char > wt, int s, int d, int n)
{
    bool visited[n+1];
    std::string pathString[100];
    for(int i = 0;i <= n; i++)
    {
        visited[i] = false;
        pathString[i].clear();
    }

    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    int u,v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0;i < adj_list[u].size(); i++)
        {
            v = adj_list[u][i];
            if(visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
        //        std::cout<<"pathString = "<<pathString[v]<<std::endl;
                pathString[v] = pathString[u] + wt[std::make_pair(u, v)];
            }
        }
    }
    return pathString[d];
}
int main()
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int n;
		std::cin>>n;
		int u,v;
		char w;
        std::vector< int > adj_list[100];
        std::map< std::pair<int, int>, char > wt;
		for(int i = 0;i < n-1; i++)
    	{
    		std::cin>>u>>v;
            std::cin>>w;
            std::cin.clear();
    		adj_list[u].push_back(v);
        	adj_list[v].push_back(u);
    		wt[std::make_pair(u, v)] = w;
        	wt[std::make_pair(v, u)] = w;
    	}
    	int m;
    	std::cin>>m;
    	for(int i = 1; i <= m; i++)
    	{
            int type, u, v;
            char c;
            std::cin>>type;
            std::cin>>u;
            std::cin>>v;
    		
    		if(type == 2)
    		{
    			std::cin>>c;
                std::cin.clear();
    			wt[std::make_pair(u, v)] = c;
        		wt[std::make_pair(v, u)] = c;
    		}
    		else
    		{

    			std::string pathString = BFS(adj_list, wt, u, v, n);
                std::cout<<pathString<<std::endl;
                int ans = 1;
                for(int i = 1;i < pathString.length(); i++)
                {
                    if(pathString[i] == pathString[0])
                        break;
                    ans++;
                }
                std::cout<<ans<<std::endl;

    		}
   	}
	}
	return 0;
}