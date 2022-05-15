#include "Agenciq.h"
#include <string.h>
#include <stdio.h>



Agenciq::Agenciq(const char* nameOfAgency) {
	strcpy_s(nameAgency, 100, nameOfAgency);
	countImoti = 0;

}
int Agenciq::Add(Imot* imot) {
	if (countImoti >= 100) return 0;
	arrImot[countImoti] = imot;
	
	countImoti++;
	return 1;
}
int Agenciq::Remove(Imot* imot) {
	int position;
	position = Search(imot->owner, imot->address);
	if (position <= -1) {
		return 0;
	}
	for (int i = position; i < countImoti; i++)
	{
		arrImot[i] = arrImot[i + 1];
	}
	countImoti--;
	return 1;
}
int Agenciq::Search(const char* imotOwner, const char* imotAddress) {
	int i;
	for (i = 0; i < countImoti; i++)
	{
		if (!strcmp(arrImot[i]->owner, imotOwner)
			&& !strcmp(arrImot[i]->address, imotAddress)
			)
		{
			return i;
		}
	}
	return -1;
}
void Agenciq::print() {
	int i;
	if (countImoti == 0) {
		printf("%s has not estates!!! \n", nameAgency);
	}
	else {
		printf("%s has this estates: \n", nameAgency);
		for (i = 0; i < countImoti; i++)
		{
			arrImot[i]->print();
		}
	}
	
}