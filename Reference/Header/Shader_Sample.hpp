matrix			g_matWorld;		// ��� ���̺�
matrix			g_matView;
float4x4		g_matProj;

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
	float2		vTexUV		: TEXCOORD0;
};

struct	VS_OUT
{
	vector		vPosition : POSITION;
	float2		vTexUV : TEXCOORD0;
};

// ���ؽ� ���̴�

VS_OUT VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);
	
	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);
	Out.vTexUV = In.vTexUV;

	return Out;
}


struct	PS_IN
{
	float2		vTexUV : TEXCOORD0;
};

struct	PS_OUT
{
	vector		vColor : COLOR0;	
};

PS_OUT		PS_MAIN(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);	// 2���� �ؽ�ó�κ��� uv��ǥ�� �ش��ϴ� ���� ������ �Լ�, ��ȯ Ÿ���� vector Ÿ��

	/*Out.vColor.rb = 1.f;*/

	return Out;
}

struct VS_IN_PARTICLE
{
	float3		vPos : POSITION;
	float		fPSize : PSIZE;
	float2		vTexUV : TEXCOORD0;

	float4		vRight	: TEXCOORD1;
	float4		vUp		: TEXCOORD2;
	float4		vLook	: TEXCOORD3;
	float4		vPosition : TEXCOORD4;

};

struct VS_OUT_PARTICLE
{
	float4		vPos : POSITION;
	float		fPSize : PSIZE;
	float2		vTexUV : TEXCOORD0;
};

VS_OUT_PARTICLE	VS_PARTICLE(VS_IN_PARTICLE In)
{
	VS_OUT_PARTICLE		Out = (VS_OUT_PARTICLE)0;

	matrix	matWorld = float4x4(In.vRight, In.vUp, In.vLook, In.vPosition);


	matrix matWV, matWVP;

	matWV = mul(matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	Out.vPos = mul(vector(In.vPos.xyz, 1.f), matWVP);

	Out.fPSize = (600.f * In.fPSize) * sqrt(1.f / pow(Out.vPos.w, 2.f));

	Out.vTexUV = In.vTexUV;
	
	return Out;
}
struct PS_IN_PARTICLE
{
	float4		vPos : POSITION;
	float		fPSize : PSIZE;
	float2		vTexUV : TEXCOORD0;

};

struct PS_OUT_PARTICLE
{
	float4		vColor : COLOR0;
};

PS_OUT_PARTICLE		PS_PARTICLE(PS_IN_PARTICLE In)
{
	PS_OUT_PARTICLE		Out = (PS_OUT_PARTICLE)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);	// 2���� �ؽ�ó�κ��� uv��ǥ�� �ش��ϴ� ���� ������ �Լ�, ��ȯ Ÿ���� vector Ÿ��


	return Out;
}


technique Default_Device
{
	// ����� ĸ��ȭ
	pass	
	{
		/*alphablendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;*/

		vertexshader = compile vs_3_0 VS_MAIN();
		pixelshader = compile ps_3_0 PS_MAIN();
	}

	pass	PointSprite
	{

		PointSpriteEnable = true;
		zwriteenable = false;

		alphatestenable = true;
		alpharef = 0;
		alphafunc = Greater;

		vertexshader = compile vs_3_0 VS_PARTICLE();
		pixelshader = compile ps_3_0 PS_PARTICLE();
	}
};