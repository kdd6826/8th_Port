#ifndef DynamicCamera_h__
#define DynamicCamera_h__

#include "Camera.h"
#include "Define.h"

BEGIN(Engine)
CCamera;
END

class CDynamicCamera : public Engine::CCamera
{
	DECLARE_SINGLETON(CDynamicCamera)
public:
	explicit CDynamicCamera(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CDynamicCamera(void);

public:
	HRESULT Ready_Object(const _vec3* pEye, const _vec3* pAt, const _vec3* pUp,	
						 const _float& fFovY, const _float& fAspect, const _float& fNear,	const _float& fFar );

	virtual _int Update_Object(const _float& fTimeDelta) override;

public:
	void		Key_Input(const _float& fTimeDelta);
	void		Mouse_Move(void);
	void		Mouse_Fix(void);

private:
	bool		m_bClick = false;
	bool		m_bFix = true;

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

};

#endif // DynamicCamera_h__
