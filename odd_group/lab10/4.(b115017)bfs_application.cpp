#include <iostream>
#include <map>
#include <queue>
int in_range(std::pair<int, int> x, int n)
{
    return ((x.first >= 1) && (x.first <= n)) && ((x.second >= 1) && (x.second <= n));
}
void print_path(std::pair<int, int> current, std::map< std::pair<int, int>, std::pair<int, int> >parent)
{
    if(parent[current] == std::make_pair(0, 0))
        std::cout<<"-->("<<current.first<<","<<current.second<<")";
    else
    {
        print_path(parent[current], parent);
        std::cout<<"-->("<<current.first<<","<<current.second<<")";
    }
}
void BFS(int n, std::pair<int, int>source, std::pair<int, int>destination, std::map< std::pair<int, int>, int> maze)
{
    std::map< std::pair<int, int>, bool> visited;
    std::map< std::pair<int, int>, std::pair<int, int> > parent;
    std::map< std::pair<int, int>, int> distance;
    std::pair <int, int> u, v;
    // initialising data structures
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            v = std::make_pair(i, j);
            visited[v] = false;
        }
    }
    std::queue< std::pair<int, int> > q;
    bool found = false;
    q.push(source);
    visited[source] = true;
    distance[source] = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();

        //  left
   //     std::cout<<"parent("<<u.first<<","<<u.second<<")-->";
        v = std::make_pair(u.first, u.second - 1);
        if(in_range(v, n))
        {
            if(visited[v] == false && (maze[v] == 3 || maze[v] == 2))
            {
             //   std::cout<<"left("<<v.first<<","<<v.second<<"), ";
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                distance[v] = distance[u] + 1;
                if(v == destination)
                {
                    found = true;
                    break;
                }
            }
        }

        //  right
        v = std::make_pair(u.first, u.second + 1);
        if(in_range(v, n))
        {
            if(visited[v] == false && (maze[v] == 3 || maze[v] == 2))
            {
             //   std::cout<<"right("<<v.first<<","<<v.second<<")";
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                distance[v] = distance[u] + 1;
                if(v == destination)
                {
                    found = true;
                    break;
                }
            }
        }

        //  down
        v = std::make_pair(u.first + 1, u.second);
        if(in_range(v, n))
        {
            if(visited[v] == false && (maze[v] == 3 || maze[v] == 2))
            {
            //    std::cout<<"down("<<v.first<<","<<v.second<<")";
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                distance[v] = distance[u] + 1;
                if(v == destination)
                {
                    found = true;
                    break;
                }
            }
        }

        //  up
        v = std::make_pair(u.first - 1, u.second);
        if(in_range(v, n))
        {
            if(visited[v] == false && (maze[v] == 3 || maze[v] == 2))
            {
             //   std::cout<<"up("<<v.first<<","<<v.second<<")";
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                distance[v] = distance[u] + 1;
                if(v == destination)
                {
                    found = true;
                    break;
                }
            }
        }
  //      std::cout<<std::endl;
    }

    if(found)
    {
        std::cout<<"Shortest distance to the destination is : "<<distance[destination]<<std::endl;
        std::cout<<"The path is ";
        print_path(destination, parent);
    }
    else
    {
        std::cout<<"Destination can't be reached from source"<<std::endl;
    }
}
int main()
{
    int n;
    std::pair<int, int> source, destination, v;
    std::cout<<"Enter the value of n : ";
    std::cin>>n;
    std::map< std::pair<int, int>, int > maze;
    std::cout<<"Enter the matrix "<<std::endl;
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            v = std::make_pair(i, j);
            std::cin>>maze[v];
            if(maze[v] == 1)
                source = v;

            if(maze[v] == 2)
                destination = v;
        }
    }
    BFS(n, source, destination, maze);
    return 0;
}