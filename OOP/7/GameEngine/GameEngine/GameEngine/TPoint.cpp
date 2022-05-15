#include "TPoint.h"
#include "GameEngineClass.h"
#include <stdio.h>

TPoint::TPoint()
{
	x = 0;
	y = 0;
}
TPoint::TPoint(int tx, int ty)
{
	x = tx;
	y = ty;

}
void TPoint::Print()
{
	printf("X: %d\nY: %d", x,y);
}
