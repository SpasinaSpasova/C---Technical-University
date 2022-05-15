#include "Apartament.h"
#include <string.h>
#include <stdio.h>

Apartament::Apartament() {
	countRoom = 0;
	floor = 0;
}
Apartament::Apartament(int cr, int f, const char* address2, const  char* owner2, float price2, float area2)
	:Imot(address2, owner2, price2, area2) {

	countRoom = cr;
	floor = f;

	strcpy_s(address, 200, address2);
	strcpy_s(owner, 200, owner2);
	price = price2;
	area = area2;
}
void Apartament::print() {
	printf("\nApartament\nRooms: %d\nFloor: %d\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", countRoom, floor, address, owner, price, area);
}