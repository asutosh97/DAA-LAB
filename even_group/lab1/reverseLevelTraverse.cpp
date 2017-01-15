#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
	struct node *left;
	struct node *right;
	int data;
};

struct node * getnode(int data)
{
	struct node *nw = (struct node *)malloc(sizeof(struct node));
	nw->data = data;
	nw->left = nw->right = NULL;
	return nw;
}
int treeHeight(struct node *curr)
{
	if(!curr)
		return 0;
	return 1 + max(treeHeight(curr->left),treeHeight(curr->right));
}
void printGivenLevel(struct node *curr,int level)
{
	if(!curr)
		return;
	else if(level == 1)
		cout<<curr->data<<" ";
	else
	{
		printGivenLevel(curr->right,level-1);
		printGivenLevel(curr->left,level-1);
	}
}
void reverseLevelTraverse(struct node *head)
{
	int H = treeHeight(head);
	for(int i = H;i >= 1;i--)
		printGivenLevel(head,i);
	cout<<endl;
}
struct node * heapInsert(struct node *curr,int position,int *arr,int size)
{
	if(position >= size)
		return NULL;

	curr = getnode(arr[position]);
	curr->left = heapInsert(curr->left,2*position+1,arr,size);
	curr->right = heapInsert(curr->right,2*position+2,arr,size);
	return curr;
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
	head = heapInsert(head,0,a,n);
	reverseLevelTraverse(head);
}