// oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BankAcc { //bankova smetka
	char AccType[12];
	char IBAN[23];
	int Amount;
};

class ClientBank {
	char Name[12];
	char Fam[15];
	static int number;
	int clinetNumber; //klientski nomer
	int NumberOfBankAccounts; //broi bankovi smetki
	BankAcc ArrayOfBankAccounts[10]; //masiv ot bankovi smetki
public:
	ClientBank();
	ClientBank(const char* Name1, const char* Fam1);
	//-	Метод, който добавя нова банкова сметка
	int AddBankAcc(const char* AccType1, const char* IBAN1, int Amount1);
	//- Метод, който премахва същяствуваща банкова сметка
	int RemoveBankAcc(const char* IBAN1);

	//-	Метод, който търси банкова сметка по зададен IBAN
 /*   BankAcc* FindAccByIBAN(const char* IBAN1) {
		for (int i = 0; i < NumberOfBankAccounts; i++)
			if (!strcmp(ArrayOfBankAccounts[i].IBAN, IBAN1)) return &ArrayOfBankAccounts[i];
		return NULL;
	}*/

};
ClientBank::ClientBank() {
	clinetNumber = number;
	number++;
	NumberOfBankAccounts = 0;
}
ClientBank::ClientBank(const char* Name1, const char* Fam1) {
	strcpy_s(Name, Name1);
	strcpy_s(Fam, Fam1);
	clinetNumber = number;
	number++;
	NumberOfBankAccounts = 0;
}
int ClientBank::AddBankAcc(const char* AccType1, const char* IBAN1, int Amount1) {
	if (NumberOfBankAccounts > 10) return 0;
	strcpy_s(ArrayOfBankAccounts[NumberOfBankAccounts].AccType, AccType1);
	strcpy_s(ArrayOfBankAccounts[NumberOfBankAccounts].IBAN, IBAN1);
	ArrayOfBankAccounts[NumberOfBankAccounts].Amount = Amount1;
	NumberOfBankAccounts++;
	return 1;
}
int ClientBank::RemoveBankAcc(const char* IBAN1) {
	if (NumberOfBankAccounts < 1) {
		printf("\n nqma bankovi smetki");

	}
	//ako ima samo 1 bankova smetka 
	if (NumberOfBankAccounts == 1) {
		ArrayOfBankAccounts[0] = ArrayOfBankAccounts[1];
	}
	for (int i = 1; i < 10; i++) {
		if (strcmp(ArrayOfBankAccounts[i].IBAN,IBAN1)) {
			for (int j = i; j < 10; j++)
				ArrayOfBankAccounts[j - 1] = ArrayOfBankAccounts[j];
		}
	}

	return 0;

}
int ClientBank::number = 1000;

int main() {
	ClientBank bank1("spasina", "spasowa");
	bank1.AddBankAcc("depozit", "BGN125", 150.23);
	bank1.AddBankAcc("depozit", "BGN126", 150.23);
	bank1.AddBankAcc("depozit", "BGN127", 150.23);
	bank1.RemoveBankAcc("BGN126");
	return 1;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
