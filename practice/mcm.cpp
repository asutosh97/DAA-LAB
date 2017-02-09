/*
matrix chain multiplication
*/

#include <iostream>
int main()
{
	int n;
	std::cout<<"Enter the number of matrices : ";
	std::cin>>n;
	std::cout<<"Enter the dimensions array : ";
	int dimensions[n+1];
	for(int i = 0;i <= n; i++)
		std::cin >> dimensions[i];

	return 0;
}