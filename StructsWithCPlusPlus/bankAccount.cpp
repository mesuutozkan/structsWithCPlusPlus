#include <iostream>

using namespace std;

/*
* 
* structs acts like a public class in C++. In classes, if any definition of the member set is not specified,
* members are defaulty accepted as private. In structs, members are defaulty public. 
* 
**/

struct bankAccount
{
private:						//if it would be a class, private typeword should not be defined. But for a struct it must be defined.

	double balance;
	string accountName;
public:
	
	bankAccount(const string &_accountName, double _balance)		//const: name is same. &_accountName: no need to create another local struct. 
	{
		accountName = _accountName;
		balance = _balance;

		cout << "Account created: " << _accountName << endl;

	}

	~bankAccount()
	{
		cout << "Account deleted: " << accountName << endl;
	}

	double getBalance()
	{
		return balance;
	
	}

	string getAccountName()
	{
		return accountName;

	}

	void deposit(double deposit, bankAccount &bankAccount)
	{
		balance += deposit;

		cout << "Current balance after deposit " << deposit << " : " << bankAccount.getBalance() << endl;
	
	}

	void withdraw(double withdraw, bankAccount &bankAccount)
	{
		balance -= withdraw;

		cout << "Current balance after withdraw " << withdraw << " : " << bankAccount.getBalance() << endl;

	}
};

int main()
{
	bankAccount mineAccount("Account A", 100);
	
	mineAccount.deposit(50, mineAccount);

	mineAccount.getBalance();

	mineAccount.withdraw(20, mineAccount);

	mineAccount.getBalance();

	bankAccount* pBankAccount = new bankAccount("Account B", 200);

	pBankAccount->getAccountName();

	pBankAccount->deposit(100, *pBankAccount);

	pBankAccount->getBalance();

	pBankAccount->withdraw(25.5, *pBankAccount);

	pBankAccount->getBalance();

	delete pBankAccount;		//if there is a heap memory usage, call destructor. stack does it automatically.

}

/**
* 
* output:
* 
Account created: Account A
Current balance after deposit 50 : 150
Current balance after withdraw 20 : 130
Account created: Account B
Current balance after deposit 100 : 300
Current balance after withdraw 25.5 : 274.5
Account deleted: Account B
Account deleted: Account A
* 
**/