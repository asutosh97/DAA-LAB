//B115045 RITESH KUMAR MOHAPATRA
//INSERT A NODE IN THE MIDDLE
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void insertb()
{
    int item;
    cout<<"enter data"<<endl;
    cin>>item;
    struct node *newnode = new struct node;
    newnode->data=item;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *ptr;
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newnode;
    }
}
void insertm()
{
    int item;
    cout<<"enter data"<<endl;
    cin>>item;
    struct node *newnode = new struct node;
    newnode->data=item;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        int c=0;
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->link;
        }
        ptr=head;
        c=(c/2)-1;
        while(c!=0)
        {
            ptr=ptr->link;
        }
        newnode->link=ptr->link;
        ptr->link=newnode;
    }
}
void traverse()
{
    cout<<"llelments in the linked list:"<<endl;
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    cout<<endl;
}
int main()
{
    int ch;
    while(1)
    {
        cout<<"1. to enter new node"<<endl;
        cout<<"2. to enter new node at middle"<<endl;
        cout<<"3. to traverse"<<endl;
        cout<<"4 tO exit"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: insertb();
                    break;
            case 2: insertm();
                    break;
            case 3: traverse();
                    break;
            default: exit(0);
                    break;
        }
    }
}
