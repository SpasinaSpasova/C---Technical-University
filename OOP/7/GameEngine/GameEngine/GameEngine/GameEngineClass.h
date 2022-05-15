#pragma once
#include "GameUnit.h"
class GameEngineClass
{
public:
	GameUnit* Units[15];
	int CountUnits;

	GameEngineClass();
	void Add(GameUnit *gameUnit);
	void Delete();
	void Step();

};

