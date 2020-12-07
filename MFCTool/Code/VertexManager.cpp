#include "stdafx.h"
#pragma comment(lib, "Resources.lib")
#include "VertexManager.h"
#include "SphereMesh.h"
#include "MFCToolView.h"
#include "TerrainTri.h"

#include "Sphere.h"
#include "Cell.h"
#include "Export_Function.h"
#include "MeshPage.h"
#include "DynamicCamera.h"
USING(Engine)

IMPLEMENT_SINGLETON(VertexManager)

VertexManager::VertexManager()
{
	m_pGraphicDev = CMFCToolView::GetInstance()->m_pGraphicDev;
}


VertexManager::~VertexManager()
{
	DestroyValue();
}

void VertexManager::DestroyValue()
{
	for (auto& sphere : list_TotalSphere)
	{
		sphere->Release();
	}
	list_TotalSphere.clear();
	list_Sphere.clear();
	lockOnObjName = VM_Obj::NONE;
	lockOnObj = nullptr;
	/////////////////////////
	//triCount = 0;
	//lineCount = 0;
}

void VertexManager::Update(float deltaTime)
{
	Key_Input(deltaTime);
}

void VertexManager::Key_Input(float deltaTime)
{
	if (!TerrainHaveCheck())
		return;

	
	
	if (Engine::Get_DIMouseState(Engine::DIM_LB) & 0x80)
	{
		if (!mouseLClick) {
			if(isNaviMesh)
				MouseLClick_NaviMesh();
			else if(isObjectMesh)
				MouseLClick_ObjectMesh();
			mouseLClick = true;
		}
	}
	else {
		mouseLClick = false;
	}

	if (Engine::Get_DIMouseState(Engine::DIM_RB) & 0x80)
	{
		
		if (!mouseRClick) {
			if (isNaviMesh)
				MouseRClick_NaviMesh();
			
			mouseRClick = true;
		}
	}
	else {
		mouseRClick = false;
	}

	if (Engine::Get_DIKeyState(DIK_C) & 0x80)
	{
		Delete_LockObject();
		/*if (!KeyC) {
			KeyC = true;

			  
			for (auto sphere : list_Sphere)
			{
				auto iter = list_TotalSphere.begin();
				for (; iter != list_TotalSphere.end();)
				{
					if (*iter == sphere) {
						Set_VtxColor(sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 0, 255, 0));
						sphere->m_Click = false;
						sphere->Release_pPoint(sphere->list_pPoint.back());
						if (sphere->m_Dead) {
							iter = list_TotalSphere.erase(iter);
						}
						break;

					}
					else
						iter++;
				}
			}
			list_Sphere.clear();
		}*/
	}
	else {
		KeyC = false;
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
	// 뷰포트 -> 투영

	vMousePos.x = (ptMouse.x / (ViewPort.Width * 0.5f)) - 1.f;
	vMousePos.y = (ptMouse.y / -(ViewPort.Height * 0.5f)) + 1.f;
	vMousePos.z = 0.f;

	// L * W * V * P * (P^-1)
	// L * W * V

	// 투영 -> 뷰 스페이스
	Engine::_matrix	matProj;
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
	D3DXMatrixInverse(&matProj, NULL, &matProj);
	D3DXVec3TransformCoord(&vMousePos, &vMousePos, &matProj);

	// 뷰 스페이스 -> 월드
	Engine::_matrix	matView;
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	D3DXMatrixInverse(&matView, NULL, &matView);

	Engine::_vec3	vRayPos, vRayDir;


	vRayPos = Engine::_vec3(0.f, 0.f, 0.f);
	vRayDir = vMousePos - vRayPos;

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matView);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matView);

	// 월드 -> 로컬
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

		if (sphere->m_Click)
			sphereOverlap = true;

		return sphere;
	}

	return nullptr;
}

Engine::CGameObject* VertexManager::Picking_ObjectMesh(HWND hWnd, Engine::CTransform* pTerrainTransformCom)
{
	POINT		ptMouse{ 0 };

	GetCursorPos(&ptMouse);
	::ScreenToClient(hWnd, &ptMouse);


	Engine::_vec3	vMousePos;

	D3DVIEWPORT9		ViewPort;
	ZeroMemory(&ViewPort, sizeof(D3DVIEWPORT9));
	m_pGraphicDev->GetViewport(&ViewPort);
	// 뷰포트 -> 투영

	vMousePos.x = (ptMouse.x / (ViewPort.Width * 0.5f)) - 1.f;
	vMousePos.y = (ptMouse.y / -(ViewPort.Height * 0.5f)) + 1.f;
	vMousePos.z = 0.f;

	// L * W * V * P * (P^-1)
	// L * W * V

	// 투영 -> 뷰 스페이스
	Engine::_matrix	matProj;
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &matProj);
	D3DXMatrixInverse(&matProj, NULL, &matProj);
	D3DXVec3TransformCoord(&vMousePos, &vMousePos, &matProj);

	// 뷰 스페이스 -> 월드
	Engine::_matrix	matView;
	m_pGraphicDev->GetTransform(D3DTS_VIEW, &matView);
	D3DXMatrixInverse(&matView, NULL, &matView);

	Engine::_vec3	vRayPos, vRayDir;


	vRayPos = Engine::_vec3(0.f, 0.f, 0.f);
	vRayDir = vMousePos - vRayPos;

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matView);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matView);

	// 월드 -> 로컬
	Engine::_matrix	matWorld;
	pTerrainTransformCom->Get_WorldMatrix(&matWorld);
	D3DXMatrixInverse(&matWorld, NULL, &matWorld);

	D3DXVec3TransformCoord(&vRayPos, &vRayPos, &matWorld);
	D3DXVec3TransformNormal(&vRayDir, &vRayDir, &matWorld);

	Engine::_matrix tmlnv;
	Engine::_vec3 vSpherePos, vMinus;
	float A, B, C, D;

	auto& iter = find_if(CMFCToolView::GetInstance()->m_mapLayer.begin(), CMFCToolView::GetInstance()->m_mapLayer.end(), Engine::CTag_Finder(L"GameLogic"));
	if (iter == CMFCToolView::GetInstance()->m_mapLayer.end())
		return nullptr;


	for (auto& sphere : iter->second->m_mapObject)
	{
		vSpherePos = dynamic_cast<Engine::CTransform*>(sphere.second->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS];
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

		//if (sphere->m_Click)
		//	sphereOverlap = true;

		return sphere.second;
	}

	return nullptr;
}

void VertexManager::Set_SphereColor(Engine::CSphere* Vtx, D3DCOLOR color)
{
	
	void* pVertex = nullptr;
	Vtx->pMesh->LockVertexBuffer(0, &pVertex);
	// 색상 정보 위치 찾기 (초록색으로 바꾸려고)
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

void VertexManager::Set_TriColor(Engine::CTerrainTriCol* Vtx, D3DCOLOR color)
{

	VTXCOL* pVertex = NULL;
	Vtx->m_pVB->Lock(0, 0, (void**)&pVertex, NULL);

	for (int i = 0; i < 3; i++)
	{
		pVertex[i].dwColor = color;
	}
	Vtx->m_pVB->Unlock();

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

void VertexManager::MouseLClick_NaviMesh()
{
	LockOnObject(VM_Obj::NONE, nullptr);

	POINT		ptMouse{ 0 };
	GetCursorPos(&ptMouse);
	::ScreenToClient(g_hWnd, &ptMouse);
	if (ptMouse.x < 0.f)
		return;

	Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(CMFCToolView::GetInstance()->Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom);
	CSphereMesh* sphere = Picking_Sphere(g_hWnd, pTerrainTransformCom);
	if (sphereOverlap) {
		sphereOverlap = false;
		return;
	}
	CTerrainTri* pickUpTri = (CMFCToolView::GetInstance()->PickUp_Tri());

	if (sphere != nullptr) {		//구체를 클릭했을때
		Set_SphereColor(sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 5, 0, 153));
		list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(sphere));
		sphere->Add_Vtx();
		sphere->m_Click = true;
	}
	else if(pickUpTri != nullptr){	//삼각형을 클릭했을때
		
	}
	else {							//지형을 클릭했을때
		Engine::_vec3	vPickPos = CMFCToolView::GetInstance()->PickUp_OnTerrain();
		if (Engine::_vec3(0.f, 0.f, 0.f) != vPickPos) {
			Engine::CGameObject* pGameObject = CSphereMesh::Create(m_pGraphicDev);
			dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS] = vPickPos;
			CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"Sphere", pGameObject);
			//dynamic_cast<CSphereMesh*>(pGameObject)->Set_VtxPos();
			dynamic_cast<CSphereMesh*>(pGameObject)->m_Click = true;

			list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
			list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
			//pGameObject->AddRef();

		}
	}

	if (list_Sphere.size() == 3) {
		Engine::_vec3 vtxPos[3];
		list<CSphereMesh*> TempSphereMesh;
		int sphereCnt = 0;
		Engine::_vec3 sphereVec[3];
		for (int i = 0; i < 3; i++)
		{
			Set_SphereColor(list_Sphere.front()->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
			list_Sphere.front()->m_Click = false;
			vtxPos[i] = list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
			TempSphereMesh.emplace_back(list_Sphere.front());
			sphereVec[sphereCnt] = list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
			sphereCnt++;
			list_Sphere.pop_front();
		}
		CTerrainTri* pTerrainTri = CTerrainTri::Create(m_pGraphicDev, vtxPos[0], vtxPos[1], vtxPos[2]);

		

		CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"TerrainTri", pTerrainTri);
		
		for (int i = 0; i < 3; i++)
		{
			pTerrainTri->list_SphereMesh.emplace_back(TempSphereMesh.front());
			TempSphereMesh.front()->list_pTerrainTri.emplace_back(pTerrainTri);
			TempSphereMesh.front()->list_pPoint.emplace_back(pTerrainTri->m_Cell->Get_pPoint((CCell::POINT)i));
			TempSphereMesh.pop_front();
		}

		/////////////////////////////////////////
		//CCW

		if (CCW2(sphereVec[0], sphereVec[1], sphereVec[2]) == 1)
		{
			pTerrainTri->DeleteWithSphere();
			/*vertex[triCount][0] = Engine::_vec3{ 0.f,0.f,0.f };
			vertex[triCount][1] = Engine::_vec3{ 0.f,0.f,0.f };
			vertex[triCount][2] = Engine::_vec3{ 0.f,0.f,0.f };
			vertex[triCount][3] = Engine::_vec3{ 0.f,0.f,0.f };
			lineCount = 0;*/
			return;
		}
		CMFCToolView::GetInstance()->Sort_TriNumber();

		MeshPage* pMeshPage = MeshPage::GetInstance();

		if (pMeshPage != nullptr)
		{
			pMeshPage->treeControl(*pTerrainTri->m_Cell->Get_Index());
			//pMeshPage->tri[triCount] = pMeshPage->treeNavi.InsertItem(L"1", 0, 0, TVI_ROOT, TVI_LAST);
			//pMeshPage->vertex[triCount][0] = pMeshPage->treeNavi.InsertItem(L"a", 0, 0, pMeshPage->tri[triCount], TVI_LAST);
			//pMeshPage->vertex[triCount][1] = pMeshPage->treeNavi.InsertItem(L"b", 0, 0, pMeshPage->tri[triCount], TVI_LAST);
			//pMeshPage->vertex[triCount][2] = pMeshPage->treeNavi.InsertItem(L"c", 0, 0, pMeshPage->tri[triCount], TVI_LAST);
		}


	

		//////////////////////////////////////////////
	}
}

void VertexManager::MouseLClick_ObjectMesh()
{
	LockOnObject(VM_Obj::NONE, nullptr);

	POINT		ptMouse{ 0 };
	GetCursorPos(&ptMouse);
	::ScreenToClient(g_hWnd, &ptMouse);
	if (ptMouse.x < 0.f)
		return;

	Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(CMFCToolView::GetInstance()->Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom);

	Picking_ObjectMesh(g_hWnd, pTerrainTransformCom);
}

void VertexManager::MouseRClick_NaviMesh()
{
	Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(CMFCToolView::GetInstance()->Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
	NULL_CHECK_RETURN(pTerrainTransformCom);
	CSphereMesh* pickUpSphere = Picking_Sphere(g_hWnd, pTerrainTransformCom);
	CTerrainTri* pickUpTri = (CMFCToolView::GetInstance()->PickUp_Tri());

	if (pickUpSphere != nullptr) {
		//구체락온
		LockOnObject(VM_Obj::SPHERE, pickUpSphere);

		Set_SphereColor(pickUpSphere->m_pBufferCom, D3DCOLOR_ARGB(255, 200, 0, 0));
	}
	else if (pickUpTri != nullptr) {
		//삼각형락온
		LockOnObject(VM_Obj::TRI, pickUpTri);

		//Set_TriColor(pickUpTri->m_pBufferCom,D3DCOLOR_ARGB(255, 0, 44, 145));
		Set_TriColor(pickUpTri->m_pBufferCom, D3DCOLOR_ARGB(255, 255, 0, 0));
	}
}

void VertexManager::LockOnObject(VM_Obj name, Engine::CGameObject* obj)
{
	switch (lockOnObjName)
	{
	case VM_Obj::SPHERE: {
		if ((Engine::Get_DIKeyState(DIK_LSHIFT) & 0x80) && name == VM_Obj::SPHERE) {
			Together_Sphere(dynamic_cast<CSphereMesh*>(lockOnObj), dynamic_cast<CSphereMesh*>(obj));
			break;
		}
		else {
			CSphereMesh* _sphere = dynamic_cast<CSphereMesh*>(lockOnObj);
			if (_sphere->m_Click)
				Set_SphereColor(_sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 5, 0, 153));
			else
				Set_SphereColor(_sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
			break;
		}
	}
	case VM_Obj::TRI: {
		if ((Engine::Get_DIKeyState(DIK_LSHIFT) & 0x80) && name == VM_Obj::SPHERE) {
			Only_Sphere(dynamic_cast<CTerrainTri*>(lockOnObj), dynamic_cast<CSphereMesh*>(obj));
		}
		CTerrainTri* _tri = dynamic_cast<CTerrainTri*>(lockOnObj);
		Set_TriColor(_tri->m_pBufferCom, D3DCOLOR_ARGB(255, 100, 255, 100));
		break;
	}
	default:
		break;
	}
	lockOnObjName = name;
	if(obj != nullptr)
		lockOnObj = obj;
	MeshPage::GetInstance()->LockOnTree();
}


int VertexManager::CCW2(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, D3DXVECTOR3 vec3)
{
	float temp1 = (vec1.x * vec2.z) + (vec2.x * vec3.z) + (vec3.x * vec1.z);
	float temp2 = temp1 - (vec1.z * vec2.x) - (vec2.z*vec3.x) - (vec3.z*vec1.x);


	if (temp2>0)//반시계
		return 1;
	else if (temp2<0)//시계
		return -1;
	else //일직선
		return 0;
}

void VertexManager::Delete_LockObject() {
	if (lockOnObj == nullptr) {
		LockOnObject(VM_Obj::NONE, nullptr);
		return;
	}

	switch (lockOnObjName)
	{
	case VM_Obj::SPHERE: {
		CSphereMesh* _sphere = dynamic_cast<CSphereMesh*>(lockOnObj);
		_sphere->DeleteWithTerrainTri();
		break;
	}
	case VM_Obj::TRI: {
		CTerrainTri* _tri = dynamic_cast<CTerrainTri*>(lockOnObj);
		_tri->DeleteWithSphere();
		break;
	}
	default:
		break;
	}



	LockOnObject(VM_Obj::NONE, nullptr);
}

void VertexManager::Erase_list_TotalSphere(CSphereMesh* sphere)
{
	for (auto& iter = list_TotalSphere.begin(); iter != list_TotalSphere.end();)
	{
		if (*iter == sphere) {
			list_TotalSphere.erase(iter);
			break;
		}
		iter++;
	}
}

void VertexManager::Together_Sphere(CSphereMesh* firstSphere, CSphereMesh* secondSphere)
{
	for (auto& tri : firstSphere->list_pTerrainTri)
	{
		for (auto& tri2 : secondSphere->list_pTerrainTri)
		{
			if (tri == tri2)
			{
				//첫번째 원과 두번째원이 같은 삼각형을 참조하고 있을경우, 예외처리
				if (firstSphere->m_Click)
					Set_SphereColor(firstSphere->m_pBufferCom, D3DCOLOR_ARGB(255, 5, 0, 153));
				else
					Set_SphereColor(firstSphere->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
				return;
			}
		}
	}

	for (auto& pVec : firstSphere->list_pPoint)
	{
		*pVec  = *secondSphere->list_pPoint.front();
		secondSphere->list_pPoint.emplace_back(pVec);
	}
	firstSphere->list_pPoint.clear();
	for (auto& pTri : firstSphere->list_pTerrainTri)
	{
		for (auto& pSphere2 : pTri->list_SphereMesh)
		{
			if (pSphere2 == firstSphere) {
				pSphere2 = secondSphere;
				break;
			}
		}
		secondSphere->list_pTerrainTri.emplace_back(pTri);
	}
	firstSphere->list_pTerrainTri.clear();
	secondSphere->Set_InitPoint();
	Erase_list_TotalSphere(firstSphere);
	firstSphere->m_Dead = true;
}

CSphereMesh* VertexManager::Only_Sphere(CTerrainTri* tri, CSphereMesh* sphere)
{
	if (sphere->list_pTerrainTri.size() == 1)
		return nullptr;

	CSphereMesh* newSphere = CSphereMesh::Create(m_pGraphicDev);
	dynamic_cast<Engine::CTransform*>(newSphere->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS] = dynamic_cast<Engine::CTransform*>(sphere->Get_Component(L"Com_Transform", Engine::ID_DYNAMIC))->m_vInfo[Engine::INFO_POS];
	CMFCToolView::GetInstance()->LayerAddObject(L"Environment", L"Sphere", newSphere);
	list_TotalSphere.emplace_back(newSphere);
	LockOnObject(VM_Obj::SPHERE, newSphere);
	//dynamic_cast<CSphereMesh*>(pGameObject)->Set_VtxPos();
	newSphere->m_Click = true;

	for (auto& iter = sphere->list_pTerrainTri.begin(); iter != sphere->list_pTerrainTri.end();)
	{
		if (*iter == tri) {
			sphere->list_pTerrainTri.erase(iter);
			break;
		}
		iter++;
	}

	Engine::_vec3* pilferPoint = nullptr;
	for (auto& iter = sphere->list_pPoint.begin(); iter != sphere->list_pPoint.end();)
	{
		bool check = false;
		for (int i = 0; i < 3; i++)
		{
			if (*iter == tri->m_Cell->Get_pPoint((Engine::CCell::POINT)i)) {
				pilferPoint = *iter;
				sphere->list_pPoint.erase(iter);
				check = true;
				break;
			}
		}
		if (check)
			break;
		iter++;
	}

	newSphere->list_pPoint.emplace_back(pilferPoint);
	newSphere->list_pTerrainTri.emplace_back(tri);
	for (auto& iter = tri->list_SphereMesh.begin(); iter != tri->list_SphereMesh.end();)
	{
		if (*iter == sphere) {
			*iter = newSphere;
		}
		iter++;
	}
	return newSphere;
}