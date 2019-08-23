#pragma once
#include "Object.h"

class Item : public Object
{
public:
	Item(int x, int y);
	virtual ~Item();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	virtual void Interaction(class Hero* a_refHero) override;

	virtual void _PreUpdate(float a_fDelta) override;	//+
	virtual void _Update(float a_fDelta) override;	//+

	eItem m_eType = eItem::None;
	class Ani* m_pAni = nullptr;	//+
	//-RenderTile m_Item[(int)eItem::Max];
};

