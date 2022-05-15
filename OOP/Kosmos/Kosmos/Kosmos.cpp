// Kosmos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
class NebesnoTqlo
{
protected:
	char ime[50];
	float obem, masa, x, y, z;
public:
	NebesnoTqlo() {
		obem = masa = x = y = z = 0;
	};
	void Set();
	NebesnoTqlo(char const* imec, float obemc, float masac, float xc, float yc, float zc);

};
void NebesnoTqlo::Set() {
	obem = masa = x = y = z = 0;
}
NebesnoTqlo::NebesnoTqlo(char const* imec, float obemc, float masac, float xc, float yc, float zc) {
	strcpy_s(ime, imec);
	obem = obemc;
	masa = masac;
	x = xc;
	y = yc;
	z = zc;
}


class Spatnik :NebesnoTqlo
{
	char planetName[100];
public:
	Spatnik();
	Spatnik(char const* imec, float obemc, float masac, float xc, float yc, float zc, char const* imeplaneta);
};
Spatnik::Spatnik(char const* imec, float obemc, float masac, float xc, float yc, float zc, char const* imeplaneta)
	:NebesnoTqlo(imec, obemc, masac, xc, yc, zc) {
	strcpy_s(ime, imec);
	obem = obemc;
	masa = masac;
	x = xc;
	y = yc;
	z = zc;
	strcpy_s(planetName, imeplaneta);
}

class Planeta : public NebesnoTqlo
{
	bool atmosfera;
	Spatnik* sparr[100];
	int countSpatnici;
public:
	Planeta(char const* imec, float obemc, float masac, float xc, float yc, float zc, bool atmosferac);
	Planeta& operator=(Planeta& p);
	void print();
};
void Planeta::print() {
	printf("%s", ime);
}
Planeta &Planeta::operator=(Planeta& p){
	obem = p.obem;
	masa = p.masa;
	x = p.x;
	y = p.y;
	z = p.z;
	strcpy_s(ime, p.ime);
	return *this;
}
Planeta::Planeta(char const* imec, float obemc, float masac, float xc, float yc, float zc, bool atmosferac)
	:NebesnoTqlo(imec, obemc, masac, xc, yc, zc) {
	strcpy_s(ime, imec);
	obem = obemc;
	masa = masac;
	x = xc;
	y = yc;
	z = zc;
	countSpatnici = 0;
	atmosfera = atmosferac;
}



int main()
{
	Planeta p1("p1", 12, 13, 14, 15, 16, true);
	p1.print();
	Planeta p2("p2", 122, 123, 124, 125, 126, false);
	p2.print();
	p1 = p2;
	p1.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

