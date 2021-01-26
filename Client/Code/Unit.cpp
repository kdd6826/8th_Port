#include "stdafx.h"
#include "Unit.h"
#include "Export_Function.h"
#include "ColliderMgr.h"
CUnit::CUnit(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CUnit::~CUnit(void)
{
	for (auto& iterator = m_VecSphereCollider.begin(); iterator != m_VecSphereCollider.end();++iterator)
	{
		//Engine::Safe_Delete_Array(*iterator);
			Engine::Safe_Release(*iterator);
	}
}

_int CUnit::Update_Object(const _float& fTimeDelta)
{
	Engine::CGameObject::Update_Object(fTimeDelta);
	for (auto& sphere : m_VecSphereCollider)
	{
		sphere->m_pDynamicMesh = this;
		sphere->Update_Object(fTimeDelta);
	}
	return S_OK;
}



void CUnit::NaviMeshChange(const _tchar* pFileKey)
{
	//Engine::CComponent* pComponent = nullptr;

	//m_pMeshCom->Free();
	//m_pMeshCom = dynamic_cast<Engine::CDynamicMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Player1"));

	m_pNaviMeshCom->Free();
	m_pNaviMeshCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, pFileKey));
	
	//NULL_CHECK_RETURN(pComponent, E_FAIL);
	//m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

}

HRESULT CUnit::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);


	pComponent = m_pNaviMeshCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Navi"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Calculator
	pComponent = m_pCalculatorCom = dynamic_cast<Engine::CCalculator*>(Engine::Clone(L"Proto_Calculator"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);




	return S_OK;
}

_int CUnit::Load_ColliderFile(_tchar* pFilePath, Engine::COLLID _collType, Engine::COLLID _collType2)
{
	_tchar		szDataPath[256] = L"";

	wsprintf(szDataPath, pFilePath);

	HANDLE hFile = CreateFile(szDataPath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL;
	DWORD dwByte = 0;
	DWORD dwstrByte = 0;

	//
	_vec3 vecPos, vecAng, vecScal;
	TCHAR meshName[MAX_PATH] = L"";
	_int meshNameSize;
	ReadFile(hFile, &meshNameSize, sizeof(_int), &dwByte, nullptr);
	ReadFile(hFile, &meshName, meshNameSize, &dwByte, nullptr);
	ReadFile(hFile, &vecPos, sizeof(_vec3), &dwByte, nullptr);
	ReadFile(hFile, &vecScal, sizeof(_vec3), &dwByte, nullptr);
	ReadFile(hFile, &vecAng, sizeof(_vec3), &dwByte, nullptr);
	//
	_int sphereCnt = 0;
	ReadFile(hFile, &sphereCnt, sizeof(_int), &dwByte, nullptr);

	for (size_t i = 0; i < sphereCnt; i++)
	{
		_vec3 spherePos, sphereScale;
		TCHAR frameName[MAX_PATH] = L"";
		_int frameNameSize;
		ReadFile(hFile, &spherePos, sizeof(_vec3), &dwByte, nullptr);
		ReadFile(hFile, &sphereScale, sizeof(_vec3), &dwByte, nullptr);
		ReadFile(hFile, &frameNameSize, sizeof(_int), &dwByte, nullptr);
		ReadFile(hFile, &frameName, frameNameSize, &dwByte, nullptr);
		///////
		wstring frameNameWString = frameName;
		string frameNameString;
		frameNameString.assign(frameNameWString.begin(), frameNameWString.end());

		CSphereCollider* sphereCol = CSphereCollider::Create(m_pGraphicDev);
		sphereCol->m_pDynamicMesh = this;
		sphereCol->isCreate = true;
		sphereCol->m_FrameName = frameNameString;
		sphereCol->m_FrameNameCheck = true;
		m_VecSphereCollider.emplace_back(sphereCol);
		sphereCol->m_pTransformCom->m_vInfo[Engine::INFO_POS] = spherePos;
		sphereCol->m_pTransformCom->m_vScale = sphereScale;
		CColliderMgr::GetInstance()->RegisterObject(_collType, sphereCol);
		CColliderMgr::GetInstance()->RegisterObject(_collType2, sphereCol);
	}

	CloseHandle(hFile);

	return S_OK;
}

HRESULT CUnit::ColliderObject()
{
	CSphereCollider* sphereCol = CSphereCollider::Create(m_pGraphicDev);
	sphereCol->m_pDynamicMesh = this;
	sphereCol->isCreate = true;

	sphereCol->m_pTransformCom->m_vInfo[Engine::INFO_POS] = m_pTransformCom->m_vInfo[Engine::INFO_POS];
	sphereCol->isEnvironment = true;
	m_VecSphereCollider.emplace_back(sphereCol);
	CColliderMgr::GetInstance()->RegisterObject(Engine::COLLID::ENEMYATTACK, sphereCol);

	return S_OK;
}



void CUnit::Free(void)
{
	Engine::CGameObject::Free();
}

