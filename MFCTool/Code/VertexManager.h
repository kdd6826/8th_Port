#pragma once

#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"

class CSphereMesh;

class VertexManager
{
	enum class VM_Obj{
		NONE, SPHERE, TRI, _END
	};
public:
	DECLARE_SINGLETON(VertexManager)
private:
	VertexManager();
	~VertexManager();

public:
	void Update(float deltaTime);
	void Key_Input(float deltaTime);
	void DrawLine();

	//��ü�� Ŭ��������, �����ϸ� nullptr �����ϸ� �ش� SphereMesh ������
	CSphereMesh* Picking_Sphere(HWND hWnd, Engine::CTransform* pTerrainTransformCom);
	//Sphere�÷����� �ٲ۴�. (Buffer������Ʈ, �÷�)
	void Set_SphereColor(Engine::CSphere* Vtx, D3DCOLOR color);
	//TerrainTri�÷����� �ٲ۴�. (Buffer������Ʈ, �÷�)
	void Set_TriColor(Engine::CTerrainTriCol * Vtx, D3DCOLOR color);

	//Terrain ������ ���� �����ϸ� true �ƴϸ� false
	bool TerrainHaveCheck();
	//��Ŭ���� ������ �ش��Լ� ����
	void MouseLClick_NaviMesh();
	//���� ������ ������ ���� �ٲ��ִµ� Or ���ο� ���� ��ü ����
	void LockOnObject(VM_Obj name, Engine::CGameObject * obj);

private:
	

public:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

private:
	bool mouseLClick = false;
	bool mouseRClick = false;
	bool KeyC = false;

	//CSphereMesh ���� ��Ƴ� ����Ʈ
	list<CSphereMesh*> list_TotalSphere;
	//�ﰢ���� ��������� 3�� �������� ��Ƴ��� SphereMesh ����Ʈ
	list<CSphereMesh*> list_Sphere;
	//�̹� �ѹ� �������� �ٽ� ���ϰ�
	bool sphereOverlap = false;
	//���� �������� ��ü�� ���ߴ���
	VM_Obj lockOnObjName = VM_Obj::_END;
	//���� �� ��ü�� ������
	Engine::CGameObject* lockOnObj = nullptr;

	D3DXVECTOR3 vertex[128];
	LPD3DXLINE line[128];
	int triCount = 0;
	int lineCount = 0;
};

