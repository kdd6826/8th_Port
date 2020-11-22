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

VS_OUTPUT LoadingProgressShader_Pass_0_vs_main(VS_INPUT Input)
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
};

struct PS_INPUT
{
	float2 mTexCoord : TEXCOORD0;
};

float fAlpha;
float fCX;
float fCY;
 
float4 LoadingProgressShader_Pass_0_ps_main( PS_INPUT Input ) : COLOR
{
	float uvs = fCX / fCY;
	float minx = 0.5f / uvs;
	float maxx = 1.f - minx;
	float uvx = 0.5f;

	if(minx > Input.mTexCoord.x) {
		uvx = Input.mTexCoord.x * uvs;
	}
	else if(maxx < Input.mTexCoord.x) {
		uvx = (Input.mTexCoord.x - maxx) * uvs + 0.5f;
	}
	Input.mTexCoord.x = uvx;

    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord);
	albedo.a *= fAlpha;
	return albedo;
}

technique LoadingProgressShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 LoadingProgressShader_Pass_0_vs_main();
      PixelShader = compile ps_2_0 LoadingProgressShader_Pass_0_ps_main();
   }
}