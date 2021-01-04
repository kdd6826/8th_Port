#ifndef Inkells_h__
#define Inkells_h__

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
class CInkells : public CMonster
{

	enum inkellsState
	{
		STATE_taunt,		
		STATE_damage_to_taunt			,//	도발중 데미지 입음
		STATE_down_end					,//다운끝(일어나는모션)
		STATE_down_begin				,//	다운시작
		STATE_down_during				,//	다운중
		STATE_turn_right				,//	오른쪽으로 도는 모션
		STATE_turn_left					,//왼쪽으로 도는모션
		STATE_run						,//	달리기
		STATE_weakpoint_broken			,//부분파괴부위 파괴되는 상태
		STATE_low_hp					,//	피 낮을때 헉헉대는거
		STATE_dying_front				,//	죽는모션
		STATE_damage_weak_top			,//? ?
		STATE_damage_weak_bottom		,// ? ?
		STATE_blind_during				,//눈뻥 상태중
		STATE_blind_begin				,//	플레이어가 폭탄(섬광탄)을 던져서 터지면 눈뻥
		STATE_threat					,//	위협 : 보스 2페이즈 분노상태 가기전에 하면좋을듯
		STATE_whirlwind					,//힐윈드
		STATE_turnright_atk				,//(보스기준 오른편에서 때리면 오른쪽으로 돌면서 1타 공격하는 모션)
		STATE_turnleft_atk				,//(보스기준 왼편에서 때리다보면 왼쪽으로 돌면서 1타 공격하는 모션)
		STATE_rage_swordwave_end		,//(분노상태 소드웨이브 2타 end)
		STATE_rage_swordwave_begin		,//(분노상태에서는 소드웨이브 2번씀 그중 begin)
		STATE_swordwave					,//내려찍기 검 충격파
		STATE_swing_triple				,//3연타
		STATE_thrust_to_whirlwind		,//	돌진찌르기후 힐윈드
		STATE_doublesmash				,//	2연타 스매시
		STATE_Idle						,//아이들 상태
		STATE_cutscene_2				,//	보스등장 두번째 컷씬
		STATE_cutscene_1				,//	보스등장 첫번째 컷씬
		STATE_Pierce					,//	찌르기
		STATE_triple_combo				,//3타 마지막
		
		


	};
private:
	explicit CInkells(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CInkells(void);

public:
	virtual HRESULT Ready_Object(void) override;
	virtual _int Update_Object(const _float& fTimeDelta) override;
	virtual void Render_Object(void) override;
private:
	HRESULT		Add_Component(void);
	HRESULT		SetUp_ConstantTable(LPD3DXEFFECT& pEffect);
	void		Move(const _float& fTimeDelta);
	
	void		Attack(const _float& fTimeDelta);
	void		SetUp_OnTerrain(void);
	_vec3		PickUp_OnTerrain(void);
	_float		m_fAngle;
	inkellsState m_state = inkellsState::STATE_Idle;

	_vec3 oldPos;
	_vec3 newPos;
	_vec3 dirPos;
	const	_matrix* m_pParentBoneMatrix = nullptr;
	const	_matrix* m_pParentWorldMatrix = nullptr;

	_vec3						m_vDir;
	_float						m_fAniSpeed=1.f;
	_float						delay = 0.f;


public:
	static CInkells*	Create(LPDIRECT3DDEVICE9 pGraphicDev);

private:
	virtual void Free(void) override;

};

END
#endif // Inkells_h__
