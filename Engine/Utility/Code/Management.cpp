#include "Export_Utility.h"

USING(Engine)
IMPLEMENT_SINGLETON(CManagement)

Engine::CManagement::CManagement(void)
	: m_pScene(nullptr)	
{

}

Engine::CManagement::~CManagement(void)
{
	Free();
}

HRESULT CManagement::Ready_Shader(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	CShader*		pShader = nullptr;

	// Sample
	pShader = CShader::Create(pGraphicDev, L"../../Reference/Header/Shader_Sample.hpp");
	NULL_CHECK_RETURN(pShader, E_FAIL);
	FAILED_CHECK_RETURN(Ready_Proto(L"Proto_Shader_Sample", pShader), E_FAIL);

	// Terrain
	pShader = CShader::Create(pGraphicDev, L"../../Reference/Header/Shader_Terrain.hpp");
	NULL_CHECK_RETURN(pShader, E_FAIL);
	FAILED_CHECK_RETURN(Ready_Proto(L"Proto_Shader_Terrain", pShader), E_FAIL);


	return S_OK;
}

HRESULT Engine::CManagement::SetUp_Scene(CScene* pScene)
{
	Safe_Release(m_pScene); // 

	m_pScene = pScene;
	
	return S_OK;
}

Engine::_int Engine::CManagement::Update_Scene(const _float& fTimeDelta)
{
	if (nullptr == m_pScene)
		return -1;

	m_pScene->Update_Scene(fTimeDelta);

	return 0;
}

void Engine::CManagement::Render_Scene(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	Get_Renderer()->Render_GameObject(pGraphicDev);

	if (nullptr == m_pScene)
		return;

	m_pScene->Render_Scene();
}

void Engine::CManagement::Free(void)
{
	Safe_Release(m_pScene);
}

Engine::CComponent* Engine::CManagement::Get_Component(const _tchar* pLayerTag, const _tchar* pObjTag, const _tchar* pComponentTag, COMPONENTID eID)
{
	if (nullptr == m_pScene)
		return nullptr;
	
	return m_pScene->Get_Component(pLayerTag, pObjTag, pComponentTag, eID);
}

Engine::CGameObject* Engine::CManagement::Get_GameObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	if (nullptr == m_pScene)
		return nullptr;

	return m_pScene->Get_GameObject(pLayerTag, pObjTag);
}

