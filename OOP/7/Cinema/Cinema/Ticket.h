#pragma once
#include "Film.h"

class Ticket
{
public:
	int numOfRow;
	int seatNumber;
	char dataOfProjection[9];
	Film* film;
	double price;
public:
	Ticket();
	Ticket(int numOfRowc, int seatNumberc, const char* dataOfProjectionc, Film* filmc, double pricec);
	virtual void PrintTicket();
	virtual void Sell();
};

