#include "Shader_Base.hpp"

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


VS_OUTPUT FadeOut_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Output.mPosition = mul( Input.mPosition, g_matWorld );
	Output.mPosition = mul( Output.mPosition, g_matView );
	Output.mPosition = mul( Output.mPosition, g_matProj );

	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

texture g_BaseTexture;
sampler2D FadeOutSampler = sampler_state
{
	Texture = (g_BaseTexture);
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
};

float FadeVal;

float4 FadeOut_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
	float4 cColor = tex2D(FadeOutSampler, Input.mTexCoord);
	cColor.a = FadeVal;

	return cColor;
}

technique FadeOutShader
{
	pass Pass_0
	{
		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		VertexShader = compile vs_3_0 FadeOut_Pass_0_Vertex_Shader_vs_main();
		PixelShader = compile ps_3_0 FadeOut_Pass_0_Pixel_Shader_ps_main();
	}
}