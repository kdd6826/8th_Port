// TerrainPage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "TerrainPage.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(TerrainPage, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &TerrainPage::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &TerrainPage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &TerrainPage::OnBnClickedRadio2)
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
}


void TerrainPage::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL TerrainPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Render_Solid.SetCheck(BST_CHECKED);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
