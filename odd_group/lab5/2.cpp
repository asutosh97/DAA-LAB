/*
2. Write a program to implement heap sort on 1000 numbers stored in a file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int left_child(int x)
{
	return 2*x;
}
int right_child(int x)
{
	return 2*x+1;
}
void heapify(int arr[], int beg, int end)
{
	int largest;
	int l = left_child(beg);
	int r = right_child(beg);
	if(l < end && arr[l] > arr[beg])
		largest = l;
	else
		largest = beg;

	if(r < end && arr[r] > arr[largest])
		largest = r;

	if(largest != beg)
	{
		std::swap(arr[beg], arr[largest]);
		heapify(arr, largest, end);
	}
}
void build_heap(int arr[], int size)
{
	for(int i = size / 2; i >= 0; i--)
		heapify(arr, i, size);
}

void heap_sort(int arr[], int size)
{
	build_heap(arr, size);
	for(int i = size - 1;i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, 0, i);
	}
}
int main()
{
	// store random numbers in a file
	std::ofstream out("a.txt");
	for(int i = 0;i < 1000; i++)
		out<<rand() % INT_MAX<<std::endl;
	out.close();

	// read the numbers to an array
	int arr[1000];
	std::ifstream in("a.txt");
	for(int i = 0;i < 1000; i++)
		in>>arr[i];
	in.close();
	heap_sort(arr,1000);

	// write numbers to the file
	out.open("a.txt");
	for(int i = 0;i < 1000; i++)
		out<<arr[i]<<std::endl;
	out.close();
	return 0;
}