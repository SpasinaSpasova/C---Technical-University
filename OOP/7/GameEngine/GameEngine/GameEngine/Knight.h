#pragma once
#include "GameUnit.h"
class Knight: GameUnit
{
	int Sword;
	int Armor;
public:
	Knight();
	Knight(int sword, int armor);
	void print();
};

