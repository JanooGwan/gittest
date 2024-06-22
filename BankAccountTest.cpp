#include <iostream>
#include "BankAccount.h"


int main() { // 2021136089 ÀÌ°ü¿ì
    SavingsAccount godAccount;
    godAccount.getBalance();
    godAccount.getAccountNumber();
    godAccount.setAccountNumber(977051600);
    godAccount.setAccountNumber(050555111);
    godAccount.getAccountNumber();
    godAccount.addInterest();
    SavingsAccount::setInterestRate(3.5);
    godAccount.addInterest();
    godAccount.addInterest();
    MinusAccount::setInterestRate(4.5);
    MinusAccount gwanAccount;
    gwanAccount.setLoanRate(5.5);
    gwanAccount.setLimit(90000000);
    gwanAccount.deposit(500000);
    gwanAccount.withdraw(999999999);
    gwanAccount.withdraw(5000000);
    gwanAccount.setLimit(8000000);
    gwanAccount.withdraw(8000000);
    gwanAccount.getBalance();
    gwanAccount.setAccountNumber(910495);
    gwanAccount.getAccountNumber();

    return 0;
}