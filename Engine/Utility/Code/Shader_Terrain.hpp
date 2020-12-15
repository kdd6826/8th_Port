matrix			g_matWorld;		// ��� ���̺�
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
vector			g_vPlayerPos;
float			g_fPower;

float			g_fDetail;
float			g_fRange;



texture			g_BaseTexture;

sampler BaseSampler = sampler_state
{
	texture = g_BaseTexture;

	minfilter = linear;
	magfilter = linear;
};

texture			g_BaseTexture1;

sampler BaseSampler1 = sampler_state
{
	texture = g_BaseTexture1;

	minfilter = linear;
	magfilter = linear;
	
	addressU = mirror;
	addressV = mirror;
};

texture			g_FilterTexture;

sampler FilterSampler = sampler_state
{
	texture = g_FilterTexture;

	minfilter = linear;
	magfilter = linear;
};

texture			g_AuraTexture;

sampler AuraSampler = sampler_state
{
	texture = g_AuraTexture;

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
	vector		vAuraPixelPos	: TEXCOORD1;
};

// ���ؽ� ���̴�

VS_OUT VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	matrix matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	matWVP = mul(matWV, g_matProj);

	// ���ݻ籤
	vector	 vWorldNormal = mul(vector(In.vNormal.xyz, 0.f), g_matWorld);
	vector	 vWorldDir = g_vLightDir * -1.f;

	float fIntensity = saturate(dot(normalize(vWorldNormal), normalize(vWorldDir)));
	//	max(dot(normalize(vWorldNormal), normalize(vWorldDir)), 0.f)
	
	// ���ݻ籤

	// �ݻ纤�� ����
	vector vReflect		= reflect(normalize(g_vLightDir), normalize(vWorldNormal));
	vector vWorldPos	= mul(vector(In.vPosition.xyz, 1.f), g_matWorld);
	vector vLook		= vWorldPos - g_vCamPos;

	Out.vSpecular = pow(saturate(dot(normalize(vReflect), normalize(vLook) * -1.f)), g_fPower);
	Out.vSpecular.a = 1.f;

	Out.vPosition = mul(vector(In.vPosition.xyz, 1.f), matWVP);

	Out.vShade = fIntensity;
	Out.vShade.a = 1.f;

	Out.vTexUV = In.vTexUV;

	Out.vAuraPixelPos = vWorldPos;

	return Out;
}


struct	PS_IN
{
	vector		vShade : COLOR0;
	vector		vSpecular : COLOR1;
	float2		vTexUV : TEXCOORD0;
	vector		vAuraPixelPos : TEXCOORD1;
};

struct	PS_OUT
{
	vector		vColor : COLOR0;	
};

PS_OUT		PS_MAIN(PS_IN In)
{
	PS_OUT		Out = (PS_OUT)0;

	vector vColor = tex2D(BaseSampler, In.vTexUV * g_fDetail);	// 2���� �ؽ�ó�κ��� uv��ǥ�� �ش��ϴ� ���� ������ �Լ�, ��ȯ Ÿ���� vector Ÿ��
	vector vColor1 = tex2D(BaseSampler1, In.vTexUV * g_fDetail);	

	vector vFilter = tex2D(FilterSampler, In.vTexUV);

	Out.vColor = vColor * vFilter + vColor1 * (1.f - vFilter);
	
	Out.vColor = In.vShade * (Out.vColor * (g_LightDiffuse * g_MtrlDiffuse)) + (g_LightAmbient * g_MtrlAmbient);// +(In.vSpecular * (g_LightSpecular * g_MtrlSpecular));
	
	vector		vAuraColor = (vector)0.f;

	if (g_vPlayerPos.x - g_fRange < In.vAuraPixelPos.x &&
		g_vPlayerPos.x + g_fRange > In.vAuraPixelPos.x &&
		g_vPlayerPos.z - g_fRange < In.vAuraPixelPos.z &&
		g_vPlayerPos.z + g_fRange > In.vAuraPixelPos.z)
	{
		float2 vTexUV;
		
		// 0 ~ 1�� ����� ���� ����
		vTexUV.x = (In.vAuraPixelPos.x - (g_vPlayerPos.x - g_fRange)) / (g_fRange * 2.f);
		vTexUV.y = ((g_vPlayerPos.z + g_fRange) - In.vAuraPixelPos.z) / (g_fRange * 2.f);

		vAuraColor = tex2D(AuraSampler, vTexUV);
	}
	
	Out.vColor += vAuraColor;

	return Out;
}

//VS_OUT VS_TEMP(VS_IN In);
//PS_OUT PS_TEMP(PS_IN In);

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

	/*pass	
	{
		vertexshader = compile vs_3_0 VS_TEMP();
		pixelshader = compile ps_3_0 PS_TEMP();
	}*/
};