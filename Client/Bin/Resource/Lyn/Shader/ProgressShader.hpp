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

VS_OUTPUT ProgressShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
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

float fValue;

float4 ProgressShader_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
    if(Input.mTexCoord.x > fValue)
        return float4(0,0,0,0);
    
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
    return albedo;
}


technique ProgressShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 ProgressShader_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 ProgressShader_Pass_0_Pixel_Shader_ps_main();
   }
}