#include "Fullscreen.hlsli"

Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VartexShaderOutput input)
{
    const float32_t2 kCenter = float32_t2(0.5f,0.5f);//中心点
    const int32_t kNumSamplers = 10;//サンプリング数
    ///上記のCBfferですると〇
    const float32_t kBlurWidth = 0.01f;//ぼかし度
    
    float32_t2 direction = input.texcoord - kCenter;
    float32_t3 outputColor = float32_t3(0.0f, 0.0f, 0.0f);
    for (int32_t sampleIndex = 0; sampleIndex < kNumSamplers; ++sampleIndex)
    {
        // uv(中心点の場所)からサンプリング点に進む
        float32_t2 texcoord = input.texcoord + direction * kBlurWidth * float32_t(sampleIndex);
        outputColor.rgb += gTexture.Sample(gSampler, texcoord).rgb;
    }
    outputColor.rgb *= rcp(kNumSamplers);
    
    PixelShaderOutput output;
    output.color.rgb = outputColor;
    output.color.a = 1.0f;
    return output;
}