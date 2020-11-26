
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
class CGameObject;
END

class CMFCToolDoc;
class CSingleTex;
class CMFC_Terrain;
class CDynamicCamera;
class CMFCToolView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMFCToolView();
	DECLARE_DYNCREATE(CMFCToolView)
public:
	CMFC_Terrain* m_pTerrain = nullptr;
	float m_fAngle = 0.f;
	// Ư���Դϴ�.
public:
	CMFCToolDoc* GetDocument() const;

	static CMFCToolView*	GetInstance(void) {
			if (nullptr == m_pInstance) {
					m_pInstance = new CMFCToolView;
			}
			return m_pInstance;
	}
	static CMFCToolView* m_pInstance;
	// �۾��Դϴ�.
private:
	HRESULT		SetUp_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev);
	HRESULT		Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev, Engine::CManagement** ppManagement);
	HRESULT Ready_Environment_Layer(const _tchar * pLayerTag);


public:
	Engine::CGraphicDev* m_pDeviceClass = nullptr;
	Engine::CManagement* m_pManagementClass = nullptr;
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

	CDynamicCamera* m_Camera = nullptr;
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
	void Update(float deltaTime);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	Engine::CComponent * Get_Component(const _tchar * pLayerTag, const _tchar * pObjTag, const _tchar * pComponentTag, Engine::COMPONENTID eID);
	void LayerAddObject(const _tchar* pLayerTag, const _tchar* pObjTag, Engine::CGameObject* pGameObject);
	void Key_Input(float deltaTime);
	_vec3 PickUp_OnTerrain(void);


private:
	HRESULT Loading();
	void RenderLine();

public:
	float moveSpeed = 15.f;
	Engine::CCalculator*		m_pCalculatorCom = nullptr;
	map<const _tchar*, Engine::CLayer*>			m_mapLayer;
	map<const _tchar*, Engine::CComponent*>			m_mapComponent[Engine::ID_END];

};

#ifndef _DEBUG  // MFCToolView.cpp�� ����� ����
inline CMFCToolDoc* CMFCToolView::GetDocument() const
{
	return reinterpret_cast<CMFCToolDoc*>(m_pDocument);
}
#endif
