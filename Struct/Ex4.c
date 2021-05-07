/*Define the data structure.
 Write a function that gets an array of this structure 
 and the number of elements in it. 
 The function must return a pointer 
 to the item with the largest amount available in its bank account.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char EGN[10];
	char name[10];
	int ammount;
}BankAcc;

BankAcc* func(BankAcc* Arr, int count)
{
	int i;
	int maxSum=Arr[0].ammount;
	int maxIndex=0;
	
	for(i=0;i<count;i++)
	{
		if(maxSum<Arr[i].ammount)
		{
			maxSum= Arr[i].ammount;
			maxIndex=i;
		}
	}
	BankAcc *p= &Arr[maxIndex];
	printf("%s %s %d", p->EGN, p->name,p->ammount);
	return p;
}
