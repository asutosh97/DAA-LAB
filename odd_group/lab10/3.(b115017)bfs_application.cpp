#include <iostream>
#include <vector>
#include <queue>
void BFS(std::vector<int>adj_list[], int n, int s, int d)
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
                parent[v] = u;
                level[v] = level[u] + 1;
                if(v == d)
                {
                    std::cout<<"The minimum distance between source and destination is "<<level[d]<<std::endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    int n, m, s, d, u, v;
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
    std::cout<<"Enter the destination vertex : ";
    std::cin>>v;
    s--;
    BFS(adj_list, n, s, d);
    return 0;
}