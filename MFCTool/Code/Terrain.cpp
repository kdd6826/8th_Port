#include "stdafx.h"
#include "Terrain.h"
#include "Texture_Manager.h"
#include "MFCToolView.h"

CTerrain::CTerrain()
{
}


CTerrain::~CTerrain()
{
	Release_Terrain(); 
}

void CTerrain::TileChange(const _vec3 & vPos, const _int & rDrawID, const _int & rOption)
{
	_int iIndex = Get_TileIndex(vPos); 
	if (-1 == iIndex)
		return; 

	m_vecTile[iIndex]->iDrawID = rDrawID; 
	m_vecTile[iIndex]->iOption = rOption; 
}

_int CTerrain::Get_TileIndex(const _vec3 & vPos)
{
	_int iSize = m_vecTile.size();
	for (size_t i = 0 ; i < iSize; ++i)
	{
		if (IsPicking(vPos, i))
			return i;
	}
	return _int(-1);
}

bool CTerrain::IsPicking(const _vec3 & vPos, const _int & i)
{

	_vec3 vRhombusPoint[4] =
	{
		{m_vecTile[i]->vPos.x, m_vecTile[i]->vPos.y + TILECY * 0.5f, 0.f},
		{ m_vecTile[i]->vPos.x + TILECX * 0.5f, m_vecTile[i]->vPos.y, 0.f },
		{ m_vecTile[i]->vPos.x, m_vecTile[i]->vPos.y - TILECY * 0.5f, 0.f },
		{ m_vecTile[i]->vPos.x - TILECX * 0.5f, m_vecTile[i]->vPos.y, 0.f }
	}; 

	//2. 마름모꼴 정점의 방향벡터 구하기. 
	_vec3 vRhombusDir[4] = 
	{
		vRhombusPoint[1] - vRhombusPoint[0],
		vRhombusPoint[2] - vRhombusPoint[1],
		vRhombusPoint[3] - vRhombusPoint[2],
		vRhombusPoint[0] - vRhombusPoint[3],
	};

	//3. 마름모꼴 방향벡터의 법선백터 뽑아내기. 
	_vec3 vRhombusNormal[4] = 
	{
		{-vRhombusDir[0].y, vRhombusDir[0].x, 0.f},
		{ -vRhombusDir[1].y, vRhombusDir[1].x, 0.f },
		{ -vRhombusDir[2].y, vRhombusDir[2].x, 0.f },
		{ -vRhombusDir[3].y, vRhombusDir[3].x, 0.f }

	}; 
	_vec3 vMouseDir[4] = 
	{
		vPos - vRhombusPoint[0], 
		vPos - vRhombusPoint[1],
		vPos - vRhombusPoint[2],
		vPos - vRhombusPoint[3],
	};

	for (int i = 0 ; i < 4; ++i)
	{
		D3DXVec3Normalize(&vRhombusNormal[i], &vRhombusNormal[i]);
		D3DXVec3Normalize(&vMouseDir[i], &vMouseDir[i]);
		if (0 < D3DXVec3Dot(&vRhombusNormal[i], &vMouseDir[i]))
			return false; 
	}
	return true; 
}

void CTerrain::Set_Ratio(_matrix & matWorld, const float & fRatioX, const float & fRatioY)
{
	matWorld._11 *= fRatioX;
	matWorld._21 *= fRatioX;
	matWorld._31 *= fRatioX;
	matWorld._41 *= fRatioX;

	matWorld._12 *= fRatioY;
	matWorld._22 *= fRatioY;
	matWorld._32 *= fRatioY;
	matWorld._42 *= fRatioY;

}

HRESULT CTerrain::Ready_Terrain()
{
	TILE* pTile = nullptr; 
	m_vecTile.reserve(TILEX * TILEY);
	float fX = 0.f, fY = 0.f; 
	for (int i = 0 ; i < TILEY; ++i)
	{
		for (int j = 0 ; j < TILEX; ++j)
		{
			pTile = new TILE; 
			
			fX = static_cast<float>((TILECX * j) + ((i % 2) * (TILECX >> 1)));
			fY = static_cast<float>((TILECY >> 1) * i);
			pTile->vPos = _vec3(fX, fY, 0.f);
			pTile->vSize = _vec3(1.f, 1.f, 0.f); 
			pTile->iIndex = j + (i * TILEX); 
			pTile->iParentIndex = 0; 
			pTile->iDrawID = 24; 
			pTile->iOption = 0;
			m_vecTile.emplace_back(pTile);
		}
	}
	return S_OK;
}

void CTerrain::MiniRender_Terrain()
{
	for (auto& pTile : m_vecTile)
	{
		const TEXINFO* pTexInfo = CTexture_Manager::GetInstance()->Get_TexInfo(L"Terrain", L"Tile", pTile->iDrawID);
		if (nullptr == pTexInfo)
			return;
		float fCenterX = float(pTexInfo->tImageInfo.Width >> 1);
		float fCenterY = float(pTexInfo->tImageInfo.Height >> 1);

		_matrix matScale, matTrans, matWorld;
		D3DXMatrixScaling(&matScale, pTile->vSize.x, pTile->vSize.y, 0.f);
		D3DXMatrixTranslation(&matTrans, pTile->vPos.x - m_pView->GetScrollPos(0), pTile->vPos.y - m_pView->GetScrollPos(1), 0.f);
		matWorld = matScale * matTrans;
		Set_Ratio(matWorld, 0.3f, 0.5f); 
		CGraphic_Device::GetInstance()->Get_Sprite()->SetTransform(&matWorld);
		CGraphic_Device::GetInstance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &_vec3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}

void CTerrain::Render_Terrain()
{
	TCHAR szBuf[MAX_PATH] = L""; 
	int iIndex = 0; 
	for (auto& pTile : m_vecTile)
	{
		const TEXINFO* pTexInfo = CTexture_Manager::GetInstance()->Get_TexInfo(L"Terrain", L"Tile", pTile->iDrawID);
		if (nullptr == pTexInfo)
			return;
		float fCenterX = float(pTexInfo->tImageInfo.Width >> 1);
		float fCenterY = float(pTexInfo->tImageInfo.Height >> 1);

		_matrix matScale, matTrans, matWorld; 
		D3DXMatrixScaling(&matScale, pTile->vSize.x, pTile->vSize.y, 0.f); 
		D3DXMatrixTranslation(&matTrans, pTile->vPos.x - m_pView->GetScrollPos(0), pTile->vPos.y - m_pView->GetScrollPos(1), 0.f); 
		matWorld = matScale * matTrans; 
		swprintf_s(szBuf, L"%d", iIndex); 
		++iIndex; 
		CGraphic_Device::GetInstance()->Get_Sprite()->SetTransform(&matWorld); 
		CGraphic_Device::GetInstance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &_vec3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
		CGraphic_Device::GetInstance()->Get_Sprite()->SetTransform(&matTrans);
		CGraphic_Device::GetInstance()->Get_Font()->DrawTextW(CGraphic_Device::GetInstance()->Get_Sprite(), szBuf, lstrlen(szBuf), nullptr, 0, D3DCOLOR_ARGB(255, 0, 0, 0));
	}
}

void CTerrain::Release_Terrain()
{
	for (auto& pTile : m_vecTile)
		Safe_Delete(pTile); 

	m_vecTile.clear(); 
	m_vecTile.shrink_to_fit(); 
}
