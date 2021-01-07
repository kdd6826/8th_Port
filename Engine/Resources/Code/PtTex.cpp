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
	
	// 오른쪽 위
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
						0, // 정적버퍼로 할당하겠다는 옵션
						0,
						D3DPOOL_MANAGED,
						&m_pVBTransform,
						NULL),
						E_FAIL);

	D3DXMATRIX		matPivot;
	D3DXMatrixIdentity(&matPivot);

	VTXMATRIX*		pVtxMatrix = NULL;

	m_pVBTransform->Lock(0, 0, (void**)&pVtxMatrix, 0);

	// 0번 파티클
	pVtxMatrix[0].vRight = *(_vec4*)&matPivot.m[0][0];
	pVtxMatrix[0].vUp = *(_vec4*)&matPivot.m[1][0];
	pVtxMatrix[0].vLook = *(_vec4*)&matPivot.m[2][0];
	pVtxMatrix[0].vPosition = *(_vec4*)&matPivot.m[3][0];

	D3DXMatrixTranslation(&matPivot, 0.f, 0.f, 2.f);

	// 1번 파티클
	pVtxMatrix[1].vRight = *(_vec4*)&matPivot.m[0][0];
	pVtxMatrix[1].vUp = *(_vec4*)&matPivot.m[1][0];
	pVtxMatrix[1].vLook = *(_vec4*)&matPivot.m[2][0];
	pVtxMatrix[1].vPosition = *(_vec4*)&matPivot.m[3][0];

	D3DXMatrixTranslation(&matPivot, 0.f, 0.f, 4.f);

	// 2번 파티클
	pVtxMatrix[2].vRight = *(_vec4*)&matPivot.m[0][0];
	pVtxMatrix[2].vUp = *(_vec4*)&matPivot.m[1][0];
	pVtxMatrix[2].vLook = *(_vec4*)&matPivot.m[2][0];
	pVtxMatrix[2].vPosition = *(_vec4*)&matPivot.m[3][0];
	
	m_pVBTransform->Unlock();

	D3DVERTEXELEMENT9			Element[MAX_FVF_DECL_SIZE] = {
		// 0번 스트림을 사용하는 버텍스의 구성 데이터
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0		},
		{ 0, 12, D3DDECLTYPE_FLOAT1, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_PSIZE, 0		},
		{ 0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0	},

		// 1번 스트림을 사용하는 버텍스의 구성 데이터
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

	// 스트림 주파수를 지정하는 함수
	//
	m_pGraphicDev->SetStreamSourceFreq(0, 1);	// 2인자 :  D3DSTREAMSOURCE_INDEXEDDATA와 인스턴싱을 하고자하는 버퍼의 개수만큼을 OR 연산하여 설정하면 지오메트리의 인스턴스 값이 논리적으로 결정 및 결합, 그러나 보편적으로 1을 사용
	// 장치의 스트림에 해당 버퍼를 바인딩시키는 함수
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, m_dwVtxSize);
	// 1인자 : 몇 번 슬롯(스트림)에 보관할 것인가
	// 2인자 : 어떤 것을 넘겨줄 것인가
	// 3인자 : 어디서부터 그릴 것인가
	// 4인자 : 어떤 단위로 표현할 것인가

	m_pGraphicDev->SetStreamSourceFreq(1, 1);	// 2인자 :  D3DSTREAMSOURCE_INSTANCEDATA와 인스턴싱을 하고자하는 버퍼의 개수만큼을 OR 연산하여 설정하면 지오메트리의 인스턴스 값이 논리적으로 결정 및 결합, 그러나 보편적으로 1을 사용
	m_pGraphicDev->SetStreamSource(1, m_pVBTransform, 0, sizeof(VTXMATRIX));
		
	m_pGraphicDev->DrawPrimitive(D3DPT_POINTLIST, 0, m_dwVtxCnt);
	
	// 인스턴스 렌더링 이후 스트림이 지닌 기본값으로 다시 설정해야만 한다.
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

