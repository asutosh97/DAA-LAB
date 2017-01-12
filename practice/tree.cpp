#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *parent;
	struct node *left;
	struct node *right;
};
struct node * getnode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->parent = NULL;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * heap_insert(struct node *curr,int position,int *arr,int size)
{
	if(position >= size)
		return NULL;

	curr = getnode(arr[position]);
	curr->left = heap_insert(curr->left,2*position+1,arr,size);
	curr->right = heap_insert(curr->right,2*position+2,arr,size);
	return curr;
}
void preorder(struct node *curr)
{
	if(curr)
	{
		cout<<curr->data<<" ";
		preorder(curr->left);
		preorder(curr->right);
	}
}

int completeNodes(struct node *curr)
{
	if(!curr)
		return 0; 
	return (completeNodes(curr->left) + completeNodes(curr->right) + ((curr->left && curr->right)?1:0) );
}
int leaveNodes(struct node * curr)
{
	if(!curr)
		return 0;
	else if(!curr->left && !curr->right)
		return 1;
	else
		return leaveNodes(curr->left) + leaveNodes(curr->right);
}
int height(struct node *curr)
{
	if(!curr)
		return 0;
	return 1+max(height(curr->left),height(curr->right));
}
void printGivenLevel(struct node *curr,int level,bool ltr)
{
	if(!curr)
		return;
	if(level == 1)
		cout<<curr->data<<" ";
	else
	{
		if(ltr)
		{
			printGivenLevel(curr->left,level - 1,ltr);
			printGivenLevel(curr->right,level - 1,ltr);
		}
		else
		{
			printGivenLevel(curr->right,level - 1,ltr);
			printGivenLevel(curr->left,level - 1,ltr);
		}
	}
}
void spiralTraverse(struct node *head)
{
	bool ltr = false;
	int H = height(head);
	for(int i = 1;i <= H; i++)
	{
		printGivenLevel(head,i,ltr);
		ltr = !ltr;
	}
	cout<<endl;
}
int totalNodes(struct node *curr)
{
	if(!curr)
		return 0;
	return 1+totalNodes(curr->left)+totalNodes(curr->right);
}
int main()
{
	int n;
	cout<<"Enter the number of elements to be inserted : ";
	cin>>n;
	int a[n];
	for(int i = 0;i < n; i++)
		cin>>a[i];
	struct node *head = NULL;
	head = heap_insert(head,0,a,n);
	cout<<"Number of complete nodes = "<<completeNodes(head)<<endl;
	cout<<"Number of leaves = "<<leaveNodes(head)<<endl;
	cout<<"Height of tree = "<<height(head)<<endl;
	cout<<"Total number of nodes = "<<totalNodes(head)<<endl;
	spiralTraverse(head);
	return 0;
}