#include "House.h"
#include <string.h>
#include <stdio.h>

House::House() {
	countRoom = 0;
	countFloor = 0;
	greenArea = 0;
}
House::House(int cr, int cf,float ga, const char* address2, const  char* owner2, float price2, float area2)
	:Imot(address2, owner2, price2, area2) {

	countRoom = cr;
	countFloor = cf;
	greenArea = ga;

	strcpy_s(address, 200, address2);
	strcpy_s(owner, 200, owner2);
	price = price2;
	area = area2;
}
void House::print() {
	printf("\nHouse\nRooms: %d\nFloors: %d\nGreenArea: %f\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", countRoom, countFloor,greenArea, address, owner, price, area);
}