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
#include "Ingkells.h"
#include "LightRay.h"
#include "Knight.h"
//#include "Zecallion.h"

#include "Stone.h"
#include "Sword.h"
#include "Tree.h"
#include "Effect.h"
#include "FireEffect.h"
#include "TriggerBox.h"

#include "DamageFont.h"
#include "DashGuard.h"
#include "DashGuard2.h"
#include "RuinBlade.h"
#include "SwordTrail.h"
#include "DarkSwordTrail.h"

#include "SkillSlot.h"
#include "HpBarBack.h"
#include "HpBarValue.h"
#include "SpBarBack.h"
#include "SpBarValue.h"
#include "StaminaBarBack.h"
#include "StaminaBarValue.h"

#include "BossHpBarBase.h"
#include "BossHpBarGreen.h"
#include "BossHpBarHit.h"
#include "BossHpBarOrange.h"
#include "BossHpBarRed.h"

#include "Skill0.h"
#include "Skill1.h"
#include "Skill2.h"
#include "Skill4.h"
#include "SkillDkTransform.h"
#include "SkillDkTransform2.h"

#include "StaticObject.h"
#include "Particle.h"

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
	void InitialUpdate();
	HRESULT		Load_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag);

		
private:
	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_GameLogic_Layer(const _tchar* pLayerTag);
	HRESULT		Ready_UI_Layer(const _tchar* pLayerTag);

	HRESULT		Ready_LightInfo(void);
	bool isInitial = false;
public:
	static CStage*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;
};

END
#endif // Stage_h__
