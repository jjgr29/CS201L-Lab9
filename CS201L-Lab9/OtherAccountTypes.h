#pragma once
#include "BankAccount.h"

class Checking : public BankAccount {
public:
	// Constructor
};


//*******************************************************
class Savings : public BankAccount {
public:
	// Constructor

	void calcInterestEarned() {}

};

//*******************************************************
class CD : public BankAccount {

private:
	bool withdrawalTaken = false;

public:
	// Constructor
	void calcInterestEarned() {}

	void processWithdrawal(int amount) {}
};

