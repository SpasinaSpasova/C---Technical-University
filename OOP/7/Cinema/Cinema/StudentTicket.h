#pragma once
#include "Ticket.h"
class StudentTicket : public Ticket
{
public:
	StudentTicket(int numOfRowc, int seatNumberc, const char* dataOfProjectionc, Film* filmc, double pricec);
	void PrintTicket();
	void Sell();
};

