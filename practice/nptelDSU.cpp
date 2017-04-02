#include <iostream>
#include <vector>
struct node
{
	char name;
	node * label;
	node(int x)
	{
		name = x;
		label = this;
	}
};

struct store
{
	node * nodes;
	node * root;
	int size;
};

void MAKESET(std::vector<store> &DSU, char x)
{
	// if character x is already present, don't insert again
	if(FINDSET(DSU, x) != -1)
		return;
	struct store temp;
	temp.nodes = temp.root = new node(x);
	temp.size = 1;
	DSU.push_back(temp); 
}
int FINDNODE(std::vector<store> &DSU, char a)
{
	for(int i = 0;i < DSU.size(); i++)
		if(DSU[i].nodes->name == a)
			return i;
	return -1;
}
int FINDSET(std::vector<store> &DSU, char a)
{
	node * location = NULL;
	int index = FINDNODE(DSU, a);
	if(index != -1)
		location = DSU[index].nodes;

	if(location)
	{
		node * startLocation = location;
		while(location->label != location)
			location = location->label;

		while(startLocation != location)
		{
			node * temp = startLocation->label;
			startLocation->label = location;
			startLocation = temp;
		}
		return FINDNODE(DSU, location->name);
	}
	return -1;
}
void UNION(std::vector<store> &DSU, char a, char b)
{
	// if both belong to same set, just return
	int rootA = FINDSET(DSU, a);
	int rootB = FINDSET(DSU, b);

	if(rootA == rootB)
		return;

	else if(DSU[rootA].size < DSU[rootB].size)
	{
		DSU[rootA].nodes->label = DSU[rootB].nodes;
		DSU[rootB].size = DSU[rootB].size + DSU[rootA].size;
		DSU[rootA].size = 0;
		DSU[rootA].root = NULL;
	}
	else
	{
		DSU[rootB].nodes->label = DSU[rootA].nodes;
		DSU[rootA].size = DSU[rootA].size + DSU[rootB].size;
		DSU[rootB].size = 0;
		DSU[rootB].root = NULL;
	}
}
int main()
{
	std::vector<store> DSU;
	while(1)
	{
		char x,a,b;
		int ch;
		std::cout<<"1.MAKESET(x)"<<std::endl;
		std::cout<<"2.UNION(a, b)"<<std::endl;
		std::cout<<"3.FINDSET(a)"<<std::endl;
		std::cout<<"4.Exit"<<std::endl;
		std::cin>>ch;
		int index;
		switch(ch)
		{
			case 1:
				std::cout<<"Enter the value of x : ";
				std::cin>>x;
				MAKESET(DSU, x);
				break;
			case 2:
				std::cout<<"Enter the value of a and b : ";
				std::cin>>a>>b;
				UNION(DSU, a, b);
				break;
			case 3:
				std::cout<<"Enter the value of a : ";
				std::cin>>a;
				index = FINDSET(DSU, a);
				if(index != -1)
					std::cout<<a<<" belongs to "<<DSU[index].nodes->name<<std::endl;
				break;
			case 4:
				return 0;
			default:
				std::cout<<"Try again!!!"<<std::endl;
		}
	}
}