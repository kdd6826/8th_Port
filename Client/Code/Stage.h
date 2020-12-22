#ifndef Stage_h__
#define Stage_h__

#include "Scene.h"
#include "Define.h"

#include "SkyBox.h"
#include "Terrain.h"
#include "Player.h"
#include "DynamicCamera.h"
#include "Unit.h"
#include "Dog.h"
#include "Titan.h"

#include "Stone.h"
#include "Sword.h"
#include "Tree.h"
#include "Effect.h"
#include "SkillSlot.h"
#include "HpBarBack.h"
#include "HpBarValue.h"
#include "SpBarBack.h"
#include "SpBarValue.h"
#include "StaminaBarBack.h"
#include "StaminaBarValue.h"


#include "StaticObject.h"
BEGIN(Client)

class CStage : public Engine::CScene
{
private:
	explicit CStage(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CStage(void);

public:
	virtual HRESULT Ready_Scene(void) override;
	virtual _int Update_Scene(const _float& fTimeDelta) override;
	virtual void Render_Scene(void) override;
	HRESULT		Load_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag);

private:
	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_GameLogic_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_UI_Layer(const _tchar* pLayerTag);

	HRESULT		Ready_LightInfo(void);

public:
	static CStage*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

END
#endif // Stage_h__
