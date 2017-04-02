#include <iostream>
#include <queue>
struct elements
{
	int freq;
	std::string name;
};

struct node
{
	std::string name;
	int freq;
	struct node * left;
	struct node * right;
	node(std::string name, int freq)
	{
		this->name = name;
		this->freq = freq;
		this->left = this->right = NULL;
	}
};

struct compare
{
	bool operator()(node * l, node * r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(node *curr, std::string str)
{
	if(!curr)
		return;
	else if(!curr->left && !curr->right)
		std::cout<<curr->name<<" : "<<str<<std::endl;
	else
	{
		printCodes(curr->left, str+"0");
		printCodes(curr->right, str+"1");
	}
}
void huffmanCodes(std::vector<elements> v)
{
	std::priority_queue<node*, std::vector<node*>, compare> minHeap;
	// create heap
	for(int i = 0;i < v.size(); i++)
		minHeap.push(new node(v[i].name, v[i].freq));

	while(minHeap.size() != 1)
	{
		struct node * left = minHeap.top();
		minHeap.pop();
		struct node * right = minHeap.top();
		minHeap.pop();
		struct node *top = new node("$", left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	printCodes(minHeap.top(),"");
}
int main()
{
	int n;
	std::cout<<"Enter the number of characters : ";
	std::cin>>n;
	std::vector<elements> v(n);
	for(int i = 0;i < n; i++)
	{
    	std::cout<<"Enter the details of the "<<i+1<<"th element"<<std::endl;
	    std::cout<<"Enter name : ";
	    std::cin>>v[i].name;
	    std::cout<<"Enter frequency : ";
	    std::cin>>v[i].freq;
	}
	huffmanCodes(v);
	return 0;
}