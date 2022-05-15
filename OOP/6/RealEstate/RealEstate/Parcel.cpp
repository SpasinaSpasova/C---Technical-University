#include "Parcel.h"
#include <string.h>
#include <stdio.h>

Parcel::Parcel() {
	water = false;
	el = false;
	nearTheRoad = 0;
}
Parcel::Parcel(bool w, bool el2, float nearTheRoad2, const char* address2, const  char* owner2, float price2, float area2)
	:Imot(address2, owner2, price2, area2) {

	water = w;
	el = el2;
	nearTheRoad = nearTheRoad2;

	strcpy_s(address, 200, address2);
	strcpy_s(owner, 200, owner2);
	price = price2;
	area = area2;
}
void Parcel::print() {
	if (!water && !el) {
		printf("\nParcel\nWater: NO\nEl: NO\nNearTheRoad: %f\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", nearTheRoad, address, owner, price, area);

	}
	else if (water && el) {
		printf("\nParcel\nWater: YES\nEl: YES\nNearTheRoad: %f\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", nearTheRoad, address, owner, price, area);

	}
	else if (!water && el) {
		printf("\nParcel\nWater: NO\nEl: YES\nNearTheRoad: %f\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", nearTheRoad, address, owner, price, area);

	}
	else if (water && !el) {
		printf("\nParcel\nWater: YES\nEl: NO\nNearTheRoad: %f\nAddress: %s\nOwner: %s\nPrice: %f\nArea: %f\n", nearTheRoad, address, owner, price, area);

	}

}