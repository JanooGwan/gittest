#include <iostream>
#include <string>

int solve(const std::string word) // 2021136089 ÀÌ°ü¿ì
{
    int cnt{1};
    bool preCharHasBlank{true};

    if (word.length() == 0)
        return 0;

    else
    {
        int i{0};
        while (word[i] == ' ')
        {
            if (i == word.length() - 1)
                return 0;
            ++i;
        }

        for (int j = i; j < word.length(); ++j)
        {
            if (word[j] == ' ' && !preCharHasBlank)
            {
                ++cnt;
                preCharHasBlank = true;
            }

            else if (word[j] != ' ')
                preCharHasBlank = false;
        }
    }
    return preCharHasBlank ? cnt - 1 : cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    std::cin.ignore();
    std::string word_arr[1000];

    int result[1000];
    for (int t{0}; t < T; ++t)
    {
        getline(std::cin, word_arr[t]);
        result[t] = solve(word_arr[t]);
    }

    for (int t{0}; t < T; ++t)
    {
        std::cout << result[t] << '\n';
    }

    return 0;
}