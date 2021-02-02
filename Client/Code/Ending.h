#ifndef Ending_h__
#define Ending_h__

#include "StageHeaders.h"

BEGIN(Client)

class CEnding : public Engine::CScene
{
private:
	explicit CEnding(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CEnding(void);

public:
	
	virtual HRESULT Ready_Scene(void) override;
	virtual _int Update_Scene(const _float& fTimeDelta) override;
	virtual void Render_Scene(void) override;
	void InitialUpdate();
	HRESULT		Load_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag);

		
private:
	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_GameLogic_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_UI_Layer(const _tchar* pLayerTag);

	HRESULT		Ready_LightInfo(void);
	bool isInitial = false;
public:
	static CEnding*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

END
#endif // Ending_h__
