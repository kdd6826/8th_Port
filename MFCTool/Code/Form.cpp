// Form.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "Form.h"

#include"TerrainPage.h"
#include "MeshPage.h"
#include "ColliderPage.h"
#include "MFCToolView.h"
#include "VertexManager.h"
#include "DynamicCamera.h"
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


// CForm �����Դϴ�.

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


// CForm �޽��� ó�����Դϴ�.


void CForm::OnBnClickedMapTool()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (nullptr == m_tMapTool.GetSafeHwnd())
		m_tMapTool.Create(IDD_MAPTOOL); 
	m_tMapTool.ShowWindow(SW_SHOW);
}


void CForm::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int sel = m_Tab.GetCurSel();

	switch (sel)
	{
	case 0:
		tab1->ShowWindow(SW_SHOW);
		tab2->ShowWindow(SW_HIDE);
		tab3->ShowWindow(SW_HIDE);
		VertexManager::GetInstance()->isNaviMesh = false;
		VertexManager::GetInstance()->isObjectMesh = false;
		

		if (CMFCToolView::GetInstance()->colliderView == false)
		{
			meshPageCamPos = CMFCToolView::GetInstance()->m_Camera->m_vEye;
			meshPageCamAt = CMFCToolView::GetInstance()->m_Camera->m_vAt;
		}

		CMFCToolView::GetInstance()->colliderView = false;
		CMFCToolView::GetInstance()->m_Camera->m_vEye = meshPageCamPos;
		CMFCToolView::GetInstance()->m_Camera->m_vAt = meshPageCamAt;
		break;
	case 1:
		tab1->ShowWindow(SW_HIDE);
		tab2->ShowWindow(SW_SHOW);
		tab3->ShowWindow(SW_HIDE);
		if (!isInitMeshPage)
		{
			//CMFCToolView::GetInstance()->Mesh_Load();
			VertexManager::GetInstance()->isObjectMesh = true;
		}
		CMFCToolView::GetInstance()->colliderView = false;
		isInitMeshPage = true;
		CMFCToolView::GetInstance()->m_Camera->m_vEye = meshPageCamPos;
		CMFCToolView::GetInstance()->m_Camera->m_vAt = meshPageCamAt;
		
			break;
	case 2:
		tab1->ShowWindow(SW_HIDE);
		tab2->ShowWindow(SW_HIDE);
		tab3->ShowWindow(SW_SHOW);
		CMFCToolView::GetInstance()->colliderView = true;
		VertexManager::GetInstance()->isNaviMesh = false;
		VertexManager::GetInstance()->isObjectMesh = false;
		
		meshPageCamPos = CMFCToolView::GetInstance()->m_Camera->m_vEye;
		meshPageCamAt = CMFCToolView::GetInstance()->m_Camera->m_vAt;
		CMFCToolView::GetInstance()->m_Camera->m_vEye = _vec3{ -98.f,-98.5f,-98.f };
		CMFCToolView::GetInstance()->m_Camera->m_vAt = _vec3{ -100.f,-98.5f,-100.f };
			break;
	default:
		break;
	}

	*pResult = 0;
}


void CForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	meshPageCamPos = CMFCToolView::GetInstance()->m_Camera->m_vEye;
	meshPageCamAt = CMFCToolView::GetInstance()->m_Camera->m_vAt;

	m_Tab.InsertItem(0, L"Terrain");
	m_Tab.InsertItem(1, L"Mesh");
	m_Tab.InsertItem(2, L"Collider");

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

	tab3 = new ColliderPage;
	tab3->Create(IDD_DIALOG3, &m_Tab);
	tab3->MoveWindow(0, 25, rect.Width(), rect.Height());
	tab3->ShowWindow(SW_HIDE);

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}
