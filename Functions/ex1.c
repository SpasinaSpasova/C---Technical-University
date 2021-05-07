/*Write a function for solving a quadratic equation.
 Return both roots using function parameters.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float QE(float a, float b, float c, float *x1, float *x2)
{
	float d=b*b-4*a*c;
	if(d==0)
	{
		*x1=(-1*b)/(2*a);
		*x2=*x1;
	}
	else if(d>0)
	{
		*x1=(-1*b-d)/(2*a);
		*x2=(-1*b+d)/(2*a);
	}
	return d;
}
