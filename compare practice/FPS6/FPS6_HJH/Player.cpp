#include "pch.h"
#include "Player.h"


Player::Player(int x, int y) : Object(x, y)
, m_Data{	// change render
		{ ' ', ' ', ' ', ' ', ' ' },
		{ ' ', 'P', 'P', 'P', ' ' },
		{ ' ', 'P', ' ', 'P', ' ' },
		{ ' ', 'P', 'P', 'P', ' ' },
		{ ' ', ' ', ' ', ' ', ' ' } }
{
	m_pNowAni = &m_Data;
}


Player::~Player()
{
}

eObjectType Player::GetObjectType() const
{
	return eObjectType::Player;
}

Rect Player::GetRendertRect()const
{
	return Rect{ rt.x - 1,rt.y - 1,rt.w,rt.h };
}