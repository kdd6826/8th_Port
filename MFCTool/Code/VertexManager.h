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

	//구체를 클릭했을때, 실패하면 nullptr 성공하면 해당 SphereMesh 포인터
	CSphereMesh* Picking_Sphere(HWND hWnd, Engine::CTransform* pTerrainTransformCom);
	Engine::CGameObject* Picking_ObjectMesh(HWND hWnd, Engine::CTransform* pTerrainTransformCom);
	//Sphere컬러값을 바꾼다. (Buffer컴포넌트, 컬러)
	void Set_SphereColor(Engine::CSphere* Vtx, D3DCOLOR color);
	//TerrainTri컬러값을 바꾼다. (Buffer컴포넌트, 컬러)
	void Set_TriColor(Engine::CTerrainTriCol * Vtx, D3DCOLOR color);
	list<CSphereMesh*> GetList_Sphere() { return list_Sphere; }
	//Terrain 지형이 지금 존재하면 true 아니면 false
	bool TerrainHaveCheck();
	//좌클릭을 했을때 해당함수 실행
	void MouseLClick_NaviMesh();
	void MouseLClick_ObjectMesh();
	void MouseRClick_NaviMesh();
	//락온 해제시 그전꺼 색상 바꿔주는등 Or 새로운 락온 객체 설정
	void LockOnObject(VM_Obj name, Engine::CGameObject * obj);
	
private:
	

public:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

public:
	//CCW 알고리즘으로 시계방향 체크
	int CCW2(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, D3DXVECTOR3 vec3);

	void Delete_LockObject();

	void Erase_list_TotalSphere(CSphereMesh * sphere);
	
	bool isNaviMesh = false;


public:
	bool mouseLClick = false;
	bool mouseRClick = false;
	bool KeyC = false;
	

	//CSphereMesh 전부 모아논 리스트
	list<CSphereMesh*> list_TotalSphere;
	//삼각형을 만들기위해 3번 찍을동안 담아놓는 SphereMesh 리스트
	list<CSphereMesh*> list_Sphere;
	//이미 한번 눌렀던거 다시 못하게
	bool sphereOverlap = false;
	//내가 무슨종류 객체를 락했는지
	VM_Obj lockOnObjName = VM_Obj::_END;
	//락을 한 객체의 포인터
	Engine::CGameObject* lockOnObj = nullptr;

};

