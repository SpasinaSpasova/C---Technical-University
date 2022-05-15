#include "Imot.h"
#include <string.h>
#include <stdio.h>

Imot::Imot() {
	 price=0;
	 area=0;
}
Imot::Imot(const char* address2, const  char* owner2, float price2, float area2) {
	strcpy_s(address, 200, address2);
	strcpy_s(owner, 200, owner2);
	price = price2;
	area = area2;
}
void Imot::print() {
	printf("\nImot\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", address, owner, price, area);
}