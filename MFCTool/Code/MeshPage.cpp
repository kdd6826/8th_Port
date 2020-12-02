// MeshPage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "MeshPage.h"
#include "afxdialogex.h"
#include "MFCToolView.h"
#include "VertexManager.h"
// MeshPage ��ȭ �����Դϴ�.

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
	DDX_Control(pDX, IDC_RADIO9, vertexTogetther);
	DDX_Control(pDX, IDC_RADIO10, vertexOnly);
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
}


BEGIN_MESSAGE_MAP(MeshPage, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &MeshPage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &MeshPage::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON10, &MeshPage::OnBnClickedButton10)
	ON_NOTIFY(NM_CLICK, IDC_TREE4, &MeshPage::OnNMClickTree4)
	ON_EN_CHANGE(IDC_EDIT14, &MeshPage::OnEnChangeEdit14)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN12, &MeshPage::OnDeltaposSpin12)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN14, &MeshPage::OnDeltaposSpin14)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN13, &MeshPage::OnDeltaposSpin13)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN9, &MeshPage::OnDeltaposSpin9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN11, &MeshPage::OnDeltaposSpin11)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN10, &MeshPage::OnDeltaposSpin10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, &MeshPage::OnDeltaposSpin6)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN8, &MeshPage::OnDeltaposSpin8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN7, &MeshPage::OnDeltaposSpin7)
END_MESSAGE_MAP()


// MeshPage �޽��� ó�����Դϴ�.

BOOL MeshPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Render_Solid.SetCheck(BST_CHECKED);
	CMFCToolView::GetInstance()->wireFrame = false;
	//Pos X,Y,Z
	CString cPosVertexX, cPosVertexY, cPosVertexZ;
	cPosVertexX.Format(_T("%9.1f\n"), m_fTransformPosX);
	cPosVertexY.Format(_T("%9.1f\n"), m_fTransformPosY);
	cPosVertexZ.Format(_T("%9.1f\n"), m_fTransformPosZ);
	SetDlgItemText(IDC_EDIT14, cPosVertexX);
	SetDlgItemText(IDC_EDIT15, cPosVertexY);
	SetDlgItemText(IDC_EDIT16, cPosVertexZ);
	//
	//Scale X,Y,Z
	CString cScalVertexX, cScalVertexY, cScalVertexZ;
	cScalVertexX.Format(_T("%9.1f\n"), m_fTransformScalX);
	cScalVertexY.Format(_T("%9.1f\n"), m_fTransformScalY);
	cScalVertexZ.Format(_T("%9.1f\n"), m_fTransformScalZ);
	SetDlgItemText(IDC_EDIT5, cScalVertexX);
	SetDlgItemText(IDC_EDIT7, cScalVertexY);
	SetDlgItemText(IDC_EDIT8, cScalVertexZ);
	//
	//Rotation X,Y,Z
	CString cRotVertexX, cRotVertexY, cRotVertexZ;
	cRotVertexX.Format(_T("%9.1f\n"), m_fTransformRotX);
	cRotVertexY.Format(_T("%9.1f\n"), m_fTransformRotY);
	cRotVertexZ.Format(_T("%9.1f\n"), m_fTransformRotZ);
	SetDlgItemText(IDC_EDIT10, cRotVertexX);
	SetDlgItemText(IDC_EDIT12, cRotVertexY);
	SetDlgItemText(IDC_EDIT13, cRotVertexZ);
	//

	mouseObject.SetCheck(BST_CHECKED);
	typeStatic.SetCheck(BST_CHECKED);
	vertexTogetther.SetCheck(BST_CHECKED);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void MeshPage::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMFCToolView::GetInstance()->wireFrame = false;
}


void MeshPage::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMFCToolView::GetInstance()->wireFrame = true;
}

void MeshPage::treeControl(int triCount)
{
	WCHAR wstr[16] = {};

	wsprintf(wstr, L"%d", triCount);

	tri[triCount] =treeNavi.InsertItem(wstr, 0, 0, TVI_ROOT, TVI_LAST);
	vertex[triCount][0] = treeNavi.InsertItem(L"0", 0, 0, tri[triCount], TVI_LAST);
	vertex[triCount][1] = treeNavi.InsertItem(L"1", 0, 0, tri[triCount], TVI_LAST);
	vertex[triCount][2] = treeNavi.InsertItem(L"2", 0, 0, tri[triCount], TVI_LAST);

	
}



void MeshPage::OnBnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	for (int i = 0; i < 128; i++)
	{
		treeNavi.DeleteItem(tri[i]);
	}
}



void MeshPage::OnNMClickTree4(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���� ���ؽ� �־����

	
	//HTREEITEM hItem = treeNavi.GetSelectedItem();
	//CStringW a =	treeNavi.GetItemText(hItem);
	
	CPoint point; 
	UINT nFlags = 0;

	GetCursorPos(&point);
	::ScreenToClient(treeNavi.m_hWnd, &point);

	HTREEITEM hItem = treeNavi.HitTest(point, &nFlags);
	//�ش� ���� ��� Text
	CString naviIndex = treeNavi.GetItemText(hItem);

	//Text�� int�� �ٲٱ�
	int indexNum;
	indexNum = _ttoi(naviIndex);

	

	if (treeNavi.GetParentItem(hItem) == 0)
	{
		//�ﰢ�� ���� ����
		//VertexManager::GetInstance()->vertex[indexNum];
	}
	else if (treeNavi.GetParentItem(hItem) != 0)
	{
		CString parentIndex = treeNavi.GetItemText(treeNavi.GetParentItem(hItem));
		int triIndex;
		triIndex = _ttoi(parentIndex);

		//CMFCToolView::GetInstance()->Get_TriOfNumber(0)
		
		//float m_fTransformPosX = VertexManager::GetInstance()->vertex[triIndex][indexNum].x;
		//float m_fTransformPosY = VertexManager::GetInstance()->vertex[triIndex][indexNum].y;
		//float m_fTransformPosZ = VertexManager::GetInstance()->vertex[triIndex][indexNum].z;
		
		CString cVertexX, cVertexY, cVertexZ;
		//cVertexX.Format(_T("%f"), m_fTransformPosX);
		//cVertexY.Format(_T("%f"), m_fTransformPosY);
		//cVertexZ.Format(_T("%f"), m_fTransformPosZ);

		SetDlgItemText(IDC_EDIT14, cVertexX);
		SetDlgItemText(IDC_EDIT15, cVertexY);
		SetDlgItemText(IDC_EDIT16, cVertexZ);
	}
	
	
	

	

	if (hItem != NULL && (nFlags & TVHT_ONITEMSTATEICON) != 0)
	{
		if (treeNavi.GetCheck(hItem))
		{
			UnCheckChildItems(hItem);
		}
		else
		{
			CheckChildItems(hItem);
		}
	}


	wchar_t text[16];

	
	TVITEMW item;
	item.mask = TVIF_TEXT;
	item.hItem = hItem;
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


void MeshPage::OnEnChangeEdit14()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CWnd *p = GetDlgItem(IDC_EDIT14);
	//SetDlgItemText(IDC_EDIT14, L"����");


	transformPosX;
	
	//VertexManager::GetInstance()->vertex[0][0].x;
}


void MeshPage::OnDeltaposSpin12(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;
	

	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformPosX+=0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformPosX);
	}
	else
	{
		m_fTransformPosX -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformPosX);
	}
	*pResult = 0;
	

	SetDlgItemText(IDC_EDIT14, cVertex);

}


void MeshPage::OnDeltaposSpin14(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;
	

	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformPosY+=0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformPosY);
	}
	else
	{
		m_fTransformPosY -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformPosY);
	}
	*pResult = 0;


	SetDlgItemText(IDC_EDIT15, cVertex);
}


void MeshPage::OnDeltaposSpin13(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformPosZ += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformPosZ);
	}
	else
	{
		m_fTransformPosZ -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformPosZ);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT16, cVertex);
}


void MeshPage::OnDeltaposSpin9(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformRotX += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformRotX);
	}
	else
	{
		m_fTransformRotX -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformRotX);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT10, cVertex);
}


void MeshPage::OnDeltaposSpin11(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformRotY += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformRotY);
	}
	else
	{
		m_fTransformRotY -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformRotY);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT12, cVertex);
}


void MeshPage::OnDeltaposSpin10(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformRotZ += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformRotZ);
	}
	else
	{
		m_fTransformRotZ -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformRotZ);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT13, cVertex);
}


void MeshPage::OnDeltaposSpin6(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformScalX += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformScalX);
	}
	else
	{
		m_fTransformScalX -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformScalX);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT5, cVertex);
}


void MeshPage::OnDeltaposSpin8(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformScalY += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformScalY);
	}
	else
	{
		m_fTransformScalY -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformScalY);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT7, cVertex);
}


void MeshPage::OnDeltaposSpin7(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cVertex;


	if (pNMUpDown->iDelta < 0)
	{
		m_fTransformScalZ += 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformScalZ);
	}
	else
	{
		m_fTransformScalZ -= 0.1f;
		cVertex.Format(_T("%9.1f\n"), m_fTransformScalZ);
	}
	*pResult = 0;

	SetDlgItemText(IDC_EDIT8, cVertex);
}
