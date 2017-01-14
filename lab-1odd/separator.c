//separate odd & even & put evens first then odd.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int size,i,j,k=0;
    printf("\n Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    printf("\n Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[j]%2 ==0 && arr[i]%2 !=0)
            {
                swap(&arr[i],&arr[j]);
                i++;
            }
        }  
    }
    
     for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
