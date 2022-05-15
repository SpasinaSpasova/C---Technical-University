#pragma once
class Film
{
	static int int1, int2;
public:
	char filmName[100];
	int year;
	char genre[20];
	double price;
public:
	Film();
	Film(const char* filmNamec, int yearc, const char* genrec, double pricec);
	void PrintFilm();

};

