struct VS_INPUT
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal: NORMAL;
	float3 mTangent : TANGENT;
	float3 mBinormal : BINORMAL;
};

struct VS_OUTPUT
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float mDepth : TEXCOORD4;
};

float4x4 g_matWorld : World;
float4x4 g_matView : View;
float4x4 g_matProj : Projection;

float4 vLightDir;	//
float4 vColor;
float fGrid;

float fFar = 1000.f;

VS_OUTPUT TerrainShader_Pass_0_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, g_matWorld );
   Output.mNormal = normalize(mul(Input.mNormal, (float3x3)g_matWorld));
   Output.mTangent = normalize(mul(Input.mTangent, (float3x3)g_matWorld));
   Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)g_matWorld));
   Output.mPosition = mul( Output.mPosition, g_matView );
   Output.mPosition = mul( Output.mPosition, g_matProj );
   Output.mDepth = Output.mPosition.z / fFar;

   Output.mTexCoord = Input.mTexCoord;
   
   return Output;
}

texture DiffuseMap;
sampler2D DiffuseSampler = sampler_state
{
	Texture = (DiffuseMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture BumpMap;
sampler2D BumpSampler = sampler_state
{
	Texture = (BumpMap);
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

texture RenderTarget;
sampler2D RenderTargetSampler = sampler_state
{
	Texture = (RenderTarget);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float mDepth : TEXCOORD4;
};

float fFog = 1.5f;

float4 TerrainShader_Pass_0_ps_main( PS_INPUT Input ) : COLOR
{
    float4 rtAlbedo = tex2D(RenderTargetSampler, Input.mTexCoord);
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord * fGrid);

	albedo.rgb = rtAlbedo.a * rtAlbedo.rgb + (1.f - rtAlbedo.a) * albedo.rgb;

    float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord * fGrid);
    bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);
    
    float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	//albedo *= vColor;

	albedo.rgb *= 1.f - Input.mDepth.r*fFog;
	albedo.rgb += Input.mDepth.r*fFog;

	return albedo;
}

struct PS_OUTPUT
{
	float4 mAlbedo : COLOR0;
	float4 mNormal : COLOR1;
	float4 mDepth : COLOR2;
};

PS_OUTPUT TerrainShader_Pass_1_ps_main( PS_INPUT Input )
{
	PS_OUTPUT Output;

    float4 rtAlbedo = tex2D(RenderTargetSampler, Input.mTexCoord);
	Output.mAlbedo = tex2D(DiffuseSampler, Input.mTexCoord * fGrid);

	Output.mAlbedo.rgb = rtAlbedo.a * rtAlbedo.rgb + (1.f - rtAlbedo.a) * Output.mAlbedo.rgb;
	//Output.mAlbedo *= vColor;

    float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord * fGrid);
    bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);
    
    float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	Output.mNormal = float4(bumpNormal*0.5f + 0.5f, 0.f);
	Output.mDepth = Input.mDepth;

	return Output;
}

texture DiffuseMap1;
sampler2D DiffuseSampler1 = sampler_state
{
	Texture = (DiffuseMap1);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture DiffuseMap2;
sampler2D DiffuseSampler2 = sampler_state
{
	Texture = (DiffuseMap2);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture DiffuseMap3;
sampler2D DiffuseSampler3 = sampler_state
{
	Texture = (DiffuseMap3);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture DiffuseMap4;
sampler2D DiffuseSampler4 = sampler_state
{
	Texture = (DiffuseMap4);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture BumpMap1;
sampler2D BumpSampler1 = sampler_state
{
	Texture = (BumpMap1);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture BumpMap2;
sampler2D BumpSampler2 = sampler_state
{
	Texture = (BumpMap2);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture BumpMap3;
sampler2D BumpSampler3 = sampler_state
{
	Texture = (BumpMap3);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture BumpMap4;
sampler2D BumpSampler4 = sampler_state
{
	Texture = (BumpMap4);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture FilterMap1;
sampler2D FilterSampler1 = sampler_state
{
	Texture = (FilterMap1);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture FilterMap2;
sampler2D FilterSampler2 = sampler_state
{
	Texture = (FilterMap2);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture FilterMap3;
sampler2D FilterSampler3 = sampler_state
{
	Texture = (FilterMap3);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

float4 TerrainShader_Pass_2_ps_main( PS_INPUT Input ) : COLOR
{
	float4 albedo;
	float4 bumpMap;
	float4 TexAlbedo[4];
	float4 TexBumpMap[4];
	float4 TexFilter[3];

	TexAlbedo[0] = tex2D(DiffuseSampler1, Input.mTexCoord * fGrid);
	TexBumpMap[0] = tex2D(BumpSampler1, Input.mTexCoord * fGrid);

	albedo = TexAlbedo[0];
	bumpMap = TexBumpMap[0];

	TexAlbedo[1] = tex2D(DiffuseSampler2, Input.mTexCoord * fGrid);
	TexBumpMap[1] = tex2D(BumpSampler2, Input.mTexCoord * fGrid);
	TexFilter[0] = tex2D(FilterSampler1, Input.mTexCoord);

	TexAlbedo[2] = tex2D(DiffuseSampler3, Input.mTexCoord * fGrid);
	TexBumpMap[2] = tex2D(BumpSampler3, Input.mTexCoord * fGrid);
	TexFilter[1] = tex2D(FilterSampler2, Input.mTexCoord);

	TexAlbedo[3] = tex2D(DiffuseSampler4, Input.mTexCoord * fGrid);
	TexBumpMap[3] = tex2D(BumpSampler4, Input.mTexCoord * fGrid);
	TexFilter[2] = tex2D(FilterSampler3, Input.mTexCoord);

	for(int i = 0; i < 3; ++i) {
		albedo = albedo * (1.f - TexFilter[i]) + TexAlbedo[i+1] * TexFilter[i];
		bumpMap = bumpMap * (1.f - TexFilter[i]) + TexBumpMap[i+1] * TexFilter[i];
	}

	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	albedo *= vColor;

	return albedo;
}

struct VS_OUTPUT_4
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float mDepth : TEXCOORD4;
	float2 mVelocity : TEXCOORD5;
};

float4x4 g_matWorldLast;
float4x4 g_matViewLast;

VS_OUTPUT_4 TerrainShader_Pass_3_vs_main(VS_INPUT Input)
{
	VS_OUTPUT_4 Output;

	Output.mPosition = mul( Input.mPosition, g_matWorld );
	Output.mNormal = normalize(mul(Input.mNormal, (float3x3)g_matWorld));
	Output.mTangent = normalize(mul(Input.mTangent, (float3x3)g_matWorld));
	Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)g_matWorld));
	Output.mPosition = mul( Output.mPosition, g_matView );
	Output.mPosition = mul( Output.mPosition, g_matProj );
	Output.mDepth = Output.mPosition.z / fFar;

	float4 vPosProjSpaceCurrent = Output.mPosition;
	float4 vPosProjSpaceLast = mul( Input.mPosition, g_matWorldLast );
	vPosProjSpaceLast = mul( vPosProjSpaceLast, g_matViewLast );
	vPosProjSpaceLast = mul( vPosProjSpaceLast, g_matProj );

	vPosProjSpaceCurrent /= abs(vPosProjSpaceCurrent.w);
	vPosProjSpaceLast /= abs(vPosProjSpaceLast.w);

	Output.mVelocity = -(vPosProjSpaceCurrent - vPosProjSpaceLast).xy / 2.f;
	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

struct PS_INPUT_5
{
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float mDepth : TEXCOORD4;
	float2 mVelocity : TEXCOORD5;
};

struct PS_OUTPUT_5
{
	float4 mAlbedo : COLOR0;
	float4 mVelocity : COLOR1;
};

PS_OUTPUT_5 TerrainShader_Pass_3_ps_main( PS_INPUT_5 Input )
{
	float4 rtAlbedo = tex2D(RenderTargetSampler, Input.mTexCoord);
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord * fGrid);

	albedo.rgb = rtAlbedo.a * rtAlbedo.rgb + (1.f - rtAlbedo.a) * albedo.rgb;

	float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord * fGrid);
	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	albedo *= vColor;

	albedo.rgb *= 1.f - Input.mDepth.r*fFog;
	albedo.rgb += Input.mDepth.r*fFog;

	PS_OUTPUT_5 Output;

	Output.mAlbedo = albedo;
	Output.mVelocity = float4(Input.mVelocity,1.0f,1.0f);

	return Output;
}

technique TerrainShader
{
	pass Pass_0
	{
		VertexShader = compile vs_2_0 TerrainShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 TerrainShader_Pass_0_ps_main();
	}

	pass Pass_1
	{
		VertexShader = compile vs_2_0 TerrainShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 TerrainShader_Pass_1_ps_main();
	}

	pass Pass_2
	{
		VertexShader = compile vs_2_0 TerrainShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 TerrainShader_Pass_2_ps_main();
	}

	pass Pass_3
	{
		VertexShader = compile vs_2_0 TerrainShader_Pass_3_vs_main();
		PixelShader = compile ps_2_0 TerrainShader_Pass_3_ps_main();
	}
}