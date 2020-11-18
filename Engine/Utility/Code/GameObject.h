#ifndef GameObject_h__
#define GameObject_h__

#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL CGameObject : public CBase
{
protected:
	explicit CGameObject(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CGameObject(void);

public:
	CComponent*	   Get_Component(const _tchar* pComponentTag, COMPONENTID eID);

public:
	virtual HRESULT			Ready_Object(void) { return S_OK; };
	virtual _int			Update_Object(const _float& fTimeDelta);
	virtual void			Render_Object(void) {};

private:
	CComponent*		Find_Component(const _tchar* pComponentTag, COMPONENTID eID);

protected:
	LPDIRECT3DDEVICE9						m_pGraphicDev;
	map<const _tchar*, CComponent*>			m_mapComponent[ID_END];

public:
	virtual void Free(void);

};
END
#endif // GameObject_h__
