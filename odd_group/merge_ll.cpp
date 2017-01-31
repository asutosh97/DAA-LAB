#include <iostream>
#include <cstdlib>
#include <climits>
struct node
{
	int data;
	struct node *next;
};
struct node * getnode(int data)
{
	struct node *nw = (struct node *)malloc(sizeof(struct node));
	nw->data = data;
	nw->next = NULL;
	return nw;
}
struct node * insert(struct node *tail,int data)
{
	struct node *temp = getnode(data);
	tail->next = temp;
	return temp;
}
void traverse(struct node *head)
{
	struct node *temp = head->next;
	while(temp)
	{
		std::cout<<temp->data<<" ";
		temp = temp->next;
	}
	std::cout<<std::endl;
}
struct node * merge_lists(struct node *head1, struct node *head2)
{
	struct node *head3 = getnode(0);
	struct node *temp1 = head1->next;
	struct node *temp2 = head2->next;
	struct node *tail3 = head3;
	std::cout<<"Entering loop "<<std::endl;
	while(!(temp1->data == INT_MAX && temp2->data == INT_MAX))
		if(temp1->data < temp2->data)
		{
			tail3 = insert(tail3, temp1->data);
			temp1 = temp1->next;
		}
		else
		{
			tail3 = insert(tail3, temp2->data);
			temp2 = temp2->next;
		}
	std::cout<<"Exiting loop "<<std::endl;
	return head3;
}
int main()
{
	int n1,item;
	struct node *head1 = getnode(0);
	struct node *tail1 = head1;
	std::cout<<"Enter the number of elements in the 1st linked list : ";
	std::cin>>n1;
	std::cout<<"Enter the elements of the 1st linked list : ";
	for(int i = 0;i < n1; i++)
	{
		std::cin>>item;
		tail1 = insert(tail1, item);
	}
	tail1 = insert(tail1, INT_MAX);
	int n2;
	struct node *head2 = getnode(0);
	struct node *tail2 = head2;
	std::cout<<"Enter the number of elements in the 2nd linked list : ";
	std::cin>>n2;
	std::cout<<"Enter the elements of the 2nd linked list : ";
	for(int i = 0;i < n2; i++)
	{
		std::cin>>item;
		tail2 = insert(tail2, item);
	}
	tail2 = insert(tail2, INT_MAX);
	std::cout<<"Insertion completed"<<std::endl;
	struct node *head3 = merge_lists(head1, head2);
/*	empty_list(head1);
	empty_list(head2);*/
	std::cout<<"The merged linked list is : ";
	traverse(head3);
	return 0;
}