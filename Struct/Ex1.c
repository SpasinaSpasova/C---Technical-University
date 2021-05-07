/* To define the structure of data 
on bank accounts of individuals. 
Write a function that obtains an array 
of arbitrary dimension from 
this structure and a reference sum. 
The function is to print on the screen the names of the 
persons who have in their account a balance 
greater than the reference amount.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char FName[25];
	char SName[25];
	char LName[25];
}PName;

typedef struct
{
	PName name;
	char EGN[15];
	char AccountNr[80];
	float AccountSum;
}Person;

void PrintPersonAccount(Person *p,int itemCount, float refSum)
{
	int i;
	for(i=0;i<itemCount;i++)
	{
		if(p[i].AccountSum>refSum)
		{
			printf("%s\t %s\t %s\t %s\t %s\t %f\n",
			       p[i].name.FName,
				   p[i].name.SName,
				   p[i].name.LName,
				   p[i].EGN,
				   p[i].AccountNr,
				   p[i].AccountSum);
		}
	}
}
void PrintPersonAccount_Second(Person *p,int itemCount, PName *names,char*egn)
{
	int i,maxIndex=0;
	float maxSum= p[0].AccountSum;
	
	for(i=1;i<itemCount;i++)
	{
		if(p[i].AccountSum>maxSum)
		{
		maxSum=p[i].AccountSum;
		maxIndex=i;
		}
	}
	
	strcpy(names->FName,p[maxIndex].name.FName);
	strcpy(names->SName,p[maxIndex].name.SName);
	strcpy(names->LName,p[maxIndex].name.LName);
	strcpy(egn,p[maxIndex].EGN);
	
}
