#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
int main() {
   while(1)
   {
      struct node *nw = (struct node*)malloc(sizeof(struct node));
      cout << "\n Enter data to be inserted:";
      int data;
      cin >> data;
      if(data < 0)
        break;
      nw->data = data;
      if(start == NULL)
      {
        start = nw;
        nw->next = NULL;
      }
      else
      {
          nw->next = start;
          start = nw;
      }
   }
   cout << "\n Traversing:";
   struct node *temp = start;
   while(temp!=NULL)
   {
        cout << temp->data << "\t";
        temp = temp->next;
   }
   return 0;
}
