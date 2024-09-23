#include "CMainGame.h"

CMainGame::CMainGame() : m_pPlayer(nullptr), m_pMonster(nullptr)
{
	m_DC = GetDC(g_hWnd);
}

CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer();
		m_pPlayer->Initialize();
	}
	if (!m_pMonster)
	{
		m_pMonster = new CMonster();
		m_pMonster->Initialize();
	}
	static_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);
	static_cast<CMonster*>(m_pMonster)->Set_Bullet(&m_BulletList);

}

void CMainGame::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();

	for (auto iter = m_BulletList.begin();
		iter != m_BulletList.end();)
	{
		if ((*iter)->Update() == OBJDEAD)
		{
			Safe_Delete<CObj*>(*iter);
			iter = m_BulletList.erase(iter);
		}
		else
		{
			++iter;
		}

	}
}

void CMainGame::Late_Update()
{
	m_pMonster->Late_Update();
	for (auto& pBullet : m_BulletList)
	{
		pBullet->Late_Update();
	}
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, 100, 100, WINCX - 100, WINCY - 100);
	m_pPlayer->Render(m_DC);
	m_pMonster->Render(m_DC);
	for (auto& pBullet : m_BulletList)
		pBullet->Render(m_DC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_DC);
	Safe_Delete<CObj*>(m_pPlayer);
	Safe_Delete<CObj*>(m_pMonster);
	for (auto& pBullet : m_BulletList)
	{
		Safe_Delete<CObj*>(pBullet);
	}
	m_BulletList.clear();
}
