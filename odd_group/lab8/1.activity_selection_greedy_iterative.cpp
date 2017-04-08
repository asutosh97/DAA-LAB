#include <iostream>
#include <vector>
#include <algorithm>
struct activity
{
    int stime;
    int ftime;
    std::string name;
};
bool compare(activity a, activity b)
{
    return a.ftime < b.ftime;
}
int main()
{
    int n;
    std::cout<<"Enter the number of activities : ";
    std::cin>>n;
    std::vector<activity> v(n);
    for(int i = 0;i < n; i++)
    {
        std::cout<<"Enter the details of the "<<i+1<<"th activity"<<std::endl;
        std::cout<<"Enter name : ";
        std::cin>>v[i].name;
        std::cout<<"Enter starting time : ";
        std::cin>>v[i].stime;
        std::cout<<"Enter finish time : ";
        std::cin>>v[i].ftime;
    }
    std::sort(v.begin(), v.end(), compare);
    std::vector<activity> ans;
    ans.push_back(v[0]);
    activity curr = v[0];
    for(int i = 1;i < n; i++)
    {
        if(v[i].stime >= curr.ftime)
        {
            curr = v[i];
            ans.push_back(curr);
        }
    }
    int l = ans.size();
    std::cout<<"The maximum number of activities are "<<l<<" and their names are : "<<std::endl;
    for(int i = 0;i < l; i++)
        std::cout<<ans[i].name<<std::endl;
    return 0;
}
