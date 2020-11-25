
// MFCToolView.h : CMFCToolView 클래스의 인터페이스
//

#pragma once

#include "Define.h"
#include "Scene.h"
#include "Base.h"
#include "Engine_Define.h"
#include "Export_Function.h"
BEGIN(Engine)
class CGraphicDev;
class CManagement;
class CGameObject;
class CScene;
END

class CMFCToolDoc;
class CSingleTex;
class CMFC_Terrain;
class CDynamicCamera;
class CMFCToolView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CMFCToolView();
	DECLARE_DYNCREATE(CMFCToolView)
public:
	CMFC_Terrain* m_pTerrain = nullptr;
	float m_fAngle = 0.f;
	// 특성입니다.
public:
	CMFCToolDoc* GetDocument() const;

	static CMFCToolView*	GetInstance(void) {
			if (nullptr == m_pInstance) {
					m_pInstance = new CMFCToolView;
			}
			return m_pInstance;
	}
	static CMFCToolView* m_pInstance;
	// 작업입니다.
private:
	HRESULT		SetUp_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev);
	HRESULT		Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev, Engine::CManagement** ppManagement);

private:
	Engine::CGraphicDev* m_pDeviceClass = nullptr;
	Engine::CManagement* m_pManagementClass = nullptr;
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

	CDynamicCamera* m_Camera = nullptr;
	_vec3 m_CameraAtDir = { 0.f, 0.f, 1.f };
	bool m_bCameraAddX = false;
	bool m_bCameraAddZ = false;
	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	
	// 구현입니다.
public:
	virtual ~CMFCToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	HRESULT Loading();
	void RenderLine();
	void CameraMove(float deltaTime);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void Update(float deltaTime);


	HRESULT		Ready_Environment_Layer(const _tchar* pLayerTag);
	
	map<const _tchar*, Engine::CLayer*>			m_mapLayer;//삭제해야함
	list<Engine::CGameObject*> list_Object;
	float moveSpeed = 15.f;
};

#ifndef _DEBUG  // MFCToolView.cpp의 디버그 버전
inline CMFCToolDoc* CMFCToolView::GetDocument() const
{
	return reinterpret_cast<CMFCToolDoc*>(m_pDocument);
}
#endif
