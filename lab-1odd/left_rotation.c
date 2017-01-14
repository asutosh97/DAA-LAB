//Program to rotate an array anticlockwise
#include <stdio.h>

int main() {
    int size,i,no_of_rotation;
    
    printf("\n Enter the size of the array:");
    scanf("%d",&size);
    
    int arr[size],store[size];
    
    printf("\n Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
        
    printf("\n Enter the number of rotation:");
    scanf("%d",&no_of_rotation);
    
    for(i=0;i<size;i++)
    {
        if(i + no_of_rotation >=size)
        {
            store[i] = arr[i+no_of_rotation-size];
        }
        else
            store[i] = arr[i+no_of_rotation];
    }
    
    printf("\n Rotated array:");
    for(i=0;i<size;i++)
        printf("%d ",store[i]);
    
    return 0;
}
