// Asutosh Sahoo
// B115017
// CSE 4th Sem
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define all(v) v.rbegin(), v.rend()
int main()
{
	int n;
	cout<<"Enter the number of sticks : ";
	cin>>n;
	vector <int> a(n);
	int i;
	for(i = 0;i < n; i++)
		cin>>a[i];
	sort(all(a));
	bool found = false;
	for(i = 0;i < n - 2; i++)
	{
		if(a[i] < a[i+1] + a[i+2])
		{
			found = true;
			break;
		}
	}
	if(found)
		cout<<"The sides are "<<a[i+2]<<" "<<a[i+1]<<" "<<a[i]<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}