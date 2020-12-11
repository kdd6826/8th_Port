#include "Renderer.h"

USING(Engine)
IMPLEMENT_SINGLETON(CRenderer)

Engine::CRenderer::CRenderer(void)
{

}

Engine::CRenderer::~CRenderer(void)
{

}

void Engine::CRenderer::Add_RenderGroup(RENDERID eGroup, CGameObject* pGameObject)
{
	if (RENDER_END <= eGroup)
		return;

	m_RenderGroup[eGroup].push_back(pGameObject);
	Safe_AddRef(pGameObject);
}

void Engine::CRenderer::Render_GameObject(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	Render_Priority(pGraphicDev);
	Render_NonAlpha(pGraphicDev);
	Render_Alpha(pGraphicDev);
	Render_UI(pGraphicDev);

	Clear_RenderGroup();
}

void Engine::CRenderer::Clear_RenderGroup(void)
{
	for (_uint i = 0; i < RENDER_END; ++i)
	{
		for_each(m_RenderGroup[i].begin(), m_RenderGroup[i].end(), CDeleteObj());
		m_RenderGroup[i].clear();
	}
}

void CRenderer::Render_Priority(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	pGraphicDev->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (auto& iter : m_RenderGroup[RENDER_PRIORITY])
		iter->Render_Object();

	pGraphicDev->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
}

void CRenderer::Render_NonAlpha(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	for (auto& iter : m_RenderGroup[RENDER_NONALPHA])
		iter->Render_Object();
}

_bool		Compare_ViewZ(CGameObject* pDest, CGameObject* pSrc)
{
	return pDest->Get_ViewZ() > pSrc->Get_ViewZ();
}

void CRenderer::Render_Alpha(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	pGraphicDev->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pGraphicDev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pGraphicDev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	m_RenderGroup[RENDER_ALPHA].sort(Compare_ViewZ);

	for (auto& iter : m_RenderGroup[RENDER_ALPHA])
		iter->Render_Object();

	pGraphicDev->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void CRenderer::Render_UI(LPDIRECT3DDEVICE9 & pGraphicDev)
{
	for (auto& iter : m_RenderGroup[RENDER_UI])
		iter->Render_Object();
}

void Engine::CRenderer::Free(void)
{
	Clear_RenderGroup();
}

