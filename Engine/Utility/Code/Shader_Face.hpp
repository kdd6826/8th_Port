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
texture		g_NormalTexture;
texture		g_BrowTexture;
texture		g_MakeUpTexture;
texture		g_FacePETexture;

float4 vColor = float4(1.f,1.f,1.f,1.f);
float fAmbient = 0.1f;
float fFakeVal = 0.f;
float fFakePow = 0.08f;

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

sampler BrowSampler = sampler_state
{
	Texture = < g_BrowTexture >;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

sampler MakeUpSampler = sampler_state
{
	Texture = < g_MakeUpTexture >;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

sampler FacePESampler = sampler_state
{
	Texture = < g_FacePETexture >;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct VS_IN
{
	float4		vPos : POSITION;
	float2		vTexUV : TEXCOORD0;
	float3		vNormal : NORMAL;
	float3		vInTangent	: TANGENT;
	float3		vInBionormal : BINORMAL;
	float4		BlendWeights    : BLENDWEIGHT;
	float4		BlendIndices    : BLENDINDICES;
};

struct VS_OUT_ALPHA
{
	vector		vPos : POSITION;
	float2		vTexUV : TEXCOORD0;
	float3		vDiffuse : TEXCOORD1;
	float3		vViewWS : TEXCOORD2;
	float3		vReflection : TEXCOORD3;
	float3		vNormal : TEXCOORD4;
	float4		vProjPos	: TEXCOORD5;
};

VS_OUT_ALPHA VS_MAIN_Alpha(VS_IN In, uniform int NumBones)
{
	VS_OUT_ALPHA		Out = (VS_OUT_ALPHA)0;

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

	Out.vPos = mul(float4(Pos.xyz, 1.0f), g_matWorld);
	Normal = mul(Normal, (float3x3)g_matWorld);
	Out.vNormal = normalize(Normal);

	Out.vTexUV = In.vTexUV.xy;

	Out.vViewWS = normalize(Out.vPos.xyz - g_vCamPos.xyz);

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;
	Out.vDiffuse = dot(-g_vLightDir.xyz, Normal);
	Out.vReflection = reflect(g_vLightDir.xyz, Normal);

	return Out;
}

struct VS_OUT
{
	vector		vPos : POSITION;
	float2		vTexUV : TEXCOORD0;
	float3		vLightWS : TEXCOORD1;
	float3		vViewWS : TEXCOORD2;
	float3		vTangent : TEXCOORD3;
	float3		vBiNormal : TEXCOORD4;
	float3		vNormal : TEXCOORD5;
	float4		vProjPos	: TEXCOORD6;
};

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
		Normal += mul(In.vNormal, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Tangent += mul(In.vInTangent, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
		Binormal += mul(In.vInBionormal, MatrixPalette[In.BlendIndices[i]]) * In.BlendWeights[i];
	}
	LastWeight = 1.0f - LastWeight;

	Pos += (mul(In.vPos, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Normal += (mul(In.vNormal, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Tangent += (mul(In.vInTangent, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);
	Binormal += (mul(In.vInBionormal, MatrixPalette[In.BlendIndices[NumBones-1]]) * LastWeight);

	Out.vPos = mul(float4(Pos.xyz, 1.0f), g_matWorld);

	Out.vTexUV = In.vTexUV.xy;

	// Transform the normal, tangent and binormal vectors from object space to homogeneous projection space:
	float3 vNormalWS   = mul( Normal,   (float3x3) g_matWorld );
	float3 vTangentWS  = mul( Tangent,  (float3x3) g_matWorld );
	float3 vBinormalWS = mul( Binormal, (float3x3) g_matWorld );

	Out.vNormal   = normalize( vNormalWS );
	Out.vTangent  = normalize( vTangentWS );
	Out.vBiNormal = normalize( vBinormalWS );

	Out.vViewWS = normalize(Out.vPos.xyz - g_vCamPos.xyz);

	Out.vLightWS = normalize(g_vLightDir);

	Out.vPos = mul(float4(Out.vPos), g_matView);
	Out.vPos = mul(float4(Out.vPos), g_matProj);
	Out.vProjPos = Out.vPos;

	return Out;
}

struct PS_INPUT
{
	float2 texCoord          : TEXCOORD0;
	float3 vLightWS          : TEXCOORD1;   
	float3 vViewWS           : TEXCOORD2; 
	float3 vTangent		 	 : TEXCOORD3;
	float3 vBiNormal		 : TEXCOORD4;
	float3 vNormal			 : TEXCOORD5;
	float4		vProjPos	: TEXCOORD6;
};

struct PS_INPUT_ALPHA
{
	float2 texCoord			: TEXCOORD0;
	float3 vDiffuse			: TEXCOORD1;
	float3 vViewWS			: TEXCOORD2;
	float3 vReflection		: TEXCOORD3;
	float3 vNormal			: TEXCOORD4;
	float4		vProjPos	: TEXCOORD5;
};

struct PS_OUTPUT
{
	float4 RGBColor : COLOR0;
	float4 mVelo : COLOR1;
	float4 mDepth : COLOR2;  
};

PS_OUTPUT RenderSceneBumpMapPS( PS_INPUT_ALPHA i )
{ 
	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);
	float3 diffuse = g_vLightDiffuse.rgb * albedo.rgb * pow(saturate(i.vDiffuse), 0.08);

	float3 ambient = g_vLightAmbient.xyz * g_vMtrlAmbient.xyz * albedo;

	float3 ResultColor = pow(ambient + diffuse, 0.454545);
	
	PS_OUTPUT Out = (PS_OUTPUT)0.f;
	Out.RGBColor.rgb = ResultColor;
	Out.RGBColor.z = pow(albedo.a, 0.454545);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	Out.mVelo = float4(10.f,0.f,0.f,0.f);
	return Out;
}   
//--------------------------------------------------------------------------------------
// Bump mapping shader
//--------------------------------------------------------------------------------------
PS_OUTPUT RenderSceneFakeSSS_Body( PS_INPUT i ) 
{ 
	float3 tangentNormal = tex2D(tNormalHeightMap, i.texCoord).xyz;
	tangentNormal = normalize(tangentNormal * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);
	float3 worldNormal = mul(TBN, tangentNormal);

	float4 albedo = pow(tex2D(BaseSampler, i.texCoord), 2.2);
	float3 lightDir = normalize(i.vLightWS);

	float4 diffuse = saturate(dot(-lightDir, worldNormal)) + float4(0.1f, 0.1f, 0.1f, 1.f);
	diffuse = sin(saturate(diffuse* 0.5f+ 0.5f)*1.57f);

	float3 fakeSour = pow(1.f - cos((diffuse*0.5f + 0.5f)*1.57f), fFakePow);
	fakeSour.r = 1.f + fFakeVal;

	albedo.rgb *= fakeSour + fAmbient;
	albedo.rgb *= diffuse * g_vLightDiffuse;

	float3 ambient = g_vLightAmbient.xyz * g_vMtrlAmbient.xyz * albedo;

	albedo.rgb+= ambient;
	float d = dot(worldNormal, -i.vViewWS) + (dot(lightDir, i.vViewWS)*0.5f + 0.5f);
	if(d > 0.f) albedo.rgb += smoothstep(0.3f, 1.f, 1.f - max(0.f, d))*0.5f;

	albedo = pow(albedo, 0.454545);

	PS_OUTPUT Out = (PS_OUTPUT)0.f;
	Out.RGBColor = albedo;
	Out.mVelo = float4(10.f,0.f,0.f,0.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	return Out;
}   
//--------------------------------------------------------------------------------------
// Bump mapping shader
//--------------------------------------------------------------------------------------
PS_OUTPUT RenderSceneFakeSSS_Face( PS_INPUT i ) 
{ 
	float4 cResultColor = float4( 0, 0, 0, 1 );

	float4 albedo = pow(tex2D( BaseSampler,  i.texCoord ), 2.2);
	float4 cBrowColor = tex2D(BrowSampler,  i.texCoord);
	float4 cMakeUpColor = tex2D(MakeUpSampler,  i.texCoord);
	float4 cFacePE = tex2D(FacePESampler,  i.texCoord);

	float4 LipsColor = (float4)0.f;
	float4 EyeColor = (float4)0.f;
	float4 BrowColor = (float4)0.f;

	LipsColor.rgb = float3(1.0f, 0.f , 0.f);
	EyeColor.rgb = float3(0.f, 0.f, 0.f);
	BrowColor.rgb = float3(0.f, 0.f, 0.f);
	
	albedo.rgb = cBrowColor.a * BrowColor.rgb + (1.f - cBrowColor.a) * albedo.rgb;
	if(cMakeUpColor.r != 0.f) 
		albedo.rgb = cMakeUpColor.a * EyeColor.rgb + (1.f - cMakeUpColor.a) * albedo.rgb;
	else if(cMakeUpColor.b != 0.f) 
		albedo.rgb = cMakeUpColor.a * LipsColor.rgb + (1.f - cMakeUpColor.a) * albedo.rgb;

	float3 tangentNormal = tex2D(tNormalHeightMap, i.texCoord).xyz;
	tangentNormal = normalize(tangentNormal * 2 - 1);

	float3x3 TBN = float3x3(normalize(i.vTangent), normalize(i.vBiNormal), normalize(i.vNormal));
	TBN = transpose(TBN);
	float3 worldNormal = mul(TBN, tangentNormal);

	float3 lightDir = normalize(i.vLightWS);

	float4 diffuse = saturate(dot(-lightDir, worldNormal))  + float4(0.1f, 0.1f, 0.1f, 1.f);
	diffuse = sin(saturate(diffuse * 0.5f+ 0.5f)*1.57f) ;

	float3 fakeSour = pow(1.f - cos((diffuse*0.5f + 0.5f)*1.57f), fFakePow);
	fakeSour.r = 1.f + fFakeVal;

	albedo.rgb *= fakeSour + fAmbient;
	albedo.rgb *= diffuse  * g_vLightDiffuse ;

	float3 specular = 0;
	if(diffuse.x > 0)
	{
		float3 reflection = reflect(lightDir, worldNormal);
		float3 viewDir = normalize(i.vViewWS);

		specular = saturate(dot(reflection, -viewDir));
		specular = pow(specular, g_fPower);
	}

	float3 ambient = g_vLightAmbient.xyz * g_vMtrlAmbient.xyz * albedo;

	albedo.rgb+= ambient;
	albedo.rgb+= specular * cFacePE.xyz * g_vLightSpecular.rgb;
	float d = dot(worldNormal, -i.vViewWS) + (dot(lightDir, i.vViewWS)*0.5f + 0.5f);
	if(d > 0.f) albedo.rgb += smoothstep(0.3f, 1.f, 1.f - max(0.f, d))*0.5f;

	albedo = pow(albedo, 0.454545);

	PS_OUTPUT Out = (PS_OUTPUT)0.f;
	Out.RGBColor = albedo;
	Out.mVelo = float4(10.f,0.f,0.f,0.f);
	Out.mDepth = float4(i.vProjPos.z / i.vProjPos.w, i.vProjPos.w * 0.001f, 0.f, 1.f);
	return Out;
}   

int CurNumBones = 2;
VertexShader vsArray[4] = { compile vs_3_0 VS_MAIN(1), 
compile vs_3_0 VS_MAIN(2),
compile vs_3_0 VS_MAIN(3),
compile vs_3_0 VS_MAIN(4)
};

VertexShader vsArray_Alpha[4] = { compile vs_3_0 VS_MAIN_Alpha(1), 
compile vs_3_0 VS_MAIN_Alpha(2),
compile vs_3_0 VS_MAIN_Alpha(3),
compile vs_3_0 VS_MAIN_Alpha(4)
};


technique RenderScene
{
	pass Fake_SSS_Body
	{
		alphatestenable = false;
		AlphaBlendEnable = false;
		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneFakeSSS_Body(); 
	}

	pass Fake_SSS_Face
	{
		alphatestenable = false;
		AlphaBlendEnable = false;
		VertexShader = (vsArray[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneFakeSSS_Face(); 
	}

	pass AlphaBlending
	{
		alphatestenable = true;
		alphafunc = greaterEqual;
		alpharef = 0x0000007f;

		//AlphaBlendEnable = false;
		AlphaBlendEnable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		VertexShader = (vsArray_Alpha[CurNumBones]);
		PixelShader  = compile ps_3_0 RenderSceneBumpMapPS(); 
	}

};
