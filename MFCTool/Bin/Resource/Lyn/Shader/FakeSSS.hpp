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
   float3 mNormal : TEXCOORD4;
};

float4x4 matWorld : World;
float4x4 matView : View;
float4x4 matProj : Projection;
float4 vCamPos;
float4 vLightDir;

VS_OUTPUT FakeSSS_Pass_0_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );

   Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
   Output.mDiffuse = saturate(dot(-vLightDir, Output.mNormal));
   Output.mViewDir = normalize(Output.mPosition.xyz - vCamPos.xyz);
   Output.mReflection = normalize(reflect(vLightDir, Output.mNormal));
   
   Output.mPosition = mul( Output.mPosition, matView );
   Output.mPosition = mul( Output.mPosition, matProj );

   Output.mTexCoord = Input.mTexCoord;
   
   return Output;
}

texture DiffuseMap;
sampler2D DiffuseSampler = sampler_state
{
	Texture = (DiffuseMap);
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
    float4 mDiffuse : TEXCOORD1;
    float3 mViewDir: TEXCOORD2;
	float3 mReflection: TEXCOORD3;
	float3 mNormal : TEXCOORD4;
};

float4 vColor;
float fAmbient = 0.1f;
float fFakeVal = 0.f;
float fFakePow = 0.08f;
float fShadowDepth = 2.f;
float fShadowPow = 1.f;

float4 FakeSSS_Pass_0_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
    float3 diffuse = pow(sin(saturate(Input.mDiffuse/fShadowDepth + (1.f - 1.f/fShadowDepth))*1.57f), fShadowPow);
    float3 fakeSour = pow(1.f - cos((Input.mDiffuse/2.f + 0.5f)*1.57f), fFakePow);
    fakeSour.r = 1.f + fFakeVal;
    
    float3 reflection = Input.mReflection;
	float3 viewDir = Input.mViewDir;
	float3 specular = 0;
	
	specular = saturate(dot(reflection, -viewDir));

    albedo.rgb *= fakeSour + fAmbient;
    albedo.rgb *= diffuse * vColor;
    albedo.rgb += (specular*0.02f + pow(specular, 2.f)*0.05f + pow(specular, 20.f)*0.2f)*0.5f;

    float d = dot(Input.mNormal, -Input.mViewDir) + (dot(vLightDir, Input.mViewDir)/2.f + 0.5f);
    if(d > 0.f) albedo.rgb += smoothstep(0.3f, 1.f, 1.f - max(0.f, d));
	
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
   float3 mViewDir : TEXCOORD4;
};

VS_OUTPUT_1 FakeSSS_Pass_1_vs_main(VS_INPUT_1 Input)
{
   VS_OUTPUT_1 Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );
   Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
   Output.mTangent = normalize(mul(Input.mTangent, (float3x3)matWorld));
   Output.mBinormal = normalize(mul(Input.mBinormal, (float3x3)matWorld));
   Output.mViewDir = normalize(Output.mPosition.xyz - vCamPos.xyz);
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

texture BrowMap;
sampler2D BrowSampler = sampler_state
{
	Texture = (BrowMap);
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

texture MakeupMap;
sampler2D MakeupSampler = sampler_state
{
	Texture = (MakeupMap);
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

texture FacePEMap;
sampler2D FacePESampler = sampler_state
{
	Texture = (FacePEMap);
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
};

float4 vMakeUpEyeColor;
float4 vMakeUpLipsColor;

float4 FakeSSS_Pass_1_ps_main( PS_INPUT_1 Input ) : COLOR
{
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
	float4 browMap = tex2D(BrowSampler, Input.mTexCoord);
	float4 makeupMap = tex2D(MakeupSampler, Input.mTexCoord);
	float facePE = tex2D(FacePESampler, Input.mTexCoord);
    
    albedo.rgb = browMap.a * browMap.rgb + (1.f - browMap.a) * albedo.rgb;
    if(makeupMap.r != 0.f) albedo.rgb = makeupMap.a * vMakeUpEyeColor.rgb + (1.f - makeupMap.a) * albedo.rgb;
    else if(makeupMap.b != 0.f) albedo.rgb = makeupMap.a * vMakeUpLipsColor.rgb + (1.f - makeupMap.a) * albedo.rgb;
    
    float4 bumpMap = tex2D(BumpSampler, Input.mTexCoord);
    bumpMap.xyz = normalize(bumpMap.xyz*2.f - 1.f);
    float3 bumpNormal = (bumpMap.x * Input.mTangent) + (bumpMap.y * Input.mBinormal) + (bumpMap.z * Input.mNormal);
	float4 diffuse = saturate(dot(-vLightDir, bumpNormal)) + float4(0.1f, 0.1f, 0.1f, 1.f);
    diffuse = pow(sin(saturate(diffuse/fShadowDepth + (1.f - 1.f/fShadowDepth))*1.57f), fShadowPow);
    
    float3 fakeSour = pow(1.f - cos((diffuse/2.f + 0.5f)*1.57f), fFakePow);
    fakeSour.r = 1.f + fFakeVal;

	float3 viewDir = Input.mViewDir;
	float3 reflection = normalize(reflect(vLightDir, bumpNormal));
	float3 specular = 0;
	
	specular = pow(saturate(dot(reflection, -viewDir)), 6.f);
	
    albedo.rgb *= fakeSour + fAmbient;
	albedo.rgb *= diffuse * vColor;
    albedo.rgb += facePE * specular;
    
    float d = dot(Input.mNormal, -Input.mViewDir) + (dot(vLightDir, Input.mViewDir)/2.f + 0.5f);
    if(d > 0.f) albedo.rgb += smoothstep(0.3f, 1.f, 1.f - max(0.f, d))*0.5f;
	
    return albedo;
}


technique FakeSSS
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 FakeSSS_Pass_0_vs_main();
      PixelShader = compile ps_2_0 FakeSSS_Pass_0_ps_main();
   }
   
   pass Pass_1
   {
      VertexShader = compile vs_2_0 FakeSSS_Pass_1_vs_main();
      PixelShader = compile ps_3_0 FakeSSS_Pass_1_ps_main();
   }
}