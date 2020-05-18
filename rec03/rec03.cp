//Saimanasa Juluru
//CS 2124
//20 September 2019
//Lab 03
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Question 1
struct Account1 {
    string accountName;
    int accountNumber;
};
//Question 2
class Account {
    //c
    friend ostream& operator<<(ostream& os, const Account& anAccount);
public:
    Account() {}
    Account(const string& aName, int aNum) : accountName(aName), accountNumber(aNum) {}
    const string& getName() { return accountName; }
    const int getNumber() { return accountNumber; }

    void deposit(int amount) {
        balance += amount;

        Transaction newAction("Deposit", amount);
        transactionHistory.push_back(newAction);
    }
    void withdraw(int amount) {
        if (balance - amount < 0) {
            cerr << "Not enough money to withdraw $" << amount << " from " << accountName << endl;
        }
        else {
            balance -= amount;
            Transaction newAction("Withdraw", amount);
            transactionHistory.push_back(newAction);
        }
    }


private:
    //Question 3
    class Transaction {
        friend ostream& operator<<(ostream& os, const Transaction& aTransaction) {
            os << aTransaction.transactionType << " of amount $" << aTransaction.transactionAmount;
            return os;
        }
    public:
        Transaction(const string& type, int amount) : transactionType(type), transactionAmount(amount) {}
    private:
        string transactionType;
        int transactionAmount;
    };

    string accountName;
    int accountNumber;
    int balance = 0;
    vector<Transaction> transactionHistory;
};

//2b + Question 3 (Transation History)
ostream& operator<<(ostream& os, const Account& anAccount) {
    os << "Account: " << anAccount.accountName << " #"
       << anAccount.accountNumber << " Balance: " << anAccount.balance
       << " Transaction history: ";
    for (size_t transaction = 0; transaction < anAccount.transactionHistory.size(); ++transaction) {
        os << anAccount.transactionHistory[transaction];
    }
    return os;
}

void localInstance(ifstream& accountFile, vector<Account>& accounts);
void curlyBrace(ifstream& accountFile, vector<Account>& accounts);
void tempInstance(ifstream& accountFile, vector<Account>& accounts);
void emplaceBack(ifstream& accountFile, vector<Account>& accounts);
void newTransaction(ifstream& accountFile, const string& type, int accountNum, vector<Account>& accounts);
void displayAccounts(const vector<Account>& accounts);

int main() {
    ifstream accountFile("accounts.txt");
    if (!accountFile) {
        cerr << "File couldn't be opened\n";
    }

    vector<Account> accounts;

    emplaceBack(accountFile, accounts);

    displayAccounts(accounts);

}


//Defining local instances of account, assign values to struct, and push back object
void localInstance(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    Account1 anAccount;
    while (accountFile >> name >> num) {
        anAccount.accountName = name;
        anAccount.accountNumber = num;
    }
}

//Use curly braces initilalizers to initialize instance
void curlyBrace(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    while (accountFile >> name >> num) {
        Account anAccount{ name, num };
        accounts.push_back(anAccount);
    }
}

//pass temporary instances
void tempInstance(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    while (accountFile >> name >> num) {
        accounts.push_back(Account(name, num));
    }
}

//using emplace_back
void emplaceBack(ifstream& accountFile, vector<Account>& accounts) {
    string name;
    int num;
    while (accountFile >> name >> num) {
        if (name == "Deposit" || name == "Withdrawal") {
            newTransaction(accountFile, name, num, accounts);
        }
        else {
            accounts.emplace_back(name, num);
        }
    }
}

void newTransaction(ifstream& accountFile, const string& type, int accountNum, vector<Account>& accounts) {
    int amount;
    accountFile >> amount;

    int position;

    for (size_t acc = 0; acc < accounts.size(); ++acc) {
        if (accountNum == accounts[acc].getNumber()) {
            position = acc;
        }
    }

    if (type == "Deposit") {
        accounts[position].deposit(amount);
    }
    else { //Withdraw
        accounts[position].withdraw(amount);
    }
}

void displayAccounts(const vector<Account>& accounts) {
    for (size_t acc = 0; acc < accounts.size(); ++acc) {
        //cout << accounts[acc].accountName << ' ' << accounts[acc].accountNumber << endl;
        cout << accounts[acc] << endl;
    }
}