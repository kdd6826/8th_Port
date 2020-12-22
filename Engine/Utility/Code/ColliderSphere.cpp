#include "ColliderSphere.h"

USING(Engine)
Engine::CColliderSphere::CColliderSphere(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)	
{
	Safe_AddRef(m_pGraphicDev);
}

Engine::CColliderSphere::CColliderSphere(const CColliderSphere& rhs)
	: m_pGraphicDev(rhs.m_pGraphicDev)
	, m_pVB(rhs.m_pVB)
	, m_pIB(rhs.m_pIB)
	, m_dwVtxCnt(rhs.m_dwVtxCnt)
	, m_dwTriCnt(rhs.m_dwTriCnt)
	, m_dwVtxSize(rhs.m_dwVtxSize)
	, m_dwFVF(rhs.m_dwFVF)
	, m_dwIdxSize(rhs.m_dwIdxSize)
{
	for (_uint i = 0; i < COL_END; ++i)
		m_pTexture[i] = rhs.m_pTexture[i];
	
	Safe_AddRef(m_pVB);
	Safe_AddRef(m_pIB);
}

Engine::CColliderSphere::~CColliderSphere(void)
{

}

HRESULT Engine::CColliderSphere::Ready_ColliderSphere()
{
	D3DXCreateSphere(m_pGraphicDev, 30.f, 12, 12, &pMesh[0], NULL);
	
	m_dwFVF = pMesh[0]->GetFVF();
	if (!(m_dwFVF & D3DFVF_DIFFUSE))
	{
		pMesh[0]->CloneMeshFVF(pMesh[0]->GetOptions(), m_dwFVF |= D3DFVF_DIFFUSE, m_pGraphicDev, &pMesh[0]);
	}
	else
	{
		pMesh[0]->CloneMeshFVF(pMesh[0]->GetOptions(), m_dwFVF, m_pGraphicDev, &pMesh[0]);
	}


	m_dwTriCnt = pMesh[0]->GetNumFaces();
	m_dwVtxCnt = pMesh[0]->GetNumVertices();
	m_dwVtxSize = pMesh[0]->GetNumBytesPerVertex();
	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;
	FAILED_CHECK_RETURN(pMesh[0]->GetVertexBuffer(&m_pVB), E_FAIL);
	FAILED_CHECK_RETURN(pMesh[0]->GetIndexBuffer(&m_pIB), E_FAIL);


	return S_OK;
}

Engine::CColliderSphere* Engine::CColliderSphere::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CColliderSphere*	pInstance = new CColliderSphere(pGraphicDev);

	if (FAILED(pInstance->Ready_ColliderSphere()))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CColliderSphere::Render_ColliderSphere(COLLTYPE eType, const _matrix* pColliderMatrix)
{
	m_matCollMatrix = *pColliderMatrix;

#ifdef _DEBUG
	m_pGraphicDev->SetTransform(D3DTS_WORLD, pColliderMatrix);

	m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	pMesh[0]->DrawSubset(0);
	
	m_pGraphicDev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
#endif

}

CComponent * CColliderSphere::Clone(void)
{
	return new CColliderSphere(*this);
}

void Engine::CColliderSphere::Free(void)
{
	for (_uint i = 0; i < COL_END; ++i)
		Safe_Release(m_pTexture[i]);

	Safe_Release(m_pVB);
	Safe_Release(m_pIB);
	Safe_Release(m_pGraphicDev);
}

