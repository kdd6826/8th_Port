#include "DynamicMesh.h"

USING(Engine)

Engine::CDynamicMesh::CDynamicMesh(LPDIRECT3DDEVICE9 pGraphicDev)
	: CMesh(pGraphicDev)
	,  m_pLoader(nullptr)
	, m_pRootFrame(nullptr)
{

}

Engine::CDynamicMesh::CDynamicMesh(const CDynamicMesh& rhs)
	: CMesh(rhs)
	, m_pRootFrame(rhs.m_pRootFrame)
	, m_pLoader(rhs.m_pLoader)
	, m_MeshContainerList(rhs.m_MeshContainerList)
{

}

Engine::CDynamicMesh::~CDynamicMesh(void)
{

}

HRESULT Engine::CDynamicMesh::Ready_Meshes(const _tchar* pFilePath, const _tchar* pFileName)
{
	_tchar		szFullPath[MAX_PATH] = L"";

	lstrcpy(szFullPath, pFilePath);
	lstrcat(szFullPath, pFileName);

	m_pLoader = CHierarchyLoader::Create(m_pGraphicDev, pFilePath);
	NULL_CHECK_RETURN(m_pLoader, E_FAIL);

	if (FAILED(D3DXLoadMeshHierarchyFromX(szFullPath,
		D3DXMESH_MANAGED,
		m_pGraphicDev,
		m_pLoader,	// HierarchyLoader
		NULL, 
		&m_pRootFrame,
		NULL))) // AniCtrl
		return E_FAIL;

	_matrix matTemp;

	Update_FrameMatrices((D3DXFRAME_DERIVED*)m_pRootFrame, D3DXMatrixIdentity(&matTemp));
	SetUp_FrameMatricesPointer((D3DXFRAME_DERIVED*)m_pRootFrame);

	return S_OK;
}

void Engine::CDynamicMesh::Render_Meshes(void)
{
	for (auto& iter : m_MeshContainerList)
	{
		D3DXMESHCONTAINER_DERIVED* pDerivedMeshContainer = iter;

		for (_ulong i = 0; i < pDerivedMeshContainer->dwNumBones; ++i)
		{
			pDerivedMeshContainer->pRenderingMatrix[i] = pDerivedMeshContainer->pFrameOffsetMatrix[i] 
														* (*pDerivedMeshContainer->ppFrameCombinedMatrix[i]);

			void*		pSrcVtx = nullptr;
			void*		pDestVtx = nullptr;

			pDerivedMeshContainer->pOriMesh->LockVertexBuffer(0, &pSrcVtx);
			pDerivedMeshContainer->MeshData.pMesh->LockVertexBuffer(0, &pDestVtx);

			pDerivedMeshContainer->pSkinInfo->UpdateSkinnedMesh(pDerivedMeshContainer->pRenderingMatrix, NULL, pSrcVtx, pDestVtx);
			// 소프트 웨어 스키닝을 수행하는 함수(스키닝 뿐 아니라 애니메이션 변경 시, 뼈대들의 정점 정보들의 변경도 동시에 수행)
			// 1인자 : 뼈의 최종적인 변환 상태
			// 2인자 : 원래대로 돌리기 위한 역행렬(굳이 안넣어줘도 된다)
			// 3인자 : 변하지 않는 원본 메쉬의 정점 정보
			// 4인자 : 변환된 정보를 담아두고 있는 메쉬의 정점 정보
			
			pDerivedMeshContainer->pOriMesh->UnlockVertexBuffer();
			pDerivedMeshContainer->MeshData.pMesh->UnlockVertexBuffer();
		}

	}
}

void Engine::CDynamicMesh::Update_FrameMatrices(D3DXFRAME_DERIVED* pFrame, const _matrix* pParentMatrix)
{
	if (nullptr == pFrame)
		return;

	pFrame->CombinedTransformationMatrix = pFrame->TransformationMatrix * (*pParentMatrix);

	if (nullptr != pFrame->pFrameSibling)
		Update_FrameMatrices((D3DXFRAME_DERIVED*)pFrame->pFrameSibling, pParentMatrix);

	if (nullptr != pFrame->pFrameFirstChild)
		Update_FrameMatrices((D3DXFRAME_DERIVED*)pFrame->pFrameFirstChild, &pFrame->CombinedTransformationMatrix);

}

void CDynamicMesh::SetUp_FrameMatricesPointer(D3DXFRAME_DERIVED * pFrame)
{
	if (nullptr != pFrame->pMeshContainer)
	{
		D3DXMESHCONTAINER_DERIVED* pDerivedMeshContainer = (D3DXMESHCONTAINER_DERIVED*)pFrame->pMeshContainer;

		for (_ulong i = 0; i < pDerivedMeshContainer->dwNumBones; ++i)
		{
			const char*		pBoneName = pDerivedMeshContainer->pSkinInfo->GetBoneName(i);
			D3DXFRAME_DERIVED*	 pDerivedFrame = (D3DXFRAME_DERIVED*)D3DXFrameFind(m_pRootFrame, pBoneName);

			pDerivedMeshContainer->ppFrameCombinedMatrix[i] = &pDerivedFrame->CombinedTransformationMatrix;
		}
		
		m_MeshContainerList.push_back(pDerivedMeshContainer);
	}

	if (nullptr != pFrame->pFrameSibling)
		SetUp_FrameMatricesPointer((D3DXFRAME_DERIVED*)pFrame->pFrameSibling);

	if (nullptr != pFrame->pFrameFirstChild)
		SetUp_FrameMatricesPointer((D3DXFRAME_DERIVED*)pFrame->pFrameFirstChild);

}

Engine::CDynamicMesh* Engine::CDynamicMesh::Create(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pFilePath, const _tchar* pFileName)
{
	CDynamicMesh*	pInstance = new CDynamicMesh(pGraphicDev);

	if (FAILED(pInstance->Ready_Meshes(pFilePath, pFileName)))
		Safe_Release(pInstance);

	return pInstance;
}

Engine::CComponent* Engine::CDynamicMesh::Clone(void)
{
	return new CDynamicMesh(*this);
}

void Engine::CDynamicMesh::Free(void)
{
	CMesh::Free();

	if (false == m_bClone)
	{
		m_pLoader->DestroyFrame(m_pRootFrame);
		Safe_Release(m_pLoader);
	}
	m_MeshContainerList.clear();

}

