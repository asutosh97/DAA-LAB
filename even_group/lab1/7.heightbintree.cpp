/*
height of a binary tree
*/
#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *lptr;
	struct node *rptr;
};
struct node * createnode(int item)
{
	struct node *newnode = new struct node;
	newnode->data = item;
	newnode->lptr = NULL;
	newnode->rptr = NULL;
	return newnode;
}
struct node * binary_insert(struct node *currrent,int position,int *arr,int n)
{
	if(position >= n)
		return NULL;

	currrent = createnode(arr[position]);
	currrent->lptr = binary_insert(currrent->lptr,2*position+1,arr,n);
	currrent->rptr = binary_insert(currrent->rptr,2*position+2,arr,n);
	return currrent;
}
int height(struct node *current)
{
	if(!current)
		return 0;
	return 1+max(height(current->lptr),height(current->rptr));
}
int main()
{
    int n,i,ch;
	std::cout<<"Enter the number of elements to be inserted : "<<std::endl;
	std::cin>>n;
	int a[n];
	for(i= 0;i < n; i++)
		std::cin>>a[i];
	struct node *head = NULL;
	head = binary_insert(head,0,a,n);
	std::cout<<"height of binary tree: "<<height(head)<<std::endl;
}
