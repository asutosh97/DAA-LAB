//Find out who won the election i.e. print the number which appear the most number of times

#include <stdio.h>

int main() {
    int size,i,j,count=0,max=0,ID;
    
    printf("\n Enter the size of the array:");
    scanf("%d",&size);
    
    int arr[size];
    
    printf("\n Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    
    //counting who got the maximum vote
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
    
    //Printing the id of highest number of votes
    printf("\nElection won:%d",ID);
    
    return 0;
}
