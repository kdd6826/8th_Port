#include "stdafx.h"
#include "Loading.h"

#include "Export_Function.h"

CLoading::CLoading(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
	, m_bFinish(false)
{
	ZeroMemory(m_szLoading, sizeof(_tchar) * 256);
	m_pGraphicDev->AddRef();
}

CLoading::~CLoading(void)
{

}

_uint	CALLBACK CLoading::Thread_Main(void* pArg)
{
	CLoading*		pLoading = (CLoading*)pArg;

	_uint iFlag = 0;

	EnterCriticalSection(pLoading->Get_Crt());

	switch (pLoading->Get_LoadingID())
	{
	case LOADING_STAGE:
		iFlag = pLoading->Loading_ForStage();		
		break;

	case LOADING_BOSS:
		break;
	}
	
	LeaveCriticalSection(pLoading->Get_Crt());
	_endthreadex(0);

	return iFlag;
}

HRESULT CLoading::Ready_Loading(LOADINGID eLoading)
{
	InitializeCriticalSection(&m_Crt);		// 크리티컬 섹션 생성

	// 쓰레드 생성 함수
	m_hThread = (HANDLE)_beginthreadex(NULL, 0, Thread_Main, this, 0, NULL);

	m_eLoading = eLoading;

	return S_OK;
}

_uint CLoading::Loading_ForStage(void)
{
	lstrcpy(m_szLoading, L"Buffer Loading.............................");
	
	int i = 0;

	// component
	Engine::CComponent*		pComponent = nullptr;

	pComponent = Engine::CCalculator::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Proto(L"Proto_Calculator", pComponent);
	
	pComponent = Engine::COptimization::Create(m_pGraphicDev, true, VTXCNTX, VTXCNTZ);
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	Engine::Ready_Proto(L"Proto_Optimization", pComponent);


	// buffer

	//FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_RcTex", Engine::BUFFER_RCTEX), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
												Engine::RESOURCE_STATIC,
												L"Buffer_TerrainTex",
												Engine::BUFFER_TERRAINTEX,
												VTXCNTX,
												VTXCNTZ,
												VTXITV),
												E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
												Engine::RESOURCE_STATIC,
												L"Buffer_CubeTex",
												Engine::BUFFER_CUBETEX),
												E_FAIL);


	lstrcpy(m_szLoading, L"Texture Loading.............................");
	// 텍스쳐

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Logo", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/HeroesLogo.jpg"), E_FAIL);
	//FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Player", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Player/Ma.jpg"), E_FAIL);
	//FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Monster", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Monster%d.png"), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												L"Texture_Terrain",
												Engine::TEX_NORMAL,
												L"../Bin/Resource/Texture/Terrain/Terrain_%d.png", 2),
												E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_SkyBox",
		Engine::TEX_CUBE,
		L"../Bin/Resource/Texture/SkyBox/SkyBox%d.dds", 1),
		E_FAIL);

	/*FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Effect", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Explosion/Explosion%d.png", 90), E_FAIL);*/

	/*FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_UI", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/hpbar.png") , E_FAIL);*/
	
	lstrcpy(m_szLoading, L"Mesh Loading.............................");
	// Stone
	//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
	//											Engine::RESOURCE_STAGE,
	//											L"Mesh_Stone", 
	//											Engine::TYPE_STATIC, 
	//											L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
	//											L"TombStone.X"),
	//											E_FAIL);
		 //MAP1
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												L"Mesh_Stone", 
												Engine::TYPE_STATIC, 
												L"../Bin/Resource/Mesh/Stage0/",
												L"FistMap.X"),
												E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												L"Mesh_Navi",
												Engine::TYPE_NAVI,
												NULL,
												NULL),
												E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Player",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/ArishaX/",
		L"NewArisha.X"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Sword",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Arisha/Weapon/",
		L"WeaponArisha.X"),
		E_FAIL);

	/*FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												L"Mesh_Player",
												Engine::TYPE_DYNAMIC,
												L"../Bin/Resource/Mesh/DynamicMesh/PlayerXFile/",
												L"Player.X"),
												E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												L"Mesh_Sword",
												Engine::TYPE_STATIC,
												L"../Bin/Resource/Mesh/StaticMesh/Sword/",
												L"Sword.X"),
												E_FAIL);*/

	//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
	//										Engine::RESOURCE_STAGE,
	//										L"Mesh_Tree",
	//										Engine::TYPE_STATIC,
	//										L"../Bin/Resource/Mesh/StaticMesh/Tree/",
	//										L"Tree01.X"),
	//										E_FAIL);
	
	
	lstrcpy(m_szLoading, L"Loading Complete!!!");

	m_bFinish = true;


	return 0;
}

CLoading* CLoading::Create(LPDIRECT3DDEVICE9 pGraphicDev, LOADINGID eLoading)
{
	CLoading*	pInstance = new CLoading(pGraphicDev);

	if (FAILED(pInstance->Ready_Loading(eLoading)))
		Safe_Release(pInstance);

	return pInstance;

}

void CLoading::Free(void)
{
	WaitForSingleObject(m_hThread, INFINITE);
	CloseHandle(m_hThread);
	DeleteCriticalSection(&m_Crt);

	Engine::Safe_Release(m_pGraphicDev);
}

