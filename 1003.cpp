#include <iostream>

int main()
{
    int n, num[300], cnt=0;
    int renum[300];
    
    std::cin>>n;

    for(int i=0; i<=n-1; i++)
    {
        std::cin>>num[i];
    }

    for(int i=0; i<=n-3; i++)
    {
        for(int j=i+1; j<=n-2; j++)
        {
            for(int k=j+1; k<=n-1; k++)
            {
                if(num[i]+num[j]+num[k]==0) cnt++;
            }
        }
    }

    std::cout<<cnt;
    return 0;
}