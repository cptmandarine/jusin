#pragma once
#include "CObj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	~CPlayer();
public:
	virtual void Initialize() final;
	virtual int Update() final;
	virtual void Late_Update() final;
	virtual void Render(HDC _hDC) final;
	virtual void Release() final;
	
	void Set_Bullet(list<CObj*>*);
private:
	void Key_Input();
	CObj* Create_Bullet(DIRECTION _dir);
private:
	list<CObj*>* m_pBullet;
};

