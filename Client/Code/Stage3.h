#ifndef Stage3_h__
#define Stage3_h__

#include "StageHeaders.h"
BEGIN(Client)

class CStage3 : public Engine::CScene
{
private:
	explicit CStage3(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStage3(void);

public:
	virtual HRESULT Ready_Scene(void) override;
	virtual _int Update_Scene(const _float& fTimeDelta) override;
	void InitialUpdate();
	virtual void Render_Scene(void) override;
	HRESULT		Load_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag);
	HRESULT		LoadStage3_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag);
	HRESULT		LoadStage3_StaticObjectFromTool1(Engine::CLayer* _layer, const _tchar* pLayerTag);
	HRESULT		LoadStage3_StaticObjectFromTool2(Engine::CLayer* _layer, const _tchar* pLayerTag);
	HRESULT		LoadStage3_StaticObjectFromTool3(Engine::CLayer* _layer, const _tchar* pLayerTag);
	HRESULT		LoadStage3_StaticObjectFromTool4(Engine::CLayer* _layer, const _tchar* pLayerTag);
private:
	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_GameLogic_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_UI_Layer(const _tchar* pLayerTag);

	HRESULT		Ready_LightInfo(void);
	bool isInitial = false;
public:
	static CStage3*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

END
#endif // Stage3_h__
