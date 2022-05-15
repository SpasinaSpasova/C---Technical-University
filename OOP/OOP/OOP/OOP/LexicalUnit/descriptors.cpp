#include "descriptors.h"
#include "lexicalUnit.h"
#include <iostream>
#include <string.h>
#include <memory>

descriptors::descriptors()
{
}

descriptors::~descriptors()
{
	free(table);
}

int descriptors::add(lexicalUnit& lu)
{
	if (number >= 100) 
	{
		return 0;
	}

	int current = search(lu.getIdentificator());

	if (current = !- 1) 
	{
		return 0;
	}

	table[number] = lu;
	number++;
	return 1;
}

int descriptors::del(char* pIdentificator)
{
	int position;
	position = search(pIdentificator);
	if (position == -1) 
	{
		return 0;
	}
	for (int i = position; i < number - 1; i++)
	{
		table[i] = table[i + 1];
	}
	number--;
	return 1;
}

int descriptors::search(char* pIdentificator)
{
	int i;

	for (i = 0; i < number; i++) 
	{
	
		if (!strcmp(table[i].getIdentificator(), pIdentificator))
		{
			return i;

		}
	}
	return -1;
}
void descriptors::print()
{
	for (int i = 0; i < number; i++)
	{
		table[i].print();
	}
}