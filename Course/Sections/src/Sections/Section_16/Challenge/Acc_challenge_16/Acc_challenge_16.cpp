#include "..\..\..\..\..\..\Sections\include\Sections\Section_16\Challenge\Acc_challenge_16\Acc_challenge_16.h"

Acc_challenge_16::Acc_challenge_16(string name,double balance)
	:name{ name }, balance{balance} {
	if (balance < 0.0)
		//throw IllegalBalanceExceptopn{};
		throw IllegalBalanceExceptopn();
};

Acc_challenge_16::~Acc_challenge_16() {
	//cout << "Acc destructor" << endl;
}
