#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountType; // C = Checking, S = Savings, CD = Certificate of Deposit
    string firstName;
    string lastName;
    string transactionDate; // yyyy-mm-dd format
    string transactionType; // New, Withdrawal, Deposit, Transfer
    int transactionAmount;
    double accountBalance;
    double interestEarned;

public:
    // Constructors
 
    // Getters
 
    // Setters
 
    // Utility functions
    //void virtual calcInterestEarned();
    //void processDeposit(int amount);
    //void virtual processWithdrawal(int amount);
    void printDetails(ofstream &out) const;
};
