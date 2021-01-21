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

VS_OUTPUT ColorShader_Pass_0_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );
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

texture DiffuseMapP;
sampler2D DiffuseSamplerP = sampler_state
{
	Texture = (DiffuseMapP);
	MipFilter = POINT;
	MinFilter = POINT;
	MagFilter = POINT;
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
};

float4 vColor;
 
float4 ColorShader_Pass_0_ps_main( PS_INPUT Input ) : COLOR
{
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);	

	albedo *= vColor;
	return albedo;
}

float4 ColorShader_Pass_1_ps_main( PS_INPUT Input ) : COLOR
{
	float4 albedo = tex2D(DiffuseSamplerP, Input.mTexCoord);	

	albedo *= vColor;
	return albedo;
}


technique ColorShader
{
	pass Pass_0
	{
		VertexShader = compile vs_2_0 ColorShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 ColorShader_Pass_0_ps_main();
	}
	pass Pass_1
	{
		VertexShader = compile vs_2_0 ColorShader_Pass_0_vs_main();
		PixelShader = compile ps_2_0 ColorShader_Pass_1_ps_main();
	}
}