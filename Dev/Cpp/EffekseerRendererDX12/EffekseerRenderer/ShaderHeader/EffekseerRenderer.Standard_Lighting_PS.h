#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /D /Emain /Fh
//    ShaderHeader/EffekseerRenderer.Standard_Lighting_PS.h
//    Shader/standard_renderer_lighting_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 _263_fLightDirection;       // Offset:    0 Size:    16
//   float4 _263_fLightColor;           // Offset:   16 Size:    16 [unused]
//   float4 _263_fLightAmbient;         // Offset:   32 Size:    16
//   float4 _263_fFlipbookParameter;    // Offset:   48 Size:    16
//   float4 _263_fUVDistortionParameter;// Offset:   64 Size:    16
//   float4 _263_fBlendTextureParameter;// Offset:   80 Size:    16
//   float4 _263_fEmissiveScaling;      // Offset:   96 Size:    16
//   float4 _263_fEdgeColor;            // Offset:  112 Size:    16
//   float4 _263_fEdgeParameter;        // Offset:  128 Size:    16
//   float4 _263_softParticleAndReconstructionParam1;// Offset:  144 Size:    16
//   float4 _263_reconstructionParam2;  // Offset:  160 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_colorSampler                    sampler      NA          NA    0        1
// g_normalSampler                   sampler      NA          NA    1        1
// g_alphaSampler                    sampler      NA          NA    2        1
// g_uvDistortionSampler             sampler      NA          NA    3        1
// g_blendSampler                    sampler      NA          NA    4        1
// g_blendAlphaSampler               sampler      NA          NA    5        1
// g_blendUVDistortionSampler        sampler      NA          NA    6        1
// g_depthSampler                    sampler      NA          NA    7        1
// g_colorTexture                    texture  float4          2d    0        1
// g_normalTexture                   texture  float4          2d    1        1
// g_alphaTexture                    texture  float4          2d    2        1
// g_uvDistortionTexture             texture  float4          2d    3        1
// g_blendTexture                    texture  float4          2d    4        1
// g_blendAlphaTexture               texture  float4          2d    5        1
// g_blendUVDistortionTexture        texture  float4          2d    6        1
// g_depthTexture                    texture  float4          2d    7        1
// PS_ConstanBuffer                  cbuffer      NA          NA    1        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// TEXCOORD                 0   xyzw        0     NONE  float   xyzw
// TEXCOORD                 1   xy          1     NONE  float   xy  
// TEXCOORD                 2   xyz         2     NONE  float   xyz 
// TEXCOORD                 3   xyz         3     NONE  float   xyz 
// TEXCOORD                 4   xyz         4     NONE  float   xyz 
// TEXCOORD                 5   xyzw        5     NONE  float   xyzw
// TEXCOORD                 6   xyzw        6     NONE  float   xyzw
// TEXCOORD                 7   xyzw        7     NONE  float   xyzw
// TEXCOORD                 8   xy          8     NONE  float   xy  
// TEXCOORD                 9   xyzw        9     NONE  float   xyzw
// SV_Position              0   xyzw       10      POS  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb1[11], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_sampler s4, mode_default
dcl_sampler s5, mode_default
dcl_sampler s6, mode_default
dcl_sampler s7, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_resource_texture2d (float,float,float,float) t4
dcl_resource_texture2d (float,float,float,float) t5
dcl_resource_texture2d (float,float,float,float) t6
dcl_resource_texture2d (float,float,float,float) t7
dcl_input_ps linear centroid v0.xyzw
dcl_input_ps linear centroid v1.xy
dcl_input_ps linear v2.xyz
dcl_input_ps linear v3.xyz
dcl_input_ps linear v4.xyz
dcl_input_ps linear v5.xyzw
dcl_input_ps linear v6.xyzw
dcl_input_ps linear v7.xyzw
dcl_input_ps linear v8.xy
dcl_input_ps linear v9.xyzw
dcl_output o0.xyzw
dcl_temps 7
sample r0.xyzw, v5.zwzz, t3.xyzw, s3
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r0.z, -r0.y, cb1[4].w, cb1[4].z
mad r0.yw, r0.xxxz, cb1[4].xxxx, v1.xxxy
sample r1.xyzw, r0.ywyy, t0.xyzw, s0
mul r1.xyzw, r1.xyzw, v0.xyzw
lt r2.x, l(0.000000), cb1[3].x
if_nz r2.x
  mad r2.xy, r0.xzxx, cb1[4].xxxx, v7.zwzz
  sample r2.xyzw, r2.xyxx, t0.xyzw, s0
  eq r3.x, cb1[3].y, l(1.000000)
  mad r2.xyzw, r2.xyzw, v0.xyzw, -r1.xyzw
  mad r2.xyzw, v8.xxxx, r2.xyzw, r1.xyzw
  movc r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
endif 
div r2.yzw, v9.xxyz, v9.wwww
add r2.yz, r2.yyzy, l(0.000000, 1.000000, 1.000000, 0.000000)
mul r3.x, r2.y, l(0.500000)
mad r3.z, -r2.z, l(0.500000), l(1.000000)
sample r3.xyzw, r3.xzxx, t7.xyzw, s7
ne r2.y, cb1[9].x, l(0.000000)
mad r2.x, r3.x, cb1[9].y, cb1[9].z
mad r3.xy, r2.xwxx, cb1[10].wwww, -cb1[10].yyyy
mad r2.xz, -r2.xxwx, cb1[10].zzzz, cb1[10].xxxx
div r2.xz, r3.xxyx, r2.xxzx
add r2.x, -r2.x, r2.z
div_sat r2.x, r2.x, cb1[9].x
mul r2.x, r1.w, r2.x
movc r1.w, r2.y, r2.x, r1.w
mad r0.xz, r0.xxzx, cb1[4].xxxx, v5.xxyx
sample r2.xyzw, r0.xzxx, t2.xyzw, s2
mul r0.x, r2.w, r2.x
mul r0.z, r0.x, r1.w
max r2.x, v8.y, l(0.000000)
ge r2.x, r2.x, r0.z
discard r2.x
sample r2.xyzw, r0.ywyy, t1.xyzw, s1
add r2.xyz, r2.xyzx, l(-0.500000, -0.500000, -0.500000, 0.000000)
add r2.xyz, r2.xyzx, r2.xyzx
mul r3.xyz, r2.yyyy, v4.xyzx
mad r2.xyw, r2.xxxx, v3.xyxz, r3.xyxz
mad r2.xyz, r2.zzzz, v2.xyzx, r2.xywx
dp3 r0.y, r2.xyzx, r2.xyzx
rsq r0.y, r0.y
mul r2.xyz, r0.yyyy, r2.xyzx
dp3 r0.y, cb1[0].xyzx, r2.xyzx
max r0.y, r0.y, l(0.000000)
sample r2.xyzw, v6.zwzz, t6.xyzw, s6
mad r2.xy, r2.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r2.z, -r2.y, cb1[4].w, cb1[4].z
mad r2.yw, r2.xxxz, cb1[4].yyyy, v7.xxxy
sample r3.xyzw, r2.ywyy, t4.xyzw, s4
mad r2.xy, r2.xzxx, cb1[4].yyyy, v6.xyxx
sample r2.xyzw, r2.xyxx, t5.xyzw, s5
mul r0.w, r2.w, r2.x
mul r2.x, r0.w, r3.w
mul r2.yzw, r2.xxxx, r3.xxyz
mad r0.w, -r3.w, r0.w, l(1.000000)
mad r4.xyz, r1.xyzx, r0.wwww, r2.yzwy
mad r5.xyz, r3.xyzx, r2.xxxx, r1.xyzx
mad r3.xyz, -r3.xyzx, r2.xxxx, r1.xyzx
eq r6.xyzw, cb1[5].xxxx, l(0.000000, 1.000000, 2.000000, 3.000000)
mul r2.xyz, r1.xyzx, r2.yzwy
movc r1.xyz, r6.wwww, r2.xyzx, r1.xyzx
movc r1.xyz, r6.zzzz, r3.xyzx, r1.xyzx
movc r1.xyz, r6.yyyy, r5.xyzx, r1.xyzx
movc r1.xyz, r6.xxxx, r4.xyzx, r1.xyzx
mul r1.xyz, r1.xyzx, cb1[6].xxxx
add r2.xyz, r0.yyyy, cb1[2].xyzx
mul r3.xyz, cb1[7].xyzx, cb1[8].yyyy
mad r0.x, r1.w, r0.x, -v8.y
add r0.x, r0.x, -cb1[8].x
round_pi r0.x, r0.x
mad r1.xyz, r1.xyzx, r2.xyzx, -r3.xyzx
mad o0.xyz, r0.xxxx, r1.xyzx, r3.xyzx
mov o0.w, r0.z
ret 
// Approximately 77 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67,   8,  75, 
    228, 157, 230, 205, 183, 213, 
    245, 175, 179,  48, 177, 169, 
    168, 103,   1,   0,   0,   0, 
    172,  19,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     24,   6,   0,   0,  72,   7, 
      0,   0, 124,   7,   0,   0, 
     48,  19,   0,   0,  82,  68, 
     69,  70, 220,   5,   0,   0, 
      1,   0,   0,   0, 112,   3, 
      0,   0,  17,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    169,   5,   0,   0,  60,   2, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     75,   2,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  91,   2,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 106,   2, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    128,   2,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 143,   2,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 163,   2, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    190,   2,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 205,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 220,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    236,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 251,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  17,   3, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      4,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
     32,   3,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   5,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  52,   3,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   6,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  79,   3, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      7,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
     94,   3,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 103,  95,  99, 111, 
    108, 111, 114,  83,  97, 109, 
    112, 108, 101, 114,   0, 103, 
     95, 110, 111, 114, 109,  97, 
    108,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  97, 
    108, 112, 104,  97,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95, 117, 118,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
     98, 108, 101, 110, 100,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95,  98, 108, 101, 
    110, 100,  65, 108, 112, 104, 
     97,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  98, 
    108, 101, 110, 100,  85,  86, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95, 100, 101, 112, 116, 
    104,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  99, 
    111, 108, 111, 114,  84, 101, 
    120, 116, 117, 114, 101,   0, 
    103,  95, 110, 111, 114, 109, 
     97, 108,  84, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     97, 108, 112, 104,  97,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95, 117, 118,  68, 
    105, 115, 116, 111, 114, 116, 
    105, 111, 110,  84, 101, 120, 
    116, 117, 114, 101,   0, 103, 
     95,  98, 108, 101, 110, 100, 
     84, 101, 120, 116, 117, 114, 
    101,   0, 103,  95,  98, 108, 
    101, 110, 100,  65, 108, 112, 
    104,  97,  84, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     98, 108, 101, 110, 100,  85, 
     86,  68, 105, 115, 116, 111, 
    114, 116, 105, 111, 110,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95, 100, 101, 112, 
    116, 104,  84, 101, 120, 116, 
    117, 114, 101,   0,  80,  83, 
     95,  67, 111, 110, 115, 116, 
     97, 110,  66, 117, 102, 102, 
    101, 114,   0, 171,  94,   3, 
      0,   0,  11,   0,   0,   0, 
    136,   3,   0,   0, 176,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 144,   4, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0, 184,   4, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0, 201,   4, 
      0,   0,  32,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0, 220,   4, 
      0,   0,  48,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0, 244,   4, 
      0,   0,  64,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0,  16,   5, 
      0,   0,  80,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0,  44,   5, 
      0,   0,  96,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0,  66,   5, 
      0,   0, 112,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0,  82,   5, 
      0,   0, 128,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0, 102,   5, 
      0,   0, 144,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0, 143,   5, 
      0,   0, 160,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 168,   4,   0,   0, 
      0,   0,   0,   0,  95,  50, 
     54,  51,  95, 102,  76, 105, 
    103, 104, 116,  68, 105, 114, 
    101,  99, 116, 105, 111, 110, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  95,  50,  54,  51, 
     95, 102,  76, 105, 103, 104, 
    116,  67, 111, 108, 111, 114, 
      0,  95,  50,  54,  51,  95, 
    102,  76, 105, 103, 104, 116, 
     65, 109,  98, 105, 101, 110, 
    116,   0,  95,  50,  54,  51, 
     95, 102,  70, 108, 105, 112, 
     98, 111, 111, 107,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  95,  50,  54,  51, 
     95, 102,  85,  86,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  80,  97, 114,  97, 
    109, 101, 116, 101, 114,   0, 
     95,  50,  54,  51,  95, 102, 
     66, 108, 101, 110, 100,  84, 
    101, 120, 116, 117, 114, 101, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0,  95,  50, 
     54,  51,  95, 102,  69, 109, 
    105, 115, 115, 105, 118, 101, 
     83,  99,  97, 108, 105, 110, 
    103,   0,  95,  50,  54,  51, 
     95, 102,  69, 100, 103, 101, 
     67, 111, 108, 111, 114,   0, 
     95,  50,  54,  51,  95, 102, 
     69, 100, 103, 101,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  95,  50,  54,  51, 
     95, 115, 111, 102, 116,  80, 
     97, 114, 116, 105,  99, 108, 
    101,  65, 110, 100,  82, 101, 
     99, 111, 110, 115, 116, 114, 
    117,  99, 116, 105, 111, 110, 
     80,  97, 114,  97, 109,  49, 
      0,  95,  50,  54,  51,  95, 
    114, 101,  99, 111, 110, 115, 
    116, 114, 117,  99, 116, 105, 
    111, 110,  80,  97, 114,  97, 
    109,  50,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  50,  57, 
     46,  57,  53,  50,  46,  51, 
     49,  49,  49,   0, 171, 171, 
     73,  83,  71,  78,  40,   1, 
      0,   0,  11,   0,   0,   0, 
      8,   0,   0,   0,  16,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0,  16,   1, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   3,   0,   0,  16,   1, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      7,   7,   0,   0,  16,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   7,   0,   0,  16,   1, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      7,   7,   0,   0,  16,   1, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
     15,  15,   0,   0,  16,   1, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,  15,   0,   0,  16,   1, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
     15,  15,   0,   0,  16,   1, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
      3,   3,   0,   0,  16,   1, 
      0,   0,   9,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   9,   0,   0,   0, 
     15,  15,   0,   0,  25,   1, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,  10,   0,   0,   0, 
     15,   0,   0,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  83,  86,  95,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0, 171, 171, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171,  83,  72,  68,  82, 
    172,  11,   0,   0,  64,   0, 
      0,   0, 235,   2,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   1,   0,   0,   0, 
     11,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      1,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      2,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      3,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      4,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      5,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      6,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      7,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   1,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   2,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      3,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   4,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   5,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      6,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   7,   0, 
      0,   0,  85,  85,   0,   0, 
     98,  24,   0,   3, 242,  16, 
     16,   0,   0,   0,   0,   0, 
     98,  24,   0,   3,  50,  16, 
     16,   0,   1,   0,   0,   0, 
     98,  16,   0,   3, 114,  16, 
     16,   0,   2,   0,   0,   0, 
     98,  16,   0,   3, 114,  16, 
     16,   0,   3,   0,   0,   0, 
     98,  16,   0,   3, 114,  16, 
     16,   0,   4,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   5,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   6,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   7,   0,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   8,   0,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   9,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   7,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0, 230,  26,  16,   0, 
      5,   0,   0,   0,  70, 126, 
     16,   0,   3,   0,   0,   0, 
      0,  96,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  15, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  50,   0,   0,  12, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  58, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,  42, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    162,   0,  16,   0,   0,   0, 
      0,   0,   6,   8,  16,   0, 
      0,   0,   0,   0,   6, 128, 
     32,   0,   1,   0,   0,   0, 
      4,   0,   0,   0,   6,  20, 
     16,   0,   1,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
    214,   5,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  49,   0, 
      0,   8,  18,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    134,   0,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0, 230,  26,  16,   0, 
      7,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  24,   0, 
      0,   8,  18,   0,  16,   0, 
      3,   0,   0,   0,  26, 128, 
     32,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,   6,  16, 
     16,   0,   8,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  21,   0, 
      0,   1,  14,   0,   0,   7, 
    226,   0,  16,   0,   2,   0, 
      0,   0,   6,  25,  16,   0, 
      9,   0,   0,   0, 246,  31, 
     16,   0,   9,   0,   0,   0, 
      0,   0,   0,  10,  98,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   6,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,  63,  50,   0,   0,  10, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   3,   0,   0,   0, 
    134,   0,  16,   0,   3,   0, 
      0,   0,  70, 126,  16,   0, 
      7,   0,   0,   0,   0,  96, 
     16,   0,   7,   0,   0,   0, 
     57,   0,   0,   8,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  50,   0,   0,  11, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  26, 128, 
     32,   0,   1,   0,   0,   0, 
      9,   0,   0,   0,  42, 128, 
     32,   0,   1,   0,   0,   0, 
      9,   0,   0,   0,  50,   0, 
      0,  12,  50,   0,  16,   0, 
      3,   0,   0,   0, 198,   0, 
     16,   0,   2,   0,   0,   0, 
    246, 143,  32,   0,   1,   0, 
      0,   0,  10,   0,   0,   0, 
     86, 133,  32, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     10,   0,   0,   0,  50,   0, 
      0,  12,  82,   0,  16,   0, 
      2,   0,   0,   0,   6,   3, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0, 166, 138, 
     32,   0,   1,   0,   0,   0, 
     10,   0,   0,   0,   6, 128, 
     32,   0,   1,   0,   0,   0, 
     10,   0,   0,   0,  14,   0, 
      0,   7,  82,   0,  16,   0, 
      2,   0,   0,   0,   6,   1, 
     16,   0,   3,   0,   0,   0, 
      6,   2,  16,   0,   2,   0, 
      0,   0,   0,   0,   0,   8, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  14,  32, 
      0,   8,  18,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   9,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10,  82,   0,  16,   0, 
      0,   0,   0,   0,   6,   2, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
      6,  17,  16,   0,   5,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0, 134,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   2,   0,   0,   0, 
      0,  96,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  52,   0, 
      0,   7,  18,   0,  16,   0, 
      2,   0,   0,   0,  26,  16, 
     16,   0,   8,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  29,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     13,   0,   4,   3,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
    214,   5,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      1,   0,   0,   0,   0,  96, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,  10, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0, 191,   0,   0, 
      0, 191,   0,   0,   0, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   7, 114,   0,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      2,   0,   0,   0,  70,  18, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,   9, 178,   0, 
     16,   0,   2,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  70,  24,  16,   0, 
      3,   0,   0,   0,  70,   8, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   2,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  70,   3, 
     16,   0,   2,   0,   0,   0, 
     16,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  68,   0, 
      0,   5,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  16,   0, 
      0,   8,  34,   0,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     52,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0, 230,  26, 
     16,   0,   6,   0,   0,   0, 
     70, 126,  16,   0,   6,   0, 
      0,   0,   0,  96,  16,   0, 
      6,   0,   0,   0,  50,   0, 
      0,  15,  50,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
    128, 191,   0,   0,   0,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  12,  66,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  58, 128, 
     32,   0,   1,   0,   0,   0, 
      4,   0,   0,   0,  42, 128, 
     32,   0,   1,   0,   0,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  10, 162,   0,  16,   0, 
      2,   0,   0,   0,   6,   8, 
     16,   0,   2,   0,   0,   0, 
     86, 133,  32,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
      6,  20,  16,   0,   7,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   3,   0, 
      0,   0, 214,   5,  16,   0, 
      2,   0,   0,   0,  70, 126, 
     16,   0,   4,   0,   0,   0, 
      0,  96,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
     50,   0,  16,   0,   2,   0, 
      0,   0, 134,   0,  16,   0, 
      2,   0,   0,   0,  86, 133, 
     32,   0,   1,   0,   0,   0, 
      4,   0,   0,   0,  70,  16, 
     16,   0,   6,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      5,   0,   0,   0,   0,  96, 
     16,   0,   5,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   7, 
    226,   0,  16,   0,   2,   0, 
      0,   0,   6,   0,  16,   0, 
      2,   0,   0,   0,   6,   9, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0, 150,   7,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      5,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 114,   0,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  24,   0,   0,  11, 
    242,   0,  16,   0,   6,   0, 
      0,   0,   6, 128,  32,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,  64, 
      0,   0,  64,  64,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
    150,   7,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      6,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 166,  10,  16,   0, 
      6,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  86,   5,  16,   0, 
      6,   0,   0,   0,  70,   2, 
     16,   0,   5,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      6,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   6, 128, 
     32,   0,   1,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   8, 114,   0,  16,   0, 
      2,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
     56,   0,   0,   9, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   7,   0,   0,   0, 
     86, 133,  32,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     50,   0,   0,  10,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  26,  16, 
     16, 128,  65,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  66,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,  50,   0, 
      0,   9, 114,  32,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     77,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  33,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   6,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
