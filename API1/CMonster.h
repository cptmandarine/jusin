#pragma once
#include "CObj.h"
class CMonster :public CObj
{
public:
	CMonster();
	virtual ~CMonster();
public:
	virtual void Initialize() final;
	virtual int Update() final;
	virtual void Late_Update() final;
	virtual void Render(HDC _hDC) final;
	virtual void Release() final;

	void Set_Bullet(list<CObj*>* _pBulletList);
private:
	list<CObj*>* m_pBulletList;
};

