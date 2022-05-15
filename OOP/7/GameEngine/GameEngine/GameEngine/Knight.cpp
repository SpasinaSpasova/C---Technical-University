#include "Knight.h"
#include "GameEngineClass.h"
#include <stdio.h>

extern GameEngineClass* p;

Knight::Knight()
{
	Sword = 0;
	Armor = 0;
}
Knight::Knight(int pSword, int pArmor)
{
	Sword = pSword;
	Armor = pArmor;

}
void Knight::print()
{
	printf("Sword: %d\nArmor: %d", Sword,Armor);
}
