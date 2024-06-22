//============================================================================
// Name        : Wallet.h
// Author      : 김상진
// Version     : 2024년도 1학기
// Copyright   : 한국기술교육대학교 컴퓨터공학부 C++프로그래밍
// Description : Wallet 클래스
//============================================================================

#ifndef WALLET_H_
#define WALLET_H_
#include <vector>
#include <string>

class Wallet {
private:
	static inline const std::vector<int> DENOMINATION{100, 500, 1000, 5000, 10000, 50000};
	std::vector<int> M;
public:
	Wallet() noexcept: M(DENOMINATION.size(),0) {}
	virtual ~Wallet() noexcept = default;
	int getCurrentAmount(int S = 5) const;
	void add(int denomination, int amount);
	void spend(int amount);
	void clear();
	void debugPrint() const noexcept;
private:
	int spend(int amount, int targetD);
	std::vector<int> getChange(int amount) const;
};

#endif /* WALLET_H_ */
