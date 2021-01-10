Matrix		g_matWorld;
Matrix		g_matView;
Matrix		g_matProj;

float3		g_vLightPos;

vector		g_vLightDir;
vector		g_vLightDiffuse;
vector		g_vLightAmbient;
vector		g_vLightSpecular;

vector		g_vMtrlDiffuse;
vector		g_vMtrlAmbient;
vector		g_vMtrlSpecular;
vector		g_fPower = 20.0f;

vector		g_vCamPos;

texture		g_BaseTexture;
texture		g_SpecTexture;

// Matrix Pallette
static const int MAX_MATRICES = 26;
float4x3    MatrixPalette[MAX_MATRICES] : WORLDMATRIXARRAY;

sampler BaseSampler = sampler_state
{
	texture	= <g_BaseTexture>;
	minfilter = linear;
	magfilter = linear;
	MagFilter = LINEAR;
};

sampler SpecularSampler = sampler_state
{
	Texture = < g_SpecTexture >;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct VS_IN
{
	float4		vPos : POSITION;
	float2		vTexUV : TEXCOORD0;
	float3		vNormal : NORMAL;
	float4		BlendWeights    : BLENDWEIGHT;
	float4		BlendIndices    : BLENDINDICES;
};

struct VS_OUT
{
	vector		vPos : POSITION;
	float2		vTexUV : TEXCOORD0;
	float3		vNormal : TEXCOORD1;
	float3		vWorldPos : TEXCOORD2;
	float3		vDiffuse : TEXCOORD3;
	float4		vProjPos	: TEXCOORD4;
};

//--------------------------------------------------------------------------------------
// For. Dynamic Mesh
//--------------------------------------------------------------------------------------

VS_OUT VS_MAIN(VS_IN In, uniform int NumBones)
{
	VS_OUT		Out = (VS_OUT)0;

	float3		Pos = 0.0f;
	float3		Normal = 0.0f;
	float		LastWeight = 0.0f;

	for(int i = 0; i < NumBones -1; i++)
	{
		LastWeight = LastWeight + In.BlendWeights[i];

		Pos += mul(In.vPos, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Normal += mul(In.vNormal, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
	}
	LastWeight = 1.0f - LastWeight;

	Pos += (mul(In.vPos, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Normal += (mul(In.vNormal, (float3x3)MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);

	Out.vPos = mul(float4(Pos, 1.f), g_matWorld);
	Out.vWorldPos = Out.vPos.xyz;

	Normal = mul(Normal, (float3x3)g_matWorld);
	Out.vNormal = normalize(Normal);

	Out.vTexUV = In.vTexUV.xy;

	Out.vPos = mul(Out.vPos, g_matView);
	Out.vPos = mul(Out.vPos, g_matProj);
	Out.vProjPos = Out.vPos;
	Out.vDiffuse = dot(-g_vLightDir.xyz, Normal);

	return Out;
}
struct PS_OUTPUT
{
	float4 RGBColor : COLOR0;  // Pixel color    
	float4 Velo : COLOR1;
	float4 mDepth : COLOR2; 
};

struct PS_INPUT
{
	vector vPos				: POSITION;
	float2 texCoord         : TEXCOORD0;
	float3 vNormal			: TEXCOORD1;
	float3 vWorldPos		: TEXCOORD2;
	float3 vDiffuse			: TEXCOORD3;
	float4		vProjPos	: TEXCOORD4;
};

int CurNumBones = 2;
VertexShader vsArray[4] = { compile vs_3_0 VS_MAIN(1), 
compile vs_3_0 VS_MAIN(2),
compile vs_3_0 VS_MAIN(3),
compile vs_3_0 VS_MAIN(4)
};

PS_OUTPUT RenderScenePS( PS_INPUT i )
{
	float4 cBaseColor = tex2D(BaseSampler, i.texCoord);
	//cBaseColor.rgb = cBaseColor.r * float3(0.8275f, 0.7843f, 0.6549);
	cBaseColor.rgb = cBaseColor.r * 0.01f;
	float4 cSpecColor = tex2D(SpecularSampler, i.texCoord);

	float3 halfDiffuse = (i.vDiffuse * g_vLightDiffuse  + 0.1f) * 0.5f + 0.5f;
	float3 viewDir = normalize(i.vWorldPos - g_vCamPos.xyz);
	float3 SpecularColor = cSpecColor.ggg*g_vLightSpecular.rgb * (1.f-cSpecColor.r);

	cBaseColor.rgb *= halfDiffuse ;

	float d = dot(i.vNormal, -viewDir);
	if(d > 0.f) cBaseColor.rgb += SpecularColor*smoothstep(0.5f, 1.f, 1.f - max(0.f, d));

	PS_OUTPUT Out = (PS_OUTPUT)0.f;
	Out.RGBColor = cBaseColor;
	Out.Velo = float4(10.f, 0.f, 0.f, 1.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	return Out;
}

PS_OUTPUT RenderSceneBumpMapPS( PS_INPUT i )
{
	float4 cBaseColor = tex2D(BaseSampler, i.texCoord);
	cBaseColor.rgb = cBaseColor.r * 0.01f;
	float4 cSpecColor = tex2D(SpecularSampler, i.texCoord);

	float3 halfDiffuse = (i.vDiffuse * g_vLightDiffuse  + 0.1f) * 0.5f + 0.5f;
	float3 viewDir = normalize(i.vWorldPos - g_vCamPos.xyz);
	float3 reflection = normalize(reflect(viewDir, i.vNormal));
	float3 specular = saturate(dot(reflection, -viewDir));
	float3 SpecularColor = cSpecColor.ggg*g_vLightSpecular.rgb * (1.f-cSpecColor.r);

	cBaseColor.rgb *= halfDiffuse;

	float d = dot(i.vNormal, -viewDir);
	if(d > 0.f) cBaseColor.rgb += SpecularColor*smoothstep(0.5f, 1.f, 1.f - max(0.f, d));

	PS_OUTPUT Out = (PS_OUTPUT)0.f;
	Out.RGBColor = cBaseColor;
	Out.Velo = float4(10.f, 0.f, 0.f, 1.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	return Out;
}

technique RenderScene
{
	pass DefaultPass
	{
		cullmode = none;

		Zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		alphatestenable = false;

		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderScenePS(); 
	}
	
	pass DefaultPass2
	{
		Zwriteenable = true;

		cullmode = none;
		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		alphatestenable = true;
		alphafunc = greaterEqual;
		alpharef = 0x0000007f;

		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS(); 
	}
};