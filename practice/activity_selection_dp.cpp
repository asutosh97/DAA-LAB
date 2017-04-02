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
int latestNonConflict(std::vector<activity> v, int index)
{
	for(int j = index - 1; j >= 0; j--)
		if(v[j].ftime <= v[index].stime)
			return j;

	return -1;
}
int activity_selection(std::vector<activity> v, int n)
{
	int table[n];
	table[0] = 1;
	for(int i = 1;i < n; i++)
	{
		int inclProfit = 1;
		int j = latestNonConflict(v, i);
		if(j != -1)
			inclProfit += table[j];
		int exclProfit = table[i-1];
		table[i] = std::max(inclProfit, exclProfit);
	}
	return table[n-1];
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
    std::cout<<"Number of activities selected : "<<activity_selection(v, n)<<std::endl;
    return 0;
}