// RealEstate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Imot.h"
#include "Apartament.h"
#include "House.h"
#include "Parcel.h"
#include "Agenciq.h"


int main()
{
	Agenciq agenciq("RealEstate");

	Imot imot("bul.Bulgaria", "Spasina", 20000.0, 50.0);
	agenciq.Add(&imot);

	Apartament apartament(3, 2, "ul.Ruski", "Vesa", 350000, 100);
	agenciq.Add(&apartament);

	House house(10, 3, 500, "ul.Pere Toshev", "Nikolay", 200000, 300);
	agenciq.Add(&house);

	Parcel parcel(1, 0, 50, "ul.Stefov", "Milka", 5000, 100);
	agenciq.Add(&parcel);

	agenciq.Remove(&imot);
	agenciq.Remove(&apartament);
	agenciq.Remove(&house);
	agenciq.Remove(&parcel);

	agenciq.print();
}

