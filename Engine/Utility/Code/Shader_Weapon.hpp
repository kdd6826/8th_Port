#include "Shader_Base.hpp"

float4		g_vLightDir;
float4		g_vCamPos;

float4		g_vColorR;
float4		g_vColorG;
float4		g_vColorB;

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
	float4		vNormal			: NORMAL;
	float4		vInTangent		: TANGENT;
	float4		vInBionormal	: BINORMAL;
	float4		BlendWeights    : BLENDWEIGHT;
	float4		BlendIndices    : BLENDINDICES;
};

struct VS_OUT
{
	vector		vPos : POSITION;
	float2		vTexUV		: TEXCOORD0;
	float3		vTangent	: TEXCOORD1;
	float3		vBiNormal	: TEXCOORD2;
	float3		vNormal		: TEXCOORD3;
	float4		vWorldPos	: TEXCOORD4;
	float4		vProjPos	: TEXCOORD5;
};

struct VS_OUT_MOTION
{
	vector		vPos : POSITION;
	float2		vTexUV		: TEXCOORD0;
	float3		vTangent	: TEXCOORD1;
	float3		vBiNormal	: TEXCOORD2;
	float3		vNormal		: TEXCOORD3;
	float4		vWorldPos	: TEXCOORD4;
	float4		vProjPos	: TEXCOORD5;
	float2		vVelocityUV : TEXCOORD6;
};

//--------------------------------------------------------------------------------------
// For. Static Mesh
//--------------------------------------------------------------------------------------

VS_OUT RenderSceneVS( float4 inPositionOS  : POSITION, 
					 float2 inTexCoord    : TEXCOORD0,
					 float4 vInNormalOS   : NORMAL,
					 float4 vInBinormalOS : BINORMAL,
					 float4 vInTangentOS  : TANGENT )
{
	VS_OUT Out;

	Out.vPos = mul(float4(inPositionOS.xyz, 1.0f), g_matWorld);
	Out.vWorldPos = Out.vPos;

	Out.vTexUV = inTexCoord.xy;

	// Transform the normal, tangent and binormal vectors from object space to homogeneous projection space:
	float3 vNormalWS   = mul( vInNormalOS.xyz,   (float3x3) g_matWorld );
	float3 vTangentWS  = mul( vInTangentOS.xyz,  (float3x3) g_matWorld );
	float3 vBinormalWS = mul( vInBinormalOS.xyz, (float3x3) g_matWorld );

	Out.vNormal   = normalize( vNormalWS );
	Out.vTangent  = normalize( vTangentWS );
	Out.vBiNormal = normalize( vBinormalWS );
	//	Out.vBiNormal = cross(vNormalWS, vTangentWS) * vInTangentOS.w;

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;

	return Out;
}   

VS_OUT_MOTION RenderSceneVS_MOTION( float4 inPositionOS  : POSITION, 
					 float2 inTexCoord    : TEXCOORD0,
					 float4 vInNormalOS   : NORMAL,
					 float4 vInBinormalOS : BINORMAL,
					 float4 vInTangentOS  : TANGENT )
{
	VS_OUT_MOTION Out;

	Out.vPos = mul(float4(inPositionOS.xyz, 1.0f), g_matWorld);
	Out.vWorldPos = Out.vPos;

	Out.vTexUV = inTexCoord.xy;

	// Transform the normal, tangent and binormal vectors from object space to homogeneous projection space:
	float3 vNormalWS   = mul( vInNormalOS.xyz,   (float3x3) g_matWorld );
	float3 vTangentWS  = mul( vInTangentOS.xyz,  (float3x3) g_matWorld );
	float3 vBinormalWS = mul( vInBinormalOS.xyz, (float3x3) g_matWorld );

	Out.vNormal   = normalize( vNormalWS );
	Out.vTangent  = normalize( vTangentWS );
	Out.vBiNormal = normalize( vBinormalWS );
	//	Out.vBiNormal = cross(vNormalWS, vTangentWS) * vInTangentOS.w;

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;

	float4 vPosProjSpaceCurrent; 
	float4 vPosProjSpaceLast; 

	vPosProjSpaceCurrent = Out.vPos;
	vPosProjSpaceLast = mul(inPositionOS, g_matWorldViewProjLast);

	vPosProjSpaceCurrent /= (vPosProjSpaceCurrent.w);
	vPosProjSpaceLast /= (vPosProjSpaceLast.w);

	float2 velocity = vPosProjSpaceCurrent.xy - vPosProjSpaceLast.xy;
	Out.vVelocityUV = velocity * 0.5f;

	return Out;
}   

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

		Pos += mul(In.vPos.xyz, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Normal += mul(In.vNormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Tangent += mul(In.vInTangent.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Binormal += mul(In.vInBionormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
	}
	LastWeight = 1.0f - LastWeight;

	Pos += (mul(In.vPos.xyz, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
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
	//Out.vBiNormal = cross(vNormalWS, vTangentWS) * In.vInTangent.w;
	Out.vBiNormal = normalize(vBinormalWS);

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;

	return Out;
}


VS_OUT_MOTION VS_MAIN_MOTION(VS_IN In, uniform int NumBones)
{
	VS_OUT_MOTION		Out = (VS_OUT_MOTION)0;

	float3		Pos = 0.0f;
	float3		Normal = 0.0f;
	float3		Tangent = 0.0f;
	float3		Binormal = 0.0f;
	float		LastWeight = 0.0f;

	for(int i = 0; i < NumBones -1; i++)
	{
		LastWeight = LastWeight + In.BlendWeights[i];

		Pos += mul(In.vPos.xyz, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Normal += mul(In.vNormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Tangent += mul(In.vInTangent.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Binormal += mul(In.vInBionormal.xyz, (float3x3)MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
	}
	LastWeight = 1.0f - LastWeight;

	Pos += (mul(In.vPos.xyz, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
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
	//Out.vBiNormal = cross(vNormalWS, vTangentWS) * In.vInTangent.w;
	Out.vBiNormal = normalize(vBinormalWS);

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;

	float4 vPosProjSpaceCurrent; 
	float4 vPosProjSpaceLast; 

	vPosProjSpaceCurrent = Out.vPos;
	vPosProjSpaceLast = mul(In.vPos, g_matWorldViewProjLast);

	vPosProjSpaceCurrent /= (vPosProjSpaceCurrent.w);
	vPosProjSpaceLast /= (vPosProjSpaceLast.w);

	float2 velocity = vPosProjSpaceCurrent.xy - vPosProjSpaceLast.xy;
	Out.vVelocityUV = velocity * 0.5f;

	return Out;
}

struct PS_OUTPUT
{
	float4 mColor : COLOR0;
	float4 mNormal : COLOR1;
	float4 mDepth : COLOR2;
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


struct PS_OUTPUT_MOTION
{
	float4 mColor : COLOR0;
	float4 mNormal : COLOR1;
	float4 mDepth : COLOR2;
	float4 mVelocityUV : COLOR3;
};

struct PS_INPUT_MOTION
{
	float2 texCoord         : TEXCOORD0;
	float3 vTangent		 	: TEXCOORD1;
	float3 vBiNormal		: TEXCOORD2;
	float3 vNormal			: TEXCOORD3;
	float4 vWorldPos		: TEXCOORD4;
	float4 vProjPos			: TEXCOORD5;
	float2 vVelocityUV		: TEXCOORD6;
};


//--------------------------------------------------------------------------------------
// Bump mapping shader
//--------------------------------------------------------------------------------------
PS_OUTPUT RenderSceneBumpMapPSColor( PS_INPUT i )
{ 
	PS_OUTPUT Out = (PS_OUTPUT)0.f;

	float4 tangentNormalOri = tex2D(tNormalHeightMap, i.texCoord);
	float3 tangentNormal = normalize(tangentNormalOri.xyz * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);
	float3 worldNormal = mul(TBN, tangentNormal);

	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);

	Out.mColor = albedo.r * g_vColorR + albedo.g * g_vColorG + albedo.b * g_vColorB;
	Out.mColor.a = albedo.a;
	
	Out.mNormal = float4(worldNormal * 0.5f + 0.5f, 0.0);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);

	return Out;
	//return float4(ambient + diffuse + specular, albedo.a);
} 

PS_OUTPUT_MOTION RenderSceneBumpMapPSColor_MOTION( PS_INPUT_MOTION i )
{ 
	PS_OUTPUT_MOTION Out = (PS_OUTPUT_MOTION)0.f;

	float4 tangentNormalOri = tex2D(tNormalHeightMap, i.texCoord);
	float3 tangentNormal = normalize(tangentNormalOri.xyz * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);
	float3 worldNormal = mul(TBN, tangentNormal);

	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);

	Out.mColor = albedo.r * g_vColorR + albedo.g * g_vColorG + albedo.b * g_vColorB;
	Out.mColor.a = albedo.a;

	Out.mNormal = float4(worldNormal * 0.5f + 0.5f, 0.0);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	Out.mVelocityUV = float4(i.vVelocityUV,1.0f,1.0f);

	return Out;
	//return float4(ambient + diffuse + specular, albedo.a);
} 

//--------------------------------------------------------------------------------------
// Bump mapping shader
//--------------------------------------------------------------------------------------
PS_OUTPUT_MOTION RenderSceneBumpMapPS_MOTION( PS_INPUT_MOTION i )
{ 
	PS_OUTPUT_MOTION Out = (PS_OUTPUT_MOTION)0.f;

	float4 tangentNormalOri = tex2D(tNormalHeightMap, i.texCoord);
	float3 tangentNormal = normalize(tangentNormalOri.xyz * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);
	float3 worldNormal = mul(TBN, tangentNormal);

	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);

	Out.mColor = albedo;
	Out.mNormal = float4(worldNormal * 0.5f + 0.5f, 0.0);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	Out.mVelocityUV = float4(i.vVelocityUV,1.0f,1.0f);
	
	return Out;
	//return float4(ambient + diffuse + specular, albedo.a);
} 

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
	Out.mNormal = float4(worldNormal * 0.5f + 0.5f, 0.0);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);

	return Out;
	//return float4(ambient + diffuse + specular, albedo.a);
} 
int CurNumBones = 2;
VertexShader vsArray[4] = { compile vs_3_0 VS_MAIN(1), 
compile vs_3_0 VS_MAIN(2),
compile vs_3_0 VS_MAIN(3),
compile vs_3_0 VS_MAIN(4)
};

VertexShader vsArray_MOTION[4] = { compile vs_3_0 VS_MAIN_MOTION(1), 
compile vs_3_0 VS_MAIN_MOTION(2),
compile vs_3_0 VS_MAIN_MOTION(3),
compile vs_3_0 VS_MAIN_MOTION(4)
};

technique RenderScene
{
	pass Dynamic_Mesh
	{
		cullmode = none;

		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS(); 
	}

	pass Static_Mesh
	{
		cullmode = ccw;

		VertexShader = compile vs_3_0 RenderSceneVS();
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPSColor(); 
	}

	pass Dynamic_Mesh_Motion
	{
		cullmode = none;

		VertexShader = (vsArray_MOTION[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS_MOTION(); 
	}

	pass Static_Mesh_Motion
	{
		cullmode = ccw;

		VertexShader = compile vs_3_0 RenderSceneVS_MOTION();
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPSColor_MOTION(); 
	}
};