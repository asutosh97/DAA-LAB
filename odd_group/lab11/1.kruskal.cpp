#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector< std::pair<int, int> > component;
int FINDSET(int x)
{
    for(int i = 0;i < component.size(); i++)
        if(component[i].first == x)
            return component[i].second;
    return -1;
}
void MAKESET(int x)
{
    if(FINDSET(x) != -1)
        return;
        component.push_back(std::make_pair(x, x));
}
void UNION(int a, int b)
{
    int p = FINDSET(a);
    int q = FINDSET(b);

    if(p == -1 || q == -1 || p == q)
        return;
    for(int i = 0;i < component.size(); i++)
    {
        if(component[i].second == p)
            component[i].second = q;
    }
}
std::vector< std::pair<int, int> > kruskal(int n, std::vector< std::pair<int, std::pair<int, int> > > wt)
{
    for(int i = 1;i <= n; i++)
        MAKESET(i);

    std::vector< std::pair<int, int> > edges;
    std::sort(wt.begin(), wt.end());
    std::pair<int, int> x;
    int count = 0;

    for(int i = 0; i < wt.size(); i++)
    {
        x = wt[i].second;
        if(FINDSET(x.first) != FINDSET(x.second))
        {
            UNION(x.first, x.second);
            edges.push_back(x);
            count++;
        }
        if(count == n-1)
            break;
    }
    return edges;
}

int main()
{
    int n;
    std::cout<<"Enter the number of vertices : ";
    std::cin>>n;
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
    }
    std::vector< std::pair<int, int> > edges = kruskal(n, wt);
    std::cout<<"The edges in the minimum spanning tree are : "<<std::endl;
    for(int i = 0;i < edges.size(); i++)
        std::cout<<"("<<edges[i].first<<","<<edges[i].second<<")"<<std::endl;

    return 0;
}
