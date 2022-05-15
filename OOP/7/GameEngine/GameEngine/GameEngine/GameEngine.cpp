

#include <iostream>
#include "TPoint.h"
#include "GameUnit.h"
#include "GameEngineClass.h"

extern GameEngineClass* p;

int main()
{
	TPoint point(5, 4);
	point.Print();
	GameEngineClass game;
	p = &game;

}


