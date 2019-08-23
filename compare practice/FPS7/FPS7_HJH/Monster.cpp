﻿#include "pch.h"
#include "Monster.h"

#include "Player.h"//+
#include "GameManager.h"//+

Monster::Monster(int x, int y) : Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', 'M', ' ', 'M', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', '1', '1', '1', '1' }
}
{
	m_pNowAni = &m_Data;
}

Monster::~Monster()
{
}

eObjectType Monster::GetObjectType() const
{
	return eObjectType::Monster;
}
bool Monster::Interaction(Player* a_refHero)	//changed
{
if(IsCross(a_refHero)==true)
{
GameMng()->Die(this);
}
return false;
}