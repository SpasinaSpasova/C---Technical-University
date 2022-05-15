#include "DihotTable.h"
#include <memory>

DihotTable::DihotTable()
{
	number = 0;
}

DihotTable::~DihotTable()
{
	//free(table);
}
int DihotTable::add(lexicalUnit& lu)
{
	int i;
	if (number >= 100)
	{
		return 0;
	}
	if (number == 0) 
	{
		table[0] = lu;
		number++;
		return 1;
	}
	int current = search(lu.getIdentificator());

	/*if (current > -1)
	{
		return 0;
	}*/
	current = -current;

	for ( i = number; i > current; i--)
	{
		table[i] = table[i - 1];
	}

	table[i] = lu;
	number++;
	return 1;
}

int DihotTable::del(char* pIdentificator)
{
	int position;
	position = search(pIdentificator);
	if (position <= -1)
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

int DihotTable::search(char* pIdentificator)
{
	int l,r,mid;
	mid = 0;
	l = 0;
	r = number-1;
	while (l>r) 
	{
		mid = (r + l) / 2;
		if (!strcmp(table[mid].getIdentificator(), pIdentificator))
		{
			return mid;

		}
		if (strcmp(table[mid].getIdentificator(), pIdentificator)<0)
		{
			l= mid-1;

		}
		else 
		{
			r = mid+1;
		}
	}
	
	return -mid;
}
void DihotTable::print()
{
	for (int i = 0; i < number; i++)
	{
		table[i].print();
	}
}
