#include "CObj.h"

CObj::CObj() : m_fSpeed(0.f), m_bDead(false), m_eDir(DIR_END)
{
	ZeroMemory(&m_Info, sizeof(m_Info));
	ZeroMemory(&m_Rect, sizeof(m_Rect));
}

CObj::~CObj()
{
}

void CObj::Set_Pos(float _fx, float _fy)
{
	m_Info.fX = _fx;
	m_Info.fY = _fy;
}

void CObj::Set_Direction(DIRECTION _dir)
{
	m_eDir = _dir;
}

void CObj::Set_Dead(bool _bDead)
{
	m_bDead = _bDead;
}

const RECT* CObj::Get_PRect() const
{
	return &m_Rect;
}

void CObj::Update_Rect()
{
	
	m_Rect.left		= LONG(m_Info.fX - m_Info.fCX / 2);
	m_Rect.right	= LONG(m_Info.fX + m_Info.fCX / 2);
	m_Rect.top		= LONG(m_Info.fY - m_Info.fCY / 2);
	m_Rect.bottom	= LONG(m_Info.fY + m_Info.fCY / 2);
}
