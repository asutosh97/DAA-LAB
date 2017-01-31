/*
swap elements in pairs
*/

#include <iostream>
#include <cstdlib>

struct node{
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
void swapValues(struct node * *a,struct node * *b)
{
	struct node *temp = *a;
	*a = *b;
	*b = temp;
}
void swapPairs(struct node *head)
{
	struct node *ptr = head;
	while(ptr->next && ptr->next->next)
	{
		struct node *parent1 = ptr;
		struct node *parent2 = ptr->next;

		struct node *child1 = parent1->next;
		struct node *child2 = parent2->next;
		
		swapValues(&parent1->next,&parent2->next);
		swapValues(&child1->next,&child2->next);

		ptr = ptr->next->next;
	}
}
int main()
{
	struct node *head = getnode(0);
	struct node *tail = head;
	while(1)
	{
		std::cout<<"1.Insert"<<std::endl;
		std::cout<<"2.Traverse"<<std::endl;
		std::cout<<"3.Swap Nodes"<<std::endl;
		std::cout<<"4.Exit"<<std::endl;
		int ch,x,y;
		bool status;
		std::cin>>ch;
		switch(ch)
		{
			case 1:
				std::cout<<"Enter the value to be inserted : ";
				std::cin>>x;
				tail = insert(tail,x);
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				swapPairs(head);
				break;
			case 4:
				return 0;
			default:
				std::cout<<"try again ..."<<std::endl;
		}
	}
}