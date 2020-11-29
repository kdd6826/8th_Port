#include "Line.h"

USING(Engine)
Engine::CLine::CLine(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{

}

Engine::CLine::CLine(const CLine& rhs)
	: CVIBuffer(rhs)
{
	Ready_Buffer();
}

Engine::CLine::~CLine(void)
{

}

HRESULT Engine::CLine::Ready_Buffer(void)
{
	//D3DXCreateLine(m_pGraphicDev, 0.6f, 8, 8, &pMesh, NULL);
	//
	//m_dwFVF = pMesh->GetFVF();
	//if (!(m_dwFVF & D3DFVF_DIFFUSE))
	//{
	//	pMesh->CloneMeshFVF(pMesh->GetOptions(), m_dwFVF |= D3DFVF_DIFFUSE, m_pGraphicDev, &pMesh);
	//}
	//else
	//{
	//	pMesh->CloneMeshFVF(pMesh->GetOptions(), m_dwFVF, m_pGraphicDev, &pMesh);
	//}
	//
	//Set_Color(D3DCOLOR_ARGB(255, 0, 255, 0));


	//m_dwTriCnt = pMesh->GetNumFaces();
	//m_dwVtxCnt = pMesh->GetNumVertices();
	//m_dwVtxSize = pMesh->GetNumBytesPerVertex();
	////for (int i = 0; i < m_dwTriCnt; i++)
	////{
	////	//인덱스 사이즈만큼 넘겨준다
	////}
	//m_dwIdxSize = sizeof(INDEX16);
	//m_IdxFmt = D3DFMT_INDEX16;

	////FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	//FAILED_CHECK_RETURN(pMesh->GetVertexBuffer(&m_pVB), E_FAIL);
	//FAILED_CHECK_RETURN(pMesh->GetIndexBuffer(&m_pIB), E_FAIL);
	//

	return S_OK;
}


Engine::CLine* Engine::CLine::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLine* pInstance = new CLine(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

CComponent* CLine::Clone(void)
{
	return new CLine(*this);
}

void Engine::CLine::Free(void)
{
	CVIBuffer::Free();
}

