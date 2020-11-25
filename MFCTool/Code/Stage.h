#ifndef Stage_h__
#define Stage_h__

#include "Scene.h"
#include "Define.h"


#include "Terrain.h"

class CStage : public Engine::CScene
{
private:
	explicit CStage(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStage(void);

public:
	virtual HRESULT Ready_Scene(void) override;
	virtual _int Update_Scene(const _float& fTimeDelta) override;
	virtual void Render_Scene(void) override;
		
private:
	HRESULT		Ready_Environment_Layer(const wchar_t* pLayerTag);
	HRESULT		Ready_GameLogic_Layer(const wchar_t* pLayerTag);
	HRESULT		Ready_UI_Layer(const wchar_t* pLayerTag);

	HRESULT		Ready_Resource(Engine::RESOURCETYPE eType);
	HRESULT		Ready_LightInfo(void);

public:
	static CStage*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

#endif // Stage_h__