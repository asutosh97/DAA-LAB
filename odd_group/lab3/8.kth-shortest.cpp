#include <iostream>
#include <climits>
int partition(int a[], int beg, int end)
{
	int x = a[end - 1];
	int i = beg - 1;
	int j;
	for(j = beg; j < end - 1; j++)
		if(a[j] < x)
			std::swap(a[++i],a[j]);
	std::swap(a[++i],a[end - 1]);
	return i;
}
int kthSmallest(int a[], int beg, int end, int k)
{
	if(end - beg <= 1)
	{
		if(beg == k - 1)
			return a[k-1];
		else
			return INT_MAX;
	}
	int q = partition(a, beg, end);
	if(q == k-1)
		return a[k-1];
	else if(k-1 < q)
		return kthSmallest(a, beg, q, k);
	else
		return kthSmallest(a, q+1, end, k);
}
int main()
{
	int n;
	std::cout<<"Enter the number of elements in the array : ";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements of the array : ";
	for(int i = 0;i < n; i++)
		std::cin>>a[i];
	int k;
	std::cout<<"Enter the value of k : ";
	std::cin>>k;
	int ksmall = kthSmallest(a, 0, n, k);
	if(ksmall != INT_MAX)
		std::cout << "The "<< k << "th smallest element is : " << ksmall << std::endl;
	else
		std::cout << "Error!" << std::endl;
	return 0;
}