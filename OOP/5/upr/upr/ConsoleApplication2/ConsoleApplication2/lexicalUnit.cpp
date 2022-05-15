#include "stdafx.h"
#include "lexicalUnit.h"
#include <string.h>

lexicalUnit::lexicalUnit()
{
	/*identificator[0] = 0;
	type[0] = 0;
	descriptor[0] = 0;*/
	address = 0;
}

lexicalUnit::lexicalUnit(char *pIdentificator, char *pType){
	strcpy_s(identificator, 20, pIdentificator);
	strcpy_s(type, 20, pType);
	setAddress(pType);
	setDescriptor();
}
lexicalUnit& lexicalUnit::operator=(lexicalUnit& lu){
	strcpy_s(identificator, 20, lu.identificator);
	strcpy_s(type, 20, lu.type);
	strcpy_s(descriptor, 5, lu.descriptor);
	address = lu.address;
	return lu;
}

char* lexicalUnit::getIdentificator(){
	return identificator;
}
void lexicalUnit::print(){
	printf_s("Identificator: %s\nType: %s\nDescriptor: %s\nAddress: %d\n", identificator, type, descriptor, address);
}

void lexicalUnit::setAddress(char *type)
{
	address = newAddress; //полето на класа получава стойността на статичната променлива, след което тя се променя според типа
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
void lexicalUnit::setDescriptor(){
	sprintf_s(descriptor, "V%d", newDescriptor);
	newDescriptor++;
}
