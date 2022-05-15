#pragma once
#include "lexicalUnit.h"
class DihotTable {
	lexicalUnit Table[100];
	int lexicalUnitCount;
public:
	DihotTable() { lexicalUnitCount = 0; }
	~DihotTable();
	int SearchLexicalUnitById(const char* pIdentificator);
	int AddLexicalUnit(lexicalUnit& lu);
	int DeleteLexicalUnit(const char* pIdentificator);
	void Print();
};