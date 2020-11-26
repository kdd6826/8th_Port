struct VS_INPUT
{
   float4 mPosition : POSITION;
   float2 mTexCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
   float4 mPosition : POSITION;
   float2 mTexCoord : TEXCOORD0;
   float2 mPos : TEXCOORD1;
};

float4x4 matWorld : World;
float4x4 matView : View;
float4x4 matProj : Projection;

float4 vColor;

VS_OUTPUT MaskShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
{
   VS_OUTPUT Output;
   
   Output.mPosition = mul( Input.mPosition, matWorld );
   Output.mPosition = mul( Output.mPosition, matView );
   Output.mPosition = mul( Output.mPosition, matProj );
   Output.mPos.x = (Output.mPosition.x / Output.mPosition.w)*0.5f + 0.5f;
   Output.mPos.y = -(Output.mPosition.y / Output.mPosition.w)*0.5f + 0.5f;

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

texture MaskMap;
sampler2D MaskSampler = sampler_state
{
	Texture = (MaskMap);
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
	float2 mPos : TEXCOORD1;
};

float fColorRamp;
bool bAdditive;
bool bUseColorAlpha;

float4 MaskShader_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord)*vColor;
	float mask = 1.f - tex2D(MaskSampler, Input.mPos).x;
    if(bUseColorAlpha && bAdditive) {
		albedo.rgb *= vColor.a;
    }
    albedo.rgb *= fColorRamp * mask;
	return albedo;
}


technique MaskShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 MaskShader_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 MaskShader_Pass_0_Pixel_Shader_ps_main();
   }
}