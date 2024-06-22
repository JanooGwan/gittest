#include <iostream>
#include <vector>

int solve(int n)
{
    int num[10];
    int i{0};

    while (n != 0)
    {
        num[i] = n % 10;
        n /= 10;
        ++i;
    }

    int result{0};

    for (int j{0}; j < i; ++j)
    {
        if (j % 2 == 0)
            result += num[j];
        else
            result -= num[j];
    }

    return result;
}

int main()
{
    int T;
    std::cin >> T;
    int n;
    for (size_t i{0}; i < T; ++i)
    {
        std::cin >> n;
        std::cout << solve(n) << '\n';
    }
}