#pragma once
#include<exception>
#include <iterator>
#include<string>
using std::map;
using std::string;
using std::out_of_range;

class BankAccount
{
public:
	BankAccount(int acctNum, const string& name) :mAcctNum(acctNum), mClientName(name) {}
	void		setAcctNum(int acctNum) { mAcctNum = acctNum; }
	int		getAcctNum() const { return (mAcctNum); }

	void		setClientName(const string& name) { mClientName = name; }
	void		setClientName(const char& name) { mClientName = name; }
	string	getClientName() const { return mClientName; }

protected:
	int		mAcctNum;
	string	mClientName;
};

class BankDB
{
public:
	BankDB() {}
	bool		addAccount(const BankAccount& acct);

	void		deleteAccount(int acctNum);

	BankAccount& findAccount(int acctNum) throw(out_of_range);
	BankAccount& findAccount(const string& name) throw(out_of_range);

protected:
	map<int, BankAccount> mAccounts;
};

bool BankDB::addAccount(const BankAccount& acct) {
	auto it = mAccounts.find(acct.getAcctNum());
	if (it == mAccounts.end()) {
		mAccounts.insert(std::make_pair(acct.getAcctNum(), acct));
		std::cout << "added\n";
		return true;
	}
	std::cout << "not add\n";
	return false;
}
BankAccount & BankDB::findAccount(int acctNum) throw(out_of_range)
{
	auto it = mAccounts.find(acctNum);
	if (it != mAccounts.end())
		return it->second;
	throw out_of_range("No account number with this number ");
}

BankAccount & BankDB::findAccount(const string & name) throw(out_of_range)
{
	for (auto i = mAccounts.begin(); i != mAccounts.end(); ++i) {
		if (i->second.getClientName() == name) {
			return i->second;
		}
	}
	throw std::out_of_range(" No account with this name ");
}

void BankDB::deleteAccount(int acctNum)
{
	for (auto i = mAccounts.begin(); i != mAccounts.end(); ++i) {
		if (i->first == acctNum)
			mAccounts.erase(acctNum);
	}
}
