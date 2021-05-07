/*Write a function that gets 
two integer two-dimensional arrays of equal dimensions. 
The function must compare the two arrays
and return the row and column of the first different element encountered.*/
#include<stdio.h>
#include<stdlib.h>

int ArrayComp(int *arr1,int *arr2, int rowCount,int colCount,int *R,int *C)
{
	int i,j;
	for(i=0;i<rowCount;i++)
	{
		for(j=0;j<colCount;j++)
		{
			if(arr1[i*colCount+j]!=arr2[i*colCount+j])
			{
				*R=i;
				*C=j;
				return 1;
			}
		}
	}
	return 0;
}
