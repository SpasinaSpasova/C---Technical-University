#pragma once
#include "TPoint.h"

class GameUnit
{
	TPoint Position;
	TPoint Target;
	int Condition;
	int MoveSpeed;
	int TactMoveSpeed;
	int AttackSpeed;
	int TactAttackSpeed;
public:
	GameUnit();
	GameUnit(TPoint pPositon, TPoint Target, int pCondition, int pMoveSpeed, int pAttackSpeed);
	virtual void print();
	void Movement(); //???
	void setTarget();


};

