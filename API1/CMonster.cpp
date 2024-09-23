#include "CMonster.h"
CMonster::CMonster() : m_pBulletList(nullptr)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_Info = { WINCX / 2, WINCY / 2, 100,100 };
	m_fSpeed = 10.f;
	m_eDir = DIR_RIHGT;
}

int CMonster::Update()
{
	RECT hitRect;
	LPRECT lpRect = &hitRect;
	if (m_Info.fX - m_Info.fCX / 2 <= 100)
	{
		m_eDir = DIR_RIHGT;
	}
	else if (m_Info.fX + m_Info.fCX / 2 >= WINCX - 100)
	{
		m_eDir = DIR_LEFT;
	}
	for (auto iter = m_pBulletList->begin();
		iter != m_pBulletList->end(); ++iter)
	{
		if (IntersectRect(lpRect, (*iter)->Get_PRect(), Get_PRect()))
		{
			m_bDead = true;
			return OBJDEAD;
		}
	}
	CObj::Update_Rect();

	return OBJNOEVENT;
}

void CMonster::Late_Update()
{
	if (!m_bDead)
	{
		switch (m_eDir)
		{
		case DIR_LEFT:
			m_Info.fX -= m_fSpeed;
			break;
		case DIR_RIHGT:
			m_Info.fX += m_fSpeed;
			break;
		default:
			break;
		}
	}
}

void CMonster::Render(HDC _hDC)
{
	if (!m_bDead)
	{
		Ellipse(_hDC, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	}
}

void CMonster::Release()
{
}

void CMonster::Set_Bullet(list<CObj*>* _pBulletList)
{
	m_pBulletList = _pBulletList;
}
