// Asutosh Sahoo
// B115017
// CSE 4th Sem
/*
Q4.WAP for tower of hannoi by using recursion.
*/
#include <iostream>
void TOH(std::string S,std::string D,std::string I,int n)
{
	if(n == 1)
	{
		std::cout<<"move from "<<S<<" to "<<D<<std::endl;
		return;
	}
	TOH(S,I,D,n-1);
	std::cout<<"move from "<<S<<" to "<<D<<std::endl;
	TOH(I,D,S,n-1);
}

int main()
{
	int n;
	std::cout<<"Enter the number of rings in Tower of Hanoi : ";
	std::cin>>n;
	TOH("Source","Destination","Intermediate",n);
	return 0;
}