#pragma once
#include "framework.h"
#include "define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Late_Update() PURE;
	virtual void Render(HDC _hDC) PURE;
	virtual void Release() PURE;

	//setter
	void Set_Pos(float _fx, float _fy);
	void Set_Direction(DIRECTION _dir);
	void Set_Dead(bool _bDead);
	//getter
	const RECT* Get_PRect() const;
protected:
	void Update_Rect();

protected:
	INFO m_Info;
	RECT m_Rect;
	DIRECTION m_eDir;
	float m_fSpeed;
	bool m_bDead;
};

