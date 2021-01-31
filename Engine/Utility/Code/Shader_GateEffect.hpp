#include "Shader_Base.hpp"

texture		g_BaseTexture;

float		g_fAlpha;

vector		g_color;
vector		g_vGateEffectUV12;
vector		g_vGateEffectUV34;

sampler BaseSampler = sampler_state
{
	texture	= g_BaseTexture;

	minfilter = linear;
	magfilter = linear;
};

struct VS_IN
{
	vector		vPos : POSITION;
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

	Matrix		matWV, matWVP;

	matWV = mul(g_matWorld, g_matView);
	
	matWVP = mul(matWV, g_matProj);


	Out.vPos = mul(vector(In.vPos.xyz, 1.f), matWVP);

	float2 uv = In.vTexUV;

	if(uv.x == 0 && uv.y == 0)
	{
		uv.x = g_vGateEffectUV12.x;
		uv.y = g_vGateEffectUV12.y;
	}
	else if(uv.x == 1 && uv.y == 0)
	{
		uv.x = g_vGateEffectUV12.z;
		uv.y = g_vGateEffectUV12.w;
	}
	else if(uv.x == 1 && uv.y == 1)
	{
		uv.x = g_vGateEffectUV34.x;
		uv.y = g_vGateEffectUV34.y;
	}
	else
	{
		uv.x = g_vGateEffectUV34.z;
		uv.y = g_vGateEffectUV34.w;
	}

	Out.vTexUV = uv;

	return Out;
}

struct PS_IN
{
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
	
	Out.vColor.rgb *= g_color.xyz;

	Out.vColor.a *= g_fAlpha;

	return Out;
}

technique Default_Technique
{
	pass one
	{	
		zenable = true;
 		zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = one;

		cullmode = none;

		VertexShader = compile vs_3_0 VS_MAIN();
		PixelShader = compile ps_3_0 PS_MAIN();
	}

	pass invsrc
	{
		zenable = true;
		zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = invsrcalpha;

		cullmode = none;

		VertexShader = compile vs_3_0 VS_MAIN();
		PixelShader = compile ps_3_0 PS_MAIN();
	}

	pass nononezenable
	{
		zenable = false;
		zwriteenable = false;

		AlphaBlendenable = true;
		srcblend = srcalpha;
		destblend = one;

		cullmode = none;

		VertexShader = compile vs_3_0 VS_MAIN();
		PixelShader = compile ps_3_0 PS_MAIN();
	}
};