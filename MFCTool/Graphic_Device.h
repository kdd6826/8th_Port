#pragma once
class CGraphic_Device
{
DECLARE_SINGLETON(CGraphic_Device)
private:
	CGraphic_Device();
	~CGraphic_Device();
public:
	LPDIRECT3DDEVICE9 Get_Device() { return m_pDevice;  }
	LPD3DXSPRITE Get_Sprite() { return m_pSprite; }
	LPD3DXFONT Get_Font() { return m_pFont; }
public:
	HRESULT Ready_Graphic_Device();
public:
	void Render_Begin(); 
	void Render_End(HWND hWnd = nullptr); 

public:
	void Release_Graphic_Device(); 
private:
	// 실질적으로 장치를 다룰 객체. 
	LPDIRECT3DDEVICE9 m_pDevice;
	// 장치의 지원 수준 조사 및 장치를 제어할 객체를 생성할 com 객체 .
	LPDIRECT3D9 m_pSDK; 
	// com 객체!- 그냥 하나 하나 부품처럼 생각한다라 생각하면 되겠다. 

	LPD3DXSPRITE m_pSprite;
	LPD3DXFONT	m_pFont; 

};

