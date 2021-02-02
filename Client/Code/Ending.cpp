#include "stdafx.h"
#include "Ending.h"
#include "Export_Function.h"
#include "Loading.h"
#include "Stage3.h"
#include "Ending.h"
#include "SoundManager.h"
#include "BackGround.h"
#include "EndingScene.h"
CEnding::CEnding(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{

}

CEnding::~CEnding(void)
{

}

HRESULT CEnding::Ready_Scene(void)
{
	//SoundManager::PlayOverlapSound(L"EndingBgm.wav", SoundChannel::PLAYER, 0.8f);
	SoundManager::PlayBGM(L"EndingBgm.wav");
	FAILED_CHECK_RETURN(Ready_Environment_Layer(L"Environment"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_GameLogic_Layer(L"GameLogic"), E_FAIL);
	FAILED_CHECK_RETURN(Ready_UI_Layer(L"UI"), E_FAIL);
	//FAILED_CHECK_RETURN(Ready_LightInfo(), E_FAIL);
	
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, TRUE);

	return S_OK;
}

Engine::_int CEnding::Update_Scene(const _float& fTimeDelta)
{
	if (Engine::Get_DIKeyState(DIK_F11) & 0x80)
	{
		SoundManager::StopSound(SoundChannel::BGM);
		CScene* pScene = nullptr;
		pScene = CStage2::Create(m_pGraphicDev);

		FAILED_CHECK_RETURN(Engine::SetUp_Scene(pScene), E_FAIL);
		return 1;
	}

	return Engine::CScene::Update_Scene(fTimeDelta);



}

void CEnding::Render_Scene(void)
{

}

void CEnding::InitialUpdate()
{
}


HRESULT CEnding::Ready_Environment_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer*			pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);
	
	Engine::CGameObject*		pGameObject = nullptr;

	m_mapLayer.emplace(pLayerTag, pLayer);
	
	return S_OK;
}

HRESULT CEnding::Ready_GameLogic_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer*			pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject*		pGameObject = nullptr;

	//pGameObject = CPlayer::Create(m_pGraphicDev,CUnit::STAGE1);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//dynamic_cast<CPlayer*>(pGameObject)->SetSpawnPosition(PlayerSpawnPositionCentral);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Player", pGameObject), E_FAIL);

	//pGameObject = CSword::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"Sword", pGameObject), E_FAIL);
	//Load_StaticObjectFromTool(pLayer, pLayerTag);
	m_mapLayer.emplace(pLayerTag, pLayer);

	return S_OK;
}

HRESULT CEnding::Ready_UI_Layer(const _tchar * pLayerTag)
{
	Engine::CLayer* pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject* pGameObject = nullptr;

	pGameObject = CFadeInOut::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"FadeInOut", pGameObject), E_FAIL);


	pGameObject = CEndingScene::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(pGameObject, E_FAIL);
	FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"EndingScene", pGameObject), E_FAIL);

	//pGameObject = CBackGround::Create(m_pGraphicDev);
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"BackGround", pGameObject), E_FAIL);

	//pGameObject = CDynamicCamera::Create(m_pGraphicDev, &_vec3(0.f, 10.f, -10.f),
	//	&_vec3(0.f, 0.f, 10.f),
	//	&_vec3(0.f, 1.f, 0.f));
	//NULL_CHECK_RETURN(pGameObject, E_FAIL);
	//FAILED_CHECK_RETURN(pLayer->Add_GameObject(L"DynamicCamera", pGameObject), E_FAIL);

	m_mapLayer.emplace(pLayerTag, pLayer);
	return S_OK;
}



HRESULT CEnding::Ready_LightInfo(void)
{
	//D3DLIGHT9		tLightInfo;
	//ZeroMemory(&tLightInfo, sizeof(D3DLIGHT9));

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

	//if (FAILED(Engine::Ready_Light(m_pGraphicDev, &tLightInfo, 2)))
	//	return E_FAIL;

	return S_OK;
}

CEnding* CEnding::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CEnding*	pInstance = new CEnding(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Client::Safe_Release(pInstance);

	return pInstance;
}

void CEnding::Free(void)
{
	Engine::CScene::Free();
}

