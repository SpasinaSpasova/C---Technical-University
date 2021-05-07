/*To define the structure of the data 
that describe the sales in a store.
 Write a function that 
 prints the company data on the screen according to a given "id".*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char articleName[50];
	float quantity;
	float price;
}Sale;

typedef struct
{
	char name[50];
	int ID;
	char address[80];
	char MOL[50];
	Sale Sales[5];
}Company;

void PrintCompany(Company *c, int itemCount, int id)
{
	int i;
	for(i=0;i<itemCount;i++)
	{
		if(c[i].ID==id)
		{
				printf("%s %d %s %s\n",
			       c[i].name,
				   c[i].ID,
				   c[i].address,
				   c[i].MOL);
				printf("%s %f %f",
			       c[i].Sales[0].articleName,
				   c[i].Sales[0].quantity,
				c[i].Sales[0].price);
		}
	}
}
