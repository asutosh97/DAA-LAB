/*
insert node in the middle of linked list
*/
#include <iostream>
#include <cstdlib>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void insertb()
{
    int item;
    std::cout<<"enter data"<<std::endl;
    std::cin>>item;
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
    std::cout<<"enter data"<<std::endl;
    std::cin>>item;
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
    std::cout<<"llelments in the linked list:"<<std::endl;
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        std::cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    std::cout<<std::endl;
}
int main()
{
    int ch;
    while(1)
    {
        std::cout<<"1. to enter new node"<<std::endl;
        std::cout<<"2. to enter new node at middle"<<std::endl;
        std::cout<<"3. to traverse"<<std::endl;
        std::cout<<"4 tO exit"<<std::endl;
        std::cout<<"enter your choice"<<std::endl;
        std::cin>>ch;
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
