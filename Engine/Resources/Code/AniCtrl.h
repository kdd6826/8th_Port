#ifndef AniCtrl_h__
#define AniCtrl_h__

#include "Engine_Define.h"
#include "Base.h"

BEGIN(Engine)
class ENGINE_DLL CAniCtrl : public CBase
{
private:
	explicit CAniCtrl(LPD3DXANIMATIONCONTROLLER pAniCtrl);
	explicit CAniCtrl(const CAniCtrl& rhs);
	virtual ~CAniCtrl(void);

private:
	LPD3DXANIMATIONCONTROLLER			m_pAniCtrl;
	_uint								m_iCurrentTrack;

public:
	static CAniCtrl*		Create(LPD3DXANIMATIONCONTROLLER pAniCtrl);
	static CAniCtrl*		Create(const CAniCtrl& rhs);
	virtual void			Free(void);

};
END

#endif // AniCtrl_h__
