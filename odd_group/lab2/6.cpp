#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

struct node * insertBST(struct node *root,int data)
{
    if(root==0)
    {
        root=new struct node;
        root->data=data;
        root->left=0;
        root->right=0;
    }
    else if(data > root->data)
        root->right = insertBST(root->right,data);
    else
        root->left = insertBST(root->left,data);
    return root;
}
int count = 0;
void inorderTraverse(struct node *root,int arr[])
{
    if(root!=0)
    {
        inorderTraverse(root->left,arr);
        arr[count++]=root->data;
        inorderTraverse(root->right,arr);
    }
}
int main()
{
    int n;
    std::cout<<"Enter the value of n : ";
    std::cin>>n;
    int arr[n];
    node *root=0;
    while(n--)
    {
        int num;
        std::cin>>num;
        root = insertBST(root,num);
    }
    inorderTraverse(root,arr);
    int k;
    std::cout<<"Enter the value of k is : ";
    std::cin>>k;
    std::cout<<k<<" th smallest element is : "<<arr[k-1]<<std::endl;
    return 0;
}
