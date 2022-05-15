#include "Ticket.h"
#include <stdio.h>
#include <string.h>

Ticket::Ticket() {
	numOfRow = 0;
	seatNumber = 0;
	price = 0;
}
Ticket::Ticket(int numOfRowc, int seatNumberc, const char* dataOfProjectionc, Film* filmc, double pricec) {
	numOfRow = numOfRowc;
	seatNumber = seatNumberc;
	strcpy_s(dataOfProjection, dataOfProjectionc);
	film = filmc;
	price = pricec;
}
void Ticket::Sell() {
	printf("Total price is %flv.\n", price);
}
void Ticket::PrintTicket() {
	printf("Ticket information:\nRow: %d; Seat: %d; Data: %s; Film: %s; Price: %flv.\n", numOfRow, seatNumber, dataOfProjection, film->filmName, price);
}