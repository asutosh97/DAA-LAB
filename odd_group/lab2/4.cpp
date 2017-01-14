// Asutosh Sahoo
// B115017
// CSE 4th Sem
#include <iostream>
using namespace std;
void TOH(string S,string D,string I,int n)
{
	if(n == 1)
	{
		cout<<"move from "<<S<<" to "<<D<<endl;
		return;
	}
	TOH(S,I,D,n-1);
	cout<<"move from "<<S<<" to "<<D<<endl;
	TOH(I,D,S,n-1);
}

int main()
{
	int n;
	cout<<"Enter the number of rings in Tower of Hanoi : ";
	cin>>n;
	TOH("Source","Destination","Intermediate",n);
	return 0;
}