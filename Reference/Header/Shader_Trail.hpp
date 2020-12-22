#include "Shader_Base.hpp"

texture		g_BaseTexture;
vector		g_vecColor;

sampler BaseSampler = sampler_state
{
	texture	= g_BaseTexture;

	minfilter = linear;
	magfilter = linear;
};

struct VS_IN
{
	vector		vPos : POSITION;
	vector		vNormal : NORMAL;
	float2		vTexUV : TEXCOORD0;
};

struct VS_OUT
{
	vector		vPos : POSITION;
	float2		vTexUV : TEXCOORD0;
};

VS_OUT VS_MAIN(VS_IN In)
{
	VS_OUT		Out = (VS_OUT)0;

	Matrix matVP = mul(g_matView, g_matProj);

	Out.vPos = mul(float4(In.vPos.xyz, 1.0f), matVP);
	Out.vTexUV = In.vTexUV;

	return Out;
}

struct PS_IN
{
	vector		vNormal : NORMAL;
	float2		vTexUV : TEXCOORD0;
};

struct PS_OUT
{
	vector		vColor : COLOR0;
};

PS_OUT PS_MAIN(PS_IN In)
{
	PS_OUT	Out = (PS_OUT)0.f;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);

	return Out;
}

PS_OUT PS_MAIN2(PS_IN In)
{
	PS_OUT	Out = (PS_OUT)0.f;

	Out.vColor = tex2D(BaseSampler, In.vTexUV);

	Out.vColor.rgb *= g_vecColor.rgb;

	return Out;
}

technique Default_Technique
{
	pass Default
	{
		cullmode = none;
		
		zenable = true;
		zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = one;

		VertexShader = compile vs_3_0 VS_MAIN();
		PixelShader = compile ps_3_0 PS_MAIN();
	}

	pass One
	{
		cullmode = none;
		
		zenable = true;
		zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		VertexShader = compile vs_3_0 VS_MAIN();
		PixelShader = compile ps_3_0 PS_MAIN();
	}

	pass Two
	{
		cullmode = none;
		
		zenable = true;
		zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = one;

		VertexShader = compile vs_3_0 VS_MAIN();
		PixelShader = compile ps_3_0 PS_MAIN2();
	}
};
