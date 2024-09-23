#pragma once
#define WINCX 800
#define WINCY 600
#define OBJNOEVENT 0
#define OBJDEAD 1
#define PURE	= 0
#define PI		3.141592f;


#define SAFE_DELETE(p) if(p){delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p){delete[] p; p = nullptr;}

template<typename T>
void Safe_Delete(T& tmp)
{
	if (tmp)
	{
		delete tmp;
		tmp = nullptr;
	}
}

typedef struct tagINFO
{
	float fX;
	float fY;
	float fCX;
	float fCY;
}INFO;

enum DIRECTION {DIR_LEFT, DIR_UP, DIR_RIHGT, DIR_DOWN, DIR_LEFTUP, DIR_RIGHTUP, DIR_END};
extern HWND g_hWnd;