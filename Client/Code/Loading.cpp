
#include "stdafx.h"
#include <io.h>
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
	for (auto& iter : vecStaticMesh)
		&iter->erase();



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

	//FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
	//										Engine::RESOURCE_STATIC,
	//										L"Buffer_PtTex",
	//										Engine::BUFFER_PTTEX),
	//										E_FAIL);


	lstrcpy(m_szLoading, L"Texture Loading.............................");
	// 텍스쳐

	//FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Logo", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Logo/Logo.jpg"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Player", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Player/Ma.jpg"), E_FAIL);
	//FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Monster", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Monster%d.png"), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Terrain",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Texture/Terrain/Terrain_%d.png", 8),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Terrain2",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Texture/Terrain/ground_%d.tga", 4),

		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Sword2Normal",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Mesh/StaticMesh/Sword2/longblade_blackhammer_normal.tga"),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Sword2",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Mesh/StaticMesh/Sword2/longblade_blackhammer.tga"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		L"Buffer_CollSphere",
		Engine::BUFFER_COLLSPHERE),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Filter",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Texture/Terrain/Filter.bmp", 1),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_Aura",
		Engine::TEX_NORMAL,
		L"../Bin/Resource/Texture/Terrain/Aura0.tga", 1),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_SkyBox",
		Engine::TEX_CUBE,
		L"../Bin/Resource/Texture/SkyBox/SkyBox%d.dds",2),
		E_FAIL);

	//FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Effect", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Explosion/Explosion%d.png", 90), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_FireEffect", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/Environment/FlameA/FlameA%d.tga", 50), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_TriggerBox", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/effect_ghostwall_ring.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_ConfusionHole1", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/aming_point_big04.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_ConfusionHole2", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/aming_point_big05.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SlashPoint", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/efx_sword_slashpoint.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_RuinBlade", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/fire_spark_02.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_LightRay", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/fire_spark_02.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SwordTrail0", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/heroes_longblade_trail02.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SwordTrail1", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/heroes_longblade_trail01.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SwordTrail2", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/heroes_longblade_trail04.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SwordTrail3", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/trail/heroes_longblade_trail05.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Black", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Effect/Black.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_DamageFont", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/Font_Damage.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SkillSlot", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/skill_slot.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_FadeInOut", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/FadeInOut.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_HpBarBack", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/PlayerHpBar_Back.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_HpBarValue", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/PlayerHpBar_Value.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SpBarBack", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/PlayerSpBar_Back.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SpBarValue", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/PlayerSpBar_ValueBar.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_StaminaBarBack", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/PlayerStaminaBar_Back.png"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_StaminaBarValue", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/PlayerStaminaBar_ValueBar.png"), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_BossHpBarBase", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/BossHpBar_base.dds"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_BossHpBarGreen", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/BossHpBar_green.dds"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_BossHpBarOrange", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/BossHpBar_Orange.dds"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_BossHpBarRed", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/BossHpBar_Red.dds"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_BossHpBarHit", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/BossHpBar_Hit.dds"), E_FAIL);

	//둠세이어
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Skill0", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/SkillIcon/Skill0.tga"), E_FAIL);
	//마나이미지
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Skill1", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/SkillIcon/Skill1.tga"), E_FAIL);
	//루블
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Skill2", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/SkillIcon/Skill2.tga"), E_FAIL);
	//로오마
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Skill4", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/SkillIcon/Skill4.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SkillDkTransform", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/SkillIcon/dk_transform_01_able.tga"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_SkillDkTransform2", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/UI/SkillIcon/dk_transform_02_able.tga"), E_FAIL);

	lstrcpy(m_szLoading, L"Mesh Loading.............................");
	// Stone
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Stone",
		Engine::TYPE_STATIC,
		L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
		L"TombStone.X"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Navi",
		Engine::TYPE_NAVI,
		L"../Bin/saveNaviCollo.dat",
		NULL),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Navi2",
		Engine::TYPE_NAVI,
		L"../Bin/saveNaviCastle.dat",
		NULL),
		E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Navi3",
		Engine::TYPE_NAVI,
		L"../Bin/naviCentral.dat",
		NULL),
		E_FAIL);
	//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
	//	Engine::RESOURCE_STAGE,
	//	L"Mesh_Navi3",
	//	Engine::TYPE_NAVI,
	//	L"../Bin/save14.dat",
	//	NULL),
	//	E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Player",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Mesh/DynamicMesh/Player/",
		L"Player.X"),
		E_FAIL);

	//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
	//	Engine::RESOURCE_STAGE,
	//	L"Mesh_Player1",
	//	Engine::TYPE_DYNAMIC,
	//	L"../Bin/Resource/Mesh/DynamicMesh/darkknight1/",
	//	L"darkknight_1_idle.X"),
	//	E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Player2",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Mesh/DynamicMesh/darkknight2/",
		L"darkknight_2_idle.X"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Dog",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Mesh/DynamicMesh/Dog/",
		L"Dog.X"),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Knight",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Mesh/DynamicMesh/Knight/",
		L"Knight_Att.X"),
		E_FAIL);


	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Mesh_Titan",
		Engine::TYPE_DYNAMIC,
		L"../Bin/Resource/Mesh/DynamicMesh/Titan/",
		L"Titan.X"),
		E_FAIL);

	//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
	//	Engine::RESOURCE_STAGE,
	//	L"Mesh_Ingkells",
	//	Engine::TYPE_DYNAMIC,
	//	L"../Bin/Resource/Mesh/DynamicMesh/Ingkells/",
	//	L"Ingkells.X"),
	//	E_FAIL);


	/*	FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			Engine::RESOURCE_STAGE,
			L"Mesh_TombStone",
			Engine::TYPE_STATIC,
			L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
			L"TombStone.X"),
			E_FAIL)*/;
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Colosseum",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/Colosseum/",
				L"Colosseum.X"),
				E_FAIL);
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Stage2",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/Stage2/",
				L"Stage2.X"),
				E_FAIL);
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_OrtelGate",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/OrtelGate/",
				L"OrtelGate.X"),
				E_FAIL);
			//
			//
			//
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_CentralGarden",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/CentralGarden/",
				L"CentralGarden.X"),
				E_FAIL);
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Fountain",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/Fountain/",
				L"Fountain.X"),
				E_FAIL);
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Weed_07",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/Weed_07/",
				L"Weed_07.X"),
				E_FAIL);

			//
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_FireTrap",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/FireTrap/",
				L"Fire_Trap.X"),
				E_FAIL);

			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Sword2",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/Sword2/",
				L"WeaponArisha2.X"),
				E_FAIL);
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Sword",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/Sword/",
				L"WeaponArisha.X"),
				E_FAIL);



			//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			//	Engine::RESOURCE_STAGE,
			//	L"Mesh_Player",
			//	Engine::TYPE_DYNAMIC,
			//	L"../Bin/Resource/ArishaX/",
			//	L"NewArisha.X"),
			//	E_FAIL);

			//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
		//	Engine::RESOURCE_STAGE,
		//	L"Mesh_Sword",
		//	Engine::TYPE_STATIC,
		//	L"../Bin/Resource/Arisha/Weapon/",
		//	L"WeaponArisha.X"),

		//	E_FAIL);
			//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			//											Engine::RESOURCE_STAGE,
			//											L"Mesh_Player",
			//											Engine::TYPE_DYNAMIC,
			//											L"../Bin/Resource/Mesh/DynamicMesh/PlayerXFile/",
			//											L"Player.X"),
			//											E_FAIL);

			//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			//											Engine::RESOURCE_STAGE,
			//											L"Mesh_Sword",
			//											Engine::TYPE_STATIC,
			//											L"../Bin/Resource/Mesh/StaticMesh/Sword/",
			//											L"Sword.X"),
			//											E_FAIL);

			//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			//										Engine::RESOURCE_STAGE,
			//										L"Mesh_Tree",
			//										Engine::TYPE_STATIC,
			//										L"../Bin/Resource/Mesh/StaticMesh/Tree/",
			//										L"Tree_00.X"),
			//										E_FAIL);
			//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			//	Engine::RESOURCE_STAGE,
			//	L"Mesh_Tree",
			//	Engine::TYPE_STATIC,
			//	L"../Bin/Resource/Mesh/StaticMesh/Weed/",
			//	L"Weed_00.X"),
			//	E_FAIL);
			FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
				Engine::RESOURCE_STAGE,
				L"Mesh_Tree",
				Engine::TYPE_STATIC,
				L"../Bin/Resource/Mesh/StaticMesh/OrtelGate/",
				L"OrtelGate.X"),
				E_FAIL);

			//
	
	
	lstrcpy(m_szLoading, L"Loading Complete!!!");

	m_bFinish = true;


	return 0;
}

void CLoading::Load_StaticObject()
{

	_finddata_t fd, fd2;

	long handle = _findfirst("../Bin/Resource/Mesh/StaticMesh/*.*", &fd);

	if (handle == 0)
		return;

	int iResult = 0;
	char szCurPath[128] = "../Bin/Resource/Mesh/StaticMesh/";
	char szFilePath[128] = "";
	char szSlash[128] = "/";
	char szStar[128] = "*.X";
	char szFullPath[128] = "";
	char meshName[128] = "";
	char meshTag[128] = "Mesh_";



	//fd2 = fd.name 
	while (iResult != -1)
	{
		//while (iResult != -1)
		//{
		strcpy_s(szFilePath, szCurPath);//"../Bin/Resource/Mesh/StaticMesh/";
		strcat_s(szFilePath, fd.name);//"../Bin/Resource/Mesh/StaticMesh/fd.name";
		strcat_s(szFilePath, szSlash);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";

		strcpy_s(szFullPath, szFilePath);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";
		strcat_s(szFullPath, szStar);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";

		strcpy_s(meshName, meshTag);//"Mesh_"
		strcat_s(meshName, fd.name);//"Mesh_File"


		if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0)
		{
			int iResult2 = 0;
			long handle2 = _findfirst(szFullPath, &fd2);//fd2  = file.X

			while (iResult2 != -1)
			{
				strcpy_s(szFullPath, szCurPath);
				strcat_s(szFullPath, fd.name);
				strcat_s(szFullPath, szSlash);
				strcat_s(szFullPath, fd2.name);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";


				wstring firstmeshName(meshName, &meshName[128]);
				wstring firstszFilePath(szFilePath, &szFilePath[128]);
				wstring firstfd2Name(fd2.name, &fd2.name[128]);

				wstring* secondMeshName = new wstring;
				*secondMeshName = firstmeshName;

				vecStaticMesh.emplace_back(secondMeshName);

				FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
					Engine::RESOURCE_STAGE,
					secondMeshName->c_str(),
					Engine::TYPE_STATIC,
					firstszFilePath.c_str(),
					firstfd2Name.c_str()),
					);
				iResult2 = _findnext(handle2, &fd2);


			}
		}



		iResult = _findnext(handle, &fd);
	}

	_findclose(handle);
}

void CLoading::Load_DynamicObject()
{

	_finddata_t fd, fd2;

	long handle = _findfirst("../Bin/Resource/Mesh/DynamicMesh/*.*", &fd);

	if (handle == 0)
		return;

	int iResult = 0;
	char szCurPath[128] = "../Bin/Resource/Mesh/DynamicMesh/";
	char szFilePath[128] = "";
	char szSlash[128] = "/";
	char szStar[128] = "*.X";
	char szFullPath[128] = "";
	char meshName[128] = "";
	char meshTag[128] = "Mesh_";



	//fd2 = fd.name 
	while (iResult != -1)
	{
		//while (iResult != -1)
		//{
		strcpy_s(szFilePath, szCurPath);//"../Bin/Resource/Mesh/StaticMesh/";
		strcat_s(szFilePath, fd.name);//"../Bin/Resource/Mesh/StaticMesh/fd.name";
		strcat_s(szFilePath, szSlash);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";

		strcpy_s(szFullPath, szFilePath);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";
		strcat_s(szFullPath, szStar);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";

		strcpy_s(meshName, meshTag);//"Mesh_"
		strcat_s(meshName, fd.name);//"Mesh_File"


		if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0)
		{
			int iResult2 = 0;
			long handle2 = _findfirst(szFullPath, &fd2);//fd2  = file.X

			while (iResult2 != -1)
			{
				strcpy_s(szFullPath, szCurPath);
				strcat_s(szFullPath, fd.name);
				strcat_s(szFullPath, szSlash);
				strcat_s(szFullPath, fd2.name);//"../Bin/Resource/Mesh/StaticMesh/fd.name/";


				wstring firstmeshName(meshName, &meshName[128]);
				wstring firstszFilePath(szFilePath, &szFilePath[128]);
				wstring firstfd2Name(fd2.name, &fd2.name[128]);

				wstring* secondMeshName = new wstring;
				*secondMeshName = firstmeshName;

				vecStaticMesh.emplace_back(secondMeshName);

				FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
					Engine::RESOURCE_STAGE,
					secondMeshName->c_str(),
					Engine::TYPE_DYNAMIC,
					firstszFilePath.c_str(),
					firstfd2Name.c_str()),
					);
				iResult2 = _findnext(handle2, &fd2);
			}
		}



		iResult = _findnext(handle, &fd);
	}

	_findclose(handle);
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

