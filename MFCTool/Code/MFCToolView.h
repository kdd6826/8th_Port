
// MFCToolView.h : CMFCToolView Ŭ������ �������̽�
//

#pragma once

#include "Define.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"
BEGIN(Engine)
class CGraphicDev;
class CManagement;
END

class CMFCToolDoc;
class CSingleTex; 
class CTerrain; 


class CMFCToolView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMFCToolView();
	DECLARE_DYNCREATE(CMFCToolView)
public:
	CTerrain* m_pTerrain = nullptr; 
	float m_fAngle = 0.f; 
// Ư���Դϴ�.
public:
	CMFCToolDoc* GetDocument() const;

// �۾��Դϴ�.
private:
	HRESULT		SetUp_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev);
	HRESULT		Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev, Engine::CManagement** ppManagement);

private:
	Engine::CGraphicDev*		m_pDeviceClass = nullptr;
	Engine::CManagement*		m_pManagementClass = nullptr;
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;
// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFCToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCToolView.cpp�� ����� ����
inline CMFCToolDoc* CMFCToolView::GetDocument() const
   { return reinterpret_cast<CMFCToolDoc*>(m_pDocument); }
#endif
