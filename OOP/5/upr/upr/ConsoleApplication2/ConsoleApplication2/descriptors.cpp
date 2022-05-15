#include "stdafx.h"
#include "descriptors.h"
#include "memory.h"
#include <iostream>
#include <stdio.h>
#include "lexicalUnit.h"

descriptors::descriptors()
{
	number = 0;
}

descriptors::~descriptors()
{
	free(table);
}

void descriptors::Print() {

	int i;

	for (i = 0; i < number; i++)
	{
		table[i].print();
	}

}

int descriptors::Search(const char* pIdentificator) {
	int i;

	for (i = 0; i < number; i++) {
		if (!strcmp(table[i].getIdentificator(), pIdentificator))
		{
			return i;
		}
	}
	return -1;
}
int descriptors::Del(const char* pIdentificator) {
	int position;
	position = Search(pIdentificator);
	if (position == -1) {
		return 0;
	}
	for (int i = position; i < number - 1; i++)
	{
		table[i] = table[i + 1];
	}
	number--;
	return 1;
}
int descriptors::Add(lexicalUnit& lu) {
	if (number >= 100) {
		return 0;
	}
	int here = Search(lu.getIdentificator());
	if (here != -1) {
		return 0;
	}
	table[number] = lu;
	number++;
	return 1;
}
