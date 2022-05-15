#pragma once
#include "lexicalUnit.h"
class descriptors
{
	lexicalUnit table[100];
	int number;
public:
	descriptors();
	~descriptors();
	int Add(lexicalUnit &lu);          // връща 1, при успешно добавяне и 0 в противен случай
	int Del(const char *pIdentificator);     // връща 1, при успешно изтриване и 0 в противен случай
	int Search(const char  *pIdentificator); // връща позицията на лексическата единица в масива или -1 в противен случай
	void Print();
};

