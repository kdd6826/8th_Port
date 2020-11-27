#include "stdafx.h"
#pragma comment(lib, "Resources.lib")
#include "VertexManager.h"
#include "SphereMesh.h"
#include "MFCToolView.h"

#include "Sphere.h"
USING(Engine)

IMPLEMENT_SINGLETON(VertexManager)

VertexManager::VertexManager()
{
	m_pGraphicDev = CMFCToolView::GetInstance()->m_pGraphicDev;
}


VertexManager::~VertexManager()
{
	for (auto& sphere : list_TotalSphere)
	{
		sphere->Release();
	}
	list_TotalSphere.clear();
}

void VertexManager::Key_Input(float deltaTime)
{
	if (!TerrainHaveCheck())
		return;

	if (Engine::Get_DIMouseState(Engine::DIM_LB) & 0x80)
	{
		if (!mouseLClick) {
			Engine::_vec3	vPickPos = CMFCToolView::GetInstance()->PickUp_OnTerrain();
			if (Engine::_vec3(0.f, 0.f, 0.f) != vPickPos) {
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
		Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(CMFCToolView::GetInstance()->Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
		NULL_CHECK_RETURN(pTerrainTransformCom);
		CSphereMesh* sphere = Picking_Sphere(g_hWnd, pTerrainTransformCom);
		if (sphere != nullptr) {
			Set_VtxColor(sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 5, 0, 153));
			//sphere->m_pBufferCom->Set_Color(D3DCOLOR_ARGB(255, 0, 0, 255));
			//sphere->m_pTransformCom->m_vInfo[Engine::INFO_POS] = { 0.f, 0.f, 0.f };
		}
	}

	if (Engine::Get_DIKeyState(DIK_LCONTROL) & 0x80 && Engine::Get_DIKeyState(DIK_Z) & 0x80)
	{
		
	}

}

CSphereMesh* VertexManager::Picking_Sphere(HWND hWnd, Engine::CTransform* pTerrainTransformCom)
{
	POINT		ptMouse{ 0 };

	GetCursorPos(&ptMouse);
	::ScreenToClient(hWnd, &ptMouse);

	Engine::_vec3	vMousePos;

	D3DVIEWPORT9		ViewPort;
	ZeroMemory(&ViewPort, sizeof(D3DVIEWPORT9));
	m_pGraphicDev->GetViewport(&ViewPort);
	// ����Ʈ -> ����

	vMousePos.x = (ptMouse.x / (ViewPort.Width * 0.5f)) - 1.f;
	vMousePos.y = (ptMouse.y / -(ViewPort.Height * 0.5f)) + 1.f;
	vMousePos.z = 0.f;

	// L * W * V * P * (P^-1)
	// L * W * V

	// ���� -> �� �����̽�
	Engine::_matrix	matProj;
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
	D3DXMatrixInverse(&matProj, NULL, &matProj);
	D3DXVec3TransformCoord(&vMousePos, &vMousePos, &matProj);

	// �� �����̽� -> ����
	Engine::_matrix	matView;
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	D3DXMatrixInverse(&matView, NULL, &matView);

	Engine::_vec3	vRayPos, vRayDir;


	vRayPos = Engine::_vec3(0.f, 0.f, 0.f);
	vRayDir = vMousePos - vRayPos;

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matView);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matView);

	// ���� -> ����
	Engine::_matrix	matWorld;
	pTerrainTransformCom->Get_WorldMatrix(&matWorld);
	D3DXMatrixInverse(&matWorld, NULL, &matWorld);

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matWorld);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matWorld);

	Engine::_matrix tmlnv;
	Engine::_vec3 vSpherePos, vMinus;
	float A, B, C, D;
	for (auto& sphere : list_TotalSphere)
	{
		vSpherePos = sphere->m_pTransformCom->m_vInfo[Engine::INFO_POS];
		vMinus = vRayPos - vSpherePos;

		A = D3DXVec3Dot(&vRayDir, &vRayDir);
		B = D3DXVec3Dot(&vRayDir, &vMinus);
		C = D3DXVec3Dot(&vMinus, &vMinus) - 0.6f * 0.6f;

		D = B * B - A * C;

		if (D < 0)
			continue;

		float t0, t1;

		t0 = -(B + sqrt(D)) / A;
		t1 = -(B - sqrt(D)) / A;
		if (t0 < 0 && t1 < 0) continue;
		return sphere;
	}

	return nullptr;
}

void VertexManager::Set_VtxColor(Engine::CSphere* Vtx, D3DCOLOR color)
{
	
	void* pVertex = nullptr;
	Vtx->pMesh->LockVertexBuffer(0, &pVertex);
	// ���� ���� ��ġ ã�� (�ʷϻ����� �ٲٷ���)
	D3DVERTEXELEMENT9 decl[MAX_FVF_DECL_SIZE];
	ZeroMemory(decl, sizeof(D3DVERTEXELEMENT9) * MAX_FVF_DECL_SIZE);

	Vtx->pMesh->GetDeclaration(decl);

	BYTE offset = 0;
	for (int i = 0; i < MAX_FVF_DECL_SIZE; i++)
	{
		if (decl[i].Usage == D3DDECLUSAGE_COLOR)
		{
			offset = (BYTE)decl[i].Offset;
			break;
		}
	}
	int vertexCount = Vtx->pMesh->GetNumVertices();
	int vertexSize = D3DXGetFVFVertexSize(Vtx->m_dwFVF);
	for (int i = 0; i < vertexCount; ++i)
	{
		DWORD* pColor = ((DWORD*)(((BYTE*)pVertex) + (i * vertexSize + offset)));
		*pColor = color;
	}

	Vtx->pMesh->UnlockVertexBuffer();

	return;
}

bool VertexManager::TerrainHaveCheck() {
	map<const Engine::_tchar*, Engine::CLayer*>* m_map = &CMFCToolView::GetInstance()->m_mapLayer;
	auto& iter = find_if((*m_map).begin(), (*m_map).end(), Engine::CTag_Finder(L"Environment"));
	if (iter == (*m_map).end())
		return false;
	multimap<const Engine::_tchar*, Engine::CGameObject*>* m_mapObject = &dynamic_cast<Engine::CLayer*>(iter->second)->m_mapObject;
	auto& iter2 = find_if((*m_mapObject).begin(), (*m_mapObject).end(), Engine::CTag_Finder(L"Terrain"));
	if (iter2 == (*m_mapObject).end())
		return false;

	return true;
}