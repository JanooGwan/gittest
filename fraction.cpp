#include "fraction.h"
#include <sstream>

// 2021136089 이관우
void test_operator_plus()
{
    Fraction a{5, 6}, b{4, -3}, c{3, 3};
    std::cout << static_cast<std::string>(a + b) << '\n';
    std::cout << static_cast<std::string>(a + c) << '\n';
    std::cout << static_cast<std::string>(b + c) << '\n';
}

void test_operator_minus()
{
    Fraction a{61, 60}, b{40, 7}, c{50, 6};
    std::cout << static_cast<std::string>(a - b) << '\n';
    std::cout << static_cast<std::string>(b - a) << '\n';
    std::cout << static_cast<std::string>(a - c) << '\n';
    std::cout << static_cast<std::string>(c - a) << '\n';
    std::cout << static_cast<std::string>(b - c) << '\n';
    std::cout << static_cast<std::string>(c - b) << '\n';
}

void test_operator_multiple()
{
    Fraction a{5, 6}, b{7, 8}, c{9, 3};
    std::cout << static_cast<std::string>(a * b) << '\n';
    std::cout << static_cast<std::string>(a * c) << '\n';
    std::cout << static_cast<std::string>(b * c) << '\n';
}

void test_operator_divide()
{
    Fraction a{5, 10}, b{5, 4}, c{3, -1};
    std::cout << static_cast<std::string>(a / b) << '\n';
    std::cout << static_cast<std::string>(b / a) << '\n';
    std::cout << static_cast<std::string>(a / c) << '\n';
    std::cout << static_cast<std::string>(c / a) << '\n';
    std::cout << static_cast<std::string>(b / c) << '\n';
    std::cout << static_cast<std::string>(c / b) << '\n';
}

void test_operator_input()
{
    std::istringstream input("5/4 10/3 50/3");
    Fraction a, b, c;

    input >> a >> b >> c;

    std::cout << "a : " << a << '\n';
    std::cout << "b : " << b << '\n';
    std::cout << "c : " << c << '\n';
}

void judge_spaceship(auto result)
{
    if (result > 0)
        std::cout << "왼쪽이 더 큼" << '\n';
    else if (result < 0)
        std::cout << "오른쪽이 더 큼" << '\n';
    else
        std::cout << "둘이 같음" << '\n';
}

void test_operator_spaceship()
{
    Fraction a{3, 5};
    Fraction b{2, 2};
    Fraction c{10, 1};

    auto res1 = a <=> b;
    auto res2 = a <=> c;
    auto res3 = b <=> c;

    std::cout << "a <=> b 결과" << '\n';
    judge_spaceship(res1);
    std::cout << "a <=> c 결과" << '\n';
    judge_spaceship(res2);
    std::cout << "b <=> c 결과" << '\n';
    judge_spaceship(res3);
}

int main()
{
    test_operator_plus();
    test_operator_minus();
    test_operator_multiple();
    test_operator_divide();
    test_operator_input();
    test_operator_spaceship();

    return 0;
}