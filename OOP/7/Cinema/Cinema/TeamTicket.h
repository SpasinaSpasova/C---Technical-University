#pragma once
#include "Ticket.h"
class TeamTicket : public Ticket
{
	int countVisitors;
public:
	TeamTicket(int countVisitorsc, int numOfRowc, int seatNumberc, const char* dataOfProjectionc, Film* filmc, double pricec);
	void PrintTicket();
	void Sell();
};

