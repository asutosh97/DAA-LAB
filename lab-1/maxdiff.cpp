//RITESH KUMAR MOHAPATRA B115045
//maximum difference between two elements array.
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,f=1;
    cout<<"Enter the no of elements:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    cout<<"Maximum difference:"<<a[0]-a[n-1]<<endl;
}
