// Asutosh Sahoo
// B115017
// CSE 4th Sem
/*
Q3.find the length of connected cells of 1s(regions) in an matrix of 0s and 1s: Given a matrix each of which may be 1 or 0 the filled cells that are connected from a regions. two cells are said to be connected if they are adjecent to each other horizontally, vertically or diagonally.find the largest region in terms of cells.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#define R 5
#define C 5
bool matrix[R][C];
int longest_path(int posx,int posy,bool visited[][C])
{
	visited[posx][posy] = true;
	int length = 0;
	for(int i = -1;i <= 1; i++)
		for(int j = -1;j <= 1; j++)
			if(posx+i >= 0 && posx+i < R && posy+j >=0 && posy+j < C)
				if(matrix[posx+i][posy+j] == true && visited[posx+i][posy+j] == false)
					length = std::max(length,longest_path(posx+i,posy+j,visited));
	return 1+length;
}
int main()
{
	std::cout<<"Enter the elements(1-0) of 5x5 matrix : "<<std::endl;
	for(int i = 0;i < R; i++)
		for(int j = 0;j < C; j++)
			std::cin>>matrix[i][j];

	bool visited[R][C];
	int largest = 0;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			memset(visited,false,sizeof(visited));
			largest = std::max(largest,longest_path(i,j,visited));		
		}
	}
	std::cout<<"largest connected section = "<<largest<<std::endl;
	return 0;
}