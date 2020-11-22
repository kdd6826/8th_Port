struct VS_INPUT
{
	float4 mPosition: POSITION;
	float2 mTexCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 mPosition: POSITION;
	float2 mTexCoord : TEXCOORD0;
	float4 mClipPosition: TEXCOORD1;
	float mDepth : TEXCOORD2;
};

float4x4 matWorld : World;
float4x4 matLightView : View;
float4x4 matLightProj : Projection;

float fFar = 1000.f;

VS_OUTPUT ShadowShader_Pass_0_vs_main(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Output.mPosition = mul(Input.mPosition, matWorld);
	Output.mPosition = mul(Output.mPosition, matLightView);
	Output.mPosition = mul(Output.mPosition, matLightProj);
	
	Output.mClipPosition = Output.mPosition;
	Output.mDepth = Output.mClipPosition.z;
	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
	float4 mClipPosition: TEXCOORD1;
	float mDepth : TEXCOORD2;
};

float4 ShadowShader_Pass_0_ps_main(PS_INPUT Input) : COLOR
{
	return float4(Input.mDepth, 0, 0, 1);
}

float4x4 matView : View;
float4x4 matProj : Projection;

VS_OUTPUT ShadowShader_Pass_1_vs_main( VS_INPUT Input )
{
    VS_OUTPUT Output;

    Output.mPosition = mul(Input.mPosition, matWorld);

    Output.mClipPosition = mul(Output.mPosition, matLightView);
    Output.mClipPosition = mul(Output.mClipPosition, matLightProj);
	Output.mDepth = Output.mClipPosition.z;

	Output.mPosition = mul(Output.mPosition, matView);
	Output.mPosition = mul(Output.mPosition, matProj);

    Output.mTexCoord = Input.mTexCoord;

    return Output;
}

texture ShadowMap;
sampler2D ShadowSampler = sampler_state
{
    Texture = (ShadowMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

float4 vColor;

float4 ShadowShader_Pass_1_ps_main(PS_INPUT Input) : COLOR
{
    float4 albedo = 0.f;

    float2 uv = Input.mClipPosition.xy;
    uv.y = -uv.y;
    uv = uv * 0.5 + 0.5;

	float4 shadowDepth = tex2D(ShadowSampler, uv);

	albedo = shadowDepth.a * vColor;

    return albedo;
}

technique ShadowShader
{
	pass Pass_0
	{
		VertexShader = compile vs_2_0 ShadowShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 ShadowShader_Pass_0_ps_main();
	}

	pass Pass_1
	{
		VertexShader = compile vs_2_0 ShadowShader_Pass_1_vs_main();
		PixelShader = compile ps_2_0 ShadowShader_Pass_1_ps_main();
	}
}