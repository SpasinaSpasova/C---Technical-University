#pragma once
class Imot
{
public:
	char address[200];
	char owner[200];
	float price;
	float area;
public:
	virtual void print();
	Imot();
	Imot( const char* address, const char* owner, float price, float area);
};

