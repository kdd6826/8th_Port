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
float4 vCamPos;
float4 vColor;

VS_OUTPUT HairShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
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

texture SpecularMap;
sampler2D SpecularSampler = sampler_state
{
	Texture = (SpecularMap);
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

float4 vLightColor;

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
    float4 mDiffuse : TEXCOORD1;
    float3 mNormal : TEXCOORD2;
    float3 mPos : TEXCOORD3;
};
 
float4 HairShader_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
    float4 vSpecularMap = tex2D(SpecularSampler, Input.mTexCoord);
    
    float4 halfDiffuse = Input.mDiffuse/2.f+0.5f;
	float3 viewDir = normalize(Input.mPos - vCamPos.xyz);
	float3 reflection = normalize(reflect(viewDir, Input.mNormal));
	float3 specular = saturate(dot(reflection, -viewDir));
	float3 SpecularColor = vSpecularMap.ggg*vLightColor.rgb * (1.f-vSpecularMap.r);
	    
    albedo.rgb *= halfDiffuse * vColor;
    albedo.rgb += SpecularColor*((1.f-cos(specular*3.14f*0.5f))*0.15f + (1.f-cos(pow(specular, 10.f)*3.14f*0.5f))*0.15f);
    
    float d = dot(Input.mNormal, -viewDir);
    if(d > 0.f) albedo.rgb += SpecularColor*smoothstep(0.5f, 1.f, 1.f - max(0.f, d));
    
	return albedo;
}

technique HairShader
{
	pass Pass_0
	{
		Zwriteenable = false;
		Cullmode = none;
		VertexShader = compile vs_2_0 HairShader_Pass_0_Vertex_Shader_vs_main();
		PixelShader = compile ps_3_0 HairShader_Pass_0_Pixel_Shader_ps_main();
	}

	pass Pass_1
	{
		Zwriteenable = true;
		Cullmode = none;
		VertexShader = compile vs_2_0 HairShader_Pass_0_Vertex_Shader_vs_main();
		PixelShader = compile ps_3_0 HairShader_Pass_0_Pixel_Shader_ps_main();
	}
}