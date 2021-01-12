#include "stdafx.h"
#include "Stage.h"
#include "Export_Function.h"
#include "Loading.h"
#include "Stage2.h"
CStage::CStage(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CStage::~CStage(void)
{

}

HRESULT CStage::Ready_Scene(void)
{
	
	FAILED_CHECK_RETURN(Ready_Environment_Layer(L"Environment"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_UI_Layer(L"UI"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_LightInfo(), E_FAIL);
	
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);

	return S_OK;
}

Engine::_int CStage::Update_Scene(const _float& fTimeDelta)
{
	if (Engine::Get_DIKeyState(DIK_F11) & 0x80)
	{
		CScene* pScene = nullptr;
		pScene = CStage2::Create(m_pGraphicDev);

		FAILED_CHECK_RETURN(Engine::SetUp_Scene(pScene), E_FAIL);
		return 1;
	}

	return Engine::CScene::Update_Scene(fTimeDelta);



}

void CStage::Render_Scene(void)
{

}

HRESULT CStage::Load_StaticObjectFromTool(Engine::CLayer* _layer, const _tchar* pLayerTag)
{
	//TCHAR szDataPath[MAX_PATH] = L"../Bin/saveObject.dat";
	TCHAR szDataPath[MAX_PATH] = L"../Bin/saveObject3.dat";
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
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_X, vecAng.x);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Y, vecAng.y);
		dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Rotation(Engine::ROTATION::ROT_Z, vecAng.z);
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
HRESULT CStage::Ready_Environment_Layer(const _tchar * pLayerTag)
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

	
	m_mapLayer.emplace(pLayerTag, pLayer);
	
	return S_OK;
}

HRESULT CStage::Ready_GameLogic_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer*			pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject*		pGameObject = nullptr;

	pGameObject = CPlayer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Player", pGameObject), E_FAIL);

	pGameObject = CSword::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Sword", pGameObject), E_FAIL);
	Load_StaticObjectFromTool(pLayer, pLayerTag);

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
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"ConfusionHole_R", pGameObject), E_FAIL);

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

	pGameObject = CRuinBlade::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"RuinBlade", pGameObject), E_FAIL);
	

	/*pGameObject = CParticle::Create(m_pGraphicDev);*/

	//pGameObject = CDog::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//dynamic_cast<Engine::CTransform*>(pGameObject->Get_Component(L"Com_Transform", Engine::COMPONENTID::ID_DYNAMIC))->Set_Pos(&_vec3{ 22.f,0.f,22.f });
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);
	////pGameObject = CDog::Create(m_pGraphicDev);
	////NULL_CHECK_RETURN(pGameObject, E_FAIL);
	////FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Dog", pGameObject), E_FAIL);

	////pGameObject = CTitan::Create(m_pGraphicDev);
	////NULL_CHECK_RETURN(pGameObject, E_FAIL);
	////FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Titan", pGameObject), E_FAIL);

	pGameObject = CIngkells::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Inkells", pGameObject), E_FAIL);

	/*for (_uint i = 0; i < 50; ++i)
	{
		pGameObject = CMonster::Create(m_pGraphicDev);
		NULL_CHECK_RETURN(pGameObject, E_FAIL);
		FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Monster", pGameObject), E_FAIL);
	}*/

	//pGameObject = CDamageFont::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DamageFont", pGameObject), E_FAIL);

	//pGameObject = CStone::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Stone", pGameObject), E_FAIL);

	//pGameObject = CTree::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Tree", pGameObject), E_FAIL);

	//for (_uint i = 0; i < 100; ++i)
	//{
		pGameObject = CSwordTrail::Create(m_pGraphicDev);
		NULL_CHECK_RETURN(pGameObject, E_FAIL);
		FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"SwordTrail", pGameObject), E_FAIL);

	//}

	//pGameObject = CUI::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"UI", pGameObject), E_FAIL);
	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CStage::Ready_UI_Layer(const _tchar * pLayerTag)
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



	pGameObject = CBossHpBarBase::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BossHpBarBase", pGameObject), E_FAIL);

	pGameObject = CBossHpBarRed::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BossHpBarRed", pGameObject), E_FAIL);

	pGameObject = CBossHpBarOrange::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BossHpBarOrange", pGameObject), E_FAIL);

	pGameObject = CBossHpBarGreen::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BossHpBarGreen", pGameObject), E_FAIL);


	pGameObject = CDynamicCamera::Create(m_pGraphicDev, &_vec3(0.f, 10.f, -10.f),
		&_vec3(0.f, 0.f, 10.f),
		&_vec3(0.f, 1.f, 0.f));
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DynamicCamera", pGameObject), E_FAIL);
	m_mapLayer.emplace(pLayerTag, pLayer);
	return S_OK;
}



HRESULT CStage::Ready_LightInfo(void)
{
	D3DLIGHT9		tLightInfo;
	ZeroMemory(&tLightInfo, sizeof(D3DLIGHT9));

	// 0번 조명
	tLightInfo.Type = D3DLIGHT_DIRECTIONAL;

	tLightInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	tLightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	tLightInfo.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.f);

	tLightInfo.Direction = _vec3(1.f, -1.f, 1.f);

	if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 0)))
		return E_FAIL;

	// 1번 조명
	tLightInfo.Type = D3DLIGHT_POINT;
	tLightInfo.Diffuse = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
	tLightInfo.Specular = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
	tLightInfo.Ambient = D3DXCOLOR(0.2f, 0.f, 0.f, 1.f);
	tLightInfo.Position = _vec3(5.f, 5.f, 5.f);
	tLightInfo.Range = 10.f;

	if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 1)))
		return E_FAIL;
		
	// 2번 조명
	tLightInfo.Type = D3DLIGHT_POINT;
	tLightInfo.Diffuse = D3DXCOLOR(0.f, 0.f, 1.f, 1.f);
	tLightInfo.Specular = D3DXCOLOR(0.f, 0.f, 1.f, 1.f);
	tLightInfo.Ambient = D3DXCOLOR(0.f, 0.f, 0.2f, 1.f);
	tLightInfo.Position = _vec3(10.f, 5.f, 10.f);
	tLightInfo.Range = 10.f;

	if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 2)))
		return E_FAIL;

	return S_OK;
}

CStage* CStage::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CStage*	pInstance = new CStage(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CStage::Free(void)
{
	Engine::CScene::Free();
}

