#include <iostream>
struct item
{
    std::string name;
    double profit;
    int weight;
    double criteria;
};
int main()
{
    int noOfItems;
    int Wmax;
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

    // 0-1 Knapsack Algorithm
    double knapsack[noOfItems+1][Wmax+1];
    for(int i = 0;i <= noOfItems; i++)
        knapsack[i][0] = 0;
    for(int w = 1; w <= Wmax; w++)
        knapsack[0][w] = 0;

    for(int i = 1;i <= noOfItems; i++)
    {
        for(int w = 1;w <= Wmax; w++)
        {
            if(arr[i-1].weight > w)
                knapsack[i][w] = knapsack[i-1][w];
            else
                knapsack[i][w] = std::max(knapsack[i-1][w], knapsack[i-1][w-arr[i-1].weight] + arr[i-1].profit);
        }
    }
    std::cout<<"Maximum profit is : "<<knapsack[noOfItems][Wmax]<<std::endl;
    return 0;
}
