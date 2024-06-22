#include <iostream>
#include <string>

int isVowel(char c) // 2021136089 ÀÌ°ü¿ì
{ 
    int judge = 0;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        judge = 1;

    return judge;
}

int solve(const std::string word, int checking_length)
{

    int max{0};
    int cnt{0};
    int i;
    std::string s;

    for (i = 0; i < checking_length; ++i)
    {
        if (isVowel(word[i]))
            ++cnt;
    }

    max = cnt;

    for (int j = i; j < word.length(); j++)
    {
        cnt -= isVowel(word[j - checking_length]);
        cnt += isVowel(word[j]);

        if (max < cnt)
            max = cnt;
    }

    return max;
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
    int l;
    int result[1000];

    for (int t{0}; t < T; ++t)
    {
        getline(std::cin, word_arr[t]);
        std::cin >> l;
        std::cin.ignore();
        result[t] = solve(word_arr[t], l);
    }

    for (int t{0}; t < T; ++t)
    {
        std::cout << result[t] << '\n';
    }

    return 0;
}