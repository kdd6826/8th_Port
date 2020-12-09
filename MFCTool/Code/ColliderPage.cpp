// ColliderPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "ColliderPage.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(ColliderPage, CDialogEx)
END_MESSAGE_MAP()


// ColliderPage 메시지 처리기입니다.
