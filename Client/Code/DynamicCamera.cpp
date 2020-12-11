#include "stdafx.h"
#include "DynamicCamera.h"
#include "Export_Function.h"

CDynamicCamera::CDynamicCamera(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CCamera(pGraphicDev)	
{

}

CDynamicCamera::~CDynamicCamera(void)
{

}

HRESULT Client::CDynamicCamera::Ready_Object(const _vec3* pEye, const _vec3* pAt, const _vec3* pUp, const _float& fFovY, const _float& fAspect, const _float& fNear, const _float& fFar)
{
	m_vEye = *pEye;
	m_vAt = *pAt;
	m_vUp = *pUp;
	m_fFovY = fFovY;
	m_fAspect = fAspect;
	m_fNear = fNear;
	m_fFar = fFar;

	FAILED_CHECK_RETURN(Engine::CCamera::Ready_Object(), E_FAIL);
	FAILED_CHECK_RETURN(Add_Component(), E_FAIL);

	return S_OK;
}

Client::CDynamicCamera* Client::CDynamicCamera::Create(LPDIRECT3DDEVICE9 pGraphicDev,
	const _vec3* pEye, const _vec3* pAt, const _vec3* pUp, 
	const _float& fFovY, const _float& fAspect, const _float& fNear, const _float& fFar)
{
	CDynamicCamera*	pInstance = new CDynamicCamera(pGraphicDev);

	if (FAILED(pInstance->Ready_Object(pEye, pAt, pUp, fFovY, fAspect, fNear, fFar)))
		Client::Safe_Release(pInstance);

	return pInstance;
}

HRESULT CDynamicCamera::Add_Component(void)
{
	Engine::CComponent* pComponent = nullptr;
	// Transform
	pComponent = m_pTransformCom = dynamic_cast<Engine::CTransform*>(Engine::Clone(L"Proto_Transform"));
	NULL_CHECK_RETURN(pComponent, E_FAIL);
	m_mapComponent[Engine::ID_DYNAMIC].emplace(L"Com_Transform", pComponent);

	return S_OK;
}

void Client::CDynamicCamera::Key_Input(const _float& fTimeDelta)
{
	_matrix			matCamWorld;
	D3DXMatrixInverse(&matCamWorld, NULL, &m_matView);

	
	/// ///////////////
	
	
	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 playerLook, playerPos, playerScale, dst, dir;

	pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook);
	pPlayerTransCom->Get_Info(Engine::INFO_POS, &playerPos);
	playerScale = pPlayerTransCom->m_vScale;


	if (isSlowChase)
	{

		dst = playerPos - (playerLook * playerScale.y * 6.f);
		dst.y += playerScale.y * 5.f;

		dir = dst - m_vEye;

		float distance = D3DXVec3Length(&dir);
		if (0.1f > distance)
		{
			int i = 0;
		}
		else
		{

			D3DXVec3Normalize(&dir, &dir);

			float speed = 10.f;

			m_vEye += dir * fTimeDelta * (speed + slowTime);

			slowTime += fTimeDelta;

			//transform->look = target->GetTransform()->position;
			m_vAt = playerPos + (playerLook * 10.f);
		}

	}
	else
	{
	
		m_vEye = playerPos - (playerLook * playerScale.y * 20000.f);
	//transform->position.y += 1.f;
		m_vEye.y += playerScale.y * 100.f;

		m_vAt = playerPos + (playerLook * 1000.f);
	}
	//m_pTransformCom->Chase_Target(&playerPos,2.f,fTimeDelta);

	//m_vAt = playerLook;
	//m_vEye = playerPos;

	if (Engine::Get_DIKeyState(DIK_W) & 0x80)
	{
		_vec3		vLook;
		memcpy(vLook, &matCamWorld.m[2][0], sizeof(_vec3));

		_vec3	vLength = *D3DXVec3Normalize(&vLook, &vLook) * 5.f * fTimeDelta;

		m_vEye += vLength;
		m_vAt += vLength;
	}

	//if (Engine::Get_DIKeyState(DIK_S) & 0x80)
	//{
	//	_vec3		vLook;
	//	memcpy(vLook, &matCamWorld.m[2][0], sizeof(_vec3));

	//	_vec3	vLength = *D3DXVec3Normalize(&vLook, &vLook) * 5.f * fTimeDelta;

	//	m_vEye -= vLength;
	//	m_vAt -= vLength;
	//}

	//if (Engine::Get_DIKeyState(DIK_A) & 0x80)
	//{
	//	_vec3		vRight;
	//	memcpy(vRight, &matCamWorld.m[0][0], sizeof(_vec3));

	//	_vec3	vLength = *D3DXVec3Normalize(&vRight, &vRight) * 5.f * fTimeDelta;

	//	m_vEye -= vLength;
	//	m_vAt -= vLength;
	//}

	//if (Engine::Get_DIKeyState(DIK_D) & 0x80)
	//{
	//	_vec3		vRight;
	//	memcpy(vRight, &matCamWorld.m[0][0], sizeof(_vec3));

	//	_vec3	vLength = *D3DXVec3Normalize(&vRight, &vRight) * 5.f * fTimeDelta;

	//	m_vEye += vLength;
	//	m_vAt += vLength;
	//}
	
	if (Engine::Get_DIKeyState(DIK_LCONTROL) & 0x80)
	{
		if (true == m_bClick)
			return;

		m_bClick = true;

		if (true == m_bFix)
			m_bFix = false;

		else
			m_bFix = true;
	}
	else
		m_bClick = false;

	if (false == m_bFix)
		return;
}

void Client::CDynamicCamera::Mouse_Move(void)
{
	_matrix			matCamWorld;
	D3DXMatrixInverse(&matCamWorld, NULL, &m_matView);

	_long	dwMouseMove = 0;
	// 마우스를 위아래로 움직일 때
	if (dwMouseMove = Engine::Get_DIMouseMove(Engine::DIMS_Y))
	{
		_vec3		vRight;
		memcpy(&vRight, &matCamWorld.m[0][0], sizeof(_vec3));

		_vec3	vLook = m_vAt - m_vEye;
		_matrix		matRot;
		D3DXMatrixRotationAxis(&matRot, &vRight, D3DXToRadian(dwMouseMove / 10.f));

		D3DXVec3TransformNormal(&vLook, &vLook, &matRot);

		m_vAt = m_vEye + vLook;
	}

	if (dwMouseMove = Engine::Get_DIMouseMove(Engine::DIMS_X))
	{
		_vec3		vUp = _vec3(0.f, 1.f, 0.f);
		
		_vec3	vLook = m_vAt - m_vEye;
		_matrix		matRot;
		D3DXMatrixRotationAxis(&matRot, &vUp, D3DXToRadian(dwMouseMove / 10.f));

		D3DXVec3TransformNormal(&vLook, &vLook, &matRot);

		m_vAt = m_vEye + vLook;
	}

	
}

void Client::CDynamicCamera::Mouse_Fix(void)
{
	POINT	ptMouse{ WINCX >> 1, WINCY >> 1 };
	ClientToScreen(g_hWnd, &ptMouse);
	SetCursorPos(ptMouse.x, ptMouse.y);

}

void CDynamicCamera::Free(void)
{
	Engine::CCamera::Free();
}

Client::_int Client::CDynamicCamera::Update_Object(const _float& fTimeDelta)
{
	Key_Input(fTimeDelta);

	if (true == m_bFix)
	{
		Mouse_Fix();
		Mouse_Move();
	}
	
	_int iExit = Engine::CCamera::Update_Object(fTimeDelta);
	
	return iExit;
}
