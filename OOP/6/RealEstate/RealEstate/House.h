#pragma once
#include "Imot.h"
class House : public Imot
{
	int countRoom;
	int countFloor;
	float greenArea;
public:

	House();
	House(int cr, int cf,float ga, const char* address2, const  char* owner2, float price2, float area2);
	void print();
};

