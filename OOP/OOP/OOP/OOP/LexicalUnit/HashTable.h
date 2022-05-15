#pragma once
#include "lexicalUnit.h"


class HashTable {
	lexicalUnit hashTable[128];
	int length;
public:
	HashTable();
	~HashTable();

	int doHashing(const char* id);
	int search(const char* _identificator);
	int add(lexicalUnit& lu);
	int remove(const char* _identificator);
	void print();
};
