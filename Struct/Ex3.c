/*Define the data structure, 
"point" with coordinates x and y and color. 
Write a function that gets an array of points 
and the number of elements in it. 
The function to "color" the points of the array 
with consecutive colors from 1 to 7.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;
	int color;
}P1;

void ColorMe(P1 *points, int count)
{
	int i,col =1;
	for(i=0;i<count;i++)
	{
		if(col>=0&&col<8)
		{
			points[i].color=col;
			col++;
		}
		else
		{
			col=1;
			points[i].color=col;
			col++;
		}
	}
	for(i=0;i<count;i++)
	{
		printf("\n The color of the point number %d is %d", i+1,points[i].color);
	}

}
