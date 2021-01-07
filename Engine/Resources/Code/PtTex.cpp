#include "PtTex.h"

USING(Engine)
Engine::CPtTex::CPtTex(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
	, m_pDecl(nullptr)
	, m_pVBTransform(nullptr)
{

}

Engine::CPtTex::CPtTex(const CPtTex& rhs)
	: CVIBuffer(rhs)
	, m_pDecl(rhs.m_pDecl)
	, m_pVBTransform(rhs.m_pVBTransform)
{
	Safe_AddRef(m_pDecl);
	Safe_AddRef(m_pVBTransform);
}

Engine::CPtTex::~CPtTex(void)
{

}

HRESULT Engine::CPtTex::Ready_Buffer(void)
{
	m_dwFVF = 0;
	m_dwTriCnt = 1;
	m_dwVtxCnt = 3;
	m_dwVtxSize = sizeof(VTXPTTEX);

	m_dwIdxSize = sizeof(INDEX16);
	m_IdxFmt = D3DFMT_INDEX16;

	FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	VTXPTTEX*		pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);
	
	// ������ ��
	pVertex[0].vPos = _vec3(0.f, 0.f, 0.f);
	pVertex[0].fPSize = 1.f;
	pVertex[0].vTexUV = _vec2(0.f, 0.f);

	pVertex[1].vPos = _vec3(0.f, 0.f, 0.f);
	pVertex[1].fPSize = 1.f;
	pVertex[1].vTexUV = _vec2(0.f, 0.f);

	pVertex[2].vPos = _vec3(0.f, 0.f, 0.f);
	pVertex[2].fPSize = 1.f;
	pVertex[2].vTexUV = _vec2(0.f, 0.f);
	
	m_pVB->Unlock();

	FAILED_CHECK_RETURN(m_pGraphicDev->CreateVertexBuffer(sizeof(VTXMATRIX) * m_dwVtxCnt,
						0, // �������۷� �Ҵ��ϰڴٴ� �ɼ�
						0,
						D3DPOOL_MANAGED,
						&m_pVBTransform,
						NULL),
						E_FAIL);

	D3DXMATRIX		matPivot;
	D3DXMatrixIdentity(&matPivot);

	VTXMATRIX*		pVtxMatrix = NULL;

	m_pVBTransform->Lock(0, 0, (void**)&pVtxMatrix, 0);

	// 0�� ��ƼŬ
	pVtxMatrix[0].vRight = *(_vec4*)&matPivot.m[0][0];
	pVtxMatrix[0].vUp = *(_vec4*)&matPivot.m[1][0];
	pVtxMatrix[0].vLook = *(_vec4*)&matPivot.m[2][0];
	pVtxMatrix[0].vPosition = *(_vec4*)&matPivot.m[3][0];

	D3DXMatrixTranslation(&matPivot, 0.f, 0.f, 2.f);

	// 1�� ��ƼŬ
	pVtxMatrix[1].vRight = *(_vec4*)&matPivot.m[0][0];
	pVtxMatrix[1].vUp = *(_vec4*)&matPivot.m[1][0];
	pVtxMatrix[1].vLook = *(_vec4*)&matPivot.m[2][0];
	pVtxMatrix[1].vPosition = *(_vec4*)&matPivot.m[3][0];

	D3DXMatrixTranslation(&matPivot, 0.f, 0.f, 4.f);

	// 2�� ��ƼŬ
	pVtxMatrix[2].vRight = *(_vec4*)&matPivot.m[0][0];
	pVtxMatrix[2].vUp = *(_vec4*)&matPivot.m[1][0];
	pVtxMatrix[2].vLook = *(_vec4*)&matPivot.m[2][0];
	pVtxMatrix[2].vPosition = *(_vec4*)&matPivot.m[3][0];
	
	m_pVBTransform->Unlock();

	D3DVERTEXELEMENT9			Element[MAX_FVF_DECL_SIZE] = {
		// 0�� ��Ʈ���� ����ϴ� ���ؽ��� ���� ������
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0		},
		{ 0, 12, D3DDECLTYPE_FLOAT1, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_PSIZE, 0		},
		{ 0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0	},

		// 1�� ��Ʈ���� ����ϴ� ���ؽ��� ���� ������
		{ 1, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 1 },
		{ 1, 16, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 2 },
		{ 1, 32, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 3 },
		{ 1, 48, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 4 },
		D3DDECL_END()
	};

	if (FAILED(m_pGraphicDev->CreateVertexDeclaration(Element, &m_pDecl)))
		return E_FAIL;
	
	return S_OK;
}


Engine::CPtTex* Engine::CPtTex::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CPtTex*	pInstance = new CPtTex(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

void Engine::CPtTex::Render_Buffer(void)
{
	m_pGraphicDev->SetVertexDeclaration(m_pDecl);

	// ��Ʈ�� ���ļ��� �����ϴ� �Լ�
	//
	m_pGraphicDev->SetStreamSourceFreq(0, 1);	// 2���� :  D3DSTREAMSOURCE_INDEXEDDATA�� �ν��Ͻ��� �ϰ����ϴ� ������ ������ŭ�� OR �����Ͽ� �����ϸ� ������Ʈ���� �ν��Ͻ� ���� �������� ���� �� ����, �׷��� ���������� 1�� ���
	// ��ġ�� ��Ʈ���� �ش� ���۸� ���ε���Ű�� �Լ�
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, m_dwVtxSize);
	// 1���� : �� �� ����(��Ʈ��)�� ������ ���ΰ�
	// 2���� : � ���� �Ѱ��� ���ΰ�
	// 3���� : ��𼭺��� �׸� ���ΰ�
	// 4���� : � ������ ǥ���� ���ΰ�

	m_pGraphicDev->SetStreamSourceFreq(1, 1);	// 2���� :  D3DSTREAMSOURCE_INSTANCEDATA�� �ν��Ͻ��� �ϰ����ϴ� ������ ������ŭ�� OR �����Ͽ� �����ϸ� ������Ʈ���� �ν��Ͻ� ���� �������� ���� �� ����, �׷��� ���������� 1�� ���
	m_pGraphicDev->SetStreamSource(1, m_pVBTransform, 0, sizeof(VTXMATRIX));
		
	m_pGraphicDev->DrawPrimitive(D3DPT_POINTLIST, 0, m_dwVtxCnt);
	
	// �ν��Ͻ� ������ ���� ��Ʈ���� ���� �⺻������ �ٽ� �����ؾ߸� �Ѵ�.
	m_pGraphicDev->SetStreamSourceFreq(0, 1);
	m_pGraphicDev->SetStreamSourceFreq(1, 1);
}

CComponent * CPtTex::Clone(void)
{
	return new CPtTex(*this);
}

void Engine::CPtTex::Free(void)
{
	Safe_Release(m_pVBTransform);
	Safe_Release(m_pDecl);


	CVIBuffer::Free();
}

