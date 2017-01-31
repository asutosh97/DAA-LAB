/* 
Show that array elements are stored in consecutive memory locations
*/
#include <stdio.h>
int main() 
{
    int size,i;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Priniting the memory address : \n");
    for(i=0;i<size;i++)
        printf("%p\n",&arr[i]);
    return 0;
}