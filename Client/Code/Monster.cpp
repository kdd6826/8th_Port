#include "stdafx.h"
#include "Monster.h"
#include "Export_Function.h"

CMonster::CMonster(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CGameObject(pGraphicDev)
{

}

CMonster::~CMonster(void)
{
	for (auto& sphere : m_VecSphereCollider)
	{
		Engine::Safe_Release(sphere);
	}
}

_int CMonster::Update_Object(const _float& fTimeDelta)
{
	for (auto& sphere : m_VecSphereCollider)
	{
		sphere->m_pDynamicMesh = this;
		sphere->Update_Object(fTimeDelta);
	}
	return S_OK;
}

bool CMonster::PlayerSearch(_vec3 _MonsterPos)
{
	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 playerPos = pPlayerTransCom->m_vInfo[Engine::INFO_POS];
	if (pPlayerTransCom == nullptr)
		return false;
	_float distX = playerPos.x - _MonsterPos.x;
	_float distZ = playerPos.z - _MonsterPos.z;

	disPlayer = sqrt(distX * distX + distZ * distZ);

	if (isSearch == true)
		return true;
	if (disPlayer < 2.f)
		return true;
	



	return false;
}

HRESULT CMonster::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;


	pComponent = m_pNaviMeshCom = dynamic_cast<Engine::CNaviMesh*>(Engine::Clone(Engine::RESOURCE_STAGE, L"Mesh_Navi"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Navi", pComponent);

	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	// Renderer
	pComponent = m_pRendererCom = Engine::Get_Renderer();
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Safe_AddRef(pComponent);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Renderer", pComponent);

	// Calculator
	pComponent = m_pCalculatorCom = dynamic_cast<Engine::CCalculator*>(Engine::Clone(L"Proto_Calculator"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_STATIC].emplace(L"Com_Calculator", pComponent);

	float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	m_pTransformCom->Set_Pos(&_vec3{ 18.f,0.f,18.f });
	Engine::CGameObject::Update_Object(timeDelta);


	return S_OK;
}

_int CMonster::Load_ColliderFile(_tchar* pFilePath)
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
		sphereCol->m_FrameName = frameNameString;
		sphereCol->m_FrameNameCheck = true;
		m_VecSphereCollider.emplace_back(sphereCol);
		sphereCol->m_pTransformCom->m_vInfo[Engine::INFO_POS] = spherePos;
		sphereCol->m_pTransformCom->m_vScale = sphereScale;
	}

	CloseHandle(hFile);

	return S_OK;
}



void CMonster::Free(void)
{
	Engine::CGameObject::Free();
}

