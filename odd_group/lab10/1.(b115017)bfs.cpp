#include <iostream>
#include <vector>
#include <queue>
void BFS(std::vector<int>adj_list[], int n, int s)
{
    bool visited[n];
    int parent[n];
    int level[n];
    for(int i = 0;i < n; i++)
    {
        parent[i] = -1;
        visited[i] = false;
        level[i] = 0;
    }
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    std::cout<<"Source node : "<<s+1;
    int u,v;
    int curr_level = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0;i < adj_list[u].size(); i++)
        {
            v = adj_list[u][i];
            if(visited[v] == false)
            {
                if(curr_level != level[u] + 1)
                {
                    curr_level = level[u] + 1;
                    std::cout<<"\nNodes at distance "<<curr_level<<" from the source are : ";
                }
                q.push(v);
                std::cout<<v+1<<" ";
                visited[v] = true;
                parent[v] = u;
                level[v] = level[u] + 1;
            }
        }
    }
}
int main()
{
    int n, m, s, u, v;
    std::cout<<"Enter the number of vertices : ";
    std::cin>>n;
    std::vector<int>adj_list[100];
    std::cout<<"Enter number edges : ";
    std::cin>>m;
    while(m--)
    {
        std::cout<<"Enter edge : ";
        std::cin>>u>>v;
        u--;
        v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    std::cout<<"Enter the source vertex : ";
    std::cin>>s;
    s--;
    BFS(adj_list, n, s);
    return 0;
}
