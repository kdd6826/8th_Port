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

float fTexCX;
float fTexCY;
float fDrawX;
float fDrawY;
float fDrawCX;
float fDrawCY;
float4 vColor;

VS_OUTPUT SpriteShader_Pass_0_Vertex_Shader_vs_main(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );
	
	float2 uv = Input.mTexCoord;

	if(uv.x == 0 && uv.y == 0) {
		uv.x = fDrawX/fTexCX;
		uv.y = fDrawY/fTexCY;
	}
	else if(uv.x == 1 && uv.y == 0) {
		uv.x = (fDrawX+fDrawCX)/fTexCX;
		uv.y = fDrawY/fTexCY;
	}
	else if(uv.x == 0 && uv.y == 1) {
		uv.x = fDrawX/fTexCX;
		uv.y = (fDrawY+fDrawCY)/fTexCY;
	}
	else {
		uv.x = (fDrawX+fDrawCX)/fTexCX;
		uv.y = (fDrawY+fDrawCY)/fTexCY;
	}

	Output.mTexCoord = uv;

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

float4 SpriteShader_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR
{
    float4 albedo = tex2D(DiffuseSampler, Input.mTexCoord)*vColor;
    albedo.rgb *= fColorRamp;
	return albedo;
}


technique SpriteShader
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 SpriteShader_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 SpriteShader_Pass_0_Pixel_Shader_ps_main();
   }
}