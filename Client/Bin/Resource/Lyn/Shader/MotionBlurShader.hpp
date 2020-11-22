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

VS_OUTPUT PostProcessMotionBlurVS(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );

	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

texture DiffuseMap;
sampler DiffuseSampler = sampler_state
{
	Texture = <DiffuseMap>;
	MinFilter = POINT;  
	MagFilter = POINT;

	AddressU = Clamp;
	AddressV = Clamp;
};

texture VelocityMap;
sampler VelocitySampler = sampler_state
{
	Texture = <VelocityMap>;
	MinFilter = POINT;
	MagFilter = POINT;

	AddressU = Clamp;
	AddressV = Clamp;
};

texture LastVelocityMap;
sampler LastVelocitySampler = sampler_state
{
	Texture = <LastVelocityMap>;
	MinFilter = POINT;
	MagFilter = POINT;

	AddressU = Clamp;
	AddressV = Clamp;
};

float PixelBlurConst = 1.0f;
static const float NumberOfPostProcessSamples = 16.0f;
float VelocityCapSq = 1.0f;

float4 PostProcessMotionBlurPS( float2 OriginalUV : TEXCOORD0 ) : COLOR
{
	float2 pixelVelocity;

	float4 curFramePixelVelocity = tex2D(VelocitySampler, OriginalUV);
	float4 lastFramePixelVelocity = tex2D(LastVelocitySampler, OriginalUV);

	float curVelocitySqMag = curFramePixelVelocity.r * curFramePixelVelocity.r +
		curFramePixelVelocity.g * curFramePixelVelocity.g;
	float lastVelocitySqMag = lastFramePixelVelocity.r * lastFramePixelVelocity.r +
		lastFramePixelVelocity.g * lastFramePixelVelocity.g;

	if( lastVelocitySqMag > curVelocitySqMag )
	{
		pixelVelocity.x =  lastFramePixelVelocity.r * PixelBlurConst;   
		pixelVelocity.y = -lastFramePixelVelocity.g * PixelBlurConst;
	}
	else
	{
		pixelVelocity.x =  curFramePixelVelocity.r * PixelBlurConst;   
		pixelVelocity.y = -curFramePixelVelocity.g * PixelBlurConst;    
	}

	float3 Blurred = 0;
	for(float i = 0; i < NumberOfPostProcessSamples; i++)
	{       
		float2 lookup = pixelVelocity * float(i) / NumberOfPostProcessSamples + OriginalUV;
		float4 Current = tex2D(DiffuseSampler, lookup);
		Blurred += Current.rgb;
	}

	return float4(Blurred / NumberOfPostProcessSamples, 1.0f);
}

float4 PostProcessMotionBlurPSDebug( float2 OriginalUV : TEXCOORD0 ) : COLOR
{
	return tex2D(DiffuseSampler, OriginalUV);
}



struct VS_OUTPUT_2
{
	float4 mPosition : POSITION;
	float2 mTexCoord : TEXCOORD0;
	float2 mVelocity : TEXCOORD1;
};

float4x4 matViewLast;
float4x4 matWorldLast;

VS_OUTPUT_2 CreateMotionBlurVS(VS_INPUT Input)
{
	VS_OUTPUT_2 Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );

	float4 vPosProjSpaceCurrent = Output.mPosition;
	float4 vPosProjSpaceLast = mul( Input.mPosition, matWorldLast );
	vPosProjSpaceLast = mul( vPosProjSpaceLast, matViewLast );
	vPosProjSpaceLast = mul( vPosProjSpaceLast, matProj );

	vPosProjSpaceCurrent *= abs(vPosProjSpaceCurrent.w);
	vPosProjSpaceLast *= abs(vPosProjSpaceLast.w);

	Output.mVelocity = -(vPosProjSpaceCurrent - vPosProjSpaceLast).xy / 2.f;
	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

struct PS_INPUT_2
{
	float2 mTexCoord : TEXCOORD0;
	float2 mVelocity : TEXCOORD1;
};

struct PS_OUTPUT_2
{
	float4 mAlbedo : COLOR0;
	float4 mVelocity : COLOR1;
};

PS_OUTPUT_2 CreateMotionBlurPS( PS_INPUT_2 Input )
{
	PS_OUTPUT_2 Output;

	Output.mAlbedo = tex2D(DiffuseSampler, Input.mTexCoord);
	Output.mVelocity = float4(Input.mVelocity,1.0f,1.0f);

	return Output;
}


struct VS_INPUT_2
{
	float4 mPosition : POSITION;
	float3 mTexCoord : TEXCOORD0;
};

struct VS_OUTPUT_3
{
	float4 mPosition : POSITION;
	float3 mTexCoord : TEXCOORD0;
	float4 mCurrent : TEXCOORD1;
	float4 mLast : TEXCOORD2;
};

VS_OUTPUT_3 CreateMotionBlurVSCube(VS_INPUT_2 Input)
{
	VS_OUTPUT_3 Output;

	Output.mPosition = mul( Input.mPosition, matWorld );
	Output.mPosition = mul( Output.mPosition, matView );
	Output.mPosition = mul( Output.mPosition, matProj );

	Output.mCurrent = Output.mPosition;
	Output.mLast = mul( Input.mPosition, matWorldLast );
	Output.mLast = mul( Output.mLast, matViewLast );
	Output.mLast = mul( Output.mLast, matProj );

	Output.mTexCoord = Input.mTexCoord;

	return Output;
}

struct PS_INPUT_3
{
	float3 mTexCoord : TEXCOORD0;
	float4 mCurrent : TEXCOORD1;
	float4 mLast : TEXCOORD2;
};

texture CubeMap;
samplerCUBE CubeSampler = sampler_state
{
	Texture = <CubeMap>;
	MinFilter = POINT;  
	MagFilter = POINT;
};

PS_OUTPUT_2 CreateMotionBlurPSCube( PS_INPUT_3 Input )
{
	PS_OUTPUT_2 Output;

	Input.mCurrent /= abs(Input.mCurrent.w);
	Input.mLast /= abs(Input.mLast.w);

	float2 vVelocity = -(Input.mCurrent - Input.mLast).xy / 2.f;

	Output.mAlbedo = texCUBE(CubeSampler, Input.mTexCoord);
	Output.mVelocity = float4(vVelocity,1.0f,1.0f);

	return Output;
}

technique MotionBlurShader
{
	pass Pass_0
	{
		VertexShader = compile vs_2_0 PostProcessMotionBlurVS();
		PixelShader = compile ps_2_0 PostProcessMotionBlurPS();
	}

	pass Pass_1
	{
		VertexShader = compile vs_2_0 PostProcessMotionBlurVS();
		PixelShader = compile ps_2_0 PostProcessMotionBlurPSDebug();
	}

	pass Pass_2
	{
		VertexShader = compile vs_2_0 CreateMotionBlurVS();
		PixelShader = compile ps_2_0 CreateMotionBlurPS();
	}

	pass Pass_3
	{
		VertexShader = compile vs_2_0 CreateMotionBlurVSCube();
		PixelShader = compile ps_2_0 CreateMotionBlurPSCube();
	}
}