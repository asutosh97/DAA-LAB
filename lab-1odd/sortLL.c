//wap to sort a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start =NULL;
struct node *current = NULL;

struct node * insert(int data)
{
    struct node *nw = (struct node*)malloc(sizeof(struct node));
    nw->data = data;
    nw->next = NULL;

    if(start == NULL)
    {
        start = nw;
        current = nw;
    }
    else
    {
        current->next = nw;
        current = nw;
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

void sort()
{
    int a;
    struct node *temp;
    struct node *temp2;
    for(temp = start;temp!=NULL;temp = temp->next)
    {
        for(temp2 = temp->next;temp2!=NULL;temp2=temp2->next)
        {
            if(temp->data > temp2->data)
            {
                a = temp->data;
                temp->data = temp2->data;
                temp2->data = a;
            }
        }
    }
    
    free(temp);
    free(temp2);
}

int main() {
   int choice,data;
   while(1)
   {
      printf("\n\t\t SORT LINKED LIST PROGRAM \n\t\t 1.Insert\n\t\t 2.Sort the linked list \n\t\t 3.Traverse \n\t\t 4.Exit");
      printf("\n Your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
                printf("\n Enter the data:");
                scanf("%d",&data);
                start = insert(data);
                break;
        case 2:
                sort();
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
   free(current);
   return 0;
}

