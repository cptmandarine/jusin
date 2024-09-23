#pragma once

#include "CObj.h"
class CBullet : public CObj
{
public:
	CBullet();
	~CBullet();
public:
	virtual void Initialize() final;
	virtual int Update() final;
	virtual void Late_Update() final;
	virtual void Render(HDC _hDC) final;
	virtual void Release() final;

private:
	void Kill_Bullet();
	void Shot_Bullet();
};

