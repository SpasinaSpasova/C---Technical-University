#pragma once
#include "Imot.h"
class Apartament : public Imot
{
	int countRoom;
	int floor;
public:
	Apartament();
	Apartament(int cr,int f, const char* address2, const  char* owner2, float price2, float area2);
	void print();
};

