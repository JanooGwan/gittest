#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int solve(int x[], int n) // 2021136089 ÀÌ°ü¿ì
{
    int min{std::numeric_limits<int>::max()};
    int result;

    for(int i{0}; i<n; ++i) {

        for(int j{i+1}; j<n; ++j) {
            if(x[i]>=x[j]) continue;

            for(int k{j+1}; k<n; ++k) {
                if(x[j]<=x[k]) continue;
                result=x[i]+x[j]+x[k];
                if(result<min) min=result;
                }
            }
        }

    return (min==std::numeric_limits<int>::max() ? -1 : min);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;

    int n;
    int result[100];

    for (int t{0}; t < T; ++t)
    {
        std::cin>>n;
        int x[200]{};

        for(int i{0}; i<n; ++i) {
            std::cin>>x[i];
            result[t]=solve(x, n);
        }
    }

    for (int t{0}; t < T; ++t)
    {
        std::cout <<result[t] << '\n';
    }

    return 0;
}