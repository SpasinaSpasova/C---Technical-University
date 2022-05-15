#include "clientBank.h"
#include <iostream>
#include <string.h>
#include <memory>

int ClientBank::Add(const char* type, const char* IBAN, double sum)
{
	if (count >= 100) return 0;
	strcpy_s(TableArr[count].type, 40, type);
	strcpy_s(TableArr[count].IBAN, 60, IBAN);
	TableArr[count].sum = sum;
	count++;
	return 1;
}
int ClientBank::Remove(const char* IBAN)
{
	int position;
	position = SearchBankAccount(IBAN);
	if (position == -1) {
		return 0;
	}
	for (int i = position; i < count - 1; i++)
	{
		TableArr[i] = TableArr[i + 1];
	}
	count--;
	//uspeshno iztrit element
	return 1;
}
int ClientBank::SearchBankAccount(const char* IBAN)
{
	int i;

	for (i = 0; i < count; i++) {
		if (!strcmp(TableArr[i].IBAN, IBAN))
		{
			return i;

		}
	}
	return -1;
}
int ClientBank::AddSummToBankAccount(double sum, const char* IBAN)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (strcmp(TableArr[i].IBAN, IBAN)) {
			TableArr[i].sum += sum;
			return 1;
		}
	}
	return 0;
}
double ClientBank::TotalSum()
{
	int i;
	double total = 0;
	for (i = 0; i < count; i++)
	{
		total = total + TableArr[i].sum;
	}
	return total;
}
void ClientBank::PrintData()
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf_s("%s %s %d\n", tempInfo.name, tempInfo.fam, tempInfo.clientNumber);
	}
}