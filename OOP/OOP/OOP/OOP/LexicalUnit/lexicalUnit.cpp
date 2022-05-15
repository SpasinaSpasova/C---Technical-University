#include "lexicalUnit.h"
#include <iostream>
#include <string.h>
#include <memory>


void lexicalUnit::setDescriptor()
{
	sprintf_s(descriptor, "V%d", newDescriptor);

	newDescriptor++;
}
lexicalUnit::lexicalUnit() {
	identificator[0] = 0;
	descriptor[0] = 0;
	type[0] = 0;
	address = 0;
}
lexicalUnit::lexicalUnit(const char* pIdentificator,const char* pType) {
	strcpy_s(identificator, pIdentificator);
	strcpy_s(type, pType);
	setAddress(type);
	setDescriptor();
}

lexicalUnit& lexicalUnit::operator=(lexicalUnit& lu) {
	strcpy_s(identificator, lu.identificator);
	strcpy_s(type, lu.type);
	strcpy_s(descriptor, lu.descriptor);
	address = lu.address;
	return *this;
}
char* lexicalUnit::getIdentificator()
{
	return identificator;
}
void lexicalUnit::setAddress(char* type)
{
	address = newAddress; 
	int size = 0;
	if (strcmp(type, "int") == 0)
		size = 2;
	if (strcmp(type, "char") == 0)
		size = 1;
	if (strcmp(type, "float") == 0)
		size = 4;
	if (strcmp(type, "double") == 0)
		size = 8;

	newAddress += size;
}
void lexicalUnit::print()
{
	printf_s("%s %s %s %d\n", identificator, type, descriptor, address);
	
}