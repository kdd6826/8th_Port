#pragma once



// CSheets

class CSheets : public CPropertySheet
{
	DECLARE_DYNAMIC(CSheets)

public:
	CSheets();
	CSheets(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSheets(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CSheets();

protected:
	DECLARE_MESSAGE_MAP()
};


