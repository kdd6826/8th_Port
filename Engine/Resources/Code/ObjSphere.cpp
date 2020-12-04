#include "ObjSphere.h"

USING(Engine)
Engine::CObjSphere::CObjSphere(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{

}

Engine::CObjSphere::CObjSphere(const CObjSphere& rhs)
	: CVIBuffer(rhs)
{
	Ready_Buffer();
}

Engine::CObjSphere::~CObjSphere(void)
{

}

HRESULT Engine::CObjSphere::Ready_Buffer(void)
{
	D3DXCreateSphere(m_pGraphicDev, 1.f, 8, 8, &pMesh, NULL);
	
	m_dwFVF = pMesh->GetFVF();
	if (!(m_dwFVF & D3DFVF_DIFFUSE))
	{
		pMesh->CloneMeshFVF(pMesh->GetOptions(), m_dwFVF |= D3DFVF_DIFFUSE, m_pGraphicDev, &pMesh);
	}
	else
	{
		pMesh->CloneMeshFVF(pMesh->GetOptions(), m_dwFVF, m_pGraphicDev, &pMesh);
	}
	
	Set_Color(D3DCOLOR_ARGB(255, 65, 175, 57));


	m_dwTriCnt = pMesh->GetNumFaces();
	m_dwVtxCnt = pMesh->GetNumVertices();
	m_dwVtxSize = pMesh->GetNumBytesPerVertex();
	//for (int i = 0; i < m_dwTriCnt; i++)
	//{
	//	//�ε��� �����ŭ �Ѱ��ش�
	//}
	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;

	//FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	FAILED_CHECK_RETURN(pMesh->GetVertexBuffer(&m_pVB), E_FAIL);
	FAILED_CHECK_RETURN(pMesh->GetIndexBuffer(&m_pIB), E_FAIL);
	

	return S_OK;
}

void Engine::CObjSphere::Set_Color(D3DCOLOR color)
{
	void* pVertex = nullptr;
	pMesh->LockVertexBuffer(0, &pVertex);
	// ���� ���� ��ġ ã�� (�ʷϻ����� �ٲٷ���)
	D3DVERTEXELEMENT9 decl[MAX_FVF_DECL_SIZE];
	ZeroMemory(decl, sizeof(D3DVERTEXELEMENT9) * MAX_FVF_DECL_SIZE);

	pMesh->GetDeclaration(decl);

	BYTE offset = 0;
	for (int i = 0; i < MAX_FVF_DECL_SIZE; i++)
	{
		if (decl[i].Usage == D3DDECLUSAGE_COLOR)
		{
			offset = (BYTE)decl[i].Offset;
			break;
		}
	}
	int vertexCount = pMesh->GetNumVertices();
	int vertexSize = D3DXGetFVFVertexSize(m_dwFVF);
	for (int i = 0; i < vertexCount; ++i)
	{
		DWORD* pColor = ((DWORD*)(((BYTE*)pVertex) + (i * vertexSize + offset)));
		*pColor = color;
	}

	pMesh->UnlockVertexBuffer();

	return;
}

Engine::CObjSphere* Engine::CObjSphere::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CObjSphere* pInstance = new CObjSphere(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

CComponent* CObjSphere::Clone(void)
{
	return new CObjSphere(*this);
}

void Engine::CObjSphere::Free(void)
{
	CVIBuffer::Free();
}
