#include "GameUnit.h"
#include "GameEngineClass.h"
#include <stdio.h>
#include <math.h>

extern GameEngineClass* p;

GameUnit::GameUnit()
{
	Condition = 0;
	MoveSpeed = 0;
	AttackSpeed = 0;
}
GameUnit::GameUnit(TPoint pPositon, TPoint pTarget,  int pCondition, int pMoveSpeed, int pAttackSpeed)
{
	Position.x = pPositon.x;
	Position.y = pPositon.y;
	Target.x = pTarget.x;
	Target.y = pTarget.y;
	Condition = pCondition;
	MoveSpeed = pMoveSpeed;
	AttackSpeed = pAttackSpeed;
	
}

void GameUnit::setTarget() 
{
	int positionMin = 0;
	float min = 500000;
	float r = 0;
	float a;
	float b;

	for (int i = 0; i < p->CountUnits; i++)
	{
		a = (Position.x - p->Units[i]->Position.x);
		b = (Position.y - p->Units[i]->Position.y);

		r = sqrt((a * a) + (b * b));

		if (r < min)
		{
			min = r;
			positionMin = i;
		}
	}
	
	Target.x = p->Units[positionMin]->Position.x;
	Target.y = p->Units[positionMin]->Position.y;

}
void GameUnit::print()
{
	printf("\nCondition: %d\nMoveSpeed: %d\nAttackSpeed: %d", Condition, MoveSpeed, AttackSpeed);
}