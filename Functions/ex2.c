/*Write a function that takes a one-dimensional array of fractional numbers
 and its dimension. The function returns
  the number of numbers, each of which is greater than the previous one.*/
#include<stdio.h>
#include<stdlib.h>

int func(float *A,int len)
{
	int i,count=0;
	for(i=0;i<len-1;i++)
	{
		if(*(A+i)>*(A+i+1))
		{
			count++;
		}
	}
	return count;
}
