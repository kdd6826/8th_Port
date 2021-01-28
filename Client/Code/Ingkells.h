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
		STATE_DAMAGE_TO_TAUNT			,//	������ ������ ����
		STATE_DOWN_END				,//�ٿ(�Ͼ�¸��)
		STATE_DOWN_BEGIN				,//	�ٿ����
		STATE_DOWN_DURING				,//	�ٿ���
		STATE_TURN_RIGHT				,//	���������� ���� ���
		STATE_TURN_LEFT					,//�������� ���¸��
		STATE_RUN						,//	�޸���
		STATE_WEAKPOINT_BROKEN			,//�κ��ı����� �ı��Ǵ� ����
		STATE_LOW_HP					,//	�� ������ �����°�
		STATE_DYING_FRONT				,//	�״¸��
		STATE_DAMAGE_WEAK_TOP			,//? ?
		STATE_DAMAGE_WEAK_BOTTOM		,// ? ?
		STATE_BLIND_DURING				,//���� ������
		STATE_BLIND_BEGIN			,//	�÷��̾ ��ź(����ź)�� ������ ������ ����
		STATE_THREAT				,//	���� : ���� 2������ �г���� �������� �ϸ�������
		STATE_WHIRLWIND					,//������
		STATE_TURNRIGHT_ATK				,//(�������� �������� ������ ���������� ���鼭 1Ÿ �����ϴ� ���)
		STATE_TURNLEFT_ATK				,//(�������� ������ �����ٺ��� �������� ���鼭 1Ÿ �����ϴ� ���)
		STATE_RAGE_SWORDWAVE_END		,//(�г���� �ҵ���̺� 2Ÿ end)
		STATE_RAGE_SWORDWAVE_BEGIN		,//(�г���¿����� �ҵ���̺� 2���� ���� begin)
		STATE_SWORDWAVE					,//������� �� �����
		STATE_SWING_TRIPLE				,//3��Ÿ
		STATE_THRUST_TO_WHIRLWIND		,//	��������� ������
		STATE_DOUBLESMASH				,//	2��Ÿ ���Ž�
		STATE_IDLE						,//���̵� ����
		STATE_CUTSCENE_2				,//	�������� �ι�° �ƾ�
		STATE_CUTSCENE_1				,//	�������� ù��° �ƾ�
		STATE_PIERCE					,//	���
		STATE_TRIPLE_COMBO				,//3Ÿ ������
		
		


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
