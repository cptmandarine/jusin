#include "CPlayer.h"
#include "CBullet.h"

CPlayer::CPlayer() : m_pBullet(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_Info.fX = WINCX / 2;
	m_Info.fY = WINCY / 2;
	m_Info.fCX = 100.f;
	m_Info.fCY = 100.f;
	m_fSpeed = 5.f;
}

int CPlayer::Update()
{
	Key_Input();
	//이미 정해졌기에 굳이 Late_Update를 할 필요가 사라짐
	CObj::Update_Rect();
	return OBJNOEVENT;
}

void CPlayer::Late_Update()
{
}


void CPlayer::Render(HDC _hDC)
{
	Rectangle(_hDC, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Set_Bullet(list<CObj*>* _pBulletList)
{
	m_pBullet = _pBulletList;
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_Info.fX -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_Info.fX += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		m_Info.fY -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_Info.fY += m_fSpeed;
	}
	if (GetAsyncKeyState('W'))
	{
		m_pBullet->push_back(Create_Bullet(DIR_UP));
	}
	if (GetAsyncKeyState('A'))
	{
		m_pBullet->push_back(Create_Bullet(DIR_LEFT));
	}
	if (GetAsyncKeyState('S'))
	{
		m_pBullet->push_back(Create_Bullet(DIR_DOWN));
	}
	if (GetAsyncKeyState('D'))
	{
		m_pBullet->push_back(Create_Bullet(DIR_RIHGT));
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(Create_Bullet(DIR_UP));
		m_pBullet->push_back(Create_Bullet(DIR_LEFTUP));
		m_pBullet->push_back(Create_Bullet(DIR_RIGHTUP));
	}
}

CObj* CPlayer::Create_Bullet(DIRECTION _dir)
{
	CObj* pBullet = new CBullet();
	pBullet->Initialize();
	pBullet->Set_Pos(m_Info.fX, m_Info.fY);
	pBullet->Set_Direction(_dir);
	return pBullet;
}
