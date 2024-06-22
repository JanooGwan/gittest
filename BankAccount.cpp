#include "BankAccount.h"
#include <iostream>

void BankAccount::getBalance() noexcept { // 2021136089 �̰���
    std::cout<<"�ش� ������ ���� �ܾ��� "<<balance<<"�� �Դϴ�."<<'\n';
}

void BankAccount::deposit(int amount) noexcept {
    if (amount > 0) {
        balance += amount;
        std::cout<<"���� ���� : ���� �ܾ��� "<<balance<<"�� �Դϴ�.";
    }

    else std::cout<<"���� ���� : �����ϴ� �ݾ��� 0 �̻��̾�� �մϴ�."<<'\n';
}

void BankAccount::withdraw(int amount) noexcept {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        std::cout<<"���� ����"<<'\n';
        std::cout<<"����� �ݾ� : amount"<<'\n';
    }

    else std::cout<<"���� ���� : �ܾ� ����"<<'\n';
}

void BankAccount::getAccountNumber() noexcept {
    if (accountNumber == NULL) std::cout<<"���¹�ȣ�� �����Ǿ� ���� �ʽ��ϴ�. ���¹�ȣ�� ������ �ּ���."<<'\n';

    else std::cout<<"�ش� ������ ���¹�ȣ�� "<<accountNumber<<" �Դϴ�."<<'\n';
}

void BankAccount::setAccountNumber(int num) noexcept {
    if (accountNumber!=NULL) std::cout<<"���� ���� : ���¹�ȣ�� ������ �� �����ϴ�."<<'\n';
    else if (num > 0) {
        accountNumber = num;
        std::cout<<"���� �Ϸ� : ������ ���¹�ȣ�� "<<num<<" �Դϴ�.";
    }

    else std::cout<<"���� ���� : �ùٸ� ���¹�ȣ�� �Է����ּ���."<<'\n';
}

void BankAccount::addInterest() {
    if (interestRate == NULL) std::cout<<"���� ���� ���� : ���� ������ �����ݸ��� ���� �������ּ���."<<'\n';

    else {
        balance += static_cast<int>(balance * interestRate);
        std::cout<<"���� ���� �Ϸ� : �ش� �Ϲ� ������ �ܾ��� "<<balance<<"�� �Դϴ�."<<'\n';
    }
}

void SavingsAccount::setInterestRate(float rate) noexcept {
    if (rate >= 0) {
        interestRate = rate;
        std::cout<<"���� ���� : ���� ������ �������� "<<interestRate<<"%�� �����Ǿ����ϴ�."<<'\n';
    }

    else std::cout<<"���� ���� : �������� 0 �̻��̾�� �մϴ�."<<'\n';
}

void SavingsAccount::addInterest() {
    if (interestRate == NULL) std::cout<<"���� ���� ���� : ���� ������ �����ݸ��� ���� �������ּ���."<<'\n';

    else {
        balance += static_cast<int>(balance * interestRate);
        std::cout<<"���� ���� �Ϸ� : �ش� ���� ������ �ܾ��� "<<balance<<"�� �Դϴ�."<<'\n';
    }
}

void MinusAccount::setLimit(int limit) {
    if(loanLimit > 50000000) {
        loanLimit = 50000000;
        std::cout<<"���� �ѵ��� 5õ���� �Դϴ�."<<'\n';
        std::cout<<"�Է��Ͻ� ���� �ѵ��� 5õ�������� �����Ǿ����ϴ�."<<'\n';
    }

    else {
        loanLimit = limit;
        std::cout<<"���� �ѵ��� �Է��Ͻ� "<<loanLimit<<"������ �����Ǿ����ϴ�."<<'\n';
    }
}

void MinusAccount::setLoanRate(float rate) {
    loanRate = rate;
    std::cout<<"���� �������� "<<loanRate<<"%�� �����Ǿ����ϴ�."<<'\n';
}

void MinusAccount::setInterestRate(float rate) noexcept {
    if (rate >= 0) {
        interestRate = rate;
        std::cout<<"�������� "<<interestRate<<"%�� �����Ǿ����ϴ�."<<'\n';
    }

    else std::cout<<"���� ���� : �������� 0 �̻��̾�� �մϴ�."<<'\n';
}

void MinusAccount::addInterest() {
    if (balance > 0) {
        balance += static_cast<int>(balance * interestRate);
        std::cout<<"���� ���� ����"<<'\n';
        std::cout<<"���� �ݾ��� "<<balance<<"�� �Դϴ�."<<'\n';
    }

    else {
        std::cout<<"���� ���� ���� : �ܾ��� �����ϴ�."<<'\n';
    }
}


void MinusAccount::withdraw(int amount) noexcept {
    if (amount <= 0) std::cout<<"���� ���� : �����ϴ� �ݾ��� 0���� Ŀ���մϴ�."<<'\n';
    
    else {
        if (balance + loanLimit >= amount) {
            balance -= amount;
            if (balance >= 0) std::cout<<"���� ���� : ���� �ܾ��� "<<balance<<"�� �Դϴ�."<<'\n';
            else std::cout<<"���� �� ���� ���� : �ܾ��� �����Ͽ� ������ �����߽��ϴ�."<<'\n'<<"���� ������ �ݾ��� "<<-balance<<"�� �Դϴ�."<<'\n';
        }

        else std::cout<<"���� ���� : �ܾ��� �����ϰ� ���⵵ �Ұ����մϴ�(���� �ѵ� �ʰ�)."<<'\n';
    }
}

void MinusAccount::deposit(int amount) noexcept {
    if (amount <= 0) {
        std::cout<<"���� ���� : ���� �ݾ��� 0���� Ŀ�� �մϴ�."<<'\n';
    }

    else {
        if (balance < 0) {
            int pay = -balance < amount ? -balance : amount;
            balance += pay + static_cast<int>(pay * loanRate);
            amount -= pay;
        }
        balance += amount;

        if (balance >=0)
            std::cout<<"�Ա� ���� : ���� �ܾ��� "<<balance<<"�� �Դϴ�."<<'\n';
        else std::cout<<"�Ա� ���� : ���� ���� �ݾ��� "<<-balance<<"�� �Դϴ�."<<'\n';
    }
}