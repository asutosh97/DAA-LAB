#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *prev;
	struct node  *next;
};
struct node  *head = NULL;
struct node  *tail = NULL;
struct node * getnode(int data)
{
	struct node *nw = new struct node;
	nw->data = data;
	nw->prev = NULL;
	nw->next = NULL;
	return nw;
}
void binsert(int data)
{
	struct node *temp = getnode(data);
	if(head == NULL)
	{
		head = tail = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}
void einsert(int data)
{
	struct node *temp = getnode(data);
	if(tail == NULL)
	{
		head = tail = temp;
		return;
	}
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
}
void btraverse()
{
	struct node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void etraverse()
{
	struct node *temp = tail;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}
void bdelete()
{
	if(head == NULL)
	{
		cout<<"empty list"<<endl;
		return;
	}
	struct node *temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}
void edelete()
{
	if(tail == NULL)
	{
		cout<<"empty list"<<endl;
		return;
	}
	struct node *temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete temp;
}
int main()
{
	while(1)
	{
		cout<<"1.Insert at beginning"<<endl;
		cout<<"2.Insert at the end"<<endl;
		cout<<"3.Delete from beginning"<<endl;
		cout<<"4.Delete from end"<<endl;
		cout<<"5.Traverse"<<endl;
		cout<<"6.Reverse traverse"<<endl;
		cout<<"7.Exit"<<endl;
		int ch,x;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the element to insert : ";
				cin>>x;
				binsert(x);
				break;
			case 2:
				cout<<"Enter the element to insert : ";
				cin>>x;
				einsert(x);
				break;
			case 3:
				bdelete();
				break;
			case 4:
				edelete();
				break;
			case 5:
				btraverse();
				break;
			case 6:
				etraverse();
				break;
			case 7:
				return 0;
			default:
				cout<<"invalid input.. try again "<<endl;
		}
	}
}