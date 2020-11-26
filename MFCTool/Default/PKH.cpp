// PKH.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "PKH.h"
#include "afxdialogex.h"


// PKH 대화 상자입니다.

IMPLEMENT_DYNAMIC(PKH, CDialogEx)

PKH::PKH(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

PKH::~PKH()
{
}

void PKH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PKH, CDialogEx)
END_MESSAGE_MAP()


// PKH 메시지 처리기입니다.
