/*
Insert in a binary tree and in order traversal
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* createNode(int data)
{
    struct node* nw = (struct node*)malloc(sizeof(struct node));
    nw->data = data;
    nw->left = NULL;
    nw->right = NULL;
    return nw;
}

struct node* insertIntoBST(struct node *root,int data)
{
    struct node * temp = createNode(data); 
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
         if(root->data >= temp->data)
         {  
            if(root->left == NULL)
             {
                root->left = temp;
             }
             else
                insertIntoBST(root->left,temp->data);
         }
         if(root->data < temp->data)
         {
            if(root->right == NULL)
             {
                root->right = temp;
             }
            else
                insertIntoBST(root->right,temp->data);
         }
    }
    return root;
}

void inorderTraversal(struct node * root)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node * root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node *root)
{
    if(root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}
int main() 
{
    int choice,data;
    while(1)
    {
        printf("BST OPERATIONS\n");
        printf("1.Insert\n");
        printf("2.Inorder Traversal\n");
        printf("3.Preorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Exit\n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter the data to be inserted:");
                    scanf("%d",&data);
                    root = insertIntoBST(root,data);
                    break;
            case 2:
                    inorderTraversal(root);
                    break;
            case 3:
                    preorderTraversal(root);
                    break;
            case 4:
                    postorderTraversal(root);
                    break;
            case 5:
                    exit(0);
            default:
                    printf("Enter valid choice.");                    
        }
    }
    return 0;
}
