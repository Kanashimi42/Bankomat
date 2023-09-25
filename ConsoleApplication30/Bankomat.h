#include <iostream>
#include <string>
#define TODAYLIMIT 1000
using namespace std;
class Bankomat {
private:
	string atmId;
	int* Nominals;
	int numNominals;
	int minWithdrawal;
	int maxWithdrawal;
	int currentBalance;
	int dayLimit;

public:
	Bankomat(string id, int* Noms, int numNoms, int minWithdraw, int maxWithdraw, int initialBalance, int dayLimit);
	~Bankomat();

	void loadMoney(int* Noms, int numNoms);
	bool withdrawMoney(int amount);
	int getCurrentBalance();
	string toString();
};
