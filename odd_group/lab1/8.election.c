/*
Find out who won the election i.e. print the number which appear the most number of times
*/

#include <stdio.h>
int main() 
{
    int size,i,j,count=0,max=0,ID;
    
    printf("Enter the size of the array:");
    scanf("%d",&size);
    
    int arr[size];
    
    printf("Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    
    for(i=0;i<size;i++)
    {
        count = 0;
        if(arr[i] == -1)
            continue;
        for(j=0;j<size;j++)
        {
            if(arr[i] == arr[j])
                count++;
        }
        if(count > max)
        {
            max = count;
            ID = arr[i];
        }
    }
    
    printf("Election won : %d",ID);
    return 0;
}
