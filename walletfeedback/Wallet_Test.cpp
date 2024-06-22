//============================================================================
// Name        : Wallet_Test.cpp
// Author      : 김상진
// Version     : 2024년도 1학기
// Copyright   : 한국기술교육대학교 컴퓨터공학부 C++프로그래밍
// Description : Wallet 클래스 테스트 프로그램
//============================================================================

#include <iostream>
#include "Wallet.h"

void test01(){
	std::cout << "\ntest01\n";
	Wallet wallet;
	wallet.add(100, 2);
	wallet.add(500, 4);
	wallet.add(1000, 2);
	wallet.add(5000, 1);
	wallet.add(10000, 1);
	if(wallet.getCurrentAmount() != 19'200) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(9000);
	if(wallet.getCurrentAmount() != 10'200) {
		std::cout << "spend 오류: 기대값: 2 0 0 0 1 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test02(){
	std::cout << "\ntest02\n";
	Wallet wallet;
	wallet.add(500, 1);
	wallet.add(50000, 1);
	if(wallet.getCurrentAmount() != 50'500) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(100);
	if(wallet.getCurrentAmount() != 50'400) {
		std::cout << "spend 오류: 기대값: 4 0 0 0 0 1\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test03(){
	std::cout << "\ntest03\n";
	Wallet wallet;
	wallet.add(100, 1);
	wallet.add(5000, 2);
	if(wallet.getCurrentAmount() != 10'100) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(5100);
	if(wallet.getCurrentAmount() != 5'000) {
		std::cout << "spend 오류: 기대값: 0 0 0 1 0 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test04(){
	std::cout << "\ntest04\n";
	Wallet wallet;
	wallet.add(100, 2);
	wallet.add(500, 4);
	wallet.add(1000, 2);
	wallet.add(5000, 1);
	wallet.add(10000, 1);
	if(wallet.getCurrentAmount() != 19'200) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(6'300);
	if(wallet.getCurrentAmount() != 12'900) {
		std::cout << "spend 오류: 기대값: 4 3 1 0 1 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test05(){
	std::cout << "\ntest05\n";
	Wallet wallet;
	wallet.add(100, 2);
	wallet.add(500, 4);
	wallet.add(1000, 2);
	wallet.add(5000, 2);
	wallet.add(10000, 1);
	if(wallet.getCurrentAmount() != 24'200) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(9'000);
	if(wallet.getCurrentAmount() != 15'200) {
		std::cout << "spend 오류: 기대값: 2 0 0 1 1 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test06(){
	std::cout << "\ntest06\n";
	Wallet wallet;
	wallet.add(100, 2);
	wallet.add(1000, 5);
	wallet.add(5000, 1);
	wallet.add(10000, 1);
	if(wallet.getCurrentAmount() != 20'200) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(9'500);
	if(wallet.getCurrentAmount() != 10'700) {
		std::cout << "spend 오류: 기대값: 2 1 0 0 1 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test07(){
	std::cout << "\ntest07\n";
	Wallet wallet;
	wallet.add(5000, 2);
	wallet.add(10000, 1);
	if(wallet.getCurrentAmount() != 20'000) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(9'500);
	if(wallet.getCurrentAmount() != 10'500) {
		std::cout << "spend 오류: 기대값: 0 1 0 0 1 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test08(){
	std::cout << "\ntest08\n";
	Wallet wallet;
	wallet.add(1000, 2);
	wallet.add(5000, 2);
	wallet.add(10000, 1);
	wallet.add(50000, 1);
	if(wallet.getCurrentAmount() != 72'000) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(61'000);
	if(wallet.getCurrentAmount() != 11'000) {
		std::cout << "spend 오류: 기대값: 0 0 1 2 0 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

void test09(){
	std::cout << "\ntest09\n";
	Wallet wallet;
	wallet.add(500, 1);
	wallet.add(1000, 4);
	wallet.add(5000, 1);
	if(wallet.getCurrentAmount() != 9'500) {
		std::cout << "getCurrentAmount 오류\n";
		return;
	}
	wallet.spend(8'100);
	if(wallet.getCurrentAmount() != 1'400) {
		std::cout << "spend 오류: 기대값: 4 0 1 0 0 0\n";
		wallet.debugPrint();
		return;
	}
	std::cout << "성공\n";
}

int main() {
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	return 0;
}
