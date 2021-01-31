#include "stdafx.h"
#include "Stage2.h"
#include "Export_Function.h"
#include "Loading.h"
#include "Unit.h"
CStage2::CStage2(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CStage2::~CStage2(void)
{

}

HRESULT CStage2::Ready_Scene(void)
{
	
	FAILED_CHECK_RETURN(Ready_Environment_Layer(L"Environment"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_UI_Layer(L"UI"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_LightInfo(), E_FAIL);
	
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);
	CColliderMgr::GetInstance();
	return S_OK;
}

Engine::_int CStage2::Update_Scene(const _float& fTimeDelta)
{
	if (!isInitial)
	{
		InitialUpdate();
		isInitial = true;
	}
	CColliderMgr::GetInstance()->Update();
	return Engine::CScene::Update_Scene(fTimeDelta);
}

void CStage2::InitialUpdate()
{
	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	pPlayerTransCom->Set_Pos(&PlayerSpawnPositionCastle);
}

void CStage2::Render_Scene(void)
{

}

HRESULT CStage2::Load_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag)
{
	//TCHAR szDataPath[MAX_PATH] = L"../Bin/saveObject.dat";
	TCHAR szDataPath[MAX_PATH] = L"../Bin/saveObject13.dat";
	HANDLE hFile = CreateFile(szDataPath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL;
	DWORD dwByte = 0;
	DWORD dwstrByte = 0;

	bool endCheck = false;
	while (true)
	{
		bool sphereOverlap = false;

		_vec3 vecPos, vecAng, vecScal;
		TCHAR meshName[MAX_PATH] = L"";
		_int meshNameSize;

		ReadFile(hFile, &meshNameSize, sizeof(_int), &dwByte, nullptr);
		ReadFile(hFile, &meshName, meshNameSize, &dwByte, nullptr);
		ReadFile(hFile, &vecPos, sizeof(_vec3), &dwByte, nullptr);
		ReadFile(hFile, &vecScal, sizeof(_vec3), &dwByte, nullptr);
		ReadFile(hFile, &vecAng, sizeof(_vec3), &dwByte, nullptr);


		if (0 == dwByte)
		{
			endCheck = true;
			break;
		}

		wstring text, temp2, num;
		text = meshName;



		Engine::CGameObject* pGameObject = nullptr;
		pGameObject = CStaticObject::Create(m_pGraphicDev, text);
		NULL_CHECK_RETURN(pGameObject, E_FAIL);
		FAILED_CHECK_RETURN(_layer->Add_GameObject(L"StaticObject", pGameObject), E_FAIL);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Pos(&vecPos);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Scale(vecScal.x, vecScal.y, vecScal.z);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->m_vAngle = vecAng;
			/*Rotation(Engine::ROTATION::ROT_X, vecAng.x);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Y, vecAng.y);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Z, vecAng.z);*/
		m_mapLayer.emplace(pLayerTag, _layer);

		if (0 == dwByte)
		{
			//Safe_Delete(pUnit);
			break;
		}



		if (endCheck) {
			break;
		}
	}
	CloseHandle(hFile);
}
HRESULT CStage2::Ready_Environment_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer*			pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);
	
	Engine::CGameObject*		pGameObject = nullptr;

	pGameObject = CSkyBox::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SkyBox", pGameObject), E_FAIL);


	pGameObject = CTerrain::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Terrain", pGameObject), E_FAIL);

	pGameObject = CSwordTrail::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SwordTrail", pGameObject), E_FAIL);

	pGameObject = CDarkSwordTrail::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DarkSwordTrail", pGameObject), E_FAIL);
	
	m_mapLayer.emplace(pLayerTag, pLayer);
	
	return S_OK;
}

HRESULT CStage2::Ready_GameLogic_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer*			pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject*		pGameObject = nullptr;

	pGameObject = CPlayer::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CPlayer*>(pGameObject)->SetSpawnPosition(PlayerSpawnPositionCastle);
	//dynamic_cast<CUnit*>(pGameObject)->NaviMeshChange(L"Mesh_Navi2");
	
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Player", pGameObject), E_FAIL);

	pGameObject = CSword::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Sword", pGameObject), E_FAIL);
	Load_StaticObjectFromTool(pLayer, pLayerTag);
/*
	pGameObject = CConfusionHole2::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole2", pGameObject), E_FAIL);

	pGameObject = CConfusionHole2::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole2_L", pGameObject), E_FAIL);
	dynamic_cast<CConfusionHole2*>(pGameObject)->dir = 1;

	pGameObject = CConfusionHole2::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole2_R", pGameObject), E_FAIL);
	dynamic_cast<CConfusionHole2*>(pGameObject)->dir = 2;

	pGameObject = CConfusionHole::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole", pGameObject), E_FAIL);

	pGameObject = CConfusionHole::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CConfusionHole*>(pGameObject)->dir = 1;
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole_L", pGameObject), E_FAIL);

	pGameObject = CConfusionHole::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CConfusionHole*>(pGameObject)->dir = 2;
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole_R", pGameObject), E_FAIL);*/

	//시작지
	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 105.f,0.f,4.5f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 105.f,0.f,5.5f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 102.f, 0.f, 4.5f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);
	
	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 103.f, 0.f, 8.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);
	
	//2번째스폰
	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 98.f, 0.f, 36.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 98.f, 0.f, 38.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 100.f, 0.f, 38.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 101.f, 0.f, 39.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	//

	//첫번쨰불
	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 106.3f,0.5f,23.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 106.8f,0.5f,23.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 107.1f,0.5f,23.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);


	//두번째불
	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 105.8f,0.5f,27.1f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 106.3f,0.5f,27.1f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 106.8f,0.5f,27.1f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	//세번쨰불
	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 106.f,0.5f,30.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 107.f,0.5f,30.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);


	//네번째 불
	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 104.f,0.5f,46.2f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 104.8f,0.5f,46.2f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 105.6f,0.5f,46.2f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);
	//다섯번째 불
	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 104.f,0.5f,48.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 104.8f,0.5f,48.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 105.6f,0.5f,48.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	//여섯번째 불
	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 104.f,0.5f,51.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 104.8f,0.5f,51.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	pGameObject = CFireEffect::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CFireEffect*>(pGameObject)->m_pTransformCom->Set_Pos(&_vec3{ 105.6f,0.5f,51.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FireEffect", pGameObject), E_FAIL);

	//세번쨰 스폰
	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 98.f, 0.f, 66.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 96.f, 0.f, 65.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 96.6f, 0.f, 68.1f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 96.5f, 0.f, 67.2f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	//4번쨰 스폰
	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 85.f, 0.f, 70.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 85.f, 0.f, 68.5f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	//5번째스폰

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 76.3f, 0.f, 65.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 76.3f, 0.f, 66.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CDog::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CDog*>(pGameObject)->SetSpawnPosition(_vec3{ 75.f, 0.f, 66.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 66.f, 0.f, 66.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 66.f, 0.f, 68.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);

	pGameObject = CKnight::Create(m_pGraphicDev, CUnit::STAGE2);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	dynamic_cast<CKnight*>(pGameObject)->SetSpawnPosition(_vec3{ 68.f, 0.f, 63.f });
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Knight", pGameObject), E_FAIL);
	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CStage2::Ready_UI_Layer(const _tchar * pLayerTag)
{

	Engine::CLayer* pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CSkillSlot::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SkillSlot", pGameObject), E_FAIL);

	pGameObject = CHpBarBack::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"HpBarBack", pGameObject), E_FAIL);

	pGameObject = CHpBarValue::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"HpBarValue", pGameObject), E_FAIL);

	pGameObject = CSpBarBack::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SpBarBack", pGameObject), E_FAIL);

	pGameObject = CSpBarValue::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SpBarValue", pGameObject), E_FAIL);

	pGameObject = CStaminaBarBack::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"StaminaBarBack", pGameObject), E_FAIL);

	pGameObject = CStaminaBarValue::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"StaminaBarValue", pGameObject), E_FAIL);

	pGameObject = CSkill0::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Skill0", pGameObject), E_FAIL);

	pGameObject = CSkill1::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Skill1", pGameObject), E_FAIL);

	pGameObject = CSkill2::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Skill2", pGameObject), E_FAIL);

	pGameObject = CSkill4::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Skill4", pGameObject), E_FAIL);


	pGameObject = CSkillDkTransform::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SkillDkTransform", pGameObject), E_FAIL);

	pGameObject = CSkillDkTransform2::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SkillDkTransform2", pGameObject), E_FAIL);


	pGameObject = CDynamicCamera::Create(m_pGraphicDev, &_vec3(0.f, 10.f, -10.f),
		&_vec3(0.f, 0.f, 10.f),
		&_vec3(0.f, 1.f, 0.f));
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DynamicCamera", pGameObject), E_FAIL);
	m_mapLayer.emplace(pLayerTag, pLayer);
	return S_OK;
}



HRESULT CStage2::Ready_LightInfo(void)
{
	D3DLIGHT9		tLightInfo;
	ZeroMemory(&tLightInfo, sizeof(D3DLIGHT9));

	//// 0번 조명
	//tLightInfo.Type = D3DLIGHT_DIRECTIONAL;

	//tLightInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	//tLightInfo.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.f);

	//tLightInfo.Direction = _vec3(1.f, -1.f, 1.f);

	//if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 0)))
	//	return E_FAIL;

	//// 1번 조명
	//tLightInfo.Type = D3DLIGHT_POINT;
	//tLightInfo.Diffuse = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
	//tLightInfo.Specular = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
	//tLightInfo.Ambient = D3DXCOLOR(0.2f, 0.f, 0.f, 1.f);
	//tLightInfo.Position = _vec3(5.f, 5.f, 5.f);
	//tLightInfo.Range = 10.f;

	//if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 1)))
	//	return E_FAIL;
	//	
	//// 2번 조명
	//tLightInfo.Type = D3DLIGHT_POINT;
	//tLightInfo.Diffuse = D3DXCOLOR(0.f, 0.f, 1.f, 1.f);
	//tLightInfo.Specular = D3DXCOLOR(0.f, 0.f, 1.f, 1.f);
	//tLightInfo.Ambient = D3DXCOLOR(0.f, 0.f, 0.2f, 1.f);
	//tLightInfo.Position = _vec3(10.f, 5.f, 10.f);
	//tLightInfo.Range = 10.f;

	if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 2)))
		return E_FAIL;

	return S_OK;
}

CStage2* CStage2::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CStage2*	pInstance = new CStage2(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CStage2::Free(void)
{
	Engine::CScene::Free();/*
	CColliderMgr::Destroy();*/
}

