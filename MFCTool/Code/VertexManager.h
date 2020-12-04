#pragma once

#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"

class CSphereMesh;

class VertexManager
{
public:
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
	
	void DestroyValue();

	//��ü�� Ŭ��������, �����ϸ� nullptr �����ϸ� �ش� SphereMesh ������
	CSphereMesh* Picking_Sphere(HWND hWnd, Engine::CTransform* pTerrainTransformCom);
	Engine::CGameObject* Picking_ObjectMesh(HWND hWnd, Engine::CTransform* pTerrainTransformCom);
	//Sphere�÷����� �ٲ۴�. (Buffer������Ʈ, �÷�)
	void Set_SphereColor(Engine::CSphere* Vtx, D3DCOLOR color);
	//TerrainTri�÷����� �ٲ۴�. (Buffer������Ʈ, �÷�)
	void Set_TriColor(Engine::CTerrainTriCol * Vtx, D3DCOLOR color);
	list<CSphereMesh*> GetList_Sphere() { return list_Sphere; }
	//Terrain ������ ���� �����ϸ� true �ƴϸ� false
	bool TerrainHaveCheck();
	//��Ŭ���� ������ �ش��Լ� ����
	void MouseLClick_NaviMesh();
	void MouseLClick_ObjectMesh();
	void MouseRClick_NaviMesh();
	//���� ������ ������ ���� �ٲ��ִµ� Or ���ο� ���� ��ü ����
	void LockOnObject(VM_Obj name, Engine::CGameObject * obj);
	
private:
	

public:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

public:
	//CCW �˰������� �ð���� üũ
	int CCW2(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, D3DXVECTOR3 vec3);

	void Delete_LockObject();

	void Erase_list_TotalSphere(CSphereMesh * sphere);
	
	bool isNaviMesh = false;


public:
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

};

