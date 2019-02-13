#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
class SavingAccount;
class CheckingAccount;

class Account {

public: double balance;
		 int numOfDeposits;
		 int numOfWithDrawals;
		 double rate;
		 double charges;

public: Account(double bal, double rating) {
	balance = bal;
	rate = rating;
	numOfDeposits = 0;
	numOfWithDrawals = 0;
	charges = 0;
}

public: virtual void Deposit(double deposits) {
	numOfDeposits++;
	balance += deposits;
}

public: virtual void Withdraw(double withdraw) {
	numOfWithDrawals++;
	balance -= withdraw;
}

private: void CalcInt() {
	balance += balance * (rate / 12.0);
}

public: virtual void MonthlyProc() {
	balance -= charges;
	CalcInt();
	numOfDeposits = 0;
	numOfWithDrawals = 0;
	charges = 0;
}

public: virtual void toString() {
	cout << "ACCOUNT MONTHLY STATISTICS:" << endl;
	cout << "Withdrawals:\t\t" << numOfWithDrawals << endl;
	cout << "Deposits:\t\t" << numOfDeposits << endl;
	cout << "Service Charges:\t\t" << charges << endl;
	cout << endl;
	cout << "Ending Balance:\t\t" << balance << endl;
}

};


class SavingAccount : public Account {

public: SavingAccount(double balance,double rate): Account(balance,rate) {
	
}

public: void Deposit(double deposits) {
	if ((balance + deposits) >= 25.0) {
		Account::Deposit(deposits);
	}
}

public: void Withdraw(double withdraws) {
	if (balance >= 25.0) {
		Account::Withdraw(withdraws);
	}
}

public: void MonthlyProc() {
	if (balance >= 25.0) {
		if (numOfWithDrawals > 4) {
			charges += (double)numOfWithDrawals - 4.0;
			Account::MonthlyProc();
		}
	}
}

public: void toString() {
	cout << "SAVINGS ";
	Account::toString();
}

};

class CheckingAccount : public Account {

public: CheckingAccount(double balance, double rate): Account(balance,rate) {
	
}

public: void Withdraw(double withdraws) {
	if (withdraws > balance) {
		charges += 15;
	}
	else {
		Account::Withdraw(withdraws);
	}
}

public: void MonthlyProc() {
	charges += 5.0 + (double)numOfDeposits * 0.1;
	Account::MonthlyProc();
}

public: void toString() {
	cout << "CHECKING ";
	Account::toString();
}

};
