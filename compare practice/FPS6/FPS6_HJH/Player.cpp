#include "pch.h"
#include "Player.h"

#include "GameManager.h"

Player::Player(int x, int y) : Object(x, y)
, m_Data{	// change render
		{ ' ', ' ', ' ', ' ', ' ' },
		{ ' ', 'P', 'P', 'P', ' ' },
		{ ' ', 'P', ' ', 'P', ' ' },
		{ ' ', 'P', 'P', 'P', ' ' },
		{ ' ', ' ', ' ', ' ', ' ' } }
{
	m_pNowAni = &m_Data;
rt.x +=1;
rt.y +=1;
rt.w = TileSize -2;
rt.h = TileSize -2;
}


Player::~Player()
{
m_refStat = nullptr;
}

eObjectType Player::GetObjectType() const
{
	return eObjectType::Player;
}

Rect Player::GetRendertRect()const
{
	return Rect{ rt.x - 1,rt.y - 1,rt.w,rt.h };
}
void Player::SetStat(struct CharacterData* a_pStat)
{
m_refStat = a_pStat;
m_nPutBombCount=0;
}
bool Player::_Update(float a_fDelta)
{
Move(a_fDelta);
BombCheck();
return false;
}
void Player::Move(float a_fDeltaTime)
{
float fAdd = a_fDeltaTime * (m_refStat->fMoveSpeed);// Seepd?
float fX=0;
float fY=0;
if(IsKeyDown(eKey::A)) {fX -= fAdd;}
if(IsKeyDown(eKey::D)) {fX += fAdd;}
if(IsKeyDown(eKey::S)) {fY += fAdd;}
if(IsKeyDown(eKey::W)) {fY -= fAdd;}
rt.x+= fX;
rt.y+= fY;
}
void Player::BombCheck()
{
if(m_nPutBombCount >= m_refStat->nBombCount){return;}
if(IsKeyDown(eKey::Space)) 

{
	COORD c = rt.Center();
	if(GameMng()->AddBomb(c.X,c.Y) == true)
{
++m_nPutBombCount;
}
}
}