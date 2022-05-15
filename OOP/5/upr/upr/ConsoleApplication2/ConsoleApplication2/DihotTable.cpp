#include "lexicalUnit.h"
#include "memory.h"
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "DihotTable.h"

DihotTable::~DihotTable() {
	free(Table);
}

void DihotTable::Print() {
	int i;

	for (i = 0; i < lexicalUnitCount; i++)
	{
		Table[i].print();
	}
}
int DihotTable::SearchLexicalUnitById(const char* pIdentificator) {

	int l, r, mid;
	mid = 0;
	l = 0;
	r = lexicalUnitCount;
	while (l < r) {
		mid = (r + l) / 2;

		if (!strcmp(Table[mid].getIdentificator(), pIdentificator)) {
			return mid;
		}
		if (strcmp(Table[mid].getIdentificator(), pIdentificator) < 0) {
			l = mid+1;
		}
		else {
			r = mid-1;
		}

	}
	return -mid;
}
int DihotTable::AddLexicalUnit(lexicalUnit& lu) {
	int i;

	if (lexicalUnitCount >= 100) {
		return 0;
	}

	if (lexicalUnitCount == 0) {
		Table[0] = lu;
		lexicalUnitCount++;
		return 1;
	}

	int here = SearchLexicalUnitById(lu.getIdentificator());

	/*if (here > -1) {
		return 0;
	}*/
	here = -here;

	for (i = lexicalUnitCount; i > here; i--) {
		Table[i] = Table[i - 1];
	}

	Table[i] = lu;
	lexicalUnitCount++;
	return 1;
}
int DihotTable::DeleteLexicalUnit(const char* pIdentificator) {
	int position;
	position = SearchLexicalUnitById(pIdentificator);
	if (position <= -1) {
		return 0;
	}
	for (int i = position; i < lexicalUnitCount - 1; i++)
	{
		Table[i] = Table[i + 1];
	}
	lexicalUnitCount--;
	return 1;
}
