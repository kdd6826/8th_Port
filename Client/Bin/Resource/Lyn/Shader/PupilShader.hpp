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
   float3 mNormal : TEXCOORD2;
   float3 mPos : TEXCOORD3;
};

float4x4 matWorld : World;
float4x4 matView : View;
float4x4 matProj : Projection;
float4 vLightDir;

VS_OUTPUT PupilShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );

   Output.mNormal = normalize(mul(Input.mNormal, (float3x3)matWorld));
   Output.mDiffuse = saturate(dot(-vLightDir, Output.mNormal));
   Output.mPos = Output.mPosition.xyz;
   
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

texture PupilMap;
sampler2D PupilSampler = sampler_state
{
	Texture = (PupilMap);
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
    float4 mDiffuse : TEXCOORD1;
    float3 mNormal : TEXCOORD2;
    float3 mPos : TEXCOORD3;
};

float4 vColor = 1.f;
float4 vEyeColor = 1.f;
float4 vCamPos1;
float4 vCamPos2;

float4 PupilShader_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord) + 0.4f;
    float2 pupilUV = Input.mTexCoord;
	pupilUV.x = pupilUV.x*1.75f-0.45f;
	pupilUV.y = (pupilUV.y-1.f)*1.75f-0.4f;
    float4 pupil = tex2D(PupilSampler, pupilUV)*vEyeColor;

    if(pupilUV.x < 1.f && pupilUV.x > 0.f && pupilUV.y < 1.f && pupilUV.y > 0.f)
    {
		albedo.rgb = pupil.a * pupil.rgb + (1.f - pupil.a) * albedo.rgb;
	}
	
	albedo *= vColor;
	
	float3 viewDir1 = normalize(Input.mPos - vCamPos1.xyz);
	float3 viewDir2 = normalize(Input.mPos - vCamPos2.xyz);
	float3 reflection1 = normalize(reflect(viewDir1, Input.mNormal));
	float3 reflection2 = normalize(reflect(viewDir2, Input.mNormal));
	
    albedo.rgb += pow(saturate(dot(reflection1, -viewDir1)), 128.f) + pow(saturate(dot(reflection2, -viewDir2)), 512.f);
    
    return albedo;
}

technique PupilShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 PupilShader_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 PupilShader_Pass_0_Pixel_Shader_ps_main();
   }
}