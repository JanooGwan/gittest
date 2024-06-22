#include <iostream>

int cal_num(int n)
{
    int k, res;
    k=n/1000000;
    res=k%100;

    return res;
}

int main()
{
    int n;
    int stunum[1001];
    std::cin>>n;
    for(int i=1; i<=n; i++)
    {
        std::cin>>stunum[i-1];
    }

    for(int i=0; i<=n-1; i++)
    {
        std::cout<<cal_num(stunum[i])<<std::endl;
    }

    return 0;
}