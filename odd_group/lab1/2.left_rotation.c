/*
Program to rotate an array anticlockwise
*/
#include <stdio.h>
int main() 
{
    int size,i,no_of_rotation;
    
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    
    int arr[size],arr2[size];
    
    printf("Enter the array elements: \n ");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
        
    printf("Enter the number of rotation: \n ");
    scanf("%d",&no_of_rotation);
    
    for(i=0;i<size;i++)
    {
        if(i + no_of_rotation >=size)
        {
            arr2[i] = arr[i+no_of_rotation-size];
        }
        else
            arr2[i] = arr[i+no_of_rotation];
    }
    
    printf("Rotated array: \n");
    for(i=0;i<size;i++)
        printf("%d ",arr2[i]);

    printf("\n");
    return 0;
}
