matrix			g_matWorld;		// ��� ���̺�
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

// ���ؽ� ���̴�

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
	vector		vNormal : COLOR1;	// �븻�̶�� ����Ÿ��(�ؽ���)�� ����ϱ� ���� ����
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


	// �ؽ��� UV�� �켱 ���� ��ǥ�� ��ȯ
	// �ؽ��� UV : 0,0 ~ 1,1
	// ���� ��ǥ : -1,1 ~ 1,-1 
	vector		vPosition; // ���� ������ ��ġ���� �Ѵ�.
	vector		vDepth = tex2D(DepthSampler, In.vTexUV);

	float		fViewZ = vDepth.y * 1000.f;
	// texture U�� �ü� �ִ� ������ ������ 0~1, ���� X�� ��ȯ�� ������ ������ -1~1
	vPosition.x = (In.vTexUV.x * 2.f - 1.f) * fViewZ;
	// texture V�� �ü� �ִ� ������ ������ (0)~(1), ���� X�� ��ȯ�� ������ ������ (1)~(-1)
	vPosition.y = (In.vTexUV.y * -2.f + 1.f) * fViewZ;
	vPosition.z = vDepth.x * fViewZ;
	vPosition.w = fViewZ;

	vPosition = mul(vPosition, g_matProjInv);
	vPosition = mul(vPosition, g_matViewInv);

	vector		vLook = normalize(vCamPos - vPosition);
	float fRimWidth = 0.1f;

	vector vCamPosition = normalize(vCamPos - vPosition);
	float fRimLightColor = smoothstep(1.f - fRimWidth, 1.f, 1 - max(0.f, dot(normalize(In.vNormal), vCamPosition)));

	Out.vColor = tex2D(BaseSampler, In.vTexUV);	// 2���� �ؽ�ó�κ��� uv��ǥ�� �ش��ϴ� ���� ������ �Լ�, ��ȯ Ÿ���� vector Ÿ��
	Out.vColor.rgb += fRimLightColor* g_fPower;
	//Out.vColor.gb = 0.f;
	// (-1 ~ 1)���� ���� ������ ���� ���͸� ����ȭ�Ͽ��� ������ xyz���� ���� �� �ִ� ������ �ش�
	// (0 ~ 1) �ؽ��� uv��ǥ�� ��ȯ
	Out.vNormal = vector(In.vNormal.xyz * 0.5f + 0.5f, 0.f);

	Out.vDepth = vector(In.vProjPos.z / In.vProjPos.w, In.vProjPos.w * 0.001f, 0.f, 0.f);
	
	return Out;
}


PS_OUT		PS_ALPHA(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);	// 2���� �ؽ�ó�κ��� uv��ǥ�� �ش��ϴ� ���� ������ �Լ�, ��ȯ Ÿ���� vector Ÿ��
	
	return Out;
}

technique Default_Device
{
	// ����� ĸ��ȭ
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