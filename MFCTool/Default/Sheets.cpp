// Sheets.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "Sheets.h"


// CSheets

IMPLEMENT_DYNAMIC(CSheets, CPropertySheet)

CSheets::CSheets()
{
}

CSheets::CSheets(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CSheets::CSheets(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CSheets::~CSheets()
{
}


BEGIN_MESSAGE_MAP(CSheets, CPropertySheet)
END_MESSAGE_MAP()


// CSheets �޽��� ó�����Դϴ�.
