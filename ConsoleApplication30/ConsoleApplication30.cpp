#include <iostream>
#include "Bankomat.h"

int main() {
	int initialNominals[] = { 10, 50, 100, 500, 1000 };
	Bankomat atm("ATM_001", initialNominals, 5, 10, 1000, 10000, TODAYLIMIT);
	cout << "Today's limit is: " << TODAYLIMIT << "!" << endl;
	cout << atm.toString() << endl;
	int addedNominals[] = { 10, 10, 10, 50, 50, 100, 100, 500, 500 };
	atm.loadMoney(addedNominals, 9);
	cout << atm.toString() << endl;

	atm.withdrawMoney(300);
	atm.withdrawMoney(7000);
	atm.withdrawMoney(50);
	atm.withdrawMoney(1000);
	atm.withdrawMoney(1);
	atm.withdrawMoney(650);
	atm.withdrawMoney(10);
	return 0;
}
