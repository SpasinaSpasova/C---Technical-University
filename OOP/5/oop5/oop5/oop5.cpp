#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct lexicalUnit {
	char identificator[20];
	char type[20];
	char descriptor[5];
	int address;
};

class Unit {
	lexicalUnit Table[100];
	int tableEnd;
	void SetAddress(char* type);
	void SetDescriptor();

public:
	static int newAddress;
	static int newDescriptor;
	Unit();
	~Unit();
	int Add(lexicalUnit& lu);
	int Del(const char* pIdentificator);
	int Search(const char* pIdentificator);
	void Print();
};
int Unit::newAddress = 0;
int Unit::newDescriptor = 1;
Unit::~Unit()
{
	free(Table);
}
Unit::Unit() {
	tableEnd = 0;
}
void Unit::SetAddress(char* type) {

	//  address = newAddress;
	int size = 0;

	if (strcmp(type, "int") == 0) {
		size = 2;
	}
	if (strcmp(type, "char") == 0) {
		size = 1;
	}
	if (strcmp(type, "float") == 0) {
		size = 4;
	}
	if (strcmp(type, "double") == 0) {
		size = 8;
	}
	newAddress += size;
}
void Unit::Print() {

	int i;

	for (i = 0; i < tableEnd; i++)
	{
		printf_s("%s %s %s %d\n", Table[i].identificator, Table[i].type, Table[i].descriptor, Table[i].address);
	}

}

int Unit::Search(const char* pIdentificator) {
	int i;

	for (i = 0; i < tableEnd; i++) {
		if (!strcmp(Table[i].identificator, pIdentificator))
		{
			return i;
		}
	}
	return -1;
}
int Unit::Del(const char* pIdentificator) {
	int position;
	position = Search(pIdentificator);
	if (position == -1) {
		return 0;
	}
	for (int i = position; i < tableEnd - 1; i++)
	{
		Table[i] = Table[i + 1];
	}
	tableEnd--;
	return 1;
}
int Unit::Add(lexicalUnit& lu) {
	if (tableEnd >= 100) {
		return 0;
	}
	int here = Search(lu.identificator);
	if(here!=-1){
		return 0;
	}
	Table[tableEnd] = lu;
	tableEnd++;
	return 1 ;
}
void Unit::SetDescriptor() {

}
int main()
{
	printf("hello");
}