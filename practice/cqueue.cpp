#include <iostream>
using namespace std;

void insert(int cqueue[],int *front,int *rear,int size,int item)
{
	/* check if the queue is full, then insert */
	if((*rear+1) % size == *front)
	{
		cout<<"overflow"<<endl;
		return;
	}
	*rear = (*rear + 1) % size;
	cqueue[*rear] = item;
}
void remove(int cqueue[],int *front,int *rear,int size)
{
	if(*rear == *front)
	{
		cout<<"underflow"<<endl;
		return;
	}
	*front = (*front + 1) % size;
}
void traverse(int cqueue[],int *front,int *rear,int size)
{
	if(*rear == *front)
	{
		cout<<"empty queue"<<endl;
		return;
	}
	for(int i = *front;i != *rear; i = (i + 1) % size)
		cout<<cqueue[(i+1) % size]<<" ";
	cout<<endl;
}
int main()
{
	int size;
	cout<<"Enter the size of the circular queue : ";
	cin>>size;
	size++;
	int cqueue[size],f,r;
	f = r = 0;
	while(1)
	{
		int ch,x;
		cout<<"1.Insert\n2.Delete\n3.Traverse\n4.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the number to be inserted : ";
				cin>>x;
				insert(cqueue,&f,&r,size,x);
				break;
			case 2:
				remove(cqueue,&f,&r,size);
				break;
			case 3:
				traverse(cqueue,&f,&r,size);
				break;
			case 4:
				return 0;
			default:
				cout<<"invalid input.. try again"<<endl;
		}
	}
}