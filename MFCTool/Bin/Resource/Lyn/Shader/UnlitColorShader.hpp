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

float4 vColor;

VS_OUTPUT UnlitColorShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
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

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
};

float fColorRamp;
bool bAdditive;
bool bUseColorAlpha;

float4 UnlitColorShader_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord)*vColor;
    if(bUseColorAlpha && bAdditive) {
		albedo.rgb *= vColor.a;
    }
    albedo.rgb *= fColorRamp;
	return albedo;
}


VS_OUTPUT UnlitColorShader_Pass_1_Vertex_Shader_vs_main(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );

	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

texture DepthMap;
sampler2D DepthSampler = sampler_state
{
	Texture = (DepthMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

float4 UnlitColorShader_Pass_1_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
	float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord)*vColor;
	if(bUseColorAlpha && bAdditive) {
		albedo.rgb *= vColor.a;
	}
	albedo.rgb *= fColorRamp;
	return albedo;
}


technique UnlitColorShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 UnlitColorShader_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 UnlitColorShader_Pass_0_Pixel_Shader_ps_main();
   }

   pass Pass_1
   {
	   VertexShader = compile vs_2_0 UnlitColorShader_Pass_1_Vertex_Shader_vs_main();
	   PixelShader = compile ps_2_0 UnlitColorShader_Pass_1_Pixel_Shader_ps_main();
   }
}