#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_Info = { 0.f, 0.f, 30.f, 30.f};
	m_fSpeed = 10.f;
}

int CBullet::Update()
{
	if (m_bDead)
	{
		return OBJDEAD;
	}
	CObj::Update_Rect();
	return OBJNOEVENT;
}

void CBullet::Late_Update()
{
	Kill_Bullet();
	Shot_Bullet();
}

void CBullet::Render(HDC _hDC)
{
	Ellipse(_hDC, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void CBullet::Release()
{
}

void CBullet::Kill_Bullet()
{
	if (100 >= m_Rect.left || 100 >= m_Rect.top ||
		WINCX - 100 <= m_Rect.right || WINCY - 100 <= m_Rect.bottom)
	{
		m_bDead = true;
	}
}

void CBullet::Shot_Bullet()
{
	switch (m_eDir)
	{
	case DIR_LEFT:
		m_Info.fX -= m_fSpeed;
		break;
	case DIR_UP:
		m_Info.fY -= m_fSpeed;
		break;
	case DIR_RIHGT:
		m_Info.fX += m_fSpeed;
		break;
	case DIR_DOWN:
		m_Info.fY += m_fSpeed;
		break;
	case DIR_LEFTUP:
		m_Info.fX -= m_fSpeed;
		m_Info.fY -= m_fSpeed;
		break;
	case DIR_RIGHTUP:
		m_Info.fX += m_fSpeed;
		m_Info.fY -= m_fSpeed;
		break;
	case DIR_END:
		break;
	default:
		break;
	}
}
