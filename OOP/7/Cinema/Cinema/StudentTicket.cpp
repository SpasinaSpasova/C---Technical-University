#include "StudentTicket.h"
#include <string.h>
#include <stdio.h>

StudentTicket::StudentTicket(int numOfRowc, int seatNumberc, const char* dataOfProjectionc, Film* filmc, double pricec)
	:Ticket(numOfRowc, seatNumberc, dataOfProjectionc, filmc, pricec)
{
	numOfRow = numOfRowc;
	seatNumber = seatNumberc;
	strcpy_s(dataOfProjection, dataOfProjectionc);
	film = filmc;
	price = pricec;
}
void StudentTicket::PrintTicket() {
	printf("STUDENT Ticket information:\nRow: %d; Seat: %d; Data: %s; Film: %s; Price: %flv.\n", numOfRow, seatNumber, dataOfProjection, film->filmName, price);
}
void StudentTicket::Sell() {
	double total = 0;
	total = price - ((price * 20) / 100);
	printf("STUDENT Total price is %flv.\n", total);
}