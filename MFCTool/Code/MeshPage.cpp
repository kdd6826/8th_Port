/// MeshPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "MeshPage.h"
#include "afxdialogex.h"
#include "MFCToolView.h"
#include "VertexManager.h"
#include "TerrainTri.h"
#include "SphereMesh.h"
#include "GameObject.h"
#include "MainFrm.h"
#include "Cell.h"
#include "TriCol.h"
#include "MFCStaticMesh.h"
// MeshPage 대화 상자입니다.

IMPLEMENT_DYNAMIC(MeshPage, CDialogEx)
IMPLEMENT_SINGLETON(MeshPage)


MeshPage::MeshPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	if (nullptr == m_pInstance) {
		m_pInstance = this;
	}
}

MeshPage::~MeshPage()
{
}

void MeshPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, Render_Solid);
	DDX_Control(pDX, IDC_RADIO2, Render_WireFrame);
	//  DDX_Control(pDX, IDC_RADIO3, mouse_Objcet);
	DDX_Control(pDX, IDC_RADIO3, mouseObject);
	DDX_Control(pDX, IDC_RADIO5, mouseNaviMesh);
	//  DDX_Control(pDX, IDC_RADIO7, typeDynamic);
	DDX_Control(pDX, IDC_RADIO7, typeStatic);
	DDX_Control(pDX, IDC_RADIO8, typeDynamic);
	DDX_Control(pDX, IDC_TREE4, treeNavi);
	DDX_Control(pDX, IDC_EDIT14, transformPosX);
	DDX_Control(pDX, IDC_EDIT15, transformPosY);
	DDX_Control(pDX, IDC_EDIT16, transformPosZ);
	DDX_Control(pDX, IDC_EDIT5, transformScalX);
	DDX_Control(pDX, IDC_EDIT7, transformScalY);
	DDX_Control(pDX, IDC_EDIT8, transformScalZ);
	DDX_Control(pDX, IDC_EDIT10, transformRotX);
	DDX_Control(pDX, IDC_EDIT12, transformRotY);
	DDX_Control(pDX, IDC_EDIT13, transformRotZ);
	DDX_Control(pDX, IDC_TREE1, treeObjCreate);
	DDX_Control(pDX, IDC_TREE2, treeObjStatic);
	DDX_Control(pDX, IDC_TREE3, treeObjDynamic);
	//DDX_Text(pDX, IDC_EDIT14, m_fTransformPosX);
	//DDX_Text(pDX, IDC_EDIT15, m_fTransformPosY);
	//DDX_Text(pDX, IDC_EDIT16, m_fTransformPosZ);
	//DDX_Text(pDX, IDC_EDIT5, m_fTransformScalX);
	//DDX_Text(pDX, IDC_EDIT7, m_fTransformScalY);
	//DDX_Text(pDX, IDC_EDIT8, m_fTransformScalZ);
	//DDX_Text(pDX, IDC_EDIT10, m_fTransformRotX);
	//DDX_Text(pDX, IDC_EDIT12, m_fTransformRotY);
	//DDX_Text(pDX, IDC_EDIT13, m_fTransformRotZ);

}


BEGIN_MESSAGE_MAP(MeshPage, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &MeshPage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &MeshPage::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON10, &MeshPage::OnBnClickedButton10)
	ON_NOTIFY(NM_CLICK, IDC_TREE4, &MeshPage::OnNMClickNaviTree)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN12, &MeshPage::TransformPosXSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN14, &MeshPage::TransformPosYSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN13, &MeshPage::TransformPosZSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN9, &MeshPage::TransformRotXSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN11, &MeshPage::TransformRotYSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN10, &MeshPage::TransformRotZSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, &MeshPage::TransformScalXSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN8, &MeshPage::TransformScalYSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN7, &MeshPage::TransformScalZSpin)
	ON_BN_CLICKED(IDC_RADIO5, &MeshPage::NaviRadioBnClicked)
	ON_BN_CLICKED(IDC_RADIO3, &MeshPage::ObjectRadioBnClicked)
	ON_BN_CLICKED(IDC_BUTTON7, &MeshPage::OnBnClickedNaviSave)
	ON_BN_CLICKED(IDC_BUTTON8, &MeshPage::OnBnClickedNaviLoad)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &MeshPage::OnNMClickObjCreateTree)
	ON_NOTIFY(NM_CLICK, IDC_TREE2, &MeshPage::OnNMClickObjStaticTree)
	ON_NOTIFY(NM_CLICK, IDC_TREE3, &MeshPage::OnNMClickObjDynamicTree)

	ON_BN_CLICKED(IDC_BUTTON9, &MeshPage::OnBnClickedObjStaticDelete)
	ON_EN_CHANGE(IDC_EDIT5, &MeshPage::OnEnChangeTransformScalX)
	ON_EN_CHANGE(IDC_EDIT7, &MeshPage::OnEnChangeTransformScalY)
	ON_EN_CHANGE(IDC_EDIT8, &MeshPage::OnEnChangeTransformScalZ)
	ON_EN_CHANGE(IDC_EDIT10, &MeshPage::OnEnChangeTransformRotX)
	ON_EN_CHANGE(IDC_EDIT12, &MeshPage::OnEnChangeTransformRotY)
	ON_EN_CHANGE(IDC_EDIT13, &MeshPage::OnEnChangeTransformRotZ)
	ON_EN_CHANGE(IDC_EDIT14, &MeshPage::OnEnChangeTransformPosX)
	ON_EN_CHANGE(IDC_EDIT15, &MeshPage::OnEnChangeTransformPosY)
	ON_EN_CHANGE(IDC_EDIT16, &MeshPage::OnEnChangeTransformPosZ)
	ON_BN_CLICKED(IDC_BUTTON15, &MeshPage::OnBnClickedStaticSave)
	ON_BN_CLICKED(IDC_BUTTON16, &MeshPage::OnBnClickedStaticLoad)
	ON_BN_CLICKED(IDC_BUTTON13, &MeshPage::OnBnClickedDynamicSave)
	ON_BN_CLICKED(IDC_BUTTON14, &MeshPage::OnBnClickedDynamicLoad)
END_MESSAGE_MAP()


// MeshPage 메시지 처리기입니다.

BOOL MeshPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Render_Solid.SetCheck(BST_CHECKED);
	CMFCToolView::GetInstance()->wireFrame = false;
	//Pos X,Y,Z
	CString cPosVertexX, cPosVertexY, cPosVertexZ;
	cPosVertexX.Format(_T("%9.2f\n"), m_fTransformPosX);
	cPosVertexY.Format(_T("%9.2f\n"), m_fTransformPosY);
	cPosVertexZ.Format(_T("%9.2f\n"), m_fTransformPosZ);
	SetDlgItemText(IDC_EDIT14, cPosVertexX);
	SetDlgItemText(IDC_EDIT15, cPosVertexY);
	SetDlgItemText(IDC_EDIT16, cPosVertexZ);
	//
	//Scale X,Y,Z

	CString cScalVertexX, cScalVertexY, cScalVertexZ;
	cScalVertexX.Format(_T("%9.2f\n"), m_fTransformScalX);
	cScalVertexY.Format(_T("%9.2f\n"), m_fTransformScalY);
	cScalVertexZ.Format(_T("%9.2f\n"), m_fTransformScalZ);
	SetDlgItemText(IDC_EDIT5, cScalVertexX);
	SetDlgItemText(IDC_EDIT7, cScalVertexY);
	SetDlgItemText(IDC_EDIT8, cScalVertexZ);
	//
	//Rotation X,Y,Z
	CString cRotVertexX, cRotVertexY, cRotVertexZ;
	cRotVertexX.Format(_T("%9.2f\n"), m_fTransformRotX);
	cRotVertexY.Format(_T("%9.2f\n"), m_fTransformRotY);
	cRotVertexZ.Format(_T("%9.2f\n"), m_fTransformRotZ);
	SetDlgItemText(IDC_EDIT10, cRotVertexX);
	SetDlgItemText(IDC_EDIT12, cRotVertexY);
	SetDlgItemText(IDC_EDIT13, cRotVertexZ);
	//

	mouseObject.SetCheck(BST_CHECKED);
	typeStatic.SetCheck(BST_CHECKED);

	InitTreeCtrl();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void MeshPage::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCToolView::GetInstance()->wireFrame = false;
}
void MeshPage::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCToolView::GetInstance()->wireFrame = true;
}
void MeshPage::treeControl(int triCount)
{
	WCHAR wstr[16] = {};

	wsprintf(wstr, L"%d", triCount);

	tri[triCount] = treeNavi.InsertItem(wstr, 0, 0, TVI_ROOT, TVI_LAST);
	vertex[triCount][0] = treeNavi.InsertItem(L"0", 0, 0, tri[triCount], TVI_LAST);
	vertex[triCount][1] = treeNavi.InsertItem(L"1", 0, 0, tri[triCount], TVI_LAST);
	vertex[triCount][2] = treeNavi.InsertItem(L"2", 0, 0, tri[triCount], TVI_LAST);


}
void MeshPage::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 삭제
	//////////////////////////
	if (selectItem == nullptr)
		return;

	if (treeNavi.GetParentItem(selectItem) == 0)
	{
		//HTREEITEM hItem = treeNavi;
		treeNavi.GetItemText(selectItem);

		//해당 셀에 담긴 Text
		CString naviIndex = treeNavi.GetItemText(selectItem);

		//Text를 int로 바꾸기
		int indexNum;
		indexNum = _ttoi(naviIndex);

		CTerrainTri* triangle = CMFCToolView::GetInstance()->Get_TriOfNumber(indexNum);
		triangle->DeleteWithSphere();

		////////////////////


		treeNavi.DeleteItem(tri[indexNum]);
		selectItem = nullptr;
	}


}

void MeshPage::InitTreeCtrl()
{

	objCreateItem = treeObjCreate.InsertItem(_T("Mesh"), objCreateItem);
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


					objCreateItemSon[0][objCreateItemSonCount] = treeObjCreate.InsertItem(firstFinder.GetFileName(), objCreateItem);

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


											if (FAILED(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												*meshTag, //Sword,TombStone
												Engine::TYPE_STATIC,
												finalPath,					//../Bin/Resource/Mesh/......
												check3)))
											{
												MessageBox(L"Fail to ready mesh");
											}

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


					objCreateItemSon[0][objCreateItemSonCount] = treeObjCreate.InsertItem(firstFinder.GetFileName(), objCreateItem);

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


											if (FAILED(Engine::Ready_Meshes(CMFCToolView::GetInstance()->m_pGraphicDev,
												Engine::RESOURCE_STAGE,
												*meshTag, //Sword,TombStone
												Engine::TYPE_DYNAMIC,
												finalPath,					//../Bin/Resource/Mesh/......
												check3)))
											{
												MessageBox(L"Fail to ready mesh");
											}

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
}

void MeshPage::OnNMClickObjCreateTree(NMHDR* pNMHDR, LRESULT* pResult)
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


			objStatic = treeObjStatic.InsertItem(text, 0, 0, TVI_ROOT, TVI_LAST);


			++objStaticCreateCount;
		}
		else if (checkState == _T("DynamicMesh"))
		{
			temp2.Format(_T("%d"), objDynamricCreateCount);

			text = treeObjCreate.GetItemText((selectItem)) + _T(" - ") + temp2;


			MeshNum = text.Left(1);
			iMeshNum = _ttoi(MeshNum);


			CMFCToolView::GetInstance()->CreateDynamicMesh((*CMFCToolView::GetInstance()->vecDynamicMesh[iMeshNum]));


			objDynamic = treeObjDynamic.InsertItem(text, 0, 0, TVI_ROOT, TVI_LAST);


			++objDynamricCreateCount;
		}
		//text += L"Mesh_" + treeObjCreate.GetItemText((treeObjCreate.GetParentItem(selectItem)));


	}


	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
void MeshPage::OnNMClickObjStaticTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CPoint point;
	UINT nFlags = 0;

	GetCursorPos(&point);
	::ScreenToClient(treeObjStatic.m_hWnd, &point);

	selectItem = treeObjStatic.HitTest(point, &nFlags);

	if (selectItem == nullptr)
	{
		return;
	}
	CString a = treeObjStatic.GetItemText(selectItem);
	CString objStaticIndexNum = a.Right(1);
	size_t temp = 0;
	temp = _ttoi(objStaticIndexNum);

	m_fTransformPosX = dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].x;
	m_fTransformPosY = dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].y;
	m_fTransformPosZ = dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].z;

	m_fTransformScalX = dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.x;
	m_fTransformScalY = dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.y;
	m_fTransformScalZ = dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.z;
	//Text를 int로 바꾸기

	CString cVertexX, cVertexY, cVertexZ;

	cVertexX.Format(_T("%9.2f\n"), m_fTransformPosX);
	cVertexY.Format(_T("%9.2f\n"), m_fTransformPosY);
	cVertexZ.Format(_T("%9.2f\n"), m_fTransformPosZ);

	SetDlgItemText(IDC_EDIT14, cVertexX);
	SetDlgItemText(IDC_EDIT15, cVertexY);
	SetDlgItemText(IDC_EDIT16, cVertexZ);

	cVertexX.Format(_T("%9.2f\n"), m_fTransformScalX);
	cVertexY.Format(_T("%9.2f\n"), m_fTransformScalY);
	cVertexZ.Format(_T("%9.2f\n"), m_fTransformScalZ);

	SetDlgItemText(IDC_EDIT5, cVertexX);
	SetDlgItemText(IDC_EDIT7, cVertexY);
	SetDlgItemText(IDC_EDIT8, cVertexZ);

	*pResult = 0;
}
void MeshPage::OnNMClickObjDynamicTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
void MeshPage::OnNMClickNaviTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기 버텍스 넣어야함
	if (selectItem == nullptr)
		return;

	HTREEITEM hItem = treeNavi.GetSelectedItem();
	CStringW a = treeNavi.GetItemText(hItem);

	int triNum = CMFCToolView::GetInstance()->Get_VectorTri(&triNum).size();


	//i = p.size();
	//삼각형 색 복귀



	//VertexManager::GetInstance()->Set_TriColor(CMFCToolView::GetInstance()->Get_TriOfNumber(triNum)->m_pBufferCom, D3DCOLOR_ARGB(255, 100, 255, 100));

	//원 색 복귀
	for (int i = 0; i < triNum; ++i)
	{
		VertexManager::GetInstance()->Set_TriColor(CMFCToolView::GetInstance()->Get_TriOfNumber(i)->m_pBufferCom, D3DCOLOR_ARGB(255, 100, 255, 100));
		for (int j = 0; j < 3; j++)
		{
			VertexManager::GetInstance()->Set_SphereColor(CMFCToolView::GetInstance()->Get_TriOfNumber(i)->list_SphereMesh[j]->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
		}
	}


	///////////////////////
	CPoint point;
	UINT nFlags = 0;

	GetCursorPos(&point);
	::ScreenToClient(treeNavi.m_hWnd, &point);

	selectItem = treeNavi.HitTest(point, &nFlags);
	//해당 셀에 담긴 Text
	CString naviIndex = treeNavi.GetItemText(selectItem);

	//Text를 int로 바꾸기
	int indexNum;
	indexNum = _ttoi(naviIndex);




	if (treeNavi.GetParentItem(selectItem) == 0)
	{
		//삼각형 셀이 선택
		//VertexManager::GetInstance()->vertex[indexNum];

		CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(indexNum);
		VertexManager::GetInstance()->Set_TriColor(tri->m_pBufferCom, D3DCOLOR_ARGB(255, 255, 0, 0));


	}
	else if (treeNavi.GetParentItem(selectItem) != 0)
	{

		CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));

		int iParentIndex = _ttoi(parentIndex);
		VertexManager::GetInstance()->Set_TriColor(CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex)->m_pBufferCom, D3DCOLOR_ARGB(255, 255, 0, 0));


		CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

		CSphereMesh* sphere[3];
		int Temp = 0;
		for (auto& _sphere : tri->list_SphereMesh)
		{
			sphere[Temp] = _sphere;
			Temp++;
		}


		lastSphereIndex = indexNum;
		VertexManager::GetInstance()->Set_SphereColor(sphere[indexNum]->m_pBufferCom, D3DCOLOR_ARGB(255, 200, 0, 0));

		int triIndex;
		triIndex = _ttoi(parentIndex);


		m_fTransformPosX = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].x;
		m_fTransformPosY = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].y;
		m_fTransformPosZ = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].z;

		m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
		m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
		m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;



		//float m_fTransformPosX = VertexManager::GetInstance()->vertex[triIndex][indexNum].x;
		//float m_fTransformPosY = VertexManager::GetInstance()->vertex[triIndex][indexNum].y;
		//float m_fTransformPosZ = VertexManager::GetInstance()->vertex[triIndex][indexNum].z;

		CString cVertexX, cVertexY, cVertexZ;

		cVertexX.Format(_T("%9.2f\n"), m_fTransformPosX);
		cVertexY.Format(_T("%9.2f\n"), m_fTransformPosY);
		cVertexZ.Format(_T("%9.2f\n"), m_fTransformPosZ);

		SetDlgItemText(IDC_EDIT14, cVertexX);
		SetDlgItemText(IDC_EDIT15, cVertexY);
		SetDlgItemText(IDC_EDIT16, cVertexZ);

		cVertexX.Format(_T("%9.2f\n"), m_fTransformScalX);
		cVertexY.Format(_T("%9.2f\n"), m_fTransformScalY);
		cVertexZ.Format(_T("%9.2f\n"), m_fTransformScalZ);

		SetDlgItemText(IDC_EDIT5, cVertexX);
		SetDlgItemText(IDC_EDIT7, cVertexY);
		SetDlgItemText(IDC_EDIT8, cVertexZ);


	}






	if (selectItem != NULL && (nFlags & TVHT_ONITEMSTATEICON) != 0)
	{
		if (treeNavi.GetCheck(selectItem))
		{
			UnCheckChildItems(selectItem);
		}
		else
		{
			CheckChildItems(selectItem);
		}
	}


	wchar_t text[16];


	TVITEMW item;
	item.mask = TVIF_TEXT;
	item.hItem = selectItem;
	item.pszText = text;
	item.cchTextMax = 16;
	treeNavi.GetItem(&item);

	OutputDebugString(text);

	*pResult = 0;
}

void MeshPage::CheckChildItems(HTREEITEM _hItem)
{
	HTREEITEM hChildItem = treeNavi.GetChildItem(_hItem);
	while (hChildItem != NULL)
	{
		treeNavi.SetCheck(hChildItem, TRUE);

		if (treeNavi.ItemHasChildren(hChildItem))
		{
			CheckChildItems(hChildItem);
		}

		hChildItem = treeNavi.GetNextItem(hChildItem, TVGN_NEXT);
	}

}
void MeshPage::UnCheckChildItems(HTREEITEM _hItem)
{
	HTREEITEM hChildItem = treeNavi.GetChildItem(_hItem);
	while (hChildItem != NULL)
	{
		treeNavi.SetCheck(hChildItem, FALSE);

		if (treeNavi.ItemHasChildren(hChildItem))
		{
			CheckChildItems(hChildItem);
		}

		hChildItem = treeNavi.GetNextItem(hChildItem, TVGN_NEXT);
	}
}


////
#pragma region Spin
//


void MeshPage::TransformPosXSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//////////////////////////

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);


			m_fTransformPosX = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].x;
			m_fTransformPosY = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].y;
			m_fTransformPosZ = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].z;

			////////////////////

			CString cVertex;
			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformPosX += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformPosX);
			}
			else
			{
				m_fTransformPosX -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformPosX);
			}
			*pResult = 0;
			sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].x = m_fTransformPosX;
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT14, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformPosX += 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformPosX);
		}
		else
		{
			m_fTransformPosX -= 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformPosX);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].x = m_fTransformPosX;
		SetDlgItemText(IDC_EDIT14, cVertex);

		*pResult = 0;




	}
}

void MeshPage::TransformPosYSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		//////////////////////////

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);


			m_fTransformPosX = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].x;
			m_fTransformPosY = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].y;
			m_fTransformPosZ = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].z;

			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformPosY += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformPosY);
			}
			else
			{
				m_fTransformPosY -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformPosY);
			}
			*pResult = 0;

			sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].y = m_fTransformPosY;
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT15, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformPosY += 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformPosY);
		}
		else
		{
			m_fTransformPosY -= 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformPosY);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].y = m_fTransformPosY;
		SetDlgItemText(IDC_EDIT15, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformPosZSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);


			m_fTransformPosX = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].x;
			m_fTransformPosY = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].y;
			m_fTransformPosZ = sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].z;

			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformPosZ += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformPosZ);
			}
			else
			{
				m_fTransformPosZ -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformPosZ);
			}
			*pResult = 0;
			sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].z = m_fTransformPosZ;
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT16, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformPosZ += 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformPosZ);
		}
		else
		{
			m_fTransformPosZ -= 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformPosZ);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].z = m_fTransformPosZ;
		SetDlgItemText(IDC_EDIT16, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformRotXSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);



			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformRotX += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformRotX);
			}
			else
			{
				m_fTransformRotX -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformRotX);
			}
			*pResult = 0;
			sphere[indexNum]->m_pTransformCom->Rotation(Engine::ROTATION::ROT_X, m_fTransformRotX);
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT10, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformRotX += 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformRotX);
		}
		else
		{
			m_fTransformRotX -= 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformRotX);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->Rotation(Engine::ROTATION::ROT_X, m_fTransformRotX);;
		SetDlgItemText(IDC_EDIT10, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformRotYSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);

			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformRotY += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformRotY);
			}
			else
			{
				m_fTransformRotY -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformRotY);
			}
			*pResult = 0;
			sphere[indexNum]->m_pTransformCom->Rotation(Engine::ROTATION::ROT_Y, m_fTransformRotY);
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT12, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformRotY += 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformRotY);
		}
		else
		{
			m_fTransformRotY -= 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformRotY);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->Rotation(Engine::ROTATION::ROT_Y, m_fTransformRotY);
		SetDlgItemText(IDC_EDIT12, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformRotZSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);

			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformRotZ += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformRotZ);
			}
			else
			{
				m_fTransformRotZ -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformRotZ);
			}
			*pResult = 0;
			sphere[indexNum]->m_pTransformCom->Rotation(Engine::ROTATION::ROT_Z, m_fTransformRotZ);
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT13, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformRotZ += 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformRotZ);
		}
		else
		{
			m_fTransformRotZ -= 0.1f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformRotZ);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->Rotation(Engine::ROTATION::ROT_Z, m_fTransformRotZ);
		SetDlgItemText(IDC_EDIT13, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformScalXSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);
			m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
			m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
			m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;
			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformScalX += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformScalX);
			}
			else
			{
				m_fTransformScalX -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformScalX);
			}
			sphere[indexNum]->m_pTransformCom->m_vScale.x = m_fTransformScalX;
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT5, cVertex);
			*pResult = 0;
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformScalX += 0.01f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformScalX);
		}
		else
		{
			m_fTransformScalX -= 0.01f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformScalX);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.x = m_fTransformScalX;
		SetDlgItemText(IDC_EDIT5, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformScalYSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);
			m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
			m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
			m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;
			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformScalY += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformScalY);
			}
			else
			{
				m_fTransformScalY -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformScalY);
			}
			*pResult = 0;

			sphere[indexNum]->m_pTransformCom->m_vScale.y = m_fTransformScalY;
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT7, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformScalY += 0.01f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformScalY);
		}
		else
		{
			m_fTransformScalY -= 0.01f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformScalY);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.y = m_fTransformScalY;
		SetDlgItemText(IDC_EDIT7, cVertex);

		*pResult = 0;




	}
}
void MeshPage::TransformScalZSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		///////////////
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//HTREEITEM hItem = treeNavi;
			treeNavi.GetItemText(selectItem);

			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);

			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);

			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);

			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}

			int triIndex;
			triIndex = _ttoi(parentIndex);

			m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
			m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
			m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;

			////////////////////
			CString cVertex;


			if (pNMUpDown->iDelta < 0)
			{
				m_fTransformScalZ += 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformScalZ);
			}
			else
			{
				m_fTransformScalZ -= 0.1f;
				cVertex.Format(_T("%9.2f\n"), m_fTransformScalZ);
			}
			*pResult = 0;
			sphere[indexNum]->m_pTransformCom->m_vScale.z = m_fTransformScalZ;
			sphere[indexNum]->Set_InitPoint();
			SetDlgItemText(IDC_EDIT8, cVertex);
		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{

		//해당 셀에 담긴 Text

			//해당 셀에 담긴 Text
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);


		//Text를 int로 바꾸기


		///////////////////
		CString cVertex;
		if (pNMUpDown->iDelta < 0)
		{
			m_fTransformScalZ += 0.01f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformScalZ);
		}
		else
		{
			m_fTransformScalZ -= 0.01f;
			cVertex.Format(_T("%9.2f\n"), m_fTransformScalZ);
		}
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.z = m_fTransformScalZ;
		SetDlgItemText(IDC_EDIT8, cVertex);

		*pResult = 0;




	}
}
#pragma endregion
void MeshPage::ObjectRadioBnClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	VertexManager::GetInstance()->isNaviMesh = false;
	VertexManager::GetInstance()->isObjectMesh = true;
}
void MeshPage::NaviRadioBnClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	VertexManager::GetInstance()->isNaviMesh = true;
	VertexManager::GetInstance()->isObjectMesh = false;
}
void MeshPage::OnBnClickedStaticSave()
{
	CFileDialog Dlg(FALSE, L"dat", L"*.dat", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data File(*.dat) | *.dat||", this);
	TCHAR szCurPath[MAX_PATH] = L"";
	TCHAR szDataPath[MAX_PATH] = L"";
	GetCurrentDirectory(MAX_PATH, szCurPath);
	PathRemoveFileSpec(szCurPath);
	PathCombine(szDataPath, szCurPath, L"Data");
	Dlg.m_ofn.lpstrInitialDir = szDataPath;
	if (IDOK == Dlg.DoModal())
	{
		CString strPath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(strPath.GetString(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;
		DWORD dwByte = 0;
		DWORD dwstrByte = 0;

		TCHAR meshKey[MAX_PATH] = L"";

		vector<Engine::CGameObject*> vecStatic = CMFCToolView::GetInstance()->vectorObjStatic;

		for (auto& rPair : vecStatic)
		{
			lstrcpy(meshKey, dynamic_cast<CMFCStaticMesh*>(rPair)->meshKey);
			_int len = lstrlen(meshKey) * 2;
			WriteFile(hFile, &len, sizeof(_int), &dwByte, nullptr);
			WriteFile(hFile, lstrcpyW(meshKey, dynamic_cast<CMFCStaticMesh*>(rPair)->meshKey), len, &dwByte, nullptr);
			WriteFile(hFile, dynamic_cast<Engine::CTransform*>(rPair->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS], sizeof(_vec3), &dwByte, nullptr);
			WriteFile(hFile, dynamic_cast<Engine::CTransform*>(rPair->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->m_vScale, sizeof(_vec3), &dwByte, nullptr);
			WriteFile(hFile, dynamic_cast<Engine::CTransform*>(rPair->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->m_vAngle, sizeof(_vec3), &dwByte, nullptr);
		}



		CloseHandle(hFile);
	}
}


void MeshPage::OnBnClickedStaticLoad()
{
	UpdateData(TRUE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(TRUE, L"dat", L"*.dat", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data File(*.dat) | *.dat||", this);
	TCHAR szCurPath[MAX_PATH] = L"";
	TCHAR szDataPath[MAX_PATH] = L"";
	GetCurrentDirectory(MAX_PATH, szCurPath);
	PathRemoveFileSpec(szCurPath);
	PathCombine(szDataPath, szCurPath, L"Data");
	Dlg.m_ofn.lpstrInitialDir = szDataPath;
	if (IDOK == Dlg.DoModal())
	{
		CString strPath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(strPath.GetString(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;
		DWORD dwByte = 0;
		DWORD dwstrByte = 0;
		int triTotalNumber = 0;

		bool endCheck = false;
		while (true)
		{
			bool sphereOverlap = false;

			_vec3 vecPos, vecAng, vecScal;
			TCHAR meshName[MAX_PATH] = L"";
			_int meshNameSize;
			ReadFile(hFile, &meshNameSize, sizeof(_int), &dwByte, nullptr);
			ReadFile(hFile, &meshName, meshNameSize, &dwByte, nullptr);
			ReadFile(hFile, &vecPos, sizeof(_vec3), &dwByte, nullptr);
			ReadFile(hFile, &vecScal, sizeof(_vec3), &dwByte, nullptr);
			ReadFile(hFile, &vecAng, sizeof(_vec3), &dwByte, nullptr);

			if (0 == dwByte)
			{
				endCheck = true;
				break;
			}
			CString text, temp2, num;
			text = meshName;

			int idx = -1;
			int size = CMFCToolView::GetInstance()->vecStaticMesh.size();
			for (int i = 0; i < size; i++)
			{
				CString* pStr = CMFCToolView::GetInstance()->vecStaticMesh[i];
				if (*pStr == text.GetString())
				{
					idx = i;
					break;
				}
			}
			num.Format(_T("%d"), idx);

			temp2.Format(_T("%d"), objStaticCreateCount);
			text = num + _T(")") + text.Mid(5) + _T(".X - ") + temp2;
			CMFCToolView::GetInstance()->LoadStaticMesh(meshName, vecPos, vecScal, vecAng);
			objStatic = treeObjStatic.InsertItem(text, 0, 0, TVI_ROOT, TVI_LAST);


			++objStaticCreateCount;
			//for (int i = 0; i < 3; i++)
			//{

			//	ReadFile(hFile, &vecPos[i], sizeof(_vec3), &dwByte, nullptr); //세모 꼭짓점 3개 벡터 가져와주고
			//	
			/*	Engine::_vec3	vPickPos = vecPos[i];
				Engine::CGameObject* pGameObject = nullptr;
				if (Engine::_vec3(0.f, 0.f, 0.f) != vPickPos) {
					for (auto& obj : VertexManager::GetInstance()->list_TotalSphere)
					{
						if (vPickPos == obj->m_pTransformCom->m_vInfo[Engine::INFO_POS]) {
							pGameObject = obj;
							dynamic_cast<CSphereMesh*>(pGameObject)->m_Click = true;
							sphereOverlap = true;
							VertexManager::GetInstance()->list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
							VertexManager::GetInstance()->list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
							break;
						}
					}
					if (pGameObject == nullptr) {
						pGameObject = CSphereMesh::Create(CMFCToolView::GetInstance()->m_pGraphicDev);
						dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS] = vPickPos;
						CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"Sphere", pGameObject);
						dynamic_cast<CSphereMesh*>(pGameObject)->m_Click = true;
						VertexManager::GetInstance()->list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
						VertexManager::GetInstance()->list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
					}
				}

				if (VertexManager::GetInstance()->list_Sphere.size() == 3) {
					Engine::_vec3 vtxPos[3];
					list<CSphereMesh*> TempSphereMesh;
					int sphereCnt = 0;
					Engine::_vec3 sphereVec[3];
					for (int i = 0; i < 3; i++)
					{
						VertexManager::GetInstance()->Set_SphereColor(VertexManager::GetInstance()->list_Sphere.front()->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
						VertexManager::GetInstance()->list_Sphere.front()->m_Click = false;
						vtxPos[i] = VertexManager::GetInstance()->list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
						TempSphereMesh.emplace_back(VertexManager::GetInstance()->list_Sphere.front());
						sphereVec[sphereCnt] = VertexManager::GetInstance()->list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
						sphereCnt++;
						VertexManager::GetInstance()->list_Sphere.pop_front();
					}
					CTerrainTri* pTerrainTri = CTerrainTri::Create(VertexManager::GetInstance()->m_pGraphicDev, vtxPos[0], vtxPos[1], vtxPos[2]);



					CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"TerrainTri", pTerrainTri);*/

					//for (int i = 0; i < 3; i++)
					//{
					//	pTerrainTri->list_SphereMesh.emplace_back(TempSphereMesh.front());
					//	TempSphereMesh.front()->list_pTerrainTri.emplace_back(pTerrainTri);
					//	TempSphereMesh.front()->list_pPoint.emplace_back(pTerrainTri->m_Cell->Get_pPoint((Engine::CCell::POINT)i));
					//	TempSphereMesh.pop_front();
					//}
					//CMFCToolView::GetInstance()->Sort_TriNumber();
					//MeshPage* pMeshPage = MeshPage::GetInstance();
					//if (pMeshPage != nullptr)
					//{
					//	pMeshPage->treeControl(*pTerrainTri->m_Cell->Get_Index());
					//}
			if (0 == dwByte)
			{
				//Safe_Delete(pUnit);
				break;
			}



			if (endCheck) {
				break;
			}
		}
		CloseHandle(hFile);
	}
	UpdateData(FALSE);
}


void MeshPage::OnBnClickedDynamicSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MeshPage::OnBnClickedDynamicLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void MeshPage::OnBnClickedNaviSave()
{
	CFileDialog Dlg(FALSE, L"dat", L"*.dat", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data File(*.dat) | *.dat||", this);
	TCHAR szCurPath[MAX_PATH] = L"";
	TCHAR szDataPath[MAX_PATH] = L"";
	GetCurrentDirectory(MAX_PATH, szCurPath);
	PathRemoveFileSpec(szCurPath);
	PathCombine(szDataPath, szCurPath, L"Data");
	Dlg.m_ofn.lpstrInitialDir = szDataPath;
	if (IDOK == Dlg.DoModal())
	{
		CString strPath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(strPath.GetString(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;
		DWORD dwByte = 0;
		DWORD dwstrByte = 0;

		int triTotalNumber = 0;
		vector<Engine::CCell*> vecTri = CMFCToolView::GetInstance()->Get_VectorTri(&triTotalNumber);

		for (auto& rPair : vecTri)
		{
			WriteFile(hFile, rPair->Get_pPoint(Engine::CCell::POINT_A), sizeof(_vec3), &dwByte, nullptr);
			WriteFile(hFile, rPair->Get_pPoint(Engine::CCell::POINT_B), sizeof(_vec3), &dwByte, nullptr);
			WriteFile(hFile, rPair->Get_pPoint(Engine::CCell::POINT_C), sizeof(_vec3), &dwByte, nullptr);

		}



		CloseHandle(hFile);
	}
}
void MeshPage::OnBnClickedNaviLoad()
{
	UpdateData(TRUE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(TRUE, L"dat", L"*.dat", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data File(*.dat) | *.dat||", this);
	TCHAR szCurPath[MAX_PATH] = L"";
	TCHAR szDataPath[MAX_PATH] = L"";
	GetCurrentDirectory(MAX_PATH, szCurPath);
	PathRemoveFileSpec(szCurPath);
	PathCombine(szDataPath, szCurPath, L"Data");
	Dlg.m_ofn.lpstrInitialDir = szDataPath;
	if (IDOK == Dlg.DoModal())
	{
		CString strPath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(strPath.GetString(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;
		DWORD dwByte = 0;
		DWORD dwstrByte = 0;
		UNITINFO* pUnit = nullptr;
		int triTotalNumber = 0;

		bool endCheck = false;
		while (true)
		{
			bool sphereOverlap = false;
			_vec3 vecPos[3];
			for (int i = 0; i < 3; i++)
			{
				ReadFile(hFile, &vecPos[i], sizeof(_vec3), &dwByte, nullptr); //세모 꼭짓점 3개 벡터 가져와주고

				if (0 == dwByte)
				{
					//Safe_Delete(pUnit);
					endCheck = true;
					break;
				}
				Engine::_vec3	vPickPos = vecPos[i];
				Engine::CGameObject* pGameObject = nullptr;
				if (Engine::_vec3(0.f, 0.f, 0.f) != vPickPos) {
					for (auto& obj : VertexManager::GetInstance()->list_TotalSphere)
					{
						if (vPickPos == obj->m_pTransformCom->m_vInfo[Engine::INFO_POS]) {
							pGameObject = obj;
							dynamic_cast<CSphereMesh*>(pGameObject)->m_Click = true;
							sphereOverlap = true;
							VertexManager::GetInstance()->list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
							VertexManager::GetInstance()->list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
							break;
						}
					}
					if (pGameObject == nullptr) {
						pGameObject = CSphereMesh::Create(CMFCToolView::GetInstance()->m_pGraphicDev);
						dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS] = vPickPos;
						CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"Sphere", pGameObject);
						//dynamic_cast<CSphereMesh*>(pGameObject)->Set_VtxPos();
						dynamic_cast<CSphereMesh*>(pGameObject)->m_Click = true;
						VertexManager::GetInstance()->list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
						VertexManager::GetInstance()->list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
					}
					//pGameObject->AddRef();
				}

				//CMFCToolView::GetInstance()->LayerAddObject();
				if (VertexManager::GetInstance()->list_Sphere.size() == 3) {
					Engine::_vec3 vtxPos[3];
					list<CSphereMesh*> TempSphereMesh;
					int sphereCnt = 0;
					Engine::_vec3 sphereVec[3];
					for (int i = 0; i < 3; i++)
					{
						VertexManager::GetInstance()->Set_SphereColor(VertexManager::GetInstance()->list_Sphere.front()->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
						VertexManager::GetInstance()->list_Sphere.front()->m_Click = false;
						vtxPos[i] = VertexManager::GetInstance()->list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
						TempSphereMesh.emplace_back(VertexManager::GetInstance()->list_Sphere.front());
						sphereVec[sphereCnt] = VertexManager::GetInstance()->list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
						sphereCnt++;
						VertexManager::GetInstance()->list_Sphere.pop_front();
					}
					CTerrainTri* pTerrainTri = CTerrainTri::Create(VertexManager::GetInstance()->m_pGraphicDev, vtxPos[0], vtxPos[1], vtxPos[2]);



					CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"TerrainTri", pTerrainTri);

					for (int i = 0; i < 3; i++)
					{
						pTerrainTri->list_SphereMesh.emplace_back(TempSphereMesh.front());
						TempSphereMesh.front()->list_pTerrainTri.emplace_back(pTerrainTri);
						TempSphereMesh.front()->list_pPoint.emplace_back(pTerrainTri->m_Cell->Get_pPoint((Engine::CCell::POINT)i));
						TempSphereMesh.pop_front();
					}
					CMFCToolView::GetInstance()->Sort_TriNumber();
					MeshPage* pMeshPage = MeshPage::GetInstance();

					if (pMeshPage != nullptr)
					{

						pMeshPage->treeControl(*pTerrainTri->m_Cell->Get_Index());
					}
					if (0 == dwByte)
					{
						//Safe_Delete(pUnit);
						break;
					}

				}


				//////////////////////////////////////////////
			}
			if (endCheck) {
				break;
			}
		}
		CloseHandle(hFile);
	}
	UpdateData(FALSE);
}



void MeshPage::OnBnClickedObjStaticDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString a = treeObjStatic.GetItemText(selectItem);
	CString objStaticIndexNum = a.Right(1);
	int temp = 0;
	temp = _ttoi(objStaticIndexNum);
	objStaticCreateCount--;



	treeObjStatic.DeleteItem(selectItem);
	///////////////////
	vector<Engine::CGameObject*> vecObj = CMFCToolView::GetInstance()->vectorObjStatic;

	dynamic_cast<CMFCStaticMesh*>(*(vecObj.begin() + temp))->isDead = true;


	//vecObj.erase(vecObj.begin()+temp);
	int i = vecObj.size();


}


void MeshPage::OnEnChangeTransformScalX()
{
	//if (selectItem == nullptr)
	//	return;
	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
			m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
			m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT5, cVertex);
			float n = _ttof(cVertex);
			m_fTransformScalX = n;
			sphere[indexNum]->m_pTransformCom->m_vScale.x = m_fTransformScalX;
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT5, cVertex);
		float n = _ttof(cVertex);
		m_fTransformScalX = n;
		if(0==CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.x = m_fTransformScalX;
	}
}


void MeshPage::OnEnChangeTransformScalY()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
			m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
			m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT7, cVertex);
			float n = _ttof(cVertex);
			m_fTransformScalY = n;
			sphere[indexNum]->m_pTransformCom->m_vScale.y = m_fTransformScalY;
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT7, cVertex);
		float n = _ttof(cVertex);
		m_fTransformScalY = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.y = m_fTransformScalY;
	}
}


void MeshPage::OnEnChangeTransformScalZ()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			m_fTransformScalX = sphere[indexNum]->m_pTransformCom->m_vScale.x;
			m_fTransformScalY = sphere[indexNum]->m_pTransformCom->m_vScale.y;
			m_fTransformScalZ = sphere[indexNum]->m_pTransformCom->m_vScale.z;
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT8, cVertex);
			float n = _ttof(cVertex);
			m_fTransformScalZ = n;
			sphere[indexNum]->m_pTransformCom->m_vScale.z = m_fTransformScalZ;
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT8, cVertex);
		float n = _ttof(cVertex);
		m_fTransformScalZ = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vScale.z = m_fTransformScalZ;
	}
}


void MeshPage::OnEnChangeTransformRotX()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT10, cVertex);
			float n = _ttof(cVertex);
			m_fTransformRotX = n;
			sphere[indexNum]->m_pTransformCom->Rotation(Engine::ROTATION::ROT_X, m_fTransformRotX);
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT10, cVertex);
		float n = _ttof(cVertex);
		m_fTransformRotX = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->Rotation(Engine::ROTATION::ROT_X, m_fTransformRotX);
	}
}


void MeshPage::OnEnChangeTransformRotY()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT12, cVertex);
			float n = _ttof(cVertex);
			m_fTransformRotY = n;
			sphere[indexNum]->m_pTransformCom->Rotation(Engine::ROTATION::ROT_Y, m_fTransformRotY);
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT12, cVertex);
		float n = _ttof(cVertex);
		m_fTransformRotY = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->Rotation(Engine::ROTATION::ROT_Y, m_fTransformRotY);
	}
}


void MeshPage::OnEnChangeTransformRotZ()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT13, cVertex);
			float n = _ttof(cVertex);
			m_fTransformRotZ = n;
			sphere[indexNum]->m_pTransformCom->Rotation(Engine::ROTATION::ROT_Z, m_fTransformRotZ);
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT13, cVertex);
		float n = _ttof(cVertex);
		m_fTransformRotZ = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->Rotation(Engine::ROTATION::ROT_Y, m_fTransformRotZ);
	}
}


void MeshPage::OnEnChangeTransformPosX()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT14, cVertex);
			float n = _ttof(cVertex);
			m_fTransformPosX = n;
			sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].x = m_fTransformPosX;
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT14, cVertex);
		float n = _ttof(cVertex);
		m_fTransformPosX = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].x = m_fTransformPosX;
	}
}


void MeshPage::OnEnChangeTransformPosY()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT15, cVertex);
			float n = _ttof(cVertex);
			m_fTransformPosY = n;
			sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].y = m_fTransformPosY;
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT15, cVertex);
		float n = _ttof(cVertex);
		m_fTransformPosY = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].y = m_fTransformPosY;
	}
}


void MeshPage::OnEnChangeTransformPosZ()
{

	if (VertexManager::GetInstance()->isNaviMesh == true)
	{
		if (treeNavi.GetParentItem(selectItem) != 0)
		{
			//해당 셀에 담긴 Text
			CString naviIndex = treeNavi.GetItemText(selectItem);
			//Text를 int로 바꾸기
			int indexNum;
			indexNum = _ttoi(naviIndex);
			CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));
			int iParentIndex = _ttoi(parentIndex);
			CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);
			CSphereMesh* sphere[3];
			int Temp = 0;
			for (auto& _sphere : tri->list_SphereMesh)
			{
				sphere[Temp] = _sphere;
				Temp++;
			}
			int triIndex;
			triIndex = _ttoi(parentIndex);
			////////////////////
			CString cVertex;
			GetDlgItemText(IDC_EDIT16, cVertex);
			float n = _ttof(cVertex);
			m_fTransformPosZ = n;
			sphere[indexNum]->m_pTransformCom->m_vInfo[Engine::INFO_POS].z = m_fTransformPosZ;
			sphere[indexNum]->Set_InitPoint();

		}
	}
	else if (VertexManager::GetInstance()->isObjectMesh = true)
	{
		CString a = treeObjStatic.GetItemText(selectItem);
		CString objStaticIndexNum = a.Right(1);
		size_t temp = 0;
		temp = _ttoi(objStaticIndexNum);
		CString cVertex;
		GetDlgItemText(IDC_EDIT16, cVertex);
		float n = _ttof(cVertex);
		m_fTransformPosZ = n;
		if (0 == CMFCToolView::GetInstance()->vectorObjStatic.size())
			return;
		dynamic_cast<CMFCStaticMesh*>(CMFCToolView::GetInstance()->vectorObjStatic.at(temp))->GetTransform()->m_vInfo[Engine::INFO_POS].z = m_fTransformPosZ;
	}
}





void MeshPage::LockOnTree()
{
	lockOnCheck = true;
	// TODO: 여기 버텍스 넣어야함

	//HTREEITEM hItem = treeNavi.GetSelectedItem();
	//CStringW a = treeNavi.GetItemText(hItem);

	//int triNum = CMFCToolView::GetInstance()->Get_VectorTri(&triNum).size();


	//i = p.size();
	//삼각형 색 복귀



	//VertexManager::GetInstance()->Set_TriColor(CMFCToolView::GetInstance()->Get_TriOfNumber(triNum)->m_pBufferCom, D3DCOLOR_ARGB(255, 100, 255, 100));

	//원 색 복귀
	//for (int i = 0; i < triNum; ++i)
	//{
	//	VertexManager::GetInstance()->Set_TriColor(CMFCToolView::GetInstance()->Get_TriOfNumber(i)->m_pBufferCom, D3DCOLOR_ARGB(255, 100, 255, 100));
	//	for (int j = 0; j < 3; j++)
	//	{
	//		VertexManager::GetInstance()->Set_SphereColor(CMFCToolView::GetInstance()->Get_TriOfNumber(i)->list_SphereMesh[j]->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
	//	}
	//}


	///////////////////////
	CPoint point;
	UINT nFlags = 0;

	GetCursorPos(&point);
	::ScreenToClient(treeNavi.m_hWnd, &point);

	selectItem = treeNavi.HitTest(point, &nFlags);
	//해당 셀에 담긴 Text
	CString naviIndex = treeNavi.GetItemText(selectItem);

	//Text를 int로 바꾸기
	int indexNum;
	indexNum = _ttoi(naviIndex);




	if (VertexManager::GetInstance()->lockOnObjName == VertexManager::VM_Obj::TRI)//treeNavi.GetParentItem(selectItem) == 0)
	{
		//삼각형 셀이 선택
		//VertexManager::GetInstance()->vertex[indexNum];

		CTerrainTri* tri = dynamic_cast<CTerrainTri*>(VertexManager::GetInstance()->lockOnObj);//CMFCToolView::GetInstance()->Get_TriOfNumber(indexNum);
		//VertexManager::GetInstance()->Set_TriColor(tri->m_pBufferCom, D3DCOLOR_ARGB(255, 255, 0, 0));


	}
	else if (VertexManager::GetInstance()->lockOnObjName == VertexManager::VM_Obj::SPHERE)
	{

		//CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(selectItem));

		//int iParentIndex = _ttoi(parentIndex);
		//VertexManager::GetInstance()->Set_TriColor(CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex)->m_pBufferCom, D3DCOLOR_ARGB(255, 255, 0, 0));


		//CTerrainTri* tri = CMFCToolView::GetInstance()->Get_TriOfNumber(iParentIndex);

		//CSphereMesh* sphere[3];
		//int Temp = 0;
		//for (auto& _sphere : tri->list_SphereMesh)
		//{
		//	sphere[Temp] = _sphere;
		//	Temp++;
		//}


		//lastSphereIndex = indexNum;
		//VertexManager::GetInstance()->Set_SphereColor(sphere[indexNum]->m_pBufferCom, D3DCOLOR_ARGB(255, 200, 0, 0));

		//int triIndex;
		//triIndex = _ttoi(parentIndex);

		CSphereMesh* sphere = dynamic_cast<CSphereMesh*>(VertexManager::GetInstance()->lockOnObj);

		m_fTransformPosX = sphere->m_pTransformCom->m_vInfo[Engine::INFO_POS].x;
		m_fTransformPosY = sphere->m_pTransformCom->m_vInfo[Engine::INFO_POS].y;
		m_fTransformPosZ = sphere->m_pTransformCom->m_vInfo[Engine::INFO_POS].z;

		m_fTransformScalX = sphere->m_pTransformCom->m_vScale.x;
		m_fTransformScalY = sphere->m_pTransformCom->m_vScale.y;
		m_fTransformScalZ = sphere->m_pTransformCom->m_vScale.z;



		//float m_fTransformPosX = VertexManager::GetInstance()->vertex[triIndex][indexNum].x;
		//float m_fTransformPosY = VertexManager::GetInstance()->vertex[triIndex][indexNum].y;
		//float m_fTransformPosZ = VertexManager::GetInstance()->vertex[triIndex][indexNum].z;

		CString cVertexX, cVertexY, cVertexZ;

		cVertexX.Format(_T("%9.1f\n"), m_fTransformPosX);
		cVertexY.Format(_T("%9.1f\n"), m_fTransformPosY);
		cVertexZ.Format(_T("%9.1f\n"), m_fTransformPosZ);

		SetDlgItemText(IDC_EDIT14, cVertexX);
		SetDlgItemText(IDC_EDIT15, cVertexY);
		SetDlgItemText(IDC_EDIT16, cVertexZ);

		cVertexX.Format(_T("%9.1f\n"), m_fTransformScalX);
		cVertexY.Format(_T("%9.1f\n"), m_fTransformScalY);
		cVertexZ.Format(_T("%9.1f\n"), m_fTransformScalZ);

		SetDlgItemText(IDC_EDIT5, cVertexX);
		SetDlgItemText(IDC_EDIT7, cVertexY);
		SetDlgItemText(IDC_EDIT8, cVertexZ);


	}






	if (selectItem != NULL && (nFlags & TVHT_ONITEMSTATEICON) != 0)
	{
		if (treeNavi.GetCheck(selectItem))
		{
			UnCheckChildItems(selectItem);
		}
		else
		{
			CheckChildItems(selectItem);
		}
	}


	wchar_t text[16];


	TVITEMW item;
	item.mask = TVIF_TEXT;
	item.hItem = selectItem;
	item.pszText = text;
	item.cchTextMax = 16;
	treeNavi.GetItem(&item);

	OutputDebugString(text);

	//*pResult = 0;
}