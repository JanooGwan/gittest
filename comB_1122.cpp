#include <iostream>
#include <string>
 
bool solve(std::string_view A, std::string_view B) 
{
    int A_cnt[100]={0};
    int B_cnt[100]={0};
    int a, b;
    int res=1;
    
    if(A.length()!=B.length()) return 0;
    
    for(int i=0; i<A.length(); i++) {
        a=A[i];
        b=B[i];

        A_cnt[a-65]++;
        B_cnt[b-65]++;
    }

    for(int i=0; i<100; i++) {
        if(A_cnt[i]!=B_cnt[i]) res=0;
    }

    return res;
}
 
int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    for(int t{0}; t < T; ++t)
	{
        std::string A, B;
		std::cin >> A >> B;
        std::cout << std::boolalpha << solve(A, B) << '\n';
    }
    return 0;
}