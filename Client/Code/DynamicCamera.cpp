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
	m_vOffset = {0.f,1.f,0.f};
	m_fAngle = 0.f;
	m_fRadius = 2.05f;
	originRadian = m_fRadius;
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
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fRadius += 5.f* Engine::Get_TimeDelta(L"Timer_Immediate");
		 
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fRadius -= 5.f * Engine::Get_TimeDelta(L"Timer_Immediate");
	}

	if (Engine::Get_DIKeyState(DIK_7) & 0x80)
		Shake();


	_matrix			matCamWorld;
	D3DXMatrixInverse(&matCamWorld, NULL, &m_matView);

	Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	_vec3 playerLook, playerPos, playerScale, dst, playerDir , dir;

	pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook);
	pPlayerTransCom->Get_Info(Engine::INFO_POS, &playerPos);
	playerDir = pPlayerTransCom->Get_Dir();

	playerScale = pPlayerTransCom->m_vScale;
	if (Engine::Get_DIKeyState(DIK_9) & 0x80)
	{
		isFree = true;
	}
	if (Engine::Get_DIKeyState(DIK_8) & 0x80)
	{
		isFree = false;
	}
	/// ////////////
	if (!isFree)
	{
		_vec3 local;
		_matrix matLocal, rotY, matTrans;

		local = m_vOffset;

		//local.x += m_fRadius;
		local.z += -m_fRadius;
		D3DXMatrixTranslation(&matTrans, local.x, local.y, local.z);

		D3DXMatrixRotationY(&rotY, m_fAngle);
		matLocal = matTrans * rotY;
		memcpy(&local, matLocal.m[3], sizeof(_vec3));

		m_vEye = local + playerPos;
		//m_vEye.y += eyeOffSet;

		dir = playerPos - m_vEye;
		dir.y = 0;
		D3DXVec3Normalize(&dir, &dir);

		//m_vAt = playerPos;
		m_vAt = playerPos + dir * 20.f;
	}
	//
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

	POINT	ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	POINT	ptCenter{ WINCX >> 1, WINCY >> 1 };

	float Sensitivity = 3.f;
	//왼
	if (ptCenter.x - ptMouse.x > 0)
	{
		m_fAngle += Sensitivity * D3DXToRadian(ptCenter.x - ptMouse.x) * Engine::Get_TimeDelta(L"Timer_Immediate");
	}
	//오
	if (ptCenter.x - ptMouse.x < 0)
	{
		m_fAngle += Sensitivity * D3DXToRadian(ptCenter.x - ptMouse.x) * Engine::Get_TimeDelta(L"Timer_Immediate");
	}

	//위
	if (ptCenter.y - ptMouse.y > 0)
	{
		if (eyeOffSet < 1.f)
		{
			eyeOffSet += Sensitivity * D3DXToRadian(ptCenter.y - ptMouse.y) * Engine::Get_TimeDelta(L"Timer_Immediate");
			
		}
	}
	//아래
	if (ptCenter.y - ptMouse.y < 0)
	{
		if (eyeOffSet > -0.5f)
		eyeOffSet += Sensitivity * D3DXToRadian(ptCenter.y - ptMouse.y) * Engine::Get_TimeDelta(L"Timer_Immediate");
	}

	//Engine::CTransform* pPlayerTransCom = dynamic_cast<Engine::CTransform*>(Engine::Get_Component(L"GameLogic", L"Player", L"Com_Transform", Engine::ID_DYNAMIC));
	//_vec3 playerLook, playerPos, playerScale, dst, playerDir, dir;

	//pPlayerTransCom->Get_Info(Engine::INFO_LOOK, &playerLook);
	//pPlayerTransCom->Get_Info(Engine::INFO_POS, &playerPos);
	//


	//_long	dwMouseMove = 0;
	//// 마우스를 위아래로 움직일 때
	//if (dwMouseMove = Engine::Get_DIMouseMove(Engine::DIMS_Y))
	//{
	//	_vec3		vRight;
	//	memcpy(&vRight, &matCamWorld.m[0][0], sizeof(_vec3));

	//	_vec3	vLook = m_vAt - m_vEye;
	//	_matrix		matRot;
	//	D3DXMatrixRotationAxis(&matRot, &vRight, D3DXToRadian(dwMouseMove / 10.f));

	//	D3DXVec3TransformNormal(&vLook, &vLook, &matRot);

	//	m_vAt = m_vEye + vLook;
	//}

	//if (dwMouseMove = Engine::Get_DIMouseMove(Engine::DIMS_X))
	//{
	//	_vec3		vUp = _vec3(0.f, 1.f, 0.f);

	//	_vec3	vLook = m_vAt - m_vEye;
	//	_matrix		matRot;
	//	D3DXMatrixRotationAxis(&matRot, &vUp, D3DXToRadian(dwMouseMove / 10.f));

	//	D3DXVec3TransformNormal(&vLook, &vLook, &matRot);

	//	m_vAt = m_vEye + vLook;
	//}

	
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
	UpdateShake();
	UpdateZoomIn();
	if (true == m_bFix)
	{
		Mouse_Move();
		Mouse_Fix();
	}
	
	_int iExit = Engine::CCamera::Update_Object(fTimeDelta);
	
	return iExit;
}

void CDynamicCamera::UpdateShake()
{
	if (isShake)
	{
		float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
		shakeDuration -= timeDelta;

		if (0 >= shakeDuration)
		{
			isShake = false;
			Set_Eye(originCamPos);
			//m_pTransformCom->Set_Pos(&originCamPos);
			shakeDuration = 0.f;
			return;
		}
		
		int iMin = (int)(-1 * 100);
		int iMax = (int)(1 * 100);
		int range = iMax - iMin + 1;
		int random = rand() % range;
		float fRandom = random / 100.f + -1;

		float ranX = fRandom;
		float ranY = fRandom;
		float ranZ = fRandom;

		_vec3 randVec = { ranX, ranY, ranZ };
		_vec3 myPos =Get_Eye();
		
		if (nullptr == this)
			Set_Eye((originCamPos + (randVec * shakeMagnitude)));
		else
			Set_Eye((myPos + (randVec * shakeMagnitude)));
	}

}

void CDynamicCamera::UpdateZoomIn()
{
	float timeDelta = Engine::Get_TimeDelta(L"Timer_Immediate");
	if (isZoom)
	{
		zoomDuration -= timeDelta;

		if (0 >= zoomDuration)
		{
			isZoom = false;
			//m_fRadius = originRadian;
			//m_pTransformCom->Set_Pos(&originCamPos);
			zoomDuration = 0.f;
			return;
		}

		int iMin = (int)(-1 * 100);
		int iMax = (int)(1 * 100);
		int range = iMax - iMin + 1;
		int random = rand() % range;
		float fRandom = random / 100.f + -1;

		float ranX = fRandom;
		float ranY = fRandom;
		float ranZ = fRandom;

		_vec3 randVec = { ranX, ranY, ranZ };
		_vec3 myPos = Get_Eye();

		if (nullptr == this)
		{
			if (originRadian - zoomMagnitude < m_fRadius)
				m_fRadius -= (zoomMagnitude)*timeDelta*5.f;
		}
		else
		{
			if (originRadian - zoomMagnitude < m_fRadius)
				m_fRadius -= (zoomMagnitude)*timeDelta * 5.f;
		}
	}
	else if (!isZoom)
	{
		if (originRadian > m_fRadius)
		{
			m_fRadius += 2.f * timeDelta;
		}
		else
		{
			m_fRadius = originRadian;
		}
	}
}

void CDynamicCamera::Shake(float _duration, float _magnitude)
{
	isShake = true;
	shakeDuration = _duration;
	shakeMagnitude = _magnitude;
	originCamPos = Get_Eye();
	
}

void CDynamicCamera::ZoomIn(float _duration, float _magnitude)
{
	isZoom = true;
	zoomDuration = _duration;
	zoomMagnitude = _magnitude;
	//originRadian = m_fRadius;
}
