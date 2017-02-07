#include<iostream>
#include <map>
#include<exception>
#include <string>
#include <stdexcept>
#include"BankDB.h"

using std::map;
using std::string;
using std::out_of_range;
using namespace std;

void bank() {
	BankDB db;

	db.addAccount(BankAccount(100, "Nicholas Solter"));
	db.addAccount(BankAccount(200, "Scott Kleper"));

	try {
		BankAccount &acct = db.findAccount(100);
		cout << "Found account 100\n";
		acct.setClientName("Nicholas A Solter");
		BankAccount &acct2 = db.findAccount("Scott Kleper");
		cout << "Found account of Scott Kelper\n";
		BankAccount &acct3 = db.findAccount(1000);
	}
	catch (out_of_range &) {
		cout << "Unable to find account\n";
	}
}


int main(int argc, char** argv)
{
	bank();
	return 0;
}
