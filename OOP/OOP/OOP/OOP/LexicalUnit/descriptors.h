#pragma once

#include "lexicalUnit.h"
#include <iostream>
#include <string.h>
#include <memory>
class descriptors
{
	lexicalUnit table[100];
	int number;
public:
	descriptors();
	~descriptors();
	int add(lexicalUnit & lu);         
	int del(char* pIdentificator);     
	int search(char* pIdentificator);  
	void print();
};
