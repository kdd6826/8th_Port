Matrix		g_matWorld;
Matrix		g_matView;
Matrix		g_matProj;

texture		g_BaseTexture;
texture		g_NormalTexture;

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

sampler tNormalHeightMap = 
sampler_state
{
	Texture = < g_NormalTexture >;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct VS_IN
{
	float4		vPos			: POSITION;
	float2		vTexUV			: TEXCOORD0;
	float3		vNormal			: NORMAL;
	float3		vInTangent		: TANGENT;
	float3		vInBionormal	: BINORMAL;
	float4		BlendWeights    : BLENDWEIGHT;
	float4		BlendIndices    : BLENDINDICES;
};

struct VS_OUT
{
	vector		vPos		: POSITION;
	float2		vTexUV		: TEXCOORD0;
	float3		vTangent	: TEXCOORD1;
	float3		vBiNormal	: TEXCOORD2;
	float3		vNormal		: TEXCOORD3;
	float4		vWorldPos	: TEXCOORD4;
	float4		vProjPos	: TEXCOORD5;
};
//--------------------------------------------------------------------------------------
// For. Dynamic Mesh
//--------------------------------------------------------------------------------------

VS_OUT VS_MAIN(VS_IN In, uniform int NumBones)
{
	VS_OUT		Out = (VS_OUT)0;

	float3		Pos = 0.0f;
	float3		Normal = 0.0f;
	float3		Tangent = 0.0f;
	float3		Binormal = 0.0f;
	float		LastWeight = 0.0f;

	for(int i = 0; i < NumBones -1; i++)
	{
		LastWeight = LastWeight + In.BlendWeights[i];

		Pos += mul(In.vPos, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Normal += mul(In.vNormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Tangent += mul(In.vInTangent.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Binormal += mul(In.vInBionormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
	}
	LastWeight = 1.0f - LastWeight;

	Pos += (mul(In.vPos, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Normal += (mul(In.vNormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Tangent += (mul(In.vInTangent.xyz, (float3x3)MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Binormal += (mul(In.vInBionormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);

	Out.vPos = mul(float4(Pos.xyz, 1.0f), g_matWorld);
	Out.vWorldPos = Out.vPos;
	Out.vTexUV = In.vTexUV.xy;

	// Transform the normal, tangent and binormal vectors from object space to homogeneous projection space:
	float3 vNormalWS   = mul( Normal,   (float3x3) g_matWorld );
	float3 vTangentWS  = mul( Tangent,  (float3x3) g_matWorld );
	float3 vBinormalWS = mul( Binormal, (float3x3) g_matWorld );

	Out.vNormal   = normalize( vNormalWS );
	Out.vTangent  = normalize( vTangentWS );
	Out.vBiNormal = normalize( vBinormalWS );
	//Out.vBiNormal = cross(vNormalWS, vTangentWS) * In.vInTangent.w;

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;

	return Out;
}
struct PS_OUTPUT
{
	float4 mColor : COLOR0;
	float4 mNormal : COLOR1;
	float4 mDepth : COLOR2;  
	float4 mVel	 : COLOR3;
};

struct PS_INPUT
{
	float2 texCoord         : TEXCOORD0;
	float3 vTangent		 	: TEXCOORD1;
	float3 vBiNormal		: TEXCOORD2;
	float3 vNormal			: TEXCOORD3;
	float4 vWorldPos		: TEXCOORD4;
	float4 vProjPos			: TEXCOORD5;
};

//--------------------------------------------------------------------------------------
// Bump mapping shader
//--------------------------------------------------------------------------------------
PS_OUTPUT RenderSceneBumpMapPS( PS_INPUT i )
{ 
	PS_OUTPUT Out = (PS_OUTPUT)0.f;

	float4 tangentNormalOri = tex2D(tNormalHeightMap, i.texCoord);
	float3 tangentNormal = normalize(tangentNormalOri.xyz * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);
	float3 worldNormal = mul(TBN, tangentNormal);

	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);
	Out.mColor = albedo;

	Out.mNormal = float4(worldNormal * 0.5f + 0.5f, 0.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	Out.mVel = float4(10.f, 0.f, 0.f, 0.f);

	return Out;
} 
//--------------------------------------------------------------------------------------
// Bump mapping shader No specular
//--------------------------------------------------------------------------------------
PS_OUTPUT RenderSceneBumpMapPS2( PS_INPUT i )
{ 
	PS_OUTPUT Out = (PS_OUTPUT)0.f;

	float4 tangentNormalOri = tex2D(tNormalHeightMap, i.texCoord);
	float3 tangentNormal = normalize(tangentNormalOri.xyz * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);	
	float3 worldNormal = mul(TBN, tangentNormal);

	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);
	Out.mColor = albedo;
	Out.mNormal = float4(worldNormal * 0.5f + 0.5f, 0.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 1.f, 1.f);
	Out.mVel = float4(10.f, 0.f, 0.f, 0.f);

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
	pass Dynamic_Mesh
	{
		alphatestenable = true;
		alphafunc = greaterEqual;
		alpharef = 0x0000002f;

		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS(); 
	}

	pass Dynamic_Mesh_NOSpec
	{
		alphatestenable = true;
		alphafunc = greaterEqual;
		alpharef = 0x0000002f;

		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS2(); 
	}
};