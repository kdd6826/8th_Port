#ifndef Ingkells_h__
#define Ingkells_h__

#include "Monster.h"
#include "Define.h"
#include "SphereCollider.h"
BEGIN(Engine)

class CDynamicMesh;
class CTransform;
class CRenderer;
class CCalculator;
class CCollider;
class CNaviMesh;
class CShader;
END

BEGIN(Client)
class CIngkells : public CMonster
{

	enum IngkellsState
	{
		STATE_TAUNT,		
		STATE_DAMAGE_TO_TAUNT			,//	도발중 데미지 입음
		STATE_DOWN_END				,//다운끝(일어나는모션)
		STATE_DOWN_BEGIN				,//	다운시작
		STATE_DOWN_DURING				,//	다운중
		STATE_TURN_RIGHT				,//	오른쪽으로 도는 모션
		STATE_TURN_LEFT					,//왼쪽으로 도는모션
		STATE_RUN						,//	달리기
		STATE_WEAKPOINT_BROKEN			,//부분파괴부위 파괴되는 상태
		STATE_LOW_HP					,//	피 낮을때 헉헉대는거
		STATE_DYING_FRONT				,//	죽는모션
		STATE_DAMAGE_WEAK_TOP			,//? ?
		STATE_DAMAGE_WEAK_BOTTOM		,// ? ?
		STATE_BLIND_DURING				,//눈뻥 상태중
		STATE_BLIND_BEGIN			,//	플레이어가 폭탄(섬광탄)을 던져서 터지면 눈뻥
		STATE_THREAT				,//	위협 : 보스 2페이즈 분노상태 가기전에 하면좋을듯
		STATE_WHIRLWIND					,//힐윈드
		STATE_TURNRIGHT_ATK				,//(보스기준 오른편에서 때리면 오른쪽으로 돌면서 1타 공격하는 모션)
		STATE_TURNLEFT_ATK				,//(보스기준 왼편에서 때리다보면 왼쪽으로 돌면서 1타 공격하는 모션)
		STATE_RAGE_SWORDWAVE_END		,//(분노상태 소드웨이브 2타 end)
		STATE_RAGE_SWORDWAVE_BEGIN		,//(분노상태에서는 소드웨이브 2번씀 그중 begin)
		STATE_SWORDWAVE					,//내려찍기 검 충격파
		STATE_SWING_TRIPLE				,//3연타
		STATE_THRUST_TO_WHIRLWIND		,//	돌진찌르기후 힐윈드
		STATE_DOUBLESMASH				,//	2연타 스매시
		STATE_IDLE						,//아이들 상태
		STATE_CUTSCENE_2				,//	보스등장 두번째 컷씬
		STATE_CUTSCENE_1				,//	보스등장 첫번째 컷씬
		STATE_PIERCE					,//	찌르기
		STATE_TRIPLE_COMBO				,//3타 마지막
		
		


	};
private:
	explicit CIngkells(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CIngkells(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
	virtual void OnCollision(Engine::CGameObject* target)override;
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
	void		Move(const _float& fTimeDelta);
	
	void		Attack(const _float& fTimeDelta);
	void		SetUp_OnTerrain(void);
	_vec3		PickUp_OnTerrain(void);
	_float		m_fAngle;
	IngkellsState m_state = IngkellsState::STATE_IDLE;

	_vec3 oldPos;
	_vec3 newPos;
	_vec3 dirPos;
	const	_matrix* m_pParentBoneMatrix = nullptr;
	const	_matrix* m_pParentWorldMatrix = nullptr;

	_vec3						m_vDir;
	_float						m_fAniSpeed=1.f;
	_float						delay = 0.f;


public:
	static CIngkells*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	static CIngkells*	Create(LPDIRECT3DDEVICE9 pGraphicDev, StageNum _stage);
private:
	virtual void Free(void) override;

};

END
#endif // Ingkells_h__
