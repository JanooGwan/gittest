#include <iostream>

int main()
{
    int num[1000];
    int t;
    int n;
    long res;
    int last_res[100];

    std::cin>>t;

    for(int i=1; i<=t; i++) {
        std::cin>>n;
        res=1;

        for(int j=1; j<=n; j++) {
            std::cin>>num[j-1];

            if(num[j-1]<0) res*=-1;
            else if(num[j-1]==0)res*=0;
    }
    
        last_res[i-1]=res;
}

    for(int i=0; i<=t-1; i++) std::cout<<last_res[i]<<'\n';

    return 0;
}