#include "Film.h"
#include <string.h>
#include <stdio.h>


Film::Film() {
	year = 0;
	price = 0;
}
Film::Film(const char* filmNamec, int yearc, const char* genrec, double pricec) {
	strcpy_s(filmName, filmNamec);
	year = yearc;
	strcpy_s(genre, genrec);
	price = pricec;
}
void Film::PrintFilm() {
	printf("The film name is: %s;\nYear: %d; Genre: %s; Price: %flv.\n", filmName, year, genre, price);
}