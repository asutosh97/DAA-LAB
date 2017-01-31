/*
maximum difference between two elements array.
*/

#include <iostream>
#include <algorithm>
int main()
{
    int n,i,f=1;
    std::cout<<"Enter the no of elements:"<<std::endl;
    std::cin>>n;
    int a[n];
    std::cout<<"Enter the elements:"<<std::endl;
    for(i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    std::sort(a,a+n,std::greater<int>());
    std::cout<<"Maximum difference:"<<a[0]-a[n-1]<<std::endl;
}
