#include "bank.h"
#include <iostream>
#include <string.h>
#include <memory>

Bank::Bank(int parameter)
{
	TableEnd = 0;
	size = Fnumber.Set(parameter);
	Table = new ClientBank[size];
}

Bank::~Bank()
{
	free(Table);
}
Bank::Bank()
{
	TableEnd = 0;
	size = Fnumber.Set(2);
	Table = new ClientBank[size];

}
int Bank::Append(ClientBank& client)
{
	ClientBank* t;
	if (TableEnd == size) {
		int fibo = Fnumber.Set(size);
		t = new ClientBank[fibo];
		if (t == NULL) {
			return -1;
		}
		memcpy(t, Table, sizeof(ClientBank) * TableEnd);
		delete[] Table;
		Table = t;
		size = fibo;
	}
	Table[TableEnd] = client;
	TableEnd++;
	return 0;
}
int Bank::Delete()
{
	return 0;
}