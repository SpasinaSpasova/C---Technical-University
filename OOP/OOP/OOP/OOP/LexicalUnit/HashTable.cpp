#include "stdafx.h"
#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {
	length = 0;
};

HashTable::~HashTable() {
	free(hashTable);
};

int HashTable::doHashing(const char* id) {
	int sum = 0;
	// id[i] != '/0'
	for (int i = 0; id[i]; i++) {
		sum += id[i];
	}
	// Thousand times more faster than {sum % 128}
	return sum & 127;
};

int HashTable::search(const char* _identificator) {
	int hashIndex = doHashing(_identificator);
	if (hashIndex == 0) {
		// if collision
	}

	int startIndex = hashIndex;
	while (1) {


		if (strcmp(hashTable[hashIndex].getIdentificator(), _identificator) == 0) {
			return hashIndex;
		}

		if (strcmp(hashTable[hashIndex].getIdentificator(), "") == 0) {
			return -hashIndex;
		}

		if (hashIndex == 127) {
			hashIndex = 0;
		}

		if (startIndex == hashIndex - 1) {
			break;
		}

		hashIndex++;
	}

	return -1;
};
int HashTable::add(lexicalUnit& lu) {
	int hashIndex = search(lu.getIdentificator());

	if (hashIndex < 0) {
		hashIndex = -hashIndex;
	}

	hashTable[hashIndex] = lu;
	return hashIndex;
};
int HashTable::remove(const char* _identificator) {
	int hashIndex = search(_identificator);

	if (hashIndex >= 0) {
		hashTable[hashIndex].getIdentificator()[0] = 0;
	}

	return -1;
};
void HashTable::print() {
	for (int i = 87; i < 128; i++) {
		int idx = search(hashTable[i].getIdentificator());
		if (idx > 0) {
			cout << "Row:" << i + 1 << endl;
			hashTable[i].print();
		}
	}
};