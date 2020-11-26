// NaviPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "NaviPage.h"
#include "afxdialogex.h"


// NaviPage 대화 상자입니다.

IMPLEMENT_DYNAMIC(NaviPage, CDialogEx)

NaviPage::NaviPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

NaviPage::~NaviPage()
{
}

void NaviPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NaviPage, CDialogEx)
END_MESSAGE_MAP()


// NaviPage 메시지 처리기입니다.
