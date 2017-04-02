#define ll long long
#include <iostream>
struct character
{
    char symbol;
    ll frequency;
    std::string code;
};

struct node
{
    character *data;
    struct node *left;
    struct node *right;
};
struct node * getnode(character *data)
{
    struct node *nw = new struct node;
    nw->data = data;
    nw->left = NULL;
    nw->right = NULL;
    return nw;
}
void preorder(struct node *curr, std::string X)
{
    if(!curr)
        return;
    if(curr->left == NULL && curr->right == NULL)
    {
        curr->data->code = X;
        std::cout<<"The huffman code of "<<curr->data->symbol<<" is "<<curr->data->code<<std::endl;
    }
    preorder(curr->left, X + '0');
    preorder(curr->right, X + '1');

}

int partition(struct node *arr[], int beg, int end)
{
    struct node *x = arr[end - 1];
    int i = beg - 1;
    for(int j = beg; j < end - 1; j++)
    {
        if(arr[j]->data->frequency < x->data->frequency)
            std::swap(arr[++i], arr[j]);
    }
    std::swap(arr[++i], arr[end - 1]);
    return i;
}

void quick_sort(struct node *arr[], int beg, int end)
{
    if(end - beg <= 1)
        return;
    int q = partition(arr, beg, end);
    quick_sort(arr, beg, q);
    quick_sort(arr, q+1, end);
}
character arr[100];
int main()
{
    int noOfCharacters;
    std::cout<<"Enter the number of characters : ";
    std::cin>>noOfCharacters;
//    character arr[noOfCharacters];
    for(int i = 0;i < noOfCharacters; i++)
    {
        std::cout<<"Enter the details of character "<<i+1<<":"<<std::endl;
        std::cout<<"Enter symbol : ";
        std::cin>>arr[i].symbol;
        std::cout<<"Enter frequency : ";
        std::cin>>arr[i].frequency;
    }

    // processing
    struct node *narr[noOfCharacters];
    for(int i = 0;i < noOfCharacters; i++)
        narr[i] = getnode(&arr[i]);

  
    for(int i = 0;i < noOfCharacters - 1; i++)
    {
        quick_sort(narr, i, noOfCharacters);
        std::cout<<"Before: The character symbols along with their frequencies are : "<<std::endl;
        for(int j = i;j < noOfCharacters; j++)
            std::cout<<"index = "<<j<<"\taddress = "<<narr[j]<<"\tsymbol : "<<narr[j]->data->symbol<<"\tfrequency : "<<narr[j]->data->frequency<<std::endl;
        character temp;
        temp.symbol = '?';
        std::cout<<"before assigning, "<<narr[i+2]->data->frequency<<std::endl;
        temp.frequency = narr[i]->data->frequency + narr[i+1]->data->frequency;
        std::cout<<"after assigning, "<<narr[i+2]->data->frequency<<std::endl;
        struct node *nw = getnode(&temp);
        nw->left = narr[i];
        nw->right = narr[i+1];
        narr[i+1] = nw;
        /*std::cout<<"After: The character symbols along with their frequencies are : "<<std::endl;
        for(int j = i+1;j < noOfCharacters; j++)
            std::cout<<"index = "<<j<<"\taddress = "<<narr[j]<<"\tsymbol : "<<narr[j]->data->symbol<<"\tfrequency : "<<narr[j]->data->frequency<<std::endl;
        */

    }
 /*   struct node *root = narr[noOfCharacters - 1];
    preorder(root, "");
    std::cout<<"The huffman codes of the characters are : "<<std::endl;
    for(int i = 0;i < noOfCharacters; i++)
        std::cout<<"symbol : "<<arr[i].symbol<<"\thuffman_code : "<<arr[i].code<<std::endl;
    return 0;
    */
}
