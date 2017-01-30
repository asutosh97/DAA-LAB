// Asutosh Sahoo
// B115017
// CSE 4th Sem
/*
Q.1 Given sticks of lengths ,l0,l1,l2,l3,l4....ln use 3 of the sticks to construct a non-degenerate triangle with the maximum possible perimeter. Then print the lengths of its sides as space-separated integers in non-decreasing order.

If there are several valid triangles having the maximum perimeter:

       1. Choose the one with the longest maximum side (i.e., the largest value for the longest side of any             valid triangle having the maximum perimeter).
       2.If more than one such triangle meets the first criterion, choose the one with the longest minimum               side (i.e., the largest value for the shortest side of any valid triangle having the maximum        perimeter).
       3.If more than one such triangle meets the second criterion, print any one of the qualifying triangles.
           If no non-degenerate triangle exists, print -1.
           */
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.rbegin(), v.rend()
int main()
{
	int n;
	std::cout<<"Enter the number of sticks : ";
	std::cin>>n;
	std::vector <int> a(n);
	int i;
	for(i = 0;i < n; i++)
		std::cin>>a[i];
	std::sort(all(a));
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
		std::cout<<"The sides are "<<a[i+2]<<" "<<a[i+1]<<" "<<a[i]<<std::endl;
	else
		std::cout<<"-1"<<std::endl;
	return 0;
}