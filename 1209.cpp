#include <iostream>
#include <algorithm>
#include <vector>

void solve(int find, std::vector<int>& arr) {
    arr.erase(remove(arr.begin(), arr.end(), find), arr.end());

}

int main()
{
    int T;
    std::cin >> T;
    int v, n;
    for(size_t i{0}; i < T; ++i) {
        std::cin >> v >> n;
        std::vector<int> x(n);
        for(size_t j{0}; j < n; ++j) {
            std::cin >> x[j];
        }

        solve(v, x);
        std::cout << x.size() << '\n';

        for(size_t k{0}; k < x.size(); ++k)
        std::cout << x[k] << " ";

        std::cout << '\n';
    }

    return 0;
}