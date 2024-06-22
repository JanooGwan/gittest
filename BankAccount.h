#ifndef BANKACCOUNT
#define BANKACOOUNT

class BankAccount { // 2021136089 ÀÌ°ü¿ì
protected:
    int balance{0};
    int accountNumber;
    static float interestRate;

public:
    BankAccount();
    void getBalance() noexcept;
    virtual void deposit(int amount) noexcept;
    virtual void withdraw(int amount) noexcept;
    void getAccountNumber() noexcept;
    void setAccountNumber(int num) noexcept;
    virtual void addInterest();
    static void setInterestRate(float rate) noexcept;
};

float BankAccount::interestRate;

class SavingsAccount : public BankAccount  {
private:
    static float interestRate;

public:
    SavingsAccount();
    void addInterest();
    static void setInterestRate(float rate) noexcept;
};

float SavingsAccount::interestRate;

class MinusAccount : public BankAccount {
private:
    float loanRate;
    int loanLimit;
    static float interestRate;

public:
    MinusAccount();
    void setLimit(int limit);
    void setLoanRate(float loanRate);
    static void setInterestRate(float rate) noexcept;
    void addInterest() override;
    void withdraw(int amount) noexcept override;
    void deposit(int amount) noexcept override;
};

float MinusAccount::interestRate;

#endif