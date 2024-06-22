#include "BankAccount.h"
#include <iostream>

void BankAccount::getBalance() noexcept { // 2021136089 이관우
    std::cout<<"해당 계좌의 현재 잔액은 "<<balance<<"원 입니다."<<'\n';
}

void BankAccount::deposit(int amount) noexcept {
    if (amount > 0) {
        balance += amount;
        std::cout<<"예금 성공 : 현재 잔액은 "<<balance<<"원 입니다.";
    }

    else std::cout<<"예금 실패 : 예금하는 금액은 0 이상이어야 합니다."<<'\n';
}

void BankAccount::withdraw(int amount) noexcept {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        std::cout<<"인출 성공"<<'\n';
        std::cout<<"인출된 금액 : amount"<<'\n';
    }

    else std::cout<<"인출 실패 : 잔액 부족"<<'\n';
}

void BankAccount::getAccountNumber() noexcept {
    if (accountNumber == NULL) std::cout<<"계좌번호가 설정되어 있지 않습니다. 계좌번호를 설정해 주세요."<<'\n';

    else std::cout<<"해당 계좌의 계좌번호는 "<<accountNumber<<" 입니다."<<'\n';
}

void BankAccount::setAccountNumber(int num) noexcept {
    if (accountNumber!=NULL) std::cout<<"설정 실패 : 계좌번호는 변경할 수 없습니다."<<'\n';
    else if (num > 0) {
        accountNumber = num;
        std::cout<<"설정 완료 : 설정된 계좌번호는 "<<num<<" 입니다.";
    }

    else std::cout<<"설정 실패 : 올바른 계좌번호를 입력해주세요."<<'\n';
}

void BankAccount::addInterest() {
    if (interestRate == NULL) std::cout<<"이자 지급 실패 : 저축 계좌의 약정금리를 먼저 설정해주세요."<<'\n';

    else {
        balance += static_cast<int>(balance * interestRate);
        std::cout<<"이자 지급 완료 : 해당 일반 계좌의 잔액은 "<<balance<<"원 입니다."<<'\n';
    }
}

void SavingsAccount::setInterestRate(float rate) noexcept {
    if (rate >= 0) {
        interestRate = rate;
        std::cout<<"설정 성공 : 저축 계좌의 이자율이 "<<interestRate<<"%로 설정되었습니다."<<'\n';
    }

    else std::cout<<"설정 실패 : 이자율은 0 이상이어야 합니다."<<'\n';
}

void SavingsAccount::addInterest() {
    if (interestRate == NULL) std::cout<<"이자 지급 실패 : 저축 계좌의 약정금리를 먼저 설정해주세요."<<'\n';

    else {
        balance += static_cast<int>(balance * interestRate);
        std::cout<<"이자 지급 완료 : 해당 저축 계좌의 잔액은 "<<balance<<"원 입니다."<<'\n';
    }
}

void MinusAccount::setLimit(int limit) {
    if(loanLimit > 50000000) {
        loanLimit = 50000000;
        std::cout<<"대출 한도는 5천만원 입니다."<<'\n';
        std::cout<<"입력하신 대출 한도는 5천만원으로 조정되었습니다."<<'\n';
    }

    else {
        loanLimit = limit;
        std::cout<<"대출 한도가 입력하신 "<<loanLimit<<"원으로 설정되었습니다."<<'\n';
    }
}

void MinusAccount::setLoanRate(float rate) {
    loanRate = rate;
    std::cout<<"대출 이자율이 "<<loanRate<<"%로 설정되었습니다."<<'\n';
}

void MinusAccount::setInterestRate(float rate) noexcept {
    if (rate >= 0) {
        interestRate = rate;
        std::cout<<"이자율이 "<<interestRate<<"%로 설정되었습니다."<<'\n';
    }

    else std::cout<<"설정 실패 : 이자율은 0 이상이어야 합니다."<<'\n';
}

void MinusAccount::addInterest() {
    if (balance > 0) {
        balance += static_cast<int>(balance * interestRate);
        std::cout<<"이자 지급 성공"<<'\n';
        std::cout<<"현재 금액은 "<<balance<<"원 입니다."<<'\n';
    }

    else {
        std::cout<<"이자 지급 실패 : 잔액이 없습니다."<<'\n';
    }
}


void MinusAccount::withdraw(int amount) noexcept {
    if (amount <= 0) std::cout<<"인출 실패 : 인출하는 금액은 0보다 커야합니다."<<'\n';
    
    else {
        if (balance + loanLimit >= amount) {
            balance -= amount;
            if (balance >= 0) std::cout<<"인출 성공 : 현재 잔액은 "<<balance<<"원 입니다."<<'\n';
            else std::cout<<"인출 및 대출 성공 : 잔액이 부족하여 대출을 진행했습니다."<<'\n'<<"현재 대출한 금액은 "<<-balance<<"원 입니다."<<'\n';
        }

        else std::cout<<"인출 실패 : 잔액이 부족하고 대출도 불가능합니다(대출 한도 초과)."<<'\n';
    }
}

void MinusAccount::deposit(int amount) noexcept {
    if (amount <= 0) {
        std::cout<<"예금 실패 : 예금 금액은 0보다 커야 합니다."<<'\n';
    }

    else {
        if (balance < 0) {
            int pay = -balance < amount ? -balance : amount;
            balance += pay + static_cast<int>(pay * loanRate);
            amount -= pay;
        }
        balance += amount;

        if (balance >=0)
            std::cout<<"입금 성공 : 현재 잔액은 "<<balance<<"원 입니다."<<'\n';
        else std::cout<<"입금 성공 : 남은 대출 금액은 "<<-balance<<"원 입니다."<<'\n';
    }
}