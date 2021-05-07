/*to write the function which receives a two-dimensional 
array of arbitrary dimension and 
returns the sum of all elements 
and the number of negative elements.*/
#include<stdio.h>
#include<stdlib.h>
int ArrayCount(int *A,int rowCount,int colCount,int *NegCount)
{
	int i,j,sum=0;
	for(i=0;i<rowCount;i++)
	{
		for(j=0;j<colCount;j++)
		{
			sum+=A[i*colCount+j];
			if(A[i*colCount+j]<0)
			{
				(*NegCount)++;
			}
		}
	}
	return sum;
}
