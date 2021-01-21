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
texture		g_PupilTexture;

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
sampler PupilSampler = sampler_state
{
	texture	= <g_PupilTexture>;
	minfilter = linear;
	magfilter = linear;
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
	float3		vDiffuse : TEXCOORD1;
	float3		vNormal : TEXCOORD2;
	float3		vWorldPos : TEXCOORD3;
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
	float4 Velo		: COLOR1;
	float4 mDepth : COLOR2; 
};

struct PS_INPUT
{
	vector vPos			: POSITION;
	float2 texCoord		: TEXCOORD0;
	float4 vDiffuse		: TEXCOORD1;
	float3 vNormal		: TEXCOORD2;
	float3		vWorldPos : TEXCOORD3;
	float4		vProjPos	: TEXCOORD4;
};
 
PS_OUTPUT RenderSceneBumpMapPS( PS_INPUT i )
{ 
	// Sample base map:
	float4 cBaseColor = pow(tex2D( BaseSampler, i.texCoord ), 2.2);

	cBaseColor.xyz += float3(0.4f,0.4f,0.4f);

	float2 pupilUV = i.texCoord;
	pupilUV.x = pupilUV.x*2.2f - 0.65f;
	pupilUV.y = (pupilUV.y - 1.f)*2.2f - 0.65f;
	float4 pupil = pow(tex2D(PupilSampler, pupilUV), 2.2) + 0.1f;

	if(pupilUV.x < 1.f && pupilUV.x > 0.f && pupilUV.y < 1.f && pupilUV.y > 0.f)
	{
		cBaseColor.rgb = pupil.a * pupil.rgb + (1.f - pupil.a) * cBaseColor.rgb;
	}

	float3 viewDir = normalize(i.vWorldPos - g_vCamPos.xyz);
	float3 reflection = normalize(reflect(viewDir, i.vNormal));

	cBaseColor.rgb *= g_vLightDiffuse.rgb;
	cBaseColor.rgb += pow(saturate(dot(reflection, -viewDir)), 128.f) * g_vLightSpecular.rgb;
	cBaseColor = pow(cBaseColor, 0.454545);

	PS_OUTPUT Out = (PS_OUTPUT)0.f;
	Out.RGBColor = cBaseColor;
	Out.Velo = float4(10.f,0.f,0.f,0.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	return Out;
}   

int CurNumBones = 2;
VertexShader vsArray[4] = { compile vs_3_0 VS_MAIN(1), 
compile vs_3_0 VS_MAIN(2),
compile vs_3_0 VS_MAIN(3),
compile vs_3_0 VS_MAIN(4)
};

technique RenderScene
{
	pass DefaultPass
	{
		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS(); 
	}
};