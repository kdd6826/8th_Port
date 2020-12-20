#ifndef Monster_h__
#define Monster_h__

#include "GameObject.h"
#include "Define.h"

BEGIN(Engine)

class CRcTex;
class CTexture;
class CTransform;
class CRenderer;
class CCalculator;

END

BEGIN(Client)
class CMonster : public Engine::CGameObject
{
public:
	CMonster(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~CMonster(void);
protected:
	bool PlayerSearch(_vec3 _MonsterPos);
private:

protected:
	_bool isSearch = false;
	_bool isAnimating = false;
	//플레이어까지의 거리
	_float disPlayer = 0.f;
	_float m_fSpeed;

	virtual void Free(void) override;

};

END
#endif // Monster_h__
