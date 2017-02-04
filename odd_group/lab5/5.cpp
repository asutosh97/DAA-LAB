/*
The vertices of an N-vertex undirected weighted graphs are labeled as . 
There is an edge between two vertices and  iff . In that case the weight of the corresponding edge is assigned to . Write an algorithm to find the minimum-weighted shortest (minimum-jump) path between any two vertices in such a graph. (Hint: Use dynamic programming approach to find a solution)
*/

#include <iostream>
#include <cstring>
int minimum_jump(int x,int y)
{
	if(x > y)
		std::swap(x,y);
	return (y - x) / 2 + (y - x) % 2;
}
int main()
{
	int n;
	std::cout<<"Enter the number of nodes : ";
	std::cin>>n;
	int arr[n][n];
	for(int i = 0;i < n; i++)
		for(int j = 0;j < n; j++)
			arr[i][j] = minimum_jump(i,j);

	while(1)
	{
		std::cout<<"Distance Calculation Menu : "<<std::endl;
		std::cout<<"1.Calculate Distance"<<std::endl;
		std::cout<<"2.Exit"<<std::endl;
		int ch;
		int x0,y0;
		std::cin>>ch;
		switch(ch)
		{
			case 1:
				std::cout<<"Enter the edges (x,y) : ";
				std::cin>>x0>>y0;
				std::cout<<arr[x0-1][y0-1]<<std::endl;
				break;
			case 2:
				return 0;

			default:
				std::cout<<"invalid input.. try again !!!"<<std::endl;
		}
	}
}