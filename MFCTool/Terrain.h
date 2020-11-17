#pragma once
class CMFCToolView; 

class CTerrain final
{
public:
	explicit CTerrain();
	virtual ~CTerrain();
public:
	void Set_View(CMFCToolView* pView) { m_pView = pView; }
public:
	void TileChange(const _vec3& vPos, const _int& rDrawID, const _int& rOption = 0);
	_int Get_TileIndex(const _vec3& vPos); 
	bool IsPicking(const _vec3& vPos, const _int& i);
	void Set_Ratio(_matrix& matWorld, const float& fRatioX, const float& fRatioY );
public:
	HRESULT Ready_Terrain(); 
	void	MiniRender_Terrain(); 
	void	Render_Terrain(); 
	void	Release_Terrain(); 

public:
	vector<TILE*> m_vecTile; 
	CMFCToolView* m_pView; 
};

