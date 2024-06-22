#include <iostream>
#include <algorithm>
#include "wallet.h"

int main()
{ // 2021136089 이관우
    Wallet wallet;

    std::cout<<"[ Wallet 관리 시스템 ]"<<'\n';
    std::cout<<"Creator : 2021136089 이관우"<<'\n';
    std::cout<<"-----------------------------"<<'\n';
    
    int n{0};
    while(n!=4) {
        std::cout<<"수행하고 싶은 작업을 선택하세요."<<'\n'<<'\n';
        std::cout<<"1) 돈 추가"<<'\n';
        std::cout<<"2) 돈 소비"<<'\n';
        std::cout<<"3) 지갑 초기화"<<'\n';
        std::cout<<"4) 프로그램 종료"<<'\n'<<'\n';
        std::cout<<"입력 : ";
        std::cin>>n;

        switch(n) {
            int a, b;

            case 1:
                std::cout<<"화폐 단위와 장 수를 입력하세요."<<'\n'<<'\n';
                std::cout<<"입력 : ";
                std::cin>>a>>b;
                wallet.add(a, b);
                break;
            
            case 2:
                std::cout<<"사용하고 싶은 금액을 입력하세요."<<'\n'<<'\n';
                std::cout<<"입력 : ";
                std::cin>>a;
                wallet.spend(a);
                break;

            case 3:
                wallet.clear();
                break;

            case 4:
                std::cout<<'\n'<<"Wallet 관리 시스템을 종료합니다."<<'\n';
                break;

            default:
                std::cout<<'\n'<<"올바른 값을 입력해주세요."<<'\n'<<'\n';
        }
    }

    return 0;
}

void isAmountPositive(int num) // 종류 1
{
    if (num <= 0)
        throw std::invalid_argument("0 이하는 입력할 수 없습니다.");
}

void overflow_plus(int a, int b) // 종류 2
{
    if (a > std::numeric_limits<int>::max() - b)
        std::overflow_error("Overflow 발생 : 돈이 너무 많습니다!");
}

void overflow_multiply(int a, int b) // 종류 2
{
    if (a > std::numeric_limits<int>::max() * b)
        std::overflow_error("Overflow 발생 : 돈이 너무 많습니다!");

}

void Wallet::add(int denomination, int amount)
{
    isAmountPositive(amount);
    isAmountPositive(denomination);
    bool isAdded = false;
    int before_add = getCurrentAmount();
    for (int i{0}; i < 6; ++i)
    {
        if (money_value[i] == denomination)
        {
            money[i] += amount;
            isAdded = true;
        }
    }

    if (isAdded)
    {
        std::cout << "충전 성공" << '\n';
        std::cout << "-------------------" << '\n';
        std::cout << "충전 전 금액 : " << before_add << '\n';
        std::cout << "충전한 금액 : " << denomination * amount << '\n';
        std::cout << "잔액 : " << getCurrentAmount() << '\n';
    }

    else
        throw std::invalid_argument("충전 실패 : 금액이 화폐 단위에 맞지 않음"); // 종류 1
}

void Wallet::spend(int amount)
{
    isAmountPositive(amount);

    if (amount % 100 != 0)
        throw std::invalid_argument("10원 또는 1원 단위는 지불할 수 없습니다."); // 종류 1

    int current_money = getCurrentAmount();

    if (current_money < amount)
        throw std::out_of_range("잔액이 부족합니다."); // 종류 1

    else
    {
        int k{0};
        while (k < 5)
        {
            if (money_value[k] <= amount && amount < money_value[k + 1])
                break;

            ++k;
        }

        int smaller_sum{0};
        for (int i{0}; i <= k; ++i)
        {
            smaller_sum += money[i] * money_value[i];
        }

        if (smaller_sum >= amount)
        {
            while (amount > 0)
            {
                if (amount >= money_value[k] && money[k] > 0)
                {
                    amount -= money_value[k];
                    --money[k];
                }

                else
                    --k;
            }
        }

        else
        {
            --money[k + 1];
            int gap;
            gap = money_value[k + 1] - amount;

            while (gap > 0)
            {
                if (gap >= money_value[k])
                {
                    gap -= money_value[k];
                    ++money[k];
                }

                else
                    --k;
            }
        }

        std::cout << "지불 성공" << '\n';
        std::cout << "-------------------" << '\n';
        std::cout << "지불 전 금액 : " << current_money << '\n';
        std::cout << "지불한 금액 : " << current_money - getCurrentAmount() << '\n';
        std::cout << "잔액 : " << getCurrentAmount() << '\n'
                  << '\n';
    }
}

void Wallet::clear() noexcept
{
    for (int i{0}; i < 6; ++i)
        money[i] = 0;
    std::cout << "지갑을 깔끔히 비웠습니다!" << '\n'
              << '\n';
}

int Wallet::getCurrentAmount() const
{
    int sum{0};
    for (int i{0}; i < 6; ++i)
    {
        overflow_multiply(money[i], money_value[i]); // 종류 2
        overflow_plus(sum, money[i] * money_value[i]); // 종류 2

        sum += money[i] * money_value[i];
    }

    if (sum < 0)
        throw std::out_of_range("오류 : 잔액이 0 이하임"); // 종류 2

    return sum;
}
