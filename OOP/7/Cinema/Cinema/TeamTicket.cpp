#include "TeamTicket.h"
#include <string.h>
#include <stdio.h>

TeamTicket::TeamTicket(int countVisitorsc, int numOfRowc, int seatNumberc, const char* dataOfProjectionc, Film* filmc, double pricec)
	:Ticket(numOfRowc, seatNumberc, dataOfProjectionc, filmc, pricec)
{
	numOfRow = numOfRowc;
	seatNumber = seatNumberc;
	strcpy_s(dataOfProjection, dataOfProjectionc);
	film = filmc;
	countVisitors = countVisitorsc;
	price = pricec;
}
void TeamTicket::PrintTicket() {
	printf("TEAM Ticket information:\nRow: %d; Seat: %d; Data: %s; Film: %s; Price for film: %flv.\n", numOfRow, seatNumber, dataOfProjection, film->filmName, price);
}
void TeamTicket::Sell() {
	double total = 0;
	if (countVisitors >= 10) {
		total = price - ((price * 10) / 100);
		total *= countVisitors;
	}
	else if (countVisitors >= 20) {
		total = price - ((price * 20) / 100);
		total *= countVisitors;
	}
	else if (countVisitors < 10) {
		total = price;
		total *= countVisitors;
	}
	
	printf("TEAM Total price is %flv.\n", total);
}