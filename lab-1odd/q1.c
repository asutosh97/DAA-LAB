//Show that array elements are stored in consecutive memory locations
#include <stdio.h>
int main() {
    int size,i;
    printf("\n Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    printf("\n Priniting the memory address:");
    for(i=0;i<size;i++)
        printf("%p\t",arr+i);
    return 0;
}
