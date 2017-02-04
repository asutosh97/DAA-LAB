/*
1. Write an algorithm and a program using recursion to construct a balanced binary search tree from a sorted array of node values. Analyze the complexity of your algorithm.
*/

#include <iostream>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node * getnode(int data)
{
	struct node *nw = new struct node;
	nw->data = data;
	nw->left = NULL;
	nw->right = NULL;
	return nw;
}
struct node * BSTForm(int arr[], int beg, int end)
{
	if(beg >= end)
		return NULL;

	int mid = (beg + end) / 2;
	struct node *nw = getnode(arr[mid]);
	nw->left = BSTForm(arr, beg, mid);
	nw->right = BSTForm(arr, mid+1, end);
	return nw;
}
void inorder(struct node *curr)
{
	if(!curr)
		return;
	inorder(curr->left);
	std::cout<<curr->data<<" ";
	inorder(curr->right);
}
int main()
{
	int size;
	std::cout<<"Enter the size of the array : ";
	std::cin>>size;
	int arr[size];
	std::cout<<"Enter the elements in sorted order : ";
	for(int i = 0; i < size; i++)
		std::cin>>arr[i];
	struct node *head = BSTForm(arr,0,size);
	std::cout<<"The inorder traversal of the BST is : ";
	inorder(head);
	std::cout<<std::endl;
	return 0;
}