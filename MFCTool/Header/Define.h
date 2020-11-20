#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#ifdef _AFX
#define ERR_MSG(Message) AfxMessageBox(Message)
#else
#define ERR_MSG(Message) MessageBox(nullptr,Message,L"System_Error",MB_OK)
#endif
extern HWND g_hWnd;

#define OBJ_DEAD 1
#define OBJ_NOEVENT 0 
#define WINCX 800
#define WINCY 600
#define TILECX 130
#define TILECY 68
#define TILEX 20
#define TILEY 30

#define ∞≠√∂∞À	0x01	//0000 0001
#define ¡ˆ∆Œ¿Ã	0x02	//0000 0010 
#define ≥™¿Ã«¡	0x04	//0000 0100

