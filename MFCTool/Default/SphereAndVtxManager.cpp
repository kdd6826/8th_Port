#include "stdafx.h"
#include "SphereAndVtxManager.h"
#include "SphereMesh.h"
#include "MFCToolView.h"

IMPLEMENT_SINGLETON(CSphereAndVtxManager)

CSphereAndVtxManager::CSphereAndVtxManager()
{
	m_pGraphicDev = CMFCToolView::GetInstance()->m_pGraphicDev;
}


CSphereAndVtxManager::~CSphereAndVtxManager()
{
	for (auto& sphere : list_TotalSphere)
	{
		sphere->Release();
	}
	list_TotalSphere.clear();
}

void CSphereAndVtxManager::Key_Input(float deltaTime)
{
	if (Engine::Get_DIMouseState(Engine::DIM_LB) & 0x80)
	{
		if (!mouseLClick) {
			_vec3	vPickPos = CMFCToolView::GetInstance()->PickUp_OnTerrain();
			if (_vec3(0.f, 0.f, 0.f) != vPickPos) {
				Engine::CGameObject* pGameObject = CSphereMesh::Create(m_pGraphicDev);
				dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS] = vPickPos;
				CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"Sphere", pGameObject);
				dynamic_cast<CSphereMesh*>(pGameObject)->Set_VtxPos();

				list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
				//pGameObject->AddRef();
			}
			mouseLClick = true;
		}
		//m_pTransformCom->Pick_Pos(&vPickPos, m_fSpeed, fTimeDelta);
	}
	else {
		mouseLClick = false;
	}

	if (Engine::Get_DIMouseState(Engine::DIM_RB) & 0x80)
	{

	}

	if (Engine::Get_DIKeyState(DIK_LCONTROL) & 0x80 && Engine::Get_DIKeyState(DIK_Z) & 0x80)
	{
		
	}
}
