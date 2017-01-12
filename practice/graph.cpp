#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
void BFS(int start,bool **a,int nodes,bool *visited)
{
	queue <int>q;
	visited[start] = true;
	q.push(start);

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout<<curr+1<<" ";
		for(int j = 0;j < nodes; j++)
		{
			if(a[curr][j] == true && visited[j] == false)
			{
				visited[j] = true;
				q.push(j);
			}
		}
	}
	cout<<endl;
}
void DFS(int start,bool **a,int nodes,bool *visited)
{
	visited[start] = true;
	cout<<start+1<<" ";
	for(int j = 0;j < nodes; j++)
	{
		if(a[start][j] == true && visited[j] == false)
			DFS(j,a,nodes,visited);
	}
}
bool** dynamic2DString(int row,int column)
{
	bool** array = new bool*[row];
	int i;
	for(i = 0;i < row;i++)
		array[i] = new bool[column];
	return array;
}

int main()
{
	int nodes;
	cout<<"Enter the number of nodes : ";
	cin>>nodes;
	
	//	adjacency matrix formation
	bool **a = dynamic2DString(nodes,nodes);

	//	initialisation
	for(int i = 0;i < nodes;i++)
		for(int j = 0;j < nodes;j++)
			a[i][j] = false;

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
				a[x-1][y-1] = true;
				a[y-1][x-1] = true;
				break;
			case 2:
				cout<<"Enter the starting node : ";
				cin>>x;
				BFS(x-1,a,nodes,visited);
				break;
			case 3:
				cout<<"Enter the starting node : ";
				cin>>x;
				DFS(x-1,a,nodes,visited);
				cout<<endl;
				break;
			default:
				cout<<"invalid entry..try again"<<endl;
		}
	}
}