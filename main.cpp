#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "account.cpp"

using namespace std;
class SavingAccount;
class CheckingAccount;


	int main() {
		bool exit = false;
		int sel;
		double input;
		SavingAccount* save = new SavingAccount(0.0, 0.12);
		CheckingAccount* check = new CheckingAccount(0.0, 0.12);
		while (!exit) {
			cout << "******** BANK ACCOUNT MENU ********" << endl;
			cout << endl;
			cout << "1.  Savings Account Deposit" << endl;
			cout << "2.  Checking Account Deposit" << endl;
			cout << "3.  Savings Account Withdrawal" << endl;
			cout << "4.  Checking Account Withdrawal" << endl;
			cout << "5.  Update and Display Account Statistics" << endl;
			cout << "6.  Exit" << endl;
			cout << endl;
			cout << "Your choice, please: (1-6)  ";
			cin >> sel;
			switch (sel)
			{
			case 1: {
				cout << "Enter amount to deposit: ";
				cin >> input;
				save->Deposit(input);
				cout << endl;
				cout << endl;
				break;
			}
			case 2: {
				cout << "Enter amout to deposit: ";
				cin >> input;
				check->Deposit(input);
				cout << endl;
				cout << endl;
				break;
			}
			case 3: {
				cout << "Enter amout to withdraw: ";
				cin >> input;
				save->Withdraw(input);
				cout << endl;
				cout << endl;
			}
			case 4: {
				cout << "Enter amout to withdraw: ";
				cin >> input;
				check->Withdraw(input);
				cout << endl;
				cout << endl;
			}
			case 5: {
				save->toString();
				cout << endl;
				cout << endl;
				cout << "Press a key to continue...";
				cin;
				cout << endl;
				cout << endl;
				check->toString();
				cout << endl;
				cout << endl;
				break;
			}
			case 6: {
				exit = true;
				break;
			}
			}
		}
		return 0;
	}
