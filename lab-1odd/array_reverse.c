//program to reverse an array
#include <stdio.h>

int main() {
    int size,i,temp;
    
    printf("\n Enter the size of the array:");
    scanf("%d",&size);
    
    int arr[size];
    
    printf("\n Enter array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
        
    //Reversing the elements of the array
    for(i=0;i<size/2;i++)
    {
       temp = arr[i];
       arr[i] = arr[size-i-1];
       arr[size-i-1] = temp;
    }
    
    //Printing the reversed array
    printf("\n Reversed array:");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
        
    return 0;
}
