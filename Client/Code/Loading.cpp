#include "stdafx.h"
#include <io.h>
#include "Loading.h"
//#include "atlstr.h"

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

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Logo", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Logo/Logo.jpg"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Player", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Player/Ma.jpg"), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Monster", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Monster%d.png"), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												L"Texture_Terrain",
												Engine::TEX_NORMAL,
												L"../Bin/Resource/Texture/Terrain/Grass_%d.tga", 2),
												E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev,
		Engine::RESOURCE_STAGE,
		L"Texture_SkyBox",
		Engine::TEX_CUBE,
		L"../Bin/Resource/Texture/SkyBox/burger%d.dds", 4),
		E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STAGE, L"Texture_Effect", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Explosion/Explosion%d.png", 90), E_FAIL);
	
	lstrcpy(m_szLoading, L"Mesh Loading.............................");

	Load_StaticObject();

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
	//										L"Tree01.X"),
	//										E_FAIL);
	
	
	lstrcpy(m_szLoading, L"Loading Complete!!!");

	m_bFinish = true;

	
	return 0;
}

void CLoading::Load_StaticObject()
{

	_finddata_t fd,fd2;

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



//	

//	CFileFind firstFinder, secondFinder, thirdFinder;
//	CString findFile = _T("../Bin/Resource/Mesh/");
//	CString PathEnd = _T("*.*");
//	CString PathEnd2 = _T("/*.*");
//	CString PathEnd3 = _T("/*.X");
//
//	CString MeshFind;
//	MeshFind += findFile + PathEnd;
//	bool bWorking = firstFinder.FindFile(MeshFind);
//
//	while (bWorking) {
//		bWorking = firstFinder.FindNextFileW();
//		if (firstFinder.IsDirectory())
//		{
//#pragma region Static
//
//
//
//			if (firstFinder.GetFileName() == _T("StaticMesh"))
//			{
//				if (firstFinder.GetFileName() != _T(".") && firstFinder.GetFileName() != _T(".."))
//				{
//					///////////////////////Dynamic, Static
//
//
//					
//
//					CString temp;
//					temp += findFile + firstFinder.GetFileName() + PathEnd2;
//
//					bool bchildWorking = secondFinder.FindFile(temp);
//					while (bchildWorking) {
//						bchildWorking = secondFinder.FindNextFileW();
//						if (secondFinder.IsDirectory())
//						{
//							if (secondFinder.GetFileName() != _T(".") && secondFinder.GetFileName() != _T(".."))
//							{
//
//								///////Player
//								
//								CString temp2;
//								temp2 += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + PathEnd3;
//								bool bThirdWorking = thirdFinder.FindFile(temp2);
//								while (bThirdWorking) {
//									bThirdWorking = thirdFinder.FindNextFileW();
//									if (secondFinder.IsDirectory())
//									{
//										if (thirdFinder.GetFileName() != _T(".") && thirdFinder.GetFileName() != _T(".."))
//										{
//											CString temp, numFileName;
//											temp.Format(_T("%d"), staticLoadCount);
//											numFileName += temp + _T(") ") + thirdFinder.GetFileName();
//
//											
//											CString finalPath;
//											finalPath += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + _T("/");
//											CString check, check2, check3;
//
//											check = firstFinder.GetFileName();
//											check2 = secondFinder.GetFileName();
//											check3 = thirdFinder.GetFileName();
//											CString ObjTag, meshName;
//
//
//											ObjTag += L"Mesh_" + secondFinder.GetFileName();
//
//											TCHAR* tMesh = nullptr;
//											tMesh = (TCHAR*)(LPCTSTR)ObjTag;
//
//
//											CString* meshTag = new CString;
//
//											*meshTag = tMesh;
//
//											
//
//
//											if (FAILED(Engine::Ready_Meshes(m_pGraphicDev,
//												Engine::RESOURCE_STAGE,
//												*meshTag, //Sword,TombStone
//												Engine::TYPE_STATIC,
//												finalPath,					//../Bin/Resource/Mesh/......
//												check3)))
//											{
//												int i = 0;
//											}
//
//											staticLoadCount++;

											///////////////////

											//FAILED_CHECK_RETURN(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	check2, //Sword,TombStone
											//	Engine::TYPE_STATIC,
											//    finalPath,					//../Bin/Resource/Mesh/......
											//	check), //Sword.X
											//	);


											///////////////
			//							}
			//						}
			//					}

			//					///////
			//				}
			//			}
			//		}

			//		////////////////////////
			//	}
			//}
#pragma endregion
#pragma region Dynamic



			//if (firstFinder.GetFileName() == _T("DynamicMesh"))
			//{
			//	if (firstFinder.GetFileName() != _T(".") && firstFinder.GetFileName() != _T(".."))
			//	{
			//		///////////////////////Dynamic, Static


			//		objCreateItemSon[0][objCreateItemSonCount] = treeObjCreate.InsertItem(firstFinder.GetFileName(), objCreateItem);

			//		CString temp;
			//		temp += findFile + firstFinder.GetFileName() + PathEnd2;

			//		bool bchildWorking = secondFinder.FindFile(temp);
			//		while (bchildWorking) {
			//			bchildWorking = secondFinder.FindNextFileW();
			//			if (secondFinder.IsDirectory())
			//			{
			//				if (secondFinder.GetFileName() != _T(".") && secondFinder.GetFileName() != _T(".."))
			//				{

			//					///////Player
			//					objCreateItemSon[1][objCreateItemSonCount] = treeObjCreate.InsertItem(secondFinder.GetFileName(), objCreateItemSon[0][objCreateItemSonCount]);
			//					CString temp2;
			//					temp2 += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + PathEnd3;
			//					bool bThirdWorking = thirdFinder.FindFile(temp2);
			//					while (bThirdWorking) {
			//						bThirdWorking = thirdFinder.FindNextFileW();
			//						if (secondFinder.IsDirectory())
			//						{
			//							if (thirdFinder.GetFileName() != _T(".") && thirdFinder.GetFileName() != _T(".."))
			//							{
			//								CString temp, numFileName;
			//								temp.Format(_T("%d"), dynamicLoadCount);
			//								numFileName += temp + _T(") ") + thirdFinder.GetFileName();

			//								objCreateItemSon[2][objCreateItemSonCount] = treeObjCreate.InsertItem(numFileName, objCreateItemSon[1][objCreateItemSonCount]);
			//								CString finalPath;
			//								finalPath += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + _T("/");
			//								CString check, check2, check3;

			//								check = firstFinder.GetFileName();
			//								check2 = secondFinder.GetFileName();
			//								check3 = thirdFinder.GetFileName();
			//								CString ObjTag, meshName;


			//								ObjTag += L"Mesh_" + secondFinder.GetFileName();

			//								TCHAR* tMesh = nullptr;
			//								tMesh = (TCHAR*)(LPCTSTR)ObjTag;
			//								

			//								CString* meshTag = new CString;

			//								*meshTag = tMesh;

			//								CMFCToolView::GetInstance()->vecDynamicMesh.emplace_back(meshTag);


			//								if (FAILED(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
			//									Engine::RESOURCE_STAGE,
			//									*meshTag, //Sword,TombStone
			//									Engine::TYPE_DYNAMIC,
			//									finalPath,					//../Bin/Resource/Mesh/......
			//									check3)))
			//								{
			//									MessageBox(L"Fail to ready mesh");
			//								}

			//								dynamicLoadCount++;

			//								///////////////////

			//								//FAILED_CHECK_RETURN(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
			//								//	Engine::RESOURCE_STAGE,
			//								//	check2, //Sword,TombStone
			//								//	Engine::TYPE_STATIC,
			//								//    finalPath,					//../Bin/Resource/Mesh/......
			//								//	check), //Sword.X
			//								//	);

			//								//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
			//								//	Engine::RESOURCE_STAGE,
			//								//	L"Mesh_Stone",
			//								//	Engine::TYPE_STATIC,
			//								//	L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
			//								//	L"TombStone.X"),
			//								//	E_FAIL);

			//								///////////////
			//							}
			//						}
			//					}

			//					///////
			//				}
			//			}
			//		}

			//		objCreateItemSonCount++;
			//		////////////////////////
			//	}
			//}
	//	}
	//}

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

