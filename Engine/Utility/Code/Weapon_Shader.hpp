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

float4x4 matViewLast;
float4x4 matWorldLast;

float4 vLightDir;
float4 vCamPos;
float4 vColor;

VS_OUTPUT WeaponShader_Pass_0_vs_main(VS_INPUT Input)
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

texture g_BaseTexture;
sampler2D DiffuseSampler = sampler_state
{
	Texture = (g_BaseTexture);
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
 
float4 WeaponShader_Pass_0_ps_main( PS_INPUT Input ) : COLOR
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
	float3 mNormal: NORMAL;
	float3 mTangent : TANGENT;
	float3 mBinormal : BINORMAL;
	float2 mTexCoord : TEXCOORD0;
};

struct VS_OUTPUT_1
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float3 mViewDir : TEXCOORD4;
	float3 mReflection : TEXCOORD5;
};

VS_OUTPUT_1 WeaponShader_Pass_1_vs_main(VS_INPUT_1 Input)
{
	VS_OUTPUT_1 Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
	Output.mTangent = normalize(mul(Input.mTangent, (float3x3)matWorld));
	Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)matWorld));
	Output.mViewDir = normalize(Output.mPosition.xyz - vCamPos.xyz);
	Output.mReflection = normalize(reflect(vLightDir.xyz, Output.mNormal));
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );

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
	float3 mViewDir : TEXCOORD4;
	float3 mReflection : TEXCOORD5;
};

float4 WeaponShader_Pass_1_ps_main( PS_INPUT_1 Input ) : COLOR
{
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
	float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	albedo *= vColor;

	float3 reflection = Input.mReflection;
	float3 viewDir = Input.mViewDir;
	float specular = 0;

	specular = saturate(dot(reflection, -viewDir));
	albedo.rgb += pow(specular, 0.2f)*0.05f + pow(specular, 10.f)*0.2f + pow(specular, 20.f)*0.3f;

	float d = dot(Input.mNormal, -viewDir);
	if(d > 0.f) albedo.rgb += smoothstep(0.4f, 1.f, 1.f - max(0.f, d));

	return albedo;
}

struct PS_OUTPUT
{
	float4 mAlbedo : COLOR0;
	float4 mNormal : COLOR1;
};

PS_OUTPUT WeaponShader_Pass_2_ps_main( PS_INPUT_1 Input )
{
	PS_OUTPUT Output;

	Output.mAlbedo = tex2D(DiffuseSampler, Input.mTexCoord);
	float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float3 reflection = Input.mReflection;
	float3 viewDir = Input.mViewDir;
	float specular = 0;
	Output.mNormal.a = 0.f;

	specular = saturate(dot(reflection, -viewDir));
	Output.mNormal.a += pow(specular, 0.2f)*0.05f + pow(specular, 10.f)*0.2f + pow(specular, 20.f)*0.3f;

	float d = dot(bumpNormal, -viewDir);
	if(d > 0.f) Output.mNormal.a += smoothstep(0.4f, 1.f, 1.f - max(0.f, d));

	Output.mNormal.xyz = bumpNormal*0.5f + 0.5f;
	Output.mAlbedo *= vColor;

	return Output;
}

struct VS_OUTPUT_2
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float3 mNormal : TEXCOORD1;
	float3 mTangent : TEXCOORD2;
	float3 mBinormal : TEXCOORD3;
	float3 mViewDir : TEXCOORD4;
	float3 mReflection : TEXCOORD5;
	float2 mVelocity : TEXCOORD6;
};

VS_OUTPUT_2 WeaponShader_Pass_2_vs_main(VS_INPUT_1 Input)
{
	VS_OUTPUT_2 Output;
	float4x4 matViewProj = mul( matView, matProj );

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
	Output.mTangent = normalize(mul(Input.mTangent, (float3x3)matWorld));
	Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)matWorld));
	Output.mViewDir = normalize(Output.mPosition.xyz - vCamPos.xyz);
	Output.mReflection = normalize(reflect(vLightDir.xyz, Output.mNormal));
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );

	float4 vPosProjSpaceCurrent = Output.mPosition;
	float4 vPosProjSpaceLast = mul( Input.mPosition, matWorldLast );
	vPosProjSpaceLast = mul( vPosProjSpaceLast, matViewLast );
	vPosProjSpaceLast = mul( vPosProjSpaceLast, matProj );

	vPosProjSpaceCurrent /= abs(vPosProjSpaceCurrent.w);
	vPosProjSpaceLast /= abs(vPosProjSpaceLast.w);

	Output.mVelocity = -(vPosProjSpaceCurrent - vPosProjSpaceLast).xy / 2.f;
	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

struct PS_OUTPUT_2
{
	float4 mAlbedo : COLOR0;
	float4 mVelocity : COLOR1;
};

PS_OUTPUT_2 WeaponShader_Pass_3_ps_main( VS_OUTPUT_2 Input )
{
	PS_OUTPUT_2 Output;

	Output.mAlbedo = tex2D(DiffuseSampler, Input.mTexCoord);
	float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
	bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);

	float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);

	float diffuse = saturate(dot(-vLightDir.xyz, bumpNormal)) + 0.1f;
	Output.mAlbedo.rgb *= diffuse/2.f+0.5f;
	Output.mAlbedo *= vColor;

	float3 reflection = Input.mReflection;
	float3 viewDir = Input.mViewDir;
	float specular = 0;

	specular = saturate(dot(reflection, -viewDir));
	Output.mAlbedo.rgb += pow(specular, 0.2f)*0.05f + pow(specular, 10.f)*0.2f + pow(specular, 20.f)*0.3f;

	float d = dot(Input.mNormal, -viewDir);
	if(d > 0.f) Output.mAlbedo.rgb += smoothstep(0.4f, 1.f, 1.f - max(0.f, d));

	Output.mVelocity = float4(Input.mVelocity,1.0f,1.0f);

	return Output;
}

technique WeaponShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 WeaponShader_Pass_0_vs_main();
      PixelShader = compile ps_2_0 WeaponShader_Pass_0_ps_main();
   }
   
   pass Pass_1
   {
      VertexShader = compile vs_2_0 WeaponShader_Pass_1_vs_main();
      PixelShader = compile ps_3_0 WeaponShader_Pass_1_ps_main();
   }

   pass Pass_2
   {
	   VertexShader = compile vs_2_0 WeaponShader_Pass_1_vs_main();
	   PixelShader = compile ps_3_0 WeaponShader_Pass_2_ps_main();
   }

   pass Pass_3
   {
	   VertexShader = compile vs_2_0 WeaponShader_Pass_2_vs_main();
	   PixelShader = compile ps_3_0 WeaponShader_Pass_3_ps_main();
   }
}