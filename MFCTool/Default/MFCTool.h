#ifndef MFCTool_h__
#define MFCTool_h__

// MFCTool.h : MFCTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.
#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"

// CMFCToolApp:
// �� Ŭ������ ������ ���ؼ��� MFCTool.cpp�� �����Ͻʽÿ�.
//

class CMFCToolApp : public CWinAppEx
{
public:
	CMFCToolApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int Run();
};

extern CMFCToolApp theApp;

#endif // MFCTool_h__