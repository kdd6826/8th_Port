// Form.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "Form.h"

#include"TerrainPage.h"
#include "MeshPage.h"
#include "PKH.h"
#include "MFCToolView.h"
#include "VertexManager.h"
USING(Client)
// CForm

IMPLEMENT_DYNCREATE(CForm, CFormView)

CForm::CForm()
	: CFormView(IDD_FORM)
{

}

CForm::~CForm()
{
}

void CForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON6, &CForm::OnBnClickedMapTool)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CForm::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CForm 진단입니다.

#ifdef _DEBUG
void CForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CForm 메시지 처리기입니다.


void CForm::OnBnClickedMapTool()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (nullptr == m_tMapTool.GetSafeHwnd())
		m_tMapTool.Create(IDD_MAPTOOL); 
	m_tMapTool.ShowWindow(SW_SHOW);
}


void CForm::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_Tab.GetCurSel();

	switch (sel)
	{
	case 0:
		tab1->ShowWindow(SW_SHOW);
		tab2->ShowWindow(SW_HIDE);
		tab3->ShowWindow(SW_HIDE);
		VertexManager::GetInstance()->isNaviMesh = false;
		VertexManager::GetInstance()->isObjectMesh = false;
			break;
	case 1:
		tab1->ShowWindow(SW_HIDE);
		tab2->ShowWindow(SW_SHOW);
		tab3->ShowWindow(SW_HIDE);
		if(!isInitMeshPage)
		{
			//CMFCToolView::GetInstance()->Mesh_Load();
		}
		isInitMeshPage = true;

			break;
	case 2:
		tab1->ShowWindow(SW_HIDE);
		tab2->ShowWindow(SW_HIDE);
		tab3->ShowWindow(SW_SHOW);
		VertexManager::GetInstance()->isNaviMesh = false;
		VertexManager::GetInstance()->isObjectMesh = false;
			break;
	default:
		break;
	}

	*pResult = 0;
}


void CForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_Tab.InsertItem(0, L"Terrain");
	m_Tab.InsertItem(1, L"Mesh");
	m_Tab.InsertItem(2, L"Temp");

	m_Tab.SetCurSel(0);
	
	CRect rect;
	m_Tab.GetWindowRect(&rect);

	tab1 = new TerrainPage;
	tab1->Create(IDD_DIALOG1, &m_Tab);
	tab1->MoveWindow(0, 25, rect.Width(), rect.Height());
	tab1->ShowWindow(SW_SHOW);

	tab2 = new MeshPage;
	tab2->Create(IDD_DIALOG2, &m_Tab);
	tab2->MoveWindow(0, 25, rect.Width(), rect.Height());
	tab2->ShowWindow(SW_HIDE);

	tab3 = new PKH;
	tab3->Create(IDD_DIALOG3, &m_Tab);
	tab3->MoveWindow(0, 25, rect.Width(), rect.Height());
	tab3->ShowWindow(SW_HIDE);

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
