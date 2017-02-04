/*
3. Write a program to find C(n, r) using recursion. Verify the complexity of your approach. Validate your complexity with significantly large input.

*/

#include <iostream>
int combinations(int n,int r)
{
	if(n == r || r == 0)
		return 1;
	return combinations(n-1, r) + combinations(n-1, r-1);
}
int main()
{
	int n,r;
	std::cout<<"Enter the value of n and r : ";
	std::cin>>n>>r;
	std::cout<<"The value of C("<<n<<","<<r<<") is "<<combinations(n,r)<<std::endl;
	return 0;
}