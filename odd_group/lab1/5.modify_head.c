/*
modify head
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * insertAtBeginning(struct node * start,int data)
{
    struct node *nw = (struct node*)malloc(sizeof(struct node));
    nw->data = data;
    nw->next = NULL;
    
    if(start == NULL)
        start = nw;
    else
    {
        nw->next = start;
        start = nw;
    }
    return start;
}
void traverse(struct node *start)
{
    struct node *temp = start;
    if(start == NULL)
        printf("Can't traverse an empty linked list\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data) ;
        temp = temp->next;
   }
   free(temp);
}

struct node * delBeg(struct node *start) 
{
    if(start->next == NULL)
        start = NULL;
    else
        start = start->next;
        
     return start;
}
int main() 
{
   int choice,data;
   struct node *start = NULL;
   while(1)
   {
      printf("\n");
      printf("Modify Head Program\n");
      printf("1.Insert at the beginning\n");
      printf("2.Delete from beginning\n");
      printf("3.Traverse\n");
      printf("4.Exit\n");
      printf("Your choice:\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
                printf("Enter the data:\n");
                scanf("%d",&data);
                start = insertAtBeginning(start,data);
                break;
        case 2:
                if(start == NULL)
                    printf("Linked List is already empty.\n");
                else
                 start = delBeg(start);
                break;
        case 3:
                traverse(start);
                break;
        case 4:
                exit(0);
        default:
                printf("No options available!!!\n");
      }
   }
   free(start);
   return 0;
}

