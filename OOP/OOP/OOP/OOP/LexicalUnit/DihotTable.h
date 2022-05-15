#pragma once

#include "descriptors.h"
#include "lexicalUnit.h"
class DihotTable
{
	lexicalUnit table[4];
	int number;
public:
	DihotTable();
	~DihotTable();
	int add(lexicalUnit& lu);         
	int del(char* pIdentificator);    
	int search(char* pIdentificator); 
	void print();

};

