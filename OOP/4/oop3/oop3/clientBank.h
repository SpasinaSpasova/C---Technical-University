#pragma once
struct BankAccount
{
	char type[40];
	char IBAN[60];
	double sum;
};


struct Client
{
	char name[30];
	char fam[50];
	int count;
	int clientNumber;
};

class ClientBank
{
	BankAccount TableArr[100];
	Client tempInfo;
	int count;
public:
	ClientBank() { count = 0; };
	ClientBank(const char* name, const char* fam, int count);
	int Add(const char* type, const char* IBAN, double sum);
	int Remove(const char* IBAN);
	int SearchBankAccount(const char* IBAN);
	int AddSummToBankAccount(double sum, const char* IBAN);
	double TotalSum();
	void PrintData();
};

