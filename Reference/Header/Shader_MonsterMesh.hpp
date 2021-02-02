matrix			g_matWorld;		// 상수 테이블
matrix			g_matView;
matrix			g_matProjInv;
matrix			g_matViewInv;
float			g_fPower;
float4x4		g_matProj;

vector			vCamPos;
vector			vCamDir;
vector			vLightDir;
texture			g_BaseTexture;

texture		g_DepthTexture;

sampler DepthSampler = sampler_state
{
	texture = g_DepthTexture;
};

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
	vector		vNormal		: NORMAL;
	float2		vTexUV		: TEXCOORD0;
	vector		vProjPos	: TEXCOORD1;
};

// 버텍스 쉐이더

VS_OUT VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);

	Out.vNormal = normalize(mul(vector(In.vNormal.xyz, 0.f), g_matWorld));

	Out.vTexUV = In.vTexUV;
	Out.vProjPos = Out.vPosition;

	return Out;
}


struct	PS_IN
{
	vector		vNormal : NORMAL;
	float2		vTexUV : TEXCOORD0;
	vector		vProjPos : TEXCOORD1;
};

struct	PS_OUT
{
	vector		vColor : COLOR0;
	vector		vNormal : COLOR1;	// 노말이라는 렌더타겟(텍스쳐)에 출력하기 위한 색상
	vector		vDepth : COLOR2;
};

PS_OUT		PS_MAIN(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	//float3 vRimColor = float3(-2.f, -2.f, -2.f);
	//int iRimPower = 5.f;

	//float fRim = saturate(dot(In.vNormal.xyz, vCamAt.xyz));
	//
	//if (fRim > 0.3)
	//	fRim = 1;
	//else
	//	fRim = -1;


	// 텍스쳐 UV를 우선 투영 좌표로 변환
	// 텍스쳐 UV : 0,0 ~ 1,1
	// 투영 좌표 : -1,1 ~ 1,-1 
	vector		vPosition; // 월드 영역에 위치여야 한다.
	vector		vDepth = tex2D(DepthSampler, In.vTexUV);

	float		fViewZ = vDepth.y * 1000.f;
	// texture U로 올수 있는 숫자의 범위는 0~1, 투영 X로 변환된 숫자의 범위는 -1~1
	vPosition.x = (In.vTexUV.x * 2.f - 1.f) * fViewZ;
	// texture V로 올수 있는 숫자의 범위는 (0)~(1), 투영 X로 변환된 숫자의 범위는 (1)~(-1)
	vPosition.y = (In.vTexUV.y * -2.f + 1.f) * fViewZ;
	vPosition.z = vDepth.x * fViewZ;
	vPosition.w = fViewZ;

	vPosition = mul(vPosition, g_matProjInv);
	vPosition = mul(vPosition, g_matViewInv);

	vector		vLook = normalize(vCamPos - vPosition);
	float fRimWidth = 0.1f;

	vector vCamPosition = normalize(vCamPos - vPosition);
	float fRimLightColor = smoothstep(1.f - fRimWidth, 1.f, 1 - max(0.f, dot(normalize(In.vNormal), vCamPosition)));

	Out.vColor = tex2D(BaseSampler, In.vTexUV);	// 2차원 텍스처로부터 uv좌표에 해당하는 색을 얻어오는 함수, 반환 타입이 vector 타입
	Out.vColor.rgb += fRimLightColor* g_fPower;
	//Out.vColor.gb = 0.f;
	// (-1 ~ 1)값은 월드 상태의 법선 벡터를 정규화하였기 때문에 xyz값이 나올 수 있는 범위에 해당
	// (0 ~ 1) 텍스쳐 uv좌표로 변환
	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);

	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w, In.vProjPos.w * 0.001f, 0.f, 0.f);
	
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