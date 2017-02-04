/*
The vertices of an N-vertex undirected weighted graphs are labeled as . There is an edge between two vertices and  iff . In that case the weight of the corresponding edge is assigned to . Write an algorithm to find the minimum-weighted shortest (minimum-jump) path between any two vertices in such a graph. (Hint: Use dynamic programming approach to find a solution)
*/

#include <iostream>
#include <cstring>
#include <climits>
int main()
{
	int nodes;
	std::cout<<"Enter the number of nodes : ";
	std::cin>>nodes;

	int jumpsAvailable[nodes+1];
	for(int i = 1;i <= nodes; i++)
		jumpsAvailable[i] = 2;

	int numberOfJumps[nodes];
	for(int i = 1;i <= nodes; i++)
		numberOfJumps[i] = INT_MAX;

	int x0,y0;
	std::cout<<"Enter the vertices : ";
	std::cin>>x0>>y0;
	
	if(x0>y0)
		std::swap(x0,y0);

	numberOfJumps[x0] = 0;

	for(int i = x0 + 1; i <= y0; i++)
	{
		for(int j = x0;j < i; j++)
		{
			if(i <= j + jumpsAvailable[j] && 1 + numberOfJumps[j] < numberOfJumps[i])
			{
				numberOfJumps[i] = 1 + numberOfJumps[j];
			}
		}
	}

	std::cout<<"The minimum number of jumps to travel from "<<x0<<" to "<<y0<<" is "<<numberOfJumps[y0]<<std::endl;
	return 0;
}