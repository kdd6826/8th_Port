#include "Export_Utility.h"
HRESULT Create_Management(CManagement** ppManagement, LPDIRECT3DDEVICE9& pGraphicDev)
{
	CManagement*		pManagement = CManagement::GetInstance();
	NULL_CHECK_RETURN(pManagement, E_FAIL);

	if (FAILED(pManagement->Ready_Shader(pGraphicDev)))
		return E_FAIL;

	*ppManagement = pManagement;

	return S_OK;
}
CComponent*	   Get_Component(const _tchar* pLayerTag, const _tchar* pObjTag, const _tchar* pComponentTag, COMPONENTID eID)
{
	return CManagement::GetInstance()->Get_Component(pLayerTag, pObjTag, pComponentTag, eID);
}

CGameObject* Get_GameObject(const _tchar* pLayerTag, const _tchar* pObjTag)
{
	return CManagement::GetInstance()->Get_GameObject(pLayerTag, pObjTag);
}

HRESULT	SetUp_Scene(CScene* pScene)
{
	return CManagement::GetInstance()->SetUp_Scene(pScene);
}
_int	Update_Scene(const _float& fTimeDelta)
{
	return CManagement::GetInstance()->Update_Scene(fTimeDelta);
}
void	Render_Scene(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	return CManagement::GetInstance()->Render_Scene(pGraphicDev);
}

// protomgr
HRESULT			Ready_Proto(const _tchar* pProtoTag, CComponent* pInstance)
{
	return CProtoMgr::GetInstance()->Ready_Proto(pProtoTag, pInstance);
}
CComponent*		Clone(const _tchar* pProtoTag)
{
	return CProtoMgr::GetInstance()->Clone(pProtoTag);
}

// Renderer
CRenderer*		Get_Renderer(void)
{
	return CRenderer::GetInstance();
}

// LightMgr

const D3DLIGHT9*		Get_Light(const _uint& iIndex)
{
	return CLightMgr::GetInstance()->Get_Light(iIndex);
}

HRESULT		Ready_Light(LPDIRECT3DDEVICE9 pGraphicDev, const D3DLIGHT9* pLightInfo, const _uint& iIndex)
{
	return CLightMgr::GetInstance()->Ready_Light(pGraphicDev, pLightInfo, iIndex);
}

void Release_Utility(void)
{
	CLightMgr::GetInstance()->DestroyInstance();
	CRenderer::GetInstance()->DestroyInstance();
	CProtoMgr::GetInstance()->DestroyInstance();
	CManagement::GetInstance()->DestroyInstance();
}