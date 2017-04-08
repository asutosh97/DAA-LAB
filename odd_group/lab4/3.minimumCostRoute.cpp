#include <iostream>
#include <cmath>
float distance(float x1,float y1,float x2,float y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
int findPoint(float arr[],int beg,int end,int y0)
{
	if(end == beg)
		return beg;	
		
	int mid = (beg + end) / 2;
	
	if(y0 > arr[mid])
		return findPoint(arr,beg,mid,y0);
	else
		return findPoint(arr,mid+1,end,y0);
}
int main()
{
	int n;
	std::cout<<"Enter the number of points on the vertical line : ";
	std::cin>>n;
	float y[n],x;
	std::cout<<"Enter the y-cordinates of the points on the line : ";
	for(int i = 0;i < n; i++)
		std::cin>>y[i];
	std::cout<<"Enter the common value of x-cordinate : ";
	std::cin>>x;	
	
	float sx,sy,dx,dy;
	std::cout<<"Enter the x and y cordinates of S respectively : ";
	std::cin>>sx>>sy;
	std::cout<<"Enter the x and y cordinates of D respectively : ";
	std::cin>>dx>>dy;
	
	// find the intersection points x0 and y0
	float x0,y0;
	x0 = x;
	y0 = (((dy - sy)/(dx - sx))*(x0 - sx)) + sy;
	// algorithm that will find the point closest to 
	int p1 = findPoint(y,0,n-1,y0);
	int p2 = p1 - 1;
	float d1 = distance(x,y[p1],x0,y0);
	float d2 = distance(x,y[p2],x0,y0);
	int pmin;
	if(d1 < d2)
		pmin = p1;
	else
		pmin = p2;
	
	std::cout<<"The cordinates of R is : ("<< x <<","<<y[pmin]<<")"<<std::endl;
	std::cout<<"The smallest distance is : "<<distance(sx,sy,x,y[pmin])+distance(x,y[pmin],dx,dy)<<std::endl; 

	return 0;
}
