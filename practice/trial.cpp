#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void display(vector < vector <int> > &adj,int nodes)
{
	for(int i = 0;i < nodes; i++)
	{
		cout<<"neighbours of "<<i+1<<": ";
		for(int j = 0;j < adj[i].size() ; j++)
			cout<<adj[i][j]+1<<" ";
		cout<<endl;
	}

}
int main()
{
	int nodes;
	cout<<"Enter the number of nodes : ";
	cin>>nodes;

	//	adjacency list formation
	vector< vector <int> > adj(nodes);
	while(1)
	{
		cout<<"1.Insert an edge"<<endl;
		cout<<"2.Display list"<<endl;
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
				display(adj,nodes);
				break;
			default:
				cout<<"invalid entry..try again"<<endl;
		}
	}
	return 0;
}