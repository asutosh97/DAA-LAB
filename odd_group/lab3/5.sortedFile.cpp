#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#define SIZE 100
#define ll long long
int partition(ll a[],int beg,int end)
{
	srand((unsigned)time(NULL));
	int random_pivot = beg + rand() % (end - beg);
	std::swap(a[random_pivot],a[beg]);
	ll x = a[beg];
	int i = beg,j;
	for(j = beg + 1;j < end; j++)
		if(a[j] < x)
			std::swap(a[++i],a[j]);
	std::swap(a[beg],a[i]);
	return i;
}
void quick_sort(ll a[],int beg,int end)
{
	if(end - beg <= 1)
		return;
	int q = partition(a,beg,end);
	quick_sort(a,beg,q);
	quick_sort(a,q+1,end);
}
int main()
{
	srand(time(NULL));
	std::ofstream out("afile.txt");
	for(int i = 0;i < SIZE; i++)
		out<<rand()<<std::endl;
	out.close();
	
	std::ifstream in("afile.txt");
	ll arr[SIZE];
	for(int i = 0;i < 100; i++)
		in>>arr[i];
	in.close();
	
	quick_sort(arr,0,SIZE);

	out.open("afile.txt");
	for(int i = 0;i < SIZE; i++)
		out<<arr[i]<<std::endl;
	out.close();
	return 0;
}