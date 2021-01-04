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
		STATE_damage_to_taunt			,//	������ ������ ����
		STATE_down_end					,//�ٿ(�Ͼ�¸��)
		STATE_down_begin				,//	�ٿ����
		STATE_down_during				,//	�ٿ���
		STATE_turn_right				,//	���������� ���� ���
		STATE_turn_left					,//�������� ���¸��
		STATE_run						,//	�޸���
		STATE_weakpoint_broken			,//�κ��ı����� �ı��Ǵ� ����
		STATE_low_hp					,//	�� ������ �����°�
		STATE_dying_front				,//	�״¸��
		STATE_damage_weak_top			,//? ?
		STATE_damage_weak_bottom		,// ? ?
		STATE_blind_during				,//���� ������
		STATE_blind_begin				,//	�÷��̾ ��ź(����ź)�� ������ ������ ����
		STATE_threat					,//	���� : ���� 2������ �г���� �������� �ϸ�������
		STATE_whirlwind					,//������
		STATE_turnright_atk				,//(�������� �������� ������ ���������� ���鼭 1Ÿ �����ϴ� ���)
		STATE_turnleft_atk				,//(�������� ������ �����ٺ��� �������� ���鼭 1Ÿ �����ϴ� ���)
		STATE_rage_swordwave_end		,//(�г���� �ҵ���̺� 2Ÿ end)
		STATE_rage_swordwave_begin		,//(�г���¿����� �ҵ���̺� 2���� ���� begin)
		STATE_swordwave					,//������� �� �����
		STATE_swing_triple				,//3��Ÿ
		STATE_thrust_to_whirlwind		,//	��������� ������
		STATE_doublesmash				,//	2��Ÿ ���Ž�
		STATE_Idle						,//���̵� ����
		STATE_cutscene_2				,//	�������� �ι�° �ƾ�
		STATE_cutscene_1				,//	�������� ù��° �ƾ�
		STATE_Pierce					,//	���
		STATE_triple_combo				,//3Ÿ ������
		
		


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
