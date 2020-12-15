matrix			g_matWorld;		// 상수 테이블
matrix			g_matView;
float4x4		g_matProj;


vector			g_vLightDir;

float4			g_LightDiffuse; // = (float4)1.f;
float4			g_LightSpecular;
float4			g_LightAmbient;

float4			g_MtrlDiffuse;
float4			g_MtrlSpecular;
float4			g_MtrlAmbient;

vector			g_vCamPos;
float			g_fPower;


texture			g_BaseTexture;

sampler BaseSampler = sampler_state
{
	texture = g_BaseTexture;

	minfilter = linear;
	magfilter = linear;
};

struct	VS_IN 
{
	vector		vPosition	: POSITION;
	vector		vNormal		: NORMAL;
	float2		vTexUV		: TEXCOORD0;
};

struct	VS_OUT
{
	vector		vPosition	: POSITION;
	vector		vShade		: COLOR0;
	vector		vSpecular	: COLOR1;
	float2		vTexUV		: TEXCOORD0;
};

// 버텍스 쉐이더

VS_OUT VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	// 난반사광
	vector	 vWorldNormal = mul(vector(In.vNormal.xyz, 0.f), g_matWorld);
	vector	 vWorldDir = g_vLightDir * -1.f;

	float fIntensity = saturate(dot(normalize(vWorldNormal), normalize(vWorldDir)));
	//	max(dot(normalize(vWorldNormal), normalize(vWorldDir)), 0.f)
	
	// 정반사광

	// 반사벡터 생성
	vector vReflect		= reflect(normalize(g_vLightDir), normalize(vWorldNormal));
	vector vWorldPos	= mul(vector(In.vPosition.xyz, 1.f), g_matWorld);
	vector vLook		= vWorldPos - g_vCamPos;

	Out.vSpecular = pow(saturate(dot(normalize(vReflect), normalize(vLook) * -1.f)), g_fPower);
	Out.vSpecular.a = 1.f;

	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);

	Out.vShade = fIntensity;
	Out.vShade.a = 1.f;

	Out.vTexUV = In.vTexUV;

	return Out;
}


struct	PS_IN
{
	vector		vShade : COLOR0;
	vector		vSpecular : COLOR1;
	float2		vTexUV : TEXCOORD0;
};

struct	PS_OUT
{
	vector		vColor : COLOR0;
	vector		vColor2 : COLOR1;
	vector		vColor3 : COLOR2;
	vector		vColor4 : COLOR3;
};

PS_OUT		PS_MAIN(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	vector vColor = tex2D(BaseSampler, In.vTexUV);	// 2차원 텍스처로부터 uv좌표에 해당하는 색을 얻어오는 함수, 반환 타입이 vector 타입
	
	Out.vColor = In.vShade * (vColor * (g_LightDiffuse * g_MtrlDiffuse)) + (g_LightAmbient * g_MtrlAmbient) + (In.vSpecular * (g_LightSpecular * g_MtrlSpecular));
	
	return Out;
}


PS_OUT		PS_ALPHA(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);	// 2차원 텍스처로부터 uv좌표에 해당하는 색을 얻어오는 함수, 반환 타입이 vector 타입
	
	return Out;
}

technique Default_Device
{
	// 기능의 캡슐화
	pass Default
	{

		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_MAIN();
	}

	pass	AlphaTest
	{
		alphatestenable = true;
		alpharef = 0xc0;
		alphafunc = greater;
		cullmode = none;

		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_ALPHA();
	}	
};