#pragma once
#include "clientBank.h"
#include "fibonacci.h"
class Bank
{
	ClientBank* Table;
	int TableEnd;
	int size;
	Fibonacci Fnumber;
public:
	Bank(int parameter);
	Bank();
	~Bank();
	int Append(ClientBank& client);
	int Delete();
};

