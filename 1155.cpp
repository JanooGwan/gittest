#include <iostream>
#include <string>
#include <vector>

std::string solve(int n, const std::string (&str)[100])
{
    std::vector<std::vector<int>> freq1(n, std::vector<int> (26));


    for (size_t i{0}; i < n; ++i)
    {
        for (size_t j{0}; j < str[i].size(); ++j)
        {
            ++freq1[i][str[i][j] - 'a'];
        }
    }

    std::vector<int> same_freq(26, 100);

    for (size_t i{0}; i < n; ++i) {
        for (size_t j{0}; j < 26; ++j) {
            if (same_freq[j] > freq1[i][j]) same_freq[j] = freq1[i][j];
        }
    }

    std::string result;

    for(size_t i{0}; i < 26; ++i) {
        if(same_freq[i]!=0) {
            result.append(same_freq[i], (char(i+'a')));
        }
    }

    return result;
}

int main()
{
    int T;
    int n;

    std::cin >> T;
    for (size_t i{0}; i < T; ++i)
    {
        std::string str[100];
        std::cin >> n;
        for (size_t j{0}; j < n; ++j)
        {
            std::cin >> str[j];
        }

        std::cout << solve(n, str)<<'\n';
    }

    return 0;
}