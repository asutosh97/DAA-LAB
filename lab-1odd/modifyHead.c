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
        printf("\n Can't traverse an empty linked list.");
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
int main() {
   int choice,data;
   struct node *start = NULL;
   while(1)
   {
      printf("\n\t\t MODIFY HEAD PROGRAM \n\t\t 1.Insert at the beginning \n\t\t 2.Delete from beginning \n\t\t 3.Traverse \n\t\t 4.Exit");
      printf("\n Your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
                printf("\n Enter the data:");
                scanf("%d",&data);
                start = insertAtBeginning(start,data);
                break;
        case 2:
                if(start == NULL)
                    printf("\n Linked List is already empty.");
                else
                 start = delBeg(start);
                break;
        case 3:
                traverse(start);
                break;
        case 4:
                exit(0);
        default:
                printf("\n No options available!!!");
      }
   }
   free(start);
   return 0;
}

