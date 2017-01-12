// Asutosh Sahoo
// B115017
// CSE 4th Sem
#include <iostream>
using namespace std;
struct node{
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
int completeNodes(struct node *curr)
{
	if(!curr)
		return 0; 
	return (completeNodes(curr->left) + completeNodes(curr->right) + ((curr->left && curr->right)?1:0) );
}
int totalNodes(struct node *curr)
{
	if(!curr)
		return 0;
	return 1+totalNodes(curr->left)+totalNodes(curr->right);
}
bool printNodeAncestors(struct node *curr,int value)
{
	if(!curr)
		return false;
	else if(curr->data == value)
		return true;

	if(printNodeAncestors(curr->left,value) || printNodeAncestors(curr->right,value))
	{
		cout<<curr->data<<" ";
		return true;
	}
	else
		return false;
}
struct node * searchNode(struct node *curr,int value)
{
	if(!curr)
		return NULL;
	else if(curr->data == value)
		return curr;
	else 
	{
		struct node *temp1 = searchNode(curr->left,value); 
		struct node *temp2 = searchNode(curr->right,value);
		if(temp1)
			return temp1;
		else if(temp2)
			return temp2;
		else
			return NULL;
	}
}
int childNodes(struct node *head,int value)
{
	struct node * curr = searchNode(head,value);
	if(!curr)
		return -1;
	else
		return totalNodes(curr) - 1;
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
	cout<<"Number of complete nodes = "<<completeNodes(head)<<endl;
	cout<<"Enter the value of the node of which you want to see the ancestors : ";
	int value;
	cin>>value;
	printNodeAncestors(head,value);
	cout<<endl;
	cout<<"Enter the node whose number of childs you want to count : ";
	cin>>value;
	cout<<"Childs of the node = "<<childNodes(head,value)<<endl;
	return 0;
}