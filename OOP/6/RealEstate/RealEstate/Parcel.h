#pragma once
#include "Imot.h"
class Parcel : public Imot
{
	bool water;
	bool el;
	float nearTheRoad;
public:
	Parcel();
	Parcel(bool w,bool el2, float nearTheRoad2, const char* address2, const  char* owner2, float price2, float area2);
	void print();
};

