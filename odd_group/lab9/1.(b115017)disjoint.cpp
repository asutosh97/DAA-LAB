#include <iostream>
#include <vector>
int FIND(std::vector< std::pair <int, int> > &DSU, int x)
{
    for(int i = 0;i < DSU.size(); i++)
    {
        if(DSU[i].first == x)
            return DSU[i].second;

    }
    return -1;
}
void MAKESET(std::vector< std::pair <int, int> > &DSU, int x)
{
    if(FIND(DSU, x) != -1)
        return;
    DSU.push_back(std::make_pair(x, x));
}
void UNION(std::vector< std::pair <int, int> > &DSU, int A, int B)
{
    int rootA = FIND(DSU, A);
    int rootB = FIND(DSU, B);

    if(rootA == rootB)
        return;

    for(int i = 0;i < DSU.size(); i++)
        if(DSU[i].second == rootA)
            DSU[i] = std::make_pair(DSU[i].first, rootB);
}

int main()
{
    std::vector < std::pair<int, int> > DSU;
    while(1)
    {
        int ch, x, a, b;
        std::cout<<"1.MAKESET(x)"<<std::endl;
        std::cout<<"2.UNION(a, b)"<<std::endl;
        std::cout<<"3.FIND(x)"<<std::endl;
        std::cout<<"4.Exit"<<std::endl;
        std::cin>>ch;
        switch(ch)
        {
        case 1:
            std::cout<<"Enter the value of x : ";
            std::cin>>x;
            MAKESET(DSU, x);
            break;
        case 2:
            std::cout<<"Enter the value of a and b : ";
            std::cin>>a>>b;
            UNION(DSU, a, b);
            break;
        case 3:
            std::cout<<"Enter the value of x : ";
            std::cin>>x;
            std::cout<<x<<" belongs to "<<FIND(DSU, x)<<std::endl;
            break;
        case 4:
            return 0;
        default:
            std::cout<<"Try again"<<std::endl;
        }
    }
    return 0;
}