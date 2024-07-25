#include "Functions.h"

bool isDigits(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

int accountPos(int acctNumber, vector<BankAccount*>& accounts) {
    return -1;
}

int validDate(string date) {
    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);
    if (isDigits(year) && isDigits(month) && isDigits(day)) {
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);
        if (y < 1900 || y > 2024)
            return -1;
        else if (m < 1 || m > 12)
            return -1;
        else if (d < 1 || d > 31)
            return -1;
    }
    return 1;
}

void applyInterest(vector<BankAccount*>& accounts) { 
}

bool validAccountInfo(vector<string> tokens, ofstream& err, string inRecord) { 
    return false;
}

void processNewAccount(vector<string> tokens, ofstream &err, string inRecord, vector<BankAccount*>& accounts) {

    if (!validAccountInfo(tokens, err, inRecord))    
        return;
    
    try {
          
    }
    catch (...) {
        err << left << setw(40) << "Input Record is Invalid:" << inRecord << endl;
        return;
    }
}

void processTransfer(vector<string> tokens, ofstream& err, string inRecord, vector<BankAccount*>& accounts) {
    if (!validAccountInfo(tokens, err, inRecord))          return;
         
}

void processWithdrawal(vector<string> tokens, ofstream& err, string inRecord, vector<BankAccount*>& accounts) {
}

void processDeposit(vector<string> tokens, ofstream& err, string inRecord, vector<BankAccount*>& accounts) {
}

void processFile(ifstream& in, ofstream& err, vector<BankAccount*>& accounts) {
   // read the input record
   // verify the type of transaction
   // verify the account number(s) are valid (exist in the current vector)
   // if amounts

    int validAcctIdx1, validAcctIdx2, acctNumber, acctNumber2, transAmount;
    string inRecord, token;
    vector<string> tokens;

    while (getline(in, inRecord)) {
        stringstream inSS(inRecord);
        tokens.clear();
        while (getline(inSS, token, ','))
            tokens.push_back(token);

        cout << "TOKENS FOUND: " << tokens.size() << " : " << inRecord << endl;

        if (tokens.at(5) == "INTEREST") {
            if (validDate(tokens.at(4)) == -1) {
                err << setw(40) << "Transaction Date is Invalid:" << inRecord << endl;
                continue;
            }
            applyInterest(accounts);
            continue;
        }
        else if (tokens.at(5) == "NEW") {
            processNewAccount(tokens, err, inRecord, accounts);
            continue;
        }
        else if (tokens.at(5) == "TRANSFER") {
            processTransfer(tokens, err, inRecord, accounts);
            continue;
        }
        else if (tokens.at(5) == "WITHDRAWAL") {
            processWithdrawal(tokens, err, inRecord, accounts);
            continue;
        }
        else if (tokens.at(5) == "DEPOSIT") {
            processDeposit(tokens, err, inRecord, accounts);
            continue;
        }
        else {
            err << left << setw(40) << "Transaction Type is Invalid:" << inRecord << endl;
            continue;
        }
    }
}


void printReport(ofstream& reportFile, vector<BankAccount*> accounts) {
    reportFile << "-----------------------------------" << endl;
    reportFile << "           Account Report          " << endl;
    reportFile << "-----------------------------------" << endl;
    reportFile << setw(20) << left << "Account Number: "
        << setw(20) << left << "Account Type: "
        << setw(20) << left << "First Name: "
        << setw(15) << left << "Last Name: "
        << setw(18) << left << "Account Balance: "
        << setw(15) << left << "Interest Earned: " << endl;

    //add sort for account numbers

    for (int i = 0; i < accounts.size(); i++)
        accounts.at(i)->printDetails(reportFile);

}
