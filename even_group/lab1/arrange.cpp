#include<iostream>
using namespace std;
bool isprime(int n)
{
	bool status=true;
	for(int i=2;i<n;i++)
	{
		if(n%i == 0)
		{
			status=false;
			break;
		}
	}
	return status;
}
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
int main()
{
	int arr[100],size;
	cout<<"enter the size : ";
	cin>>size;
	cout<<"Enter the numbers : ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(isprime(arr[i]))
		{
			swap(arr[i],arr[j]);
			j++;
		}
	}
	for(int i=j;i<size;i++)
	{
		if(arr[i]%2 != 0)
		{
			swap(arr[i],arr[j]);
			j++;
		}
	}
	
	cout<<"Rearranged array is : ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<"\n";
}
