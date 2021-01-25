#ifndef DynamicCamera_h__
#define DynamicCamera_h__

#include "Camera.h"
#include "Define.h"
BEGIN(Engine)


class CTransform;
END
BEGIN(Client)
class CDynamicCamera : public Engine::CCamera
{
public:

private:
	explicit CDynamicCamera(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDynamicCamera(void);

public:
	HRESULT Ready_Object(const _vec3* pEye, const _vec3* pAt, const _vec3* pUp,	
						 const _float& fFovY, const _float& fAspect, const _float& fNear,	const _float& fFar );

	virtual _int Update_Object(const _float& fTimeDelta) override;
	void UpdateShake();
	void UpdateZoomIn();
	void Shake(float _duration = 0.05f, float _magnitude = 0.03f);
	//시간, 확대치
	void ZoomIn(float _duration = 0.05f, float _magnitude = 0.03f);
private:

	HRESULT		Add_Component(void);
	void		Key_Input(const _float& fTimeDelta);
	void		Mouse_Move(void);
	void		Mouse_Fix(void);

private:
	bool isFree = false;
	Engine::CTransform* m_pTransformCom = nullptr;
	_bool		m_bClick = false;
	_bool		m_bFix = true;
	_float eyeOffSet = 0.f;
	float	secondRadius=0.f;
public:
	static CDynamicCamera*	Create(LPDIRECT3DDEVICE9 pGraphicDev, 
									const _vec3* pEye, 
									const _vec3* pAt, 
									const _vec3* pUp, 
									const _float& fFovY = D3DXToRadian(60.f),
									const _float& fAspect = _float(WINCX) / WINCY, 
									const _float& fNear = 0.1f, 
									const _float& fFar = 1000.f);
private:
	virtual void Free(void) override;
	bool isSlowChase = false;
	float slowTime = 0.f;
	//Shake
	bool isShake = false;
	float shakeDuration;
	float shakeMagnitude;
	_vec3 originCamPos;

	//Zoom
	bool isZoom = false;
	float zoomDuration;
	float zoomMagnitude;
	float originRadian;
};

END
#endif // DynamicCamera_h__
