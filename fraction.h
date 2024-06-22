#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <compare>

// 2021136089 이관우
class Fraction
{
private:
    int n{0};
    int d{1};

public:
    explicit Fraction() = default;
    explicit Fraction(int n, int d = 1)
    {
        if (d == 0)
            throw std::invalid_argument("분모는 0이 될 수 없음");
        if ((n >= 0 && d < 0) || (n < 0 && d < 0))
        {
            this->n = -n;
            this->d = -d;
        }
    }

    virtual ~Fraction() = default;
    int numerator() const noexcept { return n; }
    int denominator() const noexcept { return d; }

    explicit operator std::string() const noexcept
    {
        if (n % d == 0)
            return std::to_string(n / d);
        else
            return std::to_string(n) + "/" + std::to_string(d);
    }

    explicit operator double() const noexcept
    {
        return static_cast<double>(n) / d;
    }

    Fraction operator-() const
    {
        return Fraction(-n, d);
    }

    Fraction operator+(const Fraction &other) const
    {
        int num = n * other.d + other.n * d;
        int den = d * other.d;
        Fraction result(num, den);
        result.reduction();
        return result;
    }

    Fraction operator-(const Fraction &other) const
    {
        return operator+(Fraction(-other.n, other.d));
    }

    Fraction operator*(const Fraction &other) const
    {
        int num = n * other.n;
        int den = d * other.d;
        Fraction result(num, den);
        result.reduction();
        return result;
    }

    Fraction operator/(const Fraction &other) const
    {
        if (other.n == 0)
            throw std::invalid_argument("0으로 나눌 수 없음");
        return operator*(Fraction(other.d, other.n));
    }

    auto operator<=>(const Fraction &other) const
    {
        return (static_cast<double>(*this) <=> static_cast<double>(other));
    }

    bool operator==(const Fraction &other) const
    {
        return operator<=>(other) == 0;
    }

private:
    int gcd(int a, int b) const noexcept
    {
        return (b == 0) ? a : gcd(b, a % b);
    }

    void reduction() noexcept
    {
        int g = gcd(std::abs(n), d);
        n /= g;
        d /= g;
    }

    friend std::ostream &operator<<(std::ostream &os, const Fraction &o);
    friend std::istream &operator>>(std::istream &is, Fraction &f);
};

std::ostream &operator<<(std::ostream &os, const Fraction &o)
{
    os << static_cast<std::string>(o);
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &f)
{
    std::string input;
    is >> input;
    size_t pos = input.find('/');
    if (pos != std::string::npos)
    {
        try
        {
            f.n = std::stoi(input.substr(0, pos));
            f.d = std::stoi(input.substr(pos + 1));
            if (f.d == 0)
                throw std::invalid_argument("분모는 0이 될 수 없음");
            if ((f.n >= 0 && f.d < 0) || (f.n < 0 && f.d < 0))
            {
                f.n = -f.n;
                f.d = -f.d;
            }
        }
        catch (const std::exception &e)
        {
            is.setstate(std::ios::failbit);
        }
    }
    else
    {
        try
        {
            f.n = std::stoi(input);
            f.d = 1;
        }
        catch (const std::exception &e)
        {
            is.setstate(std::ios::failbit);
        }
    }
    return is;
}

#endif