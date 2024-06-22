//============================================================================
// Name        : Wallet.cpp
// Author      : 김상진
// Version     : 2024년도 1학기
// Copyright   : 한국기술교육대학교 컴퓨터공학부 C++프로그래밍
// Description : Wallet 클래스
//============================================================================

#include <iostream>
#include <algorithm>
#include "Wallet.h"

int Wallet::getCurrentAmount(int S) const {
	int total{0};
	for(int i{0}; i <= S; ++i) {
		int amount = M[i] * DENOMINATION[i];
		total += amount;
	}
	return total;
}

void Wallet::add(int denomination, int amount) {
	for(std::size_t i{0}; i < DENOMINATION.size(); ++i) {
		if(denomination == DENOMINATION[i]) {
			M[i] += amount;
			break;
		}
	}
}

void Wallet::spend(int amount) {
	// 사용할 금액과 보유 금액이 일치하는 경우
	if(getCurrentAmount() == amount) {
		clear();
		return;
	}

	// 사용할 금액보다 액면가가 큰 돈 찾기
	int targetD{1};
	for(; targetD < DENOMINATION.size(); ++targetD) {
		if(M[targetD] > 0 && amount < DENOMINATION[targetD]) break;
	}
	--targetD;
	// 지불할 금액보다 작은 액면가 돈으로는 최대한 지불
	if(getCurrentAmount(targetD) >= amount)
		amount = spend(amount, targetD);
	if(amount > 0) {
		// 보유 돈으로 정확하게 지급하지 못한 경우
		targetD = 0;
		while(M[targetD] == 0 || DENOMINATION[targetD] < amount) ++targetD;
		int changeAmount = DENOMINATION[targetD] - amount;
		--M[targetD];
		std::vector<int> change(getChange(changeAmount));
		for(std::size_t i{0}; i < DENOMINATION.size(); ++i) {
			M[i] += change[i];
		}
	}
}

// 지불할 금액보다 작은 액면가 돈으로는 최대한 지불
int Wallet::spend(int amount, int targetD) {
	while(amount > 0 && amount <= getCurrentAmount(targetD)) {
		int coins = amount / DENOMINATION[targetD];
		// 해당 액면가 돈이 부족할 수도 있음
		if(M[targetD] < coins) coins = M[targetD];
		M[targetD] -= coins;
		amount -= coins * DENOMINATION[targetD];
		--targetD;
	}
	return amount;
}

// 탐욕적 기법. 가장 큰 액면가 동전부터 이용하여 거스름 준비
std::vector<int> Wallet::getChange(int amount) const {
	std::vector<int> change(DENOMINATION.size(), 0);
	std::size_t i{DENOMINATION.size() - 1};
	while(amount > 0) {
		if(DENOMINATION[i] <= amount){
			change[i] = amount / DENOMINATION[i];
			amount -= change[i] * DENOMINATION[i];
		}
		--i;
	}
	return change;
}

void Wallet::clear(){
	std::fill(M.begin(), M.end(), 0);
}

void Wallet::debugPrint() const noexcept {
	for(auto m: M) std::cout << m << " ";
	std::cout << '\n';
}
