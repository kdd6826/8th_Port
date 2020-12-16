// ColliderPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "ColliderPage.h"
#include "afxdialogex.h"
#include "MFCToolView.h"
#include "MFCDynamicMesh.h"


// ColliderPage 대화 상자입니다.

IMPLEMENT_DYNAMIC(ColliderPage, CDialogEx)

ColliderPage::ColliderPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

ColliderPage::~ColliderPage()
{
}

void ColliderPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, treeObjCreate);
	DDX_Control(pDX, IDC_LIST1, m_BoneList);
}


BEGIN_MESSAGE_MAP(ColliderPage, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &ColliderPage::OnTvnSelchangedTree1)
	ON_LBN_SELCHANGE(IDC_LIST1, &ColliderPage::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// ColliderPage 메시지 처리기입니다.



BOOL ColliderPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_DynamicObjItem = treeObjCreate.InsertItem(_T("Mesh"), m_DynamicObjItem);
	CFileFind firstFinder, secondFinder, thirdFinder;
	CString findFile = _T("../Bin/Resource/Mesh/");
	CString PathEnd = _T("*.*");
	CString PathEnd2 = _T("/*.*");
	CString PathEnd3 = _T("/*.X");

	CString MeshFind;
	MeshFind += findFile + PathEnd;
	bool bWorking = firstFinder.FindFile(MeshFind);

	while (bWorking) {
		bWorking = firstFinder.FindNextFileW();
		if (firstFinder.IsDirectory())
		{
#pragma region Static



			if (firstFinder.GetFileName() == _T("StaticMesh"))
			{
				if (firstFinder.GetFileName() != _T(".") && firstFinder.GetFileName() != _T(".."))
				{
					///////////////////////Dynamic, Static


					objCreateItemSon[0][objCreateItemSonCount] = treeObjCreate.InsertItem(firstFinder.GetFileName(), m_DynamicObjItem);

					CString temp;
					temp += findFile + firstFinder.GetFileName() + PathEnd2;

					bool bchildWorking = secondFinder.FindFile(temp);
					while (bchildWorking) {
						bchildWorking = secondFinder.FindNextFileW();
						if (secondFinder.IsDirectory())
						{
							if (secondFinder.GetFileName() != _T(".") && secondFinder.GetFileName() != _T(".."))
							{

								///////Player
								objCreateItemSon[1][objCreateItemSonCount] = treeObjCreate.InsertItem(secondFinder.GetFileName(), objCreateItemSon[0][objCreateItemSonCount]);
								CString temp2;
								temp2 += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + PathEnd3;
								bool bThirdWorking = thirdFinder.FindFile(temp2);
								while (bThirdWorking) {
									bThirdWorking = thirdFinder.FindNextFileW();
									if (secondFinder.IsDirectory())
									{
										if (thirdFinder.GetFileName() != _T(".") && thirdFinder.GetFileName() != _T(".."))
										{
											CString temp, numFileName;
											temp.Format(_T("%d"), staticLoadCount);
											numFileName += temp + _T(") ") + thirdFinder.GetFileName();

											objCreateItemSon[2][objCreateItemSonCount] = treeObjCreate.InsertItem(numFileName, objCreateItemSon[1][objCreateItemSonCount]);
											CString finalPath;
											finalPath += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + _T("/");
											CString check, check2, check3;

											check = firstFinder.GetFileName();
											check2 = secondFinder.GetFileName();
											check3 = thirdFinder.GetFileName();
											CString ObjTag, meshName;


											ObjTag += L"Mesh_" + secondFinder.GetFileName();

											TCHAR* tMesh = nullptr;
											tMesh = (TCHAR*)(LPCTSTR)ObjTag;


											CString* meshTag = new CString;

											*meshTag = tMesh;

											CMFCToolView::GetInstance()->vecStaticMesh.emplace_back(meshTag);


											//if (FAILED(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	*meshTag, //Sword,TombStone
											//	Engine::TYPE_STATIC,
											//	finalPath,					//../Bin/Resource/Mesh/......
											//	check3)))
											//{
											//	MessageBox(L"Fail to ready mesh");
											//}

											staticLoadCount++;

											///////////////////

											//FAILED_CHECK_RETURN(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	check2, //Sword,TombStone
											//	Engine::TYPE_STATIC,
											//    finalPath,					//../Bin/Resource/Mesh/......
											//	check), //Sword.X
											//	);

											//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	L"Mesh_Stone",
											//	Engine::TYPE_STATIC,
											//	L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
											//	L"TombStone.X"),
											//	E_FAIL);

											///////////////
										}
									}
								}

								///////
							}
						}
					}

					objCreateItemSonCount++;
					////////////////////////
				}
			}
#pragma endregion
#pragma region Dynamic



			if (firstFinder.GetFileName() == _T("DynamicMesh"))
			{
				if (firstFinder.GetFileName() != _T(".") && firstFinder.GetFileName() != _T(".."))
				{
					///////////////////////Dynamic, Static


					objCreateItemSon[0][objCreateItemSonCount] = treeObjCreate.InsertItem(firstFinder.GetFileName(), m_DynamicObjItem);

					CString temp;
					temp += findFile + firstFinder.GetFileName() + PathEnd2;

					bool bchildWorking = secondFinder.FindFile(temp);
					while (bchildWorking) {
						bchildWorking = secondFinder.FindNextFileW();
						if (secondFinder.IsDirectory())
						{
							if (secondFinder.GetFileName() != _T(".") && secondFinder.GetFileName() != _T(".."))
							{

								///////Player
								objCreateItemSon[1][objCreateItemSonCount] = treeObjCreate.InsertItem(secondFinder.GetFileName(), objCreateItemSon[0][objCreateItemSonCount]);
								CString temp2;
								temp2 += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + PathEnd3;
								bool bThirdWorking = thirdFinder.FindFile(temp2);
								while (bThirdWorking) {
									bThirdWorking = thirdFinder.FindNextFileW();
									if (secondFinder.IsDirectory())
									{
										if (thirdFinder.GetFileName() != _T(".") && thirdFinder.GetFileName() != _T(".."))
										{
											CString temp, numFileName;
											temp.Format(_T("%d"), dynamicLoadCount);
											numFileName += temp + _T(") ") + thirdFinder.GetFileName();

											objCreateItemSon[2][objCreateItemSonCount] = treeObjCreate.InsertItem(numFileName, objCreateItemSon[1][objCreateItemSonCount]);
											CString finalPath;
											finalPath += findFile + firstFinder.GetFileName() + _T("/") + secondFinder.GetFileName() + _T("/");
											CString check, check2, check3;

											check = firstFinder.GetFileName();
											check2 = secondFinder.GetFileName();
											check3 = thirdFinder.GetFileName();
											CString ObjTag, meshName;


											ObjTag += L"Mesh_" + secondFinder.GetFileName();

											TCHAR* tMesh = nullptr;
											tMesh = (TCHAR*)(LPCTSTR)ObjTag;


											CString* meshTag = new CString;

											*meshTag = tMesh;

											CMFCToolView::GetInstance()->vecDynamicMesh.emplace_back(meshTag);


											//if (FAILED(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	*meshTag, //Sword,TombStone
											//	Engine::TYPE_DYNAMIC,
											//	finalPath,					//../Bin/Resource/Mesh/......
											//	check3)))
											//{
											//	MessageBox(L"Fail to ready mesh");
											//}

											dynamicLoadCount++;

											///////////////////

											//FAILED_CHECK_RETURN(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	check2, //Sword,TombStone
											//	Engine::TYPE_STATIC,
											//    finalPath,					//../Bin/Resource/Mesh/......
											//	check), //Sword.X
											//	);

											//FAILED_CHECK_RETURN(Engine::Ready_Meshes(m_pGraphicDev,
											//	Engine::RESOURCE_STAGE,
											//	L"Mesh_Stone",
											//	Engine::TYPE_STATIC,
											//	L"../Bin/Resource/Mesh/StaticMesh/TombStone/",
											//	L"TombStone.X"),
											//	E_FAIL);

											///////////////
										}
									}
								}

								///////
							}
						}
					}

					objCreateItemSonCount++;
					////////////////////////
				}
			}
#pragma endregion
		}
	}
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void ColliderPage::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	///////////////////////
	CPoint point;
	UINT nFlags = 0;

	GetCursorPos(&point);
	::ScreenToClient(treeObjCreate.m_hWnd, &point);

	selectItem = treeObjCreate.HitTest(point, &nFlags);
	//해당 셀에 담긴 Text
	CString meshText = treeObjCreate.GetItemText(selectItem);

	//Text를 int로 바꾸기
	int indexNum;
	indexNum = _ttoi(meshText);


	//Mesh
	if (treeObjCreate.GetParentItem(selectItem) == 0)
	{
		//삼각형 셀이 선택
		//VertexManager::GetInstance()->vertex[indexNum];
	}
	//Dynamic or Static
	else if (treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(selectItem)) == 0)
	{
		int i = 0;
	}
	//Player, Sword etc.
	else if (treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(selectItem))) == 0)
	{

	}
	//XFile etc.
	else if (treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(selectItem)))) == 0)
	{
		CString checkState, text, MeshNum, temp2, objStaticTreeText;
		int iMeshNum;

		checkState = treeObjCreate.GetItemText(treeObjCreate.GetParentItem(treeObjCreate.GetParentItem(selectItem)));
		if (checkState == _T("StaticMesh"))
		{
			temp2.Format(_T("%d"), objStaticCreateCount);

			text = treeObjCreate.GetItemText((selectItem)) + _T(" - ") + temp2;


			MeshNum = text.Left(1);
			iMeshNum = _ttoi(MeshNum);


			CMFCToolView::GetInstance()->CreateStaticMesh((*CMFCToolView::GetInstance()->vecStaticMesh[iMeshNum]));


			//objStatic = treeObjStatic.InsertItem(text, 0, 0, TVI_ROOT, TVI_LAST);


			++objStaticCreateCount;
		}
		else if (checkState == _T("DynamicMesh"))
		{
			temp2.Format(_T("%d"), objDynamricCreateCount);

			text = treeObjCreate.GetItemText((selectItem)) + _T(" - ") + temp2;


			MeshNum = text.Left(1);
			iMeshNum = _ttoi(MeshNum);

			vector<Engine::CGameObject*>* vecDynamic_Col = &CMFCToolView::GetInstance()->vectorObjDynamic_Collider;
			if (vecDynamic_Col->size() != 0) {
				CMFCDynamicMesh* dMesh = dynamic_cast<CMFCDynamicMesh*>(vecDynamic_Col->front());
				dMesh->isDead = true;
			}

			CMFCToolView::GetInstance()->CreateDynamicMesh_OfCollider((*CMFCToolView::GetInstance()->vecDynamicMesh[iMeshNum]));
			CMFCDynamicMesh* dMesh = dynamic_cast<CMFCDynamicMesh*>(CMFCToolView::GetInstance()->vectorObjDynamic_Collider.front());
			for (auto& frameName : dMesh->m_VecFrameName)
			{
				if(frameName == nullptr)
					continue;
				WCHAR tmpName[50] = {};
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, frameName, strlen(frameName), tmpName, 50);

				m_BoneList.InsertString(-1, (LPCTSTR)tmpName);

			}

			//objDynamic = treeObjDynamic.InsertItem(text, 0, 0, TVI_ROOT, TVI_LAST);


			++objDynamricCreateCount;
		}
		//text += L"Mesh_" + treeObjCreate.GetItemText((treeObjCreate.GetParentItem(selectItem)));


	}


	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void ColliderPage::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString Temp;
	int index = m_BoneList.GetCurSel();
	if (index == LB_ERR)
		return;
	
	m_BoneList.GetText(index, Temp);

	CMFCDynamicMesh* dMesh = dynamic_cast<CMFCDynamicMesh*>(CMFCToolView::GetInstance()->vectorObjDynamic_Collider.front());
	dMesh->Create_BoneOfSphereCollier(Temp);
	
}
