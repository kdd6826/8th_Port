#include "RenderTarget.h"
USING(Engine)

Engine::CRenderTarget::CRenderTarget(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
	, m_pTargetTexture(nullptr)
	, m_pOldTargetSurface(nullptr)
	, m_pTargetSurface(nullptr)
{
	Safe_AddRef(m_pGraphicDev);
}

Engine::CRenderTarget::~CRenderTarget(void)
{

}

HRESULT Engine::CRenderTarget::Ready_RenderTarget(const _uint& iWidth, const _uint& iHeight, D3DFORMAT Format, D3DXCOLOR Color)
{
	if (FAILED(D3DXCreateTexture(m_pGraphicDev, 
		iWidth, iHeight, 1, 
		D3DUSAGE_RENDERTARGET, Format,
		D3DPOOL_DEFAULT, 
		&m_pTargetTexture)))
		return E_FAIL;

	// 텍스쳐로부터 렌더타겟 성분을 추출하는 함수
	m_pTargetTexture->GetSurfaceLevel(0, &m_pTargetSurface);

	Safe_Release(m_pTargetTexture);
	
	return S_OK;
}

void Engine::CRenderTarget::SetUp_OnGraphicDev(const _uint& iIndex)
{
	m_pGraphicDev->GetRenderTarget(iIndex, &m_pOldTargetSurface);

	m_pGraphicDev->SetRenderTarget(iIndex, m_pTargetSurface);
}

CRenderTarget* Engine::CRenderTarget::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _uint& iWidth, const _uint& iHeight, D3DFORMAT Format, D3DXCOLOR Color)
{
	CRenderTarget*	pInstance = new CRenderTarget(pGraphicDev);

	if (FAILED(pInstance->Ready_RenderTarget(iWidth, iHeight, Format, Color)))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CRenderTarget::Free(void)
{
	Safe_Release(m_pGraphicDev);
}

