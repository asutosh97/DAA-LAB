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
void activity_selection(std::vector<activity>&v, std::vector<activity>&ans, int index, int size)
{
    if(index < size)
    {
        activity curr = ans[ans.size() - 1];
        if(v[index].stime >= curr.ftime)
            ans.push_back(v[index]);
        activity_selection(v, ans, index+1, size);
    }
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
    activity_selection(v, ans, 1, v.size());
    int l = ans.size();
    std::cout<<"The maximum number of activities are "<<l<<" and their names are : "<<std::endl;
    for(int i = 0;i < l; i++)
        std::cout<<ans[i].name<<std::endl;
    return 0;
}
