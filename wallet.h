#ifndef WALLET
#define WALLET
#include <vector>

class Wallet { // 2021136089 ÀÌ°ü¿ì
private:
    std::vector<int> money;
    std::vector<int> money_value = {100, 500, 1000, 5000, 10000, 50000};

public:
    Wallet(): money(6) {};
    virtual ~Wallet() = default;;
    void add(int denomination, int amount);
    void spend(int amount);
    void clear() noexcept;
    int getCurrentAmount() const;
};

void isAmountPositive(int num);
void overflow_plus(int a, int b);
void overflow_multiply(int a, int b);

#endif