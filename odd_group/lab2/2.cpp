// Asutosh Sahoo
// B115017
// CSE 4th Sem
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node * getnode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
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
int height(struct node *curr)
{
	if(!curr)
		return 0;
	return 1+max(height(curr->left),height(curr->right));
}
void traverseLevel(struct node *curr,int level,bool ltr)
{
	if(!curr)
		return;
	if(level == 1)
		cout<<curr->data<<" ";
	else
	{
		if(ltr)
		{
			traverseLevel(curr->left,level - 1,ltr);
			traverseLevel(curr->right,level - 1,ltr);
		}
		else
		{
			traverseLevel(curr->right,level - 1,ltr);
			traverseLevel(curr->left,level - 1,ltr);
		}
	}
}
void spiralTraverse(struct node *head)
{
	bool ltr = false;
	int H = height(head);
	for(int i = 1;i <= H; i++)
	{
		traverseLevel(head,i,ltr);
		ltr = !ltr;
	}
	cout<<endl;
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
	spiralTraverse(head);
	return 0;
}