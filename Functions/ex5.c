/*to write the function which receives a two-dimensional array with its dimension 
and returns the smallest and largest number in it*/
#include<stdio.h>
#include<stdlib.h>
void func(int *A, int m, int n, int *min, int *max)
{
	int i;
	*min=*max=*A;
	for(i=0;i<m*n;i++)
	{
		if(*(A+i)>*max)
		{
			*max=*(A+i);
		}
		if(*(A+i)<*min)
		{
			*min=*(A+i);
		}
	}
}

void func_second(int *A, int m, int n, int *min, int *max)
{
	int i,j;
	*min=*max=*A;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		
			if(*(A+i*m+j)>*max)
			{
				*max=*(A+i*m+j);
			}
			if(*(A+i*m+j)<*min)
			{
				*min=*(A+i*m+j);
			}
		}
	}
}
