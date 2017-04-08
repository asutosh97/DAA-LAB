#include <iostream>
struct item
{
    std::string name;
    double profit;
    double weight;
    double criteria;
};
int partition(item arr[], int beg, int end)
{
    item x = arr[end - 1];
    int i = beg - 1;
    for(int j = beg; j < end - 1; j++)
    {
        if(arr[j].criteria > x.criteria)
            std::swap(arr[++i], arr[j]);
    }
    std::swap(arr[++i], arr[end - 1]);
    return i;
}
void quick_sort(item arr[], int beg, int end)
{
    if(end - beg <= 1)
        return;
    int q = partition(arr, beg, end);
    quick_sort(arr, beg, q);
    quick_sort(arr, q+1, end);
}
double fractionalKnapsack(item arr[], int size, double Wmax, float X[])
{
    double weight = 0;
    int i = 0;
    double maxProfit = 0;
    while(weight < Wmax && i < size)
    {
        if(weight + arr[i].weight >= Wmax)
        {
            X[i] = (double)((Wmax - weight) / arr[i].weight);
            weight = Wmax;
        }
        else
        {
            weight += arr[i].weight;
            X[i] = 1;
        }
        std::cout<<"added "<<X[i]<<"fraction of "<<arr[i].name<<" to the knapsack"<<std::endl;
        maxProfit += arr[i].profit * X[i];
        i++;
    }
    while(i < size)
    {
        X[i++] = 0;
    }
    return maxProfit;
}
int main()
{
    int noOfItems;
    double Wmax;
    std::cout<<"Enter the number of items : ";
    std::cin>>noOfItems;
    std::cout<<"Enter the capacity of the Knapsack : ";
    std::cin>>Wmax;
    item arr[noOfItems];
    for(int i = 0;i < noOfItems; i++)
    {
        std::cout<<"Enter the details of item "<<i+1<<":"<<std::endl;
        std::cout<<"Name : ";
        std::cin>>arr[i].name;
        std::cout<<"Weight : ";
        std::cin>>arr[i].weight;
        std::cout<<"Profit : ";
        std::cin>>arr[i].profit;
        arr[i].criteria = arr[i].profit / arr[i].weight;
    }
    quick_sort(arr, 0, noOfItems);
/*    std::cout<<"The sorted array is : ";
    for(int i = 0; i <  noOfItems; i++)
        std::cout<<arr[i].name<<std::endl;
*/
    float X[noOfItems];
    double maxProfit = fractionalKnapsack(arr, noOfItems, Wmax, X);
    std::cout<<"The maximum possible profit is : "<<maxProfit<<" and the name of the items in the Knapsack with their corresponding fractions are :"<<std::endl;
    for(int i = 0;i < noOfItems; i++)
    {
        if(X[i] == 0)
            break;
        std::cout<<"Name : "<<arr[i].name<<"    Proportion : "<<X[i]<<std::endl;
    }
    return 0;

}
