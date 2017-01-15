#include <iostream>
#include <cstdlib>
using namespace std;

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
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
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
		cout<<"1.Insert"<<endl;
		cout<<"2.Traverse"<<endl;
		cout<<"3.Swap Nodes"<<endl;
		cout<<"4.Exit"<<endl;
		int ch,x,y;
		bool status;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the value to be inserted : ";
				cin>>x;
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
				cout<<"try again ..."<<endl;
		}
	}
}