#ifndef Engine_Typedef_h__
#define Engine_Typedef_h__

namespace Engine
{
	typedef		bool					_bool;

	typedef		signed char				_char;
	typedef		signed char				_byte;
	typedef		unsigned char			_ubyte;

	typedef		wchar_t					_tchar;


	typedef		signed short			_short;
	typedef		unsigned short			_ushort;

	typedef		signed int				_int;
	typedef		unsigned int			_uint;

	typedef		signed long				_long;
	typedef		unsigned long			_ulong;

	typedef		float					_float;
	typedef		double					_double;

	typedef		D3DXVECTOR3				_vec3;
	typedef		D3DXVECTOR2				_vec2;
	typedef		D3DXVECTOR4				_vec4;

	typedef		D3DXMATRIX				_matrix;
	
	typedef struct _objectStat
	{
		float attack = 1.f;
		float damage = 1.f;
		float hp = 10.f;
		float maxHp = 10.f;
		float stamina = 10.f;
		float maxStamina = 10.f;
		float sp = 0.f;
		float maxSp = 1250.f;
		float down = 0.f;
		float downDamage = 1.f;
		float totalExp = 10.f;
		float exp = 0.f;
		float moveSpeed = 3.f;
		int level = 1;
		int money = 0;

	}STAT;
}

#endif // Engine_Typedef_h__
