#pragma once
#include "framework.h"
#include "define.h"
#include "CPlayer.h"
#include "CMonster.h"
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();
private:
	HDC m_DC;
	CObj* m_pPlayer;
	CObj* m_pMonster;
	list<CObj*> m_BulletList;
};

