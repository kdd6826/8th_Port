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
BEGIN(Engine)

class CGraphicDev;
class CManagement;

END
BEGIN(Client)
class CMFCToolApp : public CWinAppEx
{
public:
	CMFCToolApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

private:
	Engine::CGraphicDev*		m_pDeviceClass = nullptr;
	Engine::CManagement*		m_pManagementClass = nullptr;
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCToolApp theApp;
END

#endif // MFCTool_h__