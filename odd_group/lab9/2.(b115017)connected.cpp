#include <iostream>
void initialize(int arr[], int N)
{
    for(int i = 0;i < N; i++)
        arr[i] = i;
}
int find(int arr[], int A)
{
    return arr[A];
}
void _union(int arr[], int N, int A, int B)
{
    int temp = arr[A];
    for(int i = 0;i < N; i++)
        if(arr[i] == temp)
            arr[i] = arr[B];
}
int main()
{
    int n,m;
    std::cout<<"Enter the number of vertices of the graph : ";
    std::cin>>n;
    std::cout<<"Enter the number of edges : ";
    std::cin>>m;
    int arr[n];
    initialize(arr, n);
    while(m--)
    {
        int a,b;
        std::cout<<"Enter edge : ";
        std::cin>>a>>b;
        a--;
        b--;
        _union(arr, n, a, b);
    }
    std::cout<<"The connected sets are :- "<<std::endl;
    int temp = arr[0];
    while(1)
    {
        for(int i = 0;i < n; i++)
        {
            if(arr[i] == temp)
            {
                std::cout<<i+1<<" ";
                arr[i] = -1;
            }
        }
        std::cout<<std::endl;
        int i;
        for(i = 0;i < n; i++)
            if(arr[i] != -1)
                break;
        if(i < n)
            temp = arr[i];
        else
            break;
    }
    return 0;
}
