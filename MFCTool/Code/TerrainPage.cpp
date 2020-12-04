// TerrainPage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "TerrainPage.h"
#include "afxdialogex.h"
#include "MFCToolView.h"
#include "VertexManager.h"
#include "SphereMesh.h"

// TerrainPage ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TerrainPage, CDialogEx)

TerrainPage::TerrainPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

TerrainPage::~TerrainPage()
{
}

void TerrainPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, Render_Solid);
	//  DDX_Control(pDX, IDC_BUTTON1, Render_WireFrame);
	DDX_Control(pDX, IDC_RADIO1, Render_Solid);
	DDX_Control(pDX, IDC_RADIO2, Render_WireFrame);
	DDX_Control(pDX, IDC_EDIT1, xCount);
	DDX_Control(pDX, IDC_EDIT2, zCount);
	DDX_Control(pDX, IDC_EDIT3, interval);
	DDX_Control(pDX, IDC_EDIT4, detail);
}


BEGIN_MESSAGE_MAP(TerrainPage, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &TerrainPage::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &TerrainPage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &TerrainPage::OnBnClickedRadio2)
	
	ON_BN_CLICKED(IDC_BUTTON1, &TerrainPage::OnBnClickedTerrainApply)
	ON_BN_CLICKED(IDC_RADIO1, &TerrainPage::OnBnClickedRadio1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &TerrainPage::OnXCountSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &TerrainPage::OnZCountSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, &TerrainPage::OnDeltaposSpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, &TerrainPage::OnDeltaposSpin5)
	ON_BN_CLICKED(IDC_BUTTON8, &TerrainPage::OnBnClickedLoad)
END_MESSAGE_MAP()


// TerrainPage �޽��� ó�����Դϴ�.


void TerrainPage::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TerrainPage::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TerrainPage::OnBnClickedRadio1()
{
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMFCToolView::GetInstance()->wireFrame = false;
}


void TerrainPage::OnBnClickedRadio2()
{
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMFCToolView::GetInstance()->wireFrame = true;
}


BOOL TerrainPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Render_Solid.SetCheck(BST_CHECKED);
	
	xCount.SetWindowTextW(L"2");
	zCount.SetWindowTextW(L"2");
	interval.SetWindowTextW(L"�̱���");
	detail.SetWindowTextW(L"�̱���");
	CMFCToolView::GetInstance()->wireFrame = true;
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void TerrainPage::OnBnClickedTerrainApply()
{

	///////////////////
	map<const _tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;
	auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Environment"));
	if (iter == (*m_map).end())
		return;

	for (auto& obj : iter->second->m_mapObject)
	{
		obj.second->Release();
	}
	VertexManager::GetInstance()->DestroyValue();
	iter->second->m_mapObject.clear();
	///////////////////

	

	//
	CString xNum = L"";
	CString zNum = L"";
	CString intervalNum = L"";
	CString detailNum = L"";

	xCount.GetWindowTextW(xNum);
	zCount.GetWindowTextW(zNum);
	interval.GetWindowTextW(intervalNum);
	detail.GetWindowTextW(detailNum);

	
	iXCount = _ttoi(xNum);
	iZCount = _ttoi(zNum);
	iInterval = _ttoi(intervalNum);
	iDetail = _ttoi(detailNum);


	CMFCToolView::GetInstance()->CreateTerrain(iXCount, iZCount, iInterval, iDetail);

	

}



void TerrainPage::OnXCountSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		iXCount++;
		cVertex.Format(_T("%d"), iXCount);
	}
	else
	{
		iXCount--;
		cVertex.Format(_T("%d"), iXCount);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT1, cVertex);
}


void TerrainPage::OnZCountSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		iZCount++;
		cVertex.Format(_T("%d"), iZCount);
	}
	else
	{
		iZCount--;
		cVertex.Format(_T("%d"), iZCount);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT2, cVertex);
}


void TerrainPage::OnDeltaposSpin4(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		iInterval++;
		cVertex.Format(_T("%d"), iInterval);
	}
	else
	{
		iInterval--;
		cVertex.Format(_T("%d"), iInterval);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT3, cVertex);
}


void TerrainPage::OnDeltaposSpin5(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		iDetail++;
		cVertex.Format(_T("%d"), iDetail);
	}
	else
	{
		iDetail--;
		cVertex.Format(_T("%d"), iDetail);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT4, cVertex);
}


void TerrainPage::OnBnClickedLoad()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
