#pragma once

#include "Imot.h"
#include <stdio.h>
#include <iostream>

class Agenciq
{
	char nameAgency[100];
	int countImoti;
	Imot* arrImot[200];
public:
	Agenciq(const char* nameOfAgency);
	int Add(Imot* imot);
	int Remove(Imot* imot);
	int Search(const char * imotOwner, const char * imotAddress);
	void print();
};

