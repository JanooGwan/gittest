#include <iostream>
#include <algorithm>
#include "wallet.h"

int main()
{ // 2021136089 �̰���
    Wallet wallet;

    std::cout<<"[ Wallet ���� �ý��� ]"<<'\n';
    std::cout<<"Creator : 2021136089 �̰���"<<'\n';
    std::cout<<"-----------------------------"<<'\n';
    
    int n{0};
    while(n!=4) {
        std::cout<<"�����ϰ� ���� �۾��� �����ϼ���."<<'\n'<<'\n';
        std::cout<<"1) �� �߰�"<<'\n';
        std::cout<<"2) �� �Һ�"<<'\n';
        std::cout<<"3) ���� �ʱ�ȭ"<<'\n';
        std::cout<<"4) ���α׷� ����"<<'\n'<<'\n';
        std::cout<<"�Է� : ";
        std::cin>>n;

        switch(n) {
            int a, b;

            case 1:
                std::cout<<"ȭ�� ������ �� ���� �Է��ϼ���."<<'\n'<<'\n';
                std::cout<<"�Է� : ";
                std::cin>>a>>b;
                wallet.add(a, b);
                break;
            
            case 2:
                std::cout<<"����ϰ� ���� �ݾ��� �Է��ϼ���."<<'\n'<<'\n';
                std::cout<<"�Է� : ";
                std::cin>>a;
                wallet.spend(a);
                break;

            case 3:
                wallet.clear();
                break;

            case 4:
                std::cout<<'\n'<<"Wallet ���� �ý����� �����մϴ�."<<'\n';
                break;

            default:
                std::cout<<'\n'<<"�ùٸ� ���� �Է����ּ���."<<'\n'<<'\n';
        }
    }

    return 0;
}

void isAmountPositive(int num) // ���� 1
{
    if (num <= 0)
        throw std::invalid_argument("0 ���ϴ� �Է��� �� �����ϴ�.");
}

void overflow_plus(int a, int b) // ���� 2
{
    if (a > std::numeric_limits<int>::max() - b)
        std::overflow_error("Overflow �߻� : ���� �ʹ� �����ϴ�!");
}

void overflow_multiply(int a, int b) // ���� 2
{
    if (a > std::numeric_limits<int>::max() * b)
        std::overflow_error("Overflow �߻� : ���� �ʹ� �����ϴ�!");

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
        std::cout << "���� ����" << '\n';
        std::cout << "-------------------" << '\n';
        std::cout << "���� �� �ݾ� : " << before_add << '\n';
        std::cout << "������ �ݾ� : " << denomination * amount << '\n';
        std::cout << "�ܾ� : " << getCurrentAmount() << '\n';
    }

    else
        throw std::invalid_argument("���� ���� : �ݾ��� ȭ�� ������ ���� ����"); // ���� 1
}

void Wallet::spend(int amount)
{
    isAmountPositive(amount);

    if (amount % 100 != 0)
        throw std::invalid_argument("10�� �Ǵ� 1�� ������ ������ �� �����ϴ�."); // ���� 1

    int current_money = getCurrentAmount();

    if (current_money < amount)
        throw std::out_of_range("�ܾ��� �����մϴ�."); // ���� 1

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

        std::cout << "���� ����" << '\n';
        std::cout << "-------------------" << '\n';
        std::cout << "���� �� �ݾ� : " << current_money << '\n';
        std::cout << "������ �ݾ� : " << current_money - getCurrentAmount() << '\n';
        std::cout << "�ܾ� : " << getCurrentAmount() << '\n'
                  << '\n';
    }
}

void Wallet::clear() noexcept
{
    for (int i{0}; i < 6; ++i)
        money[i] = 0;
    std::cout << "������ ����� ������ϴ�!" << '\n'
              << '\n';
}

int Wallet::getCurrentAmount() const
{
    int sum{0};
    for (int i{0}; i < 6; ++i)
    {
        overflow_multiply(money[i], money_value[i]); // ���� 2
        overflow_plus(sum, money[i] * money_value[i]); // ���� 2

        sum += money[i] * money_value[i];
    }

    if (sum < 0)
        throw std::out_of_range("���� : �ܾ��� 0 ������"); // ���� 2

    return sum;
}
