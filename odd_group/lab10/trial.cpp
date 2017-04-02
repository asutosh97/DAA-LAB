#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<pair<int, int>, pair<int, int> > mp;
	mp[make_pair(1, 2)] = make_pair(100, 200);
	cout<<(mp[make_pair(2, 2)] == make_pair(0, 0))<<endl;
	return 0;
}