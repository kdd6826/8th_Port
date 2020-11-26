struct VS_INPUT
{
   float4 mPosition : POSITION;
   float3 mNormal: NORMAL;
   float2 mTexCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
   float4 mPosition : POSITION;
   float2 mTexCoord : TEXCOORD0;
   float4 mDiffuse : TEXCOORD1;
   float3 mViewDir : TEXCOORD2;
   float3 mReflection : TEXCOORD3;
};

float4x4 matWorld : World;
float4x4 matView : View;
float4x4 matProj : Projection;

float4 vLightDir;
float4 vCamPos;
float4 vColor;

VS_OUTPUT SpecularShader_Pass_0_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );

   float3 vWorldNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
   Output.mDiffuse = saturate(dot(-vLightDir.xyz, vWorldNormal));
   Output.mViewDir = normalize(Output.mPosition.xyz - vCamPos.xyz);
   Output.mReflection = normalize(reflect(vLightDir.xyz, vWorldNormal));

   Output.mPosition = mul( Output.mPosition, matView );
   Output.mPosition = mul( Output.mPosition, matProj );

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

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
    float4 mDiffuse : TEXCOORD1;
    float3 mViewDir: TEXCOORD2;
	float3 mReflection: TEXCOORD3;
};
 
float4 SpecularShader_Pass_0_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
	albedo *= Input.mDiffuse;
	albedo *= vColor;

    float3 reflection = Input.mReflection;
	float3 viewDir = Input.mViewDir;
	float3 specular = 0;
	
	specular = saturate(dot(reflection, -viewDir));

    albedo.rgb += pow(specular, 0.2f)*0.05f + pow(specular, 10.f)*0.2f + pow(specular, 20.f)*0.3f;
	return albedo;
}




struct VS_INPUT_1
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal: NORMAL;
	float3 mTangent : TANGENT;
	float3 mBinormal : BINORMAL;
};

struct VS_OUTPUT_1
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float3 mPos : TEXCOORD4;
	float mDepth : TEXCOORD5;
};

float fFar = 1000.f;

VS_OUTPUT_1 SpecularShader_Pass_1_vs_main(VS_INPUT_1 Input)
{
	VS_OUTPUT_1 Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
	Output.mTangent = normalize(mul(Input.mTangent, (float3x3)matWorld));
	Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)matWorld));
	Output.mPos = Output.mPosition.xyz;
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );
	Output.mDepth = Output.mPosition.z / fFar;

	Output.mTexCoord = Input.mTexCoord;

	return Output;
}


texture BumpMap;
sampler2D BumpSampler = sampler_state
{
	Texture = (BumpMap);
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};


struct PS_INPUT_1
{
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float3 mPos : TEXCOORD4;
	float mDepth : TEXCOORD5;
};

float fFog = 1.5f;

float4 SpecularShader_Pass_1_ps_main( PS_INPUT_1 Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
    float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
    bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);
    
    float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	albedo *= vColor;
	
	float3 viewDir = normalize(Input.mPos - vCamPos.xyz);	
	float3 reflection = normalize(reflect(vLightDir.xyz, bumpNormal));
	float3 specular = 0;
	
	albedo.rgb += pow(saturate(dot(reflection, -viewDir)), 30.f)*0.5f;

	float d = dot(bumpNormal, -viewDir) + (dot(vLightDir.xyz, viewDir)/2.f + 0.5f);
    if(d > 0.f) albedo.rgb += smoothstep(0.3f, 1.f, 1.f - max(0.f, d))*0.5f;

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

PS_OUTPUT SpecularShader_Pass_2_ps_main( PS_INPUT_1 Input )
{
	PS_OUTPUT Output;

	Output.mAlbedo = tex2D(DiffuseSampler, Input.mTexCoord);
	float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 viewDir = normalize(Input.mPos - vCamPos.xyz);	
	float3 reflection = normalize(reflect(vLightDir.xyz, bumpNormal));
	float specular = 0;

	specular += pow(saturate(dot(reflection, -viewDir)), 30.f)*0.5f;

	float d = dot(bumpNormal, -viewDir) + (dot(vLightDir.xyz, viewDir)/2.f + 0.5f);
	if(d > 0.f) specular += smoothstep(0.3f, 1.f, 1.f - max(0.f, d))*0.5f;

	Output.mNormal = float4(bumpNormal*0.5f + 0.5f, specular);
	Output.mAlbedo *= vColor;
	Output.mAlbedo.rgb *= 1.f - Input.mDepth.r*fFog;
	Output.mAlbedo.rgb += Input.mDepth.r*fFog;
	Output.mDepth = Input.mDepth;

	return Output;
}


struct VS_OUTPUT_3
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float3 mPos : TEXCOORD4;
	float mDepth : TEXCOORD5;
	float4 mCurrent : TEXCOORD6;
	float4 mLast : TEXCOORD7;
};

float4x4 matViewLast;
float4x4 matWorldLast;

VS_OUTPUT_3 SpecularShader_Pass_3_vs_main(VS_INPUT_1 Input)
{
	VS_OUTPUT_3 Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
	Output.mTangent = normalize(mul(Input.mTangent, (float3x3)matWorld));
	Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)matWorld));
	Output.mPos = Output.mPosition.xyz;
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );
	Output.mDepth = Output.mPosition.z / fFar;

	Output.mCurrent = Output.mPosition;
	Output.mLast = mul( Input.mPosition, matWorldLast );
	Output.mLast = mul( Output.mLast, matViewLast );
	Output.mLast = mul( Output.mLast, matProj );
	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

struct PS_INPUT_3
{
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float3 mPos : TEXCOORD4;
	float mDepth : TEXCOORD5;
	float4 mCurrent : TEXCOORD6;
	float4 mLast : TEXCOORD7;
};

struct PS_OUTPUT_3
{
	float4 mAlbedo : COLOR0;
	float4 mVelocity : COLOR1;
};


PS_OUTPUT_3 SpecularShader_Pass_3_ps_main( PS_INPUT_3 Input )
{
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
	float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	albedo *= vColor;

	float3 viewDir = normalize(Input.mPos - vCamPos.xyz);	
	float3 reflection = normalize(reflect(vLightDir.xyz, bumpNormal));
	float3 specular = 0;

	albedo.rgb += pow(saturate(dot(reflection, -viewDir)), 30.f)*0.5f;

	float d = dot(bumpNormal, -viewDir) + (dot(vLightDir.xyz, viewDir)/2.f + 0.5f);
	if(d > 0.f) albedo.rgb += smoothstep(0.3f, 1.f, 1.f - max(0.f, d))*0.5f;

	albedo.rgb *= 1.f - Input.mDepth.r*fFog;
	albedo.rgb += Input.mDepth.r*fFog;

	PS_OUTPUT_3 Output;

	Input.mCurrent /= abs(Input.mCurrent.w);
	Input.mLast /= abs(Input.mLast.w);

	float2 vVelocity = -(Input.mCurrent - Input.mLast).xy / 2.f;

	Output.mAlbedo = albedo;
	Output.mVelocity = float4(vVelocity,1.0f,1.0f);

	return Output;
}


technique SpecularShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 SpecularShader_Pass_0_vs_main();
      PixelShader = compile ps_2_0 SpecularShader_Pass_0_ps_main();
   }
   
   pass Pass_1
   {
      VertexShader = compile vs_2_0 SpecularShader_Pass_1_vs_main();
      PixelShader = compile ps_3_0 SpecularShader_Pass_1_ps_main();
   }

   pass Pass_2
   {
	   VertexShader = compile vs_2_0 SpecularShader_Pass_1_vs_main();
	   PixelShader = compile ps_3_0 SpecularShader_Pass_2_ps_main();
   }

   pass Pass_3
   {
	   VertexShader = compile vs_2_0 SpecularShader_Pass_3_vs_main();
	   PixelShader = compile ps_3_0 SpecularShader_Pass_3_ps_main();
   }
}