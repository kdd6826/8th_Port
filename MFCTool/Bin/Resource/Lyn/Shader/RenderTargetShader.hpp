struct VS_INPUT
{
   float4 mPosition : POSITION;
   float2 mTexCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
   float4 mPosition : POSITION;
   float2 mTexCoord : TEXCOORD0;
};

float4x4 matWorld : World;
float4x4 matView : View;
float4x4 matProj : Projection;

VS_OUTPUT RenderTargetShader_Pass_0_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );
   Output.mPosition = mul( Output.mPosition, matView );
   Output.mPosition = mul( Output.mPosition, matProj );

   Output.mTexCoord = Input.mTexCoord;
   
   return Output;
}

texture AlbedoMap;
sampler2D AlbedoSampler = sampler_state
{
	Texture = (AlbedoMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture NormalMap;
sampler2D NormalSampler = sampler_state
{
	Texture = (NormalMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

texture DepthMap;
sampler2D DepthSampler = sampler_state
{
	Texture = (DepthMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
};

float4 vLightDir;
float fAlpha;

float4 RenderTargetShader_Pass_0_ps_main( PS_INPUT Input ) : COLOR
{
	float4 albedo = tex2D(AlbedoSampler, Input.mTexCoord);
	float4 normal = tex2D(NormalSampler, Input.mTexCoord);
	float4 depth = tex2D(DepthSampler, Input.mTexCoord);

	albedo.a = fAlpha;

	if(depth.r == 1.f) return albedo;

	normal.xyz = normal.xyz*2.f - 1.f;

	float diffuse = saturate(dot(-vLightDir.xyz, normal.xyz)) + 0.1f;
	albedo.rgb *= diffuse/2.f+0.5f;
	albedo.rgb += normal.a;

	return albedo;
}

float4 RenderTargetShader_Pass_1_ps_main( PS_INPUT Input ) : COLOR
{
	float4 albedo = tex2D(AlbedoSampler, Input.mTexCoord);
	albedo.a = fAlpha;
	return albedo;
}

technique RenderTargetShader
{
	pass Pass_0
	{
		VertexShader = compile vs_2_0 RenderTargetShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 RenderTargetShader_Pass_0_ps_main();
	}
	pass Pass_1
	{
		VertexShader = compile vs_2_0 RenderTargetShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 RenderTargetShader_Pass_1_ps_main();
	}
}