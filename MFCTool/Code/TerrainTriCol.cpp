#include "stdafx.h"
#include "TerrainTriCol.h"

CTerrainTriCol::CTerrainTriCol(LPDIRECT3DDEVICE9 pGraphicDev)
	//: Engine::CVIBuffer(pGraphicDev)
{

}

//CTerrainTriCol::CTerrainTriCol(const CTerrainTriCol& rhs)
	//: Engine::CVIBuffer(rhs)
//{

//}

CTerrainTriCol::~CTerrainTriCol(void)
{

}

//HRESULT CTerrainTriCol::Ready_Buffer(_vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
//	, D3DXCOLOR VtxCol1, D3DXCOLOR VtxCol2, D3DXCOLOR VtxCol3)
//{
	//m_dwFVF = FVF_COL;
	//m_dwTriCnt = 1;
	//m_dwVtxCnt = 3;
	//m_dwVtxSize = sizeof(VTXCOL);

	//m_dwIdxSize = sizeof(INDEX16);
	//m_IdxFmt = D3DFMT_INDEX16;

	//FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	//VTXCOL*		pVertex = NULL;

	//m_pVB->Lock(0, 0, (void**)&pVertex, NULL);
	//// 1인자 : 어디서부터 잠글 것인가
	//// 2인자 : 숫자가 0이면 전체 영역을 잠근다.
	//// 3인자 : 인자값을 통해서 버텍스 버퍼 내 정점 중 첫번째 주소를 얻어온다.
	//// 4인자 : 잠그는 형태를 묻는 인자, 정적 버퍼인 경우 0

	//pVertex[0].vPos = VtxPos1;
	//pVertex[0].dwColor = VtxCol1;

	//pVertex[1].vPos = VtxPos2;
	//pVertex[1].dwColor = VtxCol2;

	//pVertex[2].vPos = VtxPos3;
	//pVertex[2].dwColor = VtxCol3;

	//m_pVB->Unlock();

	//INDEX16*		pIndex = nullptr;

	//m_pIB->Lock(0, 0, (void**)&pIndex, 0);

	//pIndex[0]._0 = 0;
	//pIndex[0]._1 = 1;
	//pIndex[0]._2 = 2;

	//m_pIB->Unlock();


//	return S_OK;
//}


//CTerrainTriCol* CTerrainTriCol::Create(LPDIRECT3DDEVICE9 pGraphicDev, _vec3 VtxPos1, _vec3 VtxPos2, _vec3 VtxPos3
//	, D3DXCOLOR VtxCol1, D3DXCOLOR VtxCol2, D3DXCOLOR VtxCol3)
//{
	//CTerrainTriCol*	pInstance = new CTerrainTriCol(pGraphicDev);

	//if (FAILED(pInstance->Ready_Buffer(VtxPos1, VtxPos2, VtxPos3, VtxCol1, VtxCol2, VtxCol3)))
	//	Engine::Safe_Release(pInstance);

	//return pInstance;
//	return nullptr;
//}

//void CTerrainTriCol::Free(void)
//{
	//CVIBuffer::Free();
//}

//Engine::CComponent* Engine::CTerrainTriCol::Clone(void)
//{
	//return new CTerrainTriCol(*this);
	//return nullptr;
//}

