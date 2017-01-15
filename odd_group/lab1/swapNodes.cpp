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
struct node * searchNode(struct node *head,int data)
{
	struct node *temp = head;
	while(temp->next)
	{
		if(temp->next->data == data)
			return temp;
		temp = temp->next;
	}
	return NULL;
}
void swapValues(struct node * *a,struct node * *b)
{
	struct node *temp = *a;
	*a = *b;
	*b = temp;
}
bool swapNodes(struct node *head,int x,int y)
{
	struct node *parent1 = searchNode(head,x);
	struct node *parent2 = searchNode(head,y);
	if(!parent1 || !parent2)
		return false;

	struct node *child1 = parent1->next;
	struct node *child2 = parent2->next;
	swapValues(&parent1->next,&parent2->next);
	swapValues(&child1->next,&child2->next);
	return true;
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
				cout<<"Enter the value of nodes to be swapped : ";
				cin>>x>>y;
				status = swapNodes(head,x,y);
				if(status)
					cout<<"succesfully swapped nodes"<<endl;
				else
					cout<<"values not found in the list"<<endl;
				break;
			case 4:
				return 0;
			default:
				cout<<"try again ..."<<endl;
		}
	}
}