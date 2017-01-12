#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#define R 5
#define C 5
using namespace std;
bool matrix[R][C];
int longest_path(int posx,int posy,bool visited[][C])
{
	visited[posx][posy] = true;
	int length = 0;
	for(int i = -1;i <= 1; i++)
	{
		for(int j = -1;j <= 1; j++)
		{
			if(posx+i >= 0 && posx+i < R && posy+j >=0 && posy+j < C)
			{
				if(matrix[posx+i][posy+j] == true && visited[posx+i][posy+j] == false)
				{
					length = max(length,longest_path(posx+i,posy+j,visited));
				}
			}
		}
	}
	return 1+length;
}
int main()
{
	for(int i = 0;i < R; i++)
		for(int j = 0;j < C; j++)
			cin>>matrix[i][j];

	bool visited[R][C];
	memset(visited,false,sizeof(visited));

	cout<<"longest path = "<<longest_path(0,0,visited)<<endl;
	return 0;
}