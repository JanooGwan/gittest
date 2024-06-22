#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

bool solve(std::string time) // 2021136089 ÀÌ°ü¿ì
{
    time.erase(remove(time.begin(), time.end(), ':'), time.end());

    int times[4]{};
    int time_cnt{0};
    int n{0};

    for (int i = 0; i < time.length(); i++)
    {
        if (time[i] == ' ')
        {
            time_cnt = 0;
            ++n;
        }

        else
        {
            times[n] += pow(10, 3 - time_cnt) * int(time[i] - '0');
            ++time_cnt;
        }
    }

    return ((times[1] >= times[2] && times[0] <= times[3]));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    std::cin.ignore();
    std::string time_arr[100];

    bool result[100];
    for (int t{0}; t < T; ++t)
    {
        getline(std::cin, time_arr[t]);
        result[t] = solve(time_arr[t]);
    }

    for (int t{0}; t < T; ++t)
    {
        std::cout << std::boolalpha << result[t] << '\n';
    }

    return 0;
}