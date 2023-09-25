#include "Bankomat.h"
string intToString(int number) {
	if (number == 0) {
		return "0";
	}

	string result = "";
	bool isNegative = false;

	if (number < 0) {
		isNegative = true;
		number = -number;
	}

	while (number > 0) {
		int digit = number % 10;
		result = char('0' + digit) + result;
		number /= 10;
	}

	if (isNegative) {
		result = "-" + result;
	}

	return result;
}

Bankomat::Bankomat(string id, int* Noms, int numNoms, int minWithdraw, int maxWithdraw, int initialBalance, int dayLimit) :
	atmId(id), Nominals(new int[numNoms]), numNominals(numNoms), minWithdrawal(minWithdraw), maxWithdrawal(maxWithdraw), currentBalance(initialBalance), dayLimit(dayLimit) {
	for (int i = 0; i < numNominals; ++i) {
		this->Nominals[i] = Noms[i];
	}
}

Bankomat::~Bankomat() {
	delete[] Nominals;
}

void Bankomat::loadMoney(int* Noms, int numNoms) {
	int loadedNoms = 0;
	for (int i = 0; i < numNoms; ++i) {
		currentBalance += Noms[i];
		loadedNoms += Noms[i];
	}
	cout << "Loaded: " << loadedNoms << " coupons!" << endl;
}

bool Bankomat::withdrawMoney(int amount) {
	cout << "Withdrawing: " << amount << " coupons!" << endl;
	if (amount < minWithdrawal || amount > maxWithdrawal || amount > currentBalance || amount > dayLimit) {
		cout << "Error! Wrong summ for withdraw or day limit is expired!" << endl;
		return false;
	}

	int remainingAmount = amount;
	for (int i = 0; i < numNominals; ++i) {
		while (remainingAmount >= Nominals[i]) {
			remainingAmount -= Nominals[i];
			dayLimit -= Nominals[i];
			currentBalance -= Nominals[i];
		}
	}

	cout << "Withdrawed " << amount << " coupons. Left: " << currentBalance << " coupons." << " Today's user limit is: " << dayLimit << " coupons!" << endl;
	return true;
}

int Bankomat::getCurrentBalance() {
	return currentBalance;
}

string Bankomat::toString() {
	string atmbalance = intToString(currentBalance);
	return "Atm balance: " + atmbalance + " coupons.";
}
