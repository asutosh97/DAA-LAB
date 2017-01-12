#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start,vector < vector <int> > &adj,int nodes,bool *visited)
{	
	visited[start] = true;
	cout<<start+1<<" ";

	queue <int>q;
	q.push(start);

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int j = 0;j < adj[curr].size(); j++)
		{
			if(visited[adj[curr][j]] == false)
			{
				visited[adj[curr][j]] = true;
				cout<<adj[curr][j]+1<<" ";
				q.push(adj[curr][j]);
			}
		}
	}
	cout<<endl;
}
void DFS(int start,vector < vector <int> > &adj,int nodes,bool *visited)
{
	visited[start] = true;
	cout<<start+1<<" ";
	for(int j = 0;j < adj[start].size(); j++)
	{
		if(visited[adj[start][j]] == false)
			DFS(adj[start][j],adj,nodes,visited);
	}
}
int main()
{
	int nodes;
	cout<<"Enter the number of nodes : ";
	cin>>nodes;

	//	adjacency list formation
	vector< vector <int> > adj(nodes);
	bool visited[nodes];
	while(1)
	{
		memset(visited,false,sizeof(visited));
		cout<<"1.Insert an edge"<<endl;
		cout<<"2.BFS"<<endl;
		cout<<"3.DFS"<<endl;
		int ch,x,y;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the edge(x,y) : ";
				cin>>x>>y;
				adj[x-1].push_back(y-1);
				adj[y-1].push_back(x-1);
				break;
			case 2:
				cout<<"Enter the starting node : ";
				cin>>x;
				BFS(x-1,adj,nodes,visited);
				break;
		case 3:
				cout<<"Enter the starting node : ";
				cin>>x;
				DFS(x-1,adj,nodes,visited);
				cout<<endl;
				break;
			default:
				cout<<"invalid entry..try again"<<endl;
		}
	}
	return 0;
}