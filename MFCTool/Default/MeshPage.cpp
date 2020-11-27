// MeshPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "MeshPage.h"
#include "afxdialogex.h"


// MeshPage 대화 상자입니다.

IMPLEMENT_DYNAMIC(MeshPage, CDialogEx)

MeshPage::MeshPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

MeshPage::~MeshPage()
{
}

void MeshPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MeshPage, CDialogEx)
END_MESSAGE_MAP()


// MeshPage 메시지 처리기입니다.