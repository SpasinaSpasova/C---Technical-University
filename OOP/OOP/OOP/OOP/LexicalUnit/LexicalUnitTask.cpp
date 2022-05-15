
//#include "stdafx.h"
#include <iostream>
#include "descriptors.h"
#include "lexicalUnit.h"
#include "HashTable.h"
#include "DihotTable.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int lexicalUnit::newAddress = 0;     // инициализация на статична променлива
int lexicalUnit::newDescriptor = 1;  // инициализация на статична променлива

int main()
{
	lexicalUnit lexicalUnit0("lu", "float");
	lexicalUnit lexicalUnit1("ll", "int");
	lexicalUnit lexicalUnit2("ll2", "int");
	lexicalUnit lexicalUnit3("ll3", "int");

	HashTable hashTable;
	hashTable.add(lexicalUnit0);
	hashTable.add(lexicalUnit1);
	hashTable.print();
	hashTable.remove("lu");
	hashTable.print();
	//// EX.2
	//DihotTable dihot;
	//dihot.add(lexicalUnit0);
	//dihot.add(lexicalUnit1);
	//dihot.add(lexicalUnit2);
	//dihot.add(lexicalUnit3);
	//dihot.print();

	// EX.1
	//Descriptor descriptor;
	//descriptor.add(lexicalUnit);
	//descriptor.add(lexicalUnit1);
	//descriptor.print();
	//descriptor.search(lexicalUnit1.getIdentificator());
	//descriptor.del(lexicalUnit.getIdentificator());
	//descriptor.print();


	return 0;
}


