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
			MouseLClick_NaviMesh();
		}
	}
	else {
		mouseLClick = false;
	}

	if (Engine::Get_DIMouseState(Engine::DIM_RB) & 0x80)
	{
		if (!mouseRClick) {
			mouseRClick = true;
			Engine::CTransform* pTerrainTransformCom = dynamic_cast<Engine::CTransform*>(CMFCToolView::GetInstance()->Get_Component(L"Environment", L"Terrain", L"Com_Transform", Engine::ID_DYNAMIC));
			NULL_CHECK_RETURN(pTerrainTransformCom);
			CSphereMesh* pickUpSphere = Picking_Sphere(g_hWnd, pTerrainTransformCom);
			CTerrainTri* pickUpTri = (CMFCToolView::GetInstance()->PickUp_Tri());

			if (pickUpSphere != nullptr) {
				//구체락온
				LockOnObject(VM_Obj::SPHERE, pickUpSphere);

				pickUpSphere->m_pTransformCom->m_vInfo[Engine::INFO_POS].y += 0.1f; //나중에삭제 테스트용

				Set_SphereColor(pickUpSphere->m_pBufferCom, D3DCOLOR_ARGB(255, 200, 0, 0));
				pickUpSphere->Set_InitPoint(); //포지션값 이동후 이거 반드시 불러올것
			}
			else if (pickUpTri != nullptr) {
				//삼각형락온
				LockOnObject(VM_Obj::TRI, pickUpTri);

				//Set_TriColor(pickUpTri->m_pBufferCom,D3DCOLOR_ARGB(255, 0, 44, 145));
				Set_TriColor(pickUpTri->m_pBufferCom, D3DCOLOR_ARGB(255, 255, 0, 0));
			}
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

void VertexManager::DrawLine()
{


	

	for (int i = 0; i < triCount+1; i++)
	{
		//D3DXCreateLine(m_pGraphicDev, &line[i]);
		//line[i]->SetWidth(5.f);
		//line[i]->SetAntialias(FALSE);
	}
	// 투영 -> 뷰 스페이스
	Engine::_matrix	out, view, proj, world;

	m_pGraphicDev->GetTransform(D3DTS_VIEW, &view);
	m_pGraphicDev->GetTransform(D3DTS_PROJECTION, &proj);
	m_pGraphicDev->GetTransform(D3DTS_WORLD, &world);

	D3DXMatrixIdentity(&out);
	out = view * proj;


	//line->DrawTransform(vertex, 1, &world, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	//line->DrawTransform(vertex, 2, &world, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	for (int i = 0; i < triCount + 1; ++i)
	{

		D3DXCreateLine(m_pGraphicDev, &line[i]);
		line[i]->SetWidth(5.f);
		line[i]->SetAntialias(FALSE);
		line[i]->Begin();
		line[i]->DrawTransform(vertex[i],4, &out, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
		line[i]->End();
		line[i]->Release();
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
	mouseLClick = true;
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
			dynamic_cast<CSphereMesh*>(pGameObject)->Set_VtxPos();
			dynamic_cast<CSphereMesh*>(pGameObject)->m_Click = true;

			list_TotalSphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
			list_Sphere.emplace_back(dynamic_cast<CSphereMesh*>(pGameObject));
			//pGameObject->AddRef();

			/////////////////////////////////////////
			//삼각형 라인 생성
			lineCount++;
			vertex[triCount][lineCount - 1] = vPickPos + Engine::_vec3(0.01f, 0.01f, 0.01f);
			//삼각형 마지막
			if (lineCount % 3 == 0)
			{
				vertex[triCount][lineCount] = vertex[triCount][lineCount - 3];
				//
				MeshPage* pMeshPage = MeshPage::GetInstance();;

				if (CCW2(vertex[triCount][0], vertex[triCount][1], vertex[triCount][2]) == 1)
				{

					vertex[triCount][0] = Engine::_vec3{ 0.f,0.f,0.f };
					vertex[triCount][1] = Engine::_vec3{ 0.f,0.f,0.f };
					vertex[triCount][2] = Engine::_vec3{ 0.f,0.f,0.f };
					return;
				}
				
				if (pMeshPage != nullptr)
				{
					pMeshPage->treeControl(triCount);
					//pMeshPage->tri[triCount] = pMeshPage->treeNavi.InsertItem(L"1", 0, 0, TVI_ROOT, TVI_LAST);
					//pMeshPage->vertex[triCount][0] = pMeshPage->treeNavi.InsertItem(L"a", 0, 0, pMeshPage->tri[triCount], TVI_LAST);
					//pMeshPage->vertex[triCount][1] = pMeshPage->treeNavi.InsertItem(L"b", 0, 0, pMeshPage->tri[triCount], TVI_LAST);
					//pMeshPage->vertex[triCount][2] = pMeshPage->treeNavi.InsertItem(L"c", 0, 0, pMeshPage->tri[triCount], TVI_LAST);
				}
				//

				

				lineCount++;
				triCount++;
				lineCount = 0;
				
			
			}
			
			//////////////////////////////////////////////
		}
	}

	if (list_Sphere.size() == 3) {
		Engine::_vec3 vtxPos[3];
		list<CSphereMesh*> TempSphereMesh;
		for (int i = 0; i < 3; i++)
		{
			Set_SphereColor(list_Sphere.front()->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
			list_Sphere.front()->m_Click = false;
			vtxPos[i] = list_Sphere.front()->m_pTransformCom->m_vInfo[Engine::INFO_POS];
			TempSphereMesh.emplace_back(list_Sphere.front());
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
	}
}

void VertexManager::LockOnObject(VM_Obj name, Engine::CGameObject* obj)
{
	switch (lockOnObjName)
	{
	case VM_Obj::SPHERE: {
		CSphereMesh* _sphere = dynamic_cast<CSphereMesh*>(lockOnObj);
		if (_sphere->m_Click)
			Set_SphereColor(_sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 5, 0, 153));
		else
			Set_SphereColor(_sphere->m_pBufferCom, D3DCOLOR_ARGB(255, 8, 103, 1));
		break;
	}
	case VM_Obj::TRI: {
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