xof 0303txt 0032
template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}


Material material_0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_1.tga";
 }
}

Material material_2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material material_3 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material material_4 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_4.tga";
 }
}

Material material_6 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_6.tga";
 }
}

Material world_func_detail_Brush_14_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_14_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_16_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_16_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_18_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_18_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_20_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_20_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_22_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_22_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_24_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_24_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_26_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_26_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_28_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_28_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_30_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_30_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_32_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_32_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_34_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_34_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_36_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_36_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_38_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_38_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_40_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_40_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_42_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_42_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_44_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_44_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_46_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_46_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_48_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_48_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_50_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_50_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_52_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_52_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_54_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_54_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_56_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_56_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_58_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_58_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_60_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_60_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_62_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_62_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_64_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_64_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_66_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_66_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_68_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_68_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_70_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_70_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_72_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_72_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_74_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_74_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_76_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_76_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_78_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_78_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_80_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_80_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_82_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_82_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_84_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_84_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_86_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_86_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_88_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_88_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_90_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_90_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_92_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_92_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_94_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_94_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_96_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_96_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_98_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_98_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_100_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_100_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_102_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_102_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_104_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_104_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_106_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_106_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_108_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_108_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_110_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_110_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_112_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_112_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_114_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_114_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_116_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_116_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_118_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_118_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_120_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_120_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_122_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_122_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_124_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_124_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_126_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_126_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_128_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_128_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_130_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_130_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_132_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_132_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_134_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_134_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_136_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_136_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_138_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_138_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_168_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_168_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_170_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_170_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_172_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_172_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_174_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_174_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_176_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_176_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_178_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_178_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_180_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_180_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_182_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_182_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_184_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_184_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_186_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_186_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_188_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_188_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_190_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_190_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_192_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_192_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_194_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_194_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_196_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_196_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_198_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_198_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_200_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_200_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_202_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_202_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_204_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_204_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_7 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_328_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_328_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material material_8 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_330_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_330_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_333_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_333_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_335_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_335_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_337_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_337_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_338_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_338_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_338_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_339_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_339_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_339_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_340_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_340_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_341_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_341_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_342_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_342_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_342_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_343_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_343_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_343_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_344_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_344_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_344_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material material_10 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material material_11 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_11.tga";
 }
}

Material world_func_detail_Brush_350_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_350_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_351_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_351_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_352_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_352_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_353_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_353_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_354_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_354_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material material_9 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_356_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_356_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_357_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_357_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_358_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_358_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_358_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_359_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_359_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_361_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_361_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_364_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_364_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_366_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_366_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_368_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_368_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_369_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_369_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_369_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_370_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_370_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_370_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_371_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_371_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_372_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_372_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_373_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_373_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_373_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_374_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_374_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_374_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_375_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_375_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_375_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_381_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_381_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_382_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_382_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_383_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_383_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_384_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_384_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_385_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_385_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_387_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_387_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_388_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_388_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_389_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_389_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_389_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_390_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_390_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_392_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_392_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_395_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_395_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_397_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_397_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_399_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_399_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_400_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_400_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_400_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_401_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_401_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_401_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_402_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_402_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_403_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_403_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_404_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_404_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_404_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_405_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_405_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_405_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_406_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_406_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_406_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_412_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_412_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_413_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_413_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_414_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_414_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_415_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_415_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_416_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_416_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_418_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_418_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_419_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_419_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_420_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_420_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_420_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_421_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_421_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_423_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_423_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_426_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_426_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_428_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_428_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_430_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_430_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_431_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_431_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_431_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_432_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_432_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_432_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_433_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_433_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_434_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_434_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_435_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_435_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_435_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_436_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_436_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_436_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_437_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_437_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_437_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_443_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_443_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_444_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_444_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_445_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_445_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_446_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_446_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_447_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_447_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_449_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_449_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_450_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_450_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_451_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_451_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_451_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_452_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_452_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_454_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_454_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_457_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_457_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_459_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_459_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_461_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_461_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_462_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_462_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_462_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_463_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_463_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_463_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_464_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_464_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_465_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_465_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_466_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_466_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_466_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_467_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_467_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_467_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_468_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_468_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_468_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_474_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_474_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_475_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_475_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_476_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_476_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_477_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_477_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_478_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_478_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_480_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_480_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_481_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_481_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_482_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_482_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_482_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_483_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_483_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_485_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_485_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_488_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_488_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_490_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_490_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_492_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_492_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_493_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_493_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_493_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_494_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_494_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_494_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_495_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_495_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_496_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_496_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_497_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_497_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_497_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_498_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_498_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_498_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_499_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_499_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_499_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_505_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_505_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_506_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_506_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_507_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_507_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_508_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_508_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_509_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_509_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_511_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_511_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_512_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_512_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_513_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_513_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_513_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_514_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_514_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_516_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_516_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_519_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_519_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_521_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_521_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_523_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_523_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_524_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_524_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_524_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_525_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_525_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_525_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_526_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_526_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_527_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_527_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_528_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_528_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_528_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_529_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_529_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_529_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_530_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_530_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_530_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_536_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_536_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_537_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_537_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_538_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_538_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_539_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_539_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_540_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_540_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_542_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_542_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_543_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_543_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_544_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_544_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_544_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_545_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_545_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_547_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_547_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_550_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_550_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_552_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_552_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_554_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_554_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_555_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_555_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_555_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_556_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_556_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_556_mso_material_7Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_557_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_557_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_558_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_558_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_559_mso_material_8Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_559_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_559_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_560_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_560_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_560_mso_material_8Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_561_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_561_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_561_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_567_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_567_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_568_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_568_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_569_mso_material_10Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_569_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_570_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_570_mso_material_7Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_571_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_571_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_573_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_573_mso_material_9Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_574_mso_material_9Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material world_func_detail_Brush_574_mso_material_10Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_10.tga";
 }
}

Material world_func_detail_Brush_575_mso_material_7Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_7.tga";
 }
}

Material world_func_detail_Brush_575_mso_material_8Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_8.tga";
 }
}

Material world_func_detail_Brush_575_mso_material_9Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_9.tga";
 }
}

Material material_12 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_12.tga";
 }
}

Material material_13 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_13.tga";
 }
}

Material material_14 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_14.tga";
 }
}

Material material_15 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material world_func_detail_Brush_1120_mso_material_15Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material world_func_detail_Brush_1120_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1124_mso_material_15Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material world_func_detail_Brush_1124_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1125_mso_material_15Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material world_func_detail_Brush_1125_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_16 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_16.tga";
 }
}

Material world_func_detail_Brush_1134_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1134_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1136_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1136_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1137_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1137_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1138_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1138_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1139_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1139_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1140_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1140_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1141_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1141_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1142_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1142_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1151_mso_material_19Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_19.tga";
 }
}

Material world_func_detail_Brush_1151_mso_material_20Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1152_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1152_mso_material_19Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_19.tga";
 }
}

Material world_func_detail_Brush_1154_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1154_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1155_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1155_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1156_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1156_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1157_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1157_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1158_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1158_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1159_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1159_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1160_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1160_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1161_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1161_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1162_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1162_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1163_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1163_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1164_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1164_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1165_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1165_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1166_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1166_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1167_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1167_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1168_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1168_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1169_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1169_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1170_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1170_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1171_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1171_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1172_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1172_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1173_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1173_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1174_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1174_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1175_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1175_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1180_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1180_mso_material_15Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material world_func_detail_Brush_1184_mso_material_15Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material world_func_detail_Brush_1184_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1185_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1185_mso_material_15Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_15.tga";
 }
}

Material material_21 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1189_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1189_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1190_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1190_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1191_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1191_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1192_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1192_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1193_mso_material_21Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1193_mso_material_20Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1194_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1194_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1195_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1195_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1196_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1196_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1197_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1197_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1198_mso_material_21Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1198_mso_material_20Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1199_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1199_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1200_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1200_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1201_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1201_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1202_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1202_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1203_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1203_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1204_mso_material_21Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1204_mso_material_20Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1205_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1205_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1206_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1206_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1207_mso_material_20Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1207_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1208_mso_material_21Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1208_mso_material_20Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material world_func_detail_Brush_1219_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1219_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1220_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1220_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1222_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1222_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1223_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1223_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1225_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1225_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1226_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1226_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1227_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1227_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1229_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1229_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1259_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1259_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1260_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1260_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1262_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1262_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1263_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1263_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1265_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1265_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1266_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1266_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1267_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1267_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1269_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1269_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1304_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1304_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1305_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1305_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1324_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1324_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1325_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1325_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1327_mso_material_22Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_22.tga";
 }
}

Material world_func_detail_Brush_1327_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1327_mso_material_23Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_23.tga";
 }
}

Material world_func_detail_Brush_1400_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1400_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1414_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1414_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1428_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1428_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_24 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1443_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1443_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1445_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1445_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1446_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1446_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1447_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1447_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1448_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1448_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1449_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1449_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1450_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1450_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1451_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1451_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1459_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1459_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1460_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1460_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1461_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1461_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1462_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1462_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1463_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1463_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1464_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1464_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1465_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1465_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1466_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1466_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1467_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1467_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1468_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1468_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1469_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1469_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1470_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1470_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1471_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1471_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1472_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1472_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1473_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1473_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1474_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1474_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1475_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1475_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1476_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1476_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1477_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1477_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1478_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1478_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1479_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1479_mso_material_18Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1480_mso_material_18Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material world_func_detail_Brush_1480_mso_material_17Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1481_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1481_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1483_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1483_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1484_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1484_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1486_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1486_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1487_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1487_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1489_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1489_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1490_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1490_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1492_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1492_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1496_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1496_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1498_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1498_mso_material_3Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1499_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1499_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1508_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1508_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1515_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1515_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1526_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1526_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1543_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1543_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1552_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1552_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1559_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1559_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1570_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1570_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_25 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_25.tga";
 }
}

Material material_18 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_18.tga";
 }
}

Material material_26 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_26.tga";
 }
}

Material material_27 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_27.tga";
 }
}

Material material_28 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_28.tga";
 }
}

Material world_func_detail_Brush_1633_mso_material_14Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_14.tga";
 }
}

Material world_func_detail_Brush_1633_mso_material_19Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_19.tga";
 }
}

Material material_19 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_19.tga";
 }
}

Material world_func_detail_Brush_1639_mso_material_19Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_19.tga";
 }
}

Material world_func_detail_Brush_1639_mso_material_14Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_14.tga";
 }
}

Material world_func_detail_Brush_1645_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1645_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_29 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_29.tga";
 }
}

Material world_func_detail_Brush_1653_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1653_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1654_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1654_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1655_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1655_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1656_mso_material_31Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1656_mso_material_30Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1657_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1657_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1658_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1658_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1659_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1659_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1660_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1660_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1661_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1661_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1662_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1662_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1663_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1663_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1664_mso_material_31Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1664_mso_material_30Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1665_mso_material_31Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1665_mso_material_30Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1666_mso_material_31Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1666_mso_material_30Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1667_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1667_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1668_mso_material_31Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1668_mso_material_30Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1669_mso_material_17Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1669_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_17 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_17.tga";
 }
}

Material world_func_detail_Brush_1671_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1671_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1672_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1672_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1673_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1673_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1674_mso_material_31Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1674_mso_material_30Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1675_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1675_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1676_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1676_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1677_mso_material_30Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_30.tga";
 }
}

Material world_func_detail_Brush_1677_mso_material_31Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_31.tga";
 }
}

Material world_func_detail_Brush_1678_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1678_mso_material_23Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_23.tga";
 }
}

Material world_func_detail_Brush_1678_mso_material_22Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_22.tga";
 }
}

Material world_func_detail_Brush_1694_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1694_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1696_mso_material_32Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_32.tga";
 }
}

Material world_func_detail_Brush_1696_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1698_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1698_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1699_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1699_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material material_32 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_32.tga";
 }
}

Material world_func_detail_Brush_1704_mso_material_32Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_32.tga";
 }
}

Material world_func_detail_Brush_1704_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1708_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1708_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1724_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1724_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1726_mso_material_32Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_32.tga";
 }
}

Material world_func_detail_Brush_1726_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1728_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1728_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1729_mso_material_24Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1729_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1734_mso_material_32Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_32.tga";
 }
}

Material world_func_detail_Brush_1734_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1738_mso_material_0Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material world_func_detail_Brush_1738_mso_material_24Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_24.tga";
 }
}

Material world_func_detail_Brush_1783_mso_material_3Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Material world_func_detail_Brush_1783_mso_material_2Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1808_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1808_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1813_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1813_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1818_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1818_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1820_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1820_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1822_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1822_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1824_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1824_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1826_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1826_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1828_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1828_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1830_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1830_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material world_func_detail_Brush_1832_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material world_func_detail_Brush_1832_mso_material_21Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_21.tga";
 }
}

Material material_20 {
 1.000000;1.000000;1.000000;1.000000;;
 9.600000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_20.tga";
 }
}

Material Stair_2_mso_material_2Sub0 {
 1.000000;1.000000;1.000000;1.000000;;
 9.599999;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_2.tga";
 }
}

Material Stair_2_mso_material_0Sub1 {
 1.000000;1.000000;1.000000;1.000000;;
 9.599999;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_0.tga";
 }
}

Material Stair_2_mso_material_3Sub2 {
 1.000000;1.000000;1.000000;1.000000;;
 9.599999;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "Map_material_3.tga";
 }
}

Frame world_worldspawn_Brush_1 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_10 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_19 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_24 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_26 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_27 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_28 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_32 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_70 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_71 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_72 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_73 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_74 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_75 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_76 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_77 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_78 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_worldspawn_Brush_79 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_1 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_3 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_5 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_6 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_8 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_10 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_12 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_13 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_14 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_brush_Brush_16 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_2 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_4 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_5 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_7 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_8 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_10 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_11 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_13 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_14 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_15 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_16 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_17 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_18 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_19 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_20 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_21 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_22 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_23 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_24 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_25 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_26 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_27 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_28 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_29 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_30 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_31 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_32 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_33 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_34 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_35 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_36 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_37 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_38 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_39 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_40 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_41 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_42 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_43 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_44 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_45 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_46 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_47 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_48 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_49 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_50 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_51 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_52 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_53 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_54 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_55 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_56 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_57 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_58 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_59 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_60 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_61 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_62 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_63 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_64 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_65 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_66 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_67 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_68 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_69 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_70 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_71 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_72 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_73 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_74 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_75 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_76 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_77 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_78 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_79 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_80 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_81 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_82 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_83 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_84 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_85 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_86 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_87 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_88 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_89 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_90 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_91 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_92 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_93 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_94 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_95 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_96 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_97 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_98 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_99 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_100 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_101 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_102 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_103 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_104 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_105 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_106 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_107 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_108 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_109 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_110 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_111 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_112 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_113 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_114 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_115 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_116 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_117 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_118 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_119 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_120 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_121 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_122 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_123 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_124 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_125 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_126 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_127 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_128 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_129 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_130 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_131 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_132 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_133 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_134 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_135 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_136 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_137 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_138 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_139 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_168 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_169 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_170 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_171 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_172 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_173 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_174 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_175 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_176 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_177 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_178 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_179 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_180 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_181 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_182 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_183 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_184 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_185 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_186 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_187 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_188 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_189 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_190 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_191 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_192 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_193 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_194 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_195 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_196 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_197 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_198 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_199 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_200 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_201 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_202 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_203 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_204 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_205 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_206 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_207 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_208 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_209 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_210 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_211 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_212 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_213 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_214 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_215 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_216 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_217 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_218 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_219 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_220 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_221 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_222 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_223 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_224 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_225 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_226 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_227 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_228 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_229 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_230 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_231 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_232 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_233 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_234 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_235 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_236 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_237 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_238 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_239 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_240 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_241 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_242 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_243 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_244 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_245 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_246 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_247 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_248 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_249 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_250 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_251 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_252 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_253 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_254 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_255 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_256 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_257 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_258 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_259 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_260 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_261 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_262 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_263 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_264 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_265 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_266 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_267 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_268 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_269 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_270 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_271 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_272 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_273 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_274 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_275 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_276 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_277 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_278 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_279 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_280 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_281 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_282 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_283 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_284 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_285 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_286 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_287 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_288 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_289 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_290 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_291 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_292 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_293 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_294 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_295 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_296 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_297 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_298 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_299 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_300 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_301 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_302 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_303 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_304 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_305 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_306 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_307 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_308 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_309 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_310 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_311 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_312 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_313 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_314 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_315 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_316 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_317 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_318 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_319 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_320 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_321 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_322 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_323 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_324 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_325 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_326 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_327 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_328 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_329 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_330 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_331 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_332 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_333 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_334 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_335 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_336 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_337 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_338 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_339 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_340 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_341 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_342 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_343 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_344 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_345 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_346 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_347 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_348 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_349 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_350 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_351 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_352 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_353 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_354 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_355 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_356 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_357 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_358 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_359 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_360 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_361 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_362 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_363 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_364 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_365 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_366 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_367 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_368 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_369 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_370 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_371 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_372 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_373 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_374 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_375 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_376 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_377 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_378 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_379 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_380 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_381 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_382 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_383 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_384 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_385 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_386 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_387 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_388 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_389 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_390 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_391 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_392 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_393 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_394 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_395 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_396 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_397 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_398 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_399 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_400 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_401 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_402 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_403 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_404 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_405 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_406 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_407 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_408 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_409 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_410 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_411 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_412 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_413 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_414 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_415 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_416 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_417 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_418 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_419 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_420 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_421 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_422 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_423 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_424 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_425 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_426 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_427 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_428 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_429 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_430 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_431 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_432 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_433 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_434 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_435 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_436 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_437 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_438 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_439 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_440 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_441 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_442 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_443 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_444 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_445 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_446 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_447 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_448 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_449 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_450 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_451 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_452 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_453 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_454 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_455 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_456 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_457 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_458 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_459 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_460 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_461 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_462 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_463 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_464 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_465 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_466 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_467 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_468 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_469 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_470 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_471 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_472 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_473 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_474 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_475 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_476 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_477 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_478 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_479 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_480 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_481 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_482 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_483 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_484 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_485 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_486 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_487 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_488 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_489 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_490 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_491 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_492 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_493 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_494 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_495 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_496 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_497 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_498 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_499 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_500 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_501 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_502 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_503 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_504 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_505 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_506 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_507 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_508 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_509 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_510 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_511 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_512 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_513 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_514 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_515 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_516 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_517 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_518 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_519 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_520 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_521 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_522 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_523 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_524 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_525 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_526 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_527 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_528 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_529 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_530 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_531 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_532 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_533 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_534 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_535 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_536 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_537 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_538 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_539 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_540 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_541 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_542 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_543 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_544 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_545 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_546 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_547 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_548 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_549 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_550 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_551 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_552 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_553 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_554 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_555 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_556 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_557 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_558 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_559 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_560 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_561 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_562 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_563 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_564 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_565 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_566 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_567 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_568 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_569 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_570 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_571 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_572 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_573 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_574 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_575 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_576 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_577 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_578 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_579 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_580 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_581 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_582 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_583 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_584 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_585 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_586 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_587 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_588 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_589 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_590 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_591 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_592 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_593 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_594 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_595 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_596 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_597 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_598 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_599 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_600 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_601 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_602 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_603 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_604 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_605 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_606 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_607 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_608 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_609 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_610 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_611 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_612 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_613 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_614 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_615 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_616 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_617 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_618 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_619 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_620 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_621 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_622 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_623 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_624 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_625 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_626 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_627 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_628 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_629 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_630 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_631 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_632 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_633 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_634 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_635 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_636 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_637 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_638 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_639 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_640 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_641 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_642 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_643 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_644 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_645 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_646 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_647 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_648 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_649 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_650 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_651 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_652 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_653 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_654 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_655 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_656 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_657 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_658 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_659 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_660 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_661 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_662 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_663 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_664 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_665 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_666 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_667 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_668 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_669 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_670 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_671 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_672 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_673 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_674 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_675 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_676 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_677 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_678 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_679 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_680 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_681 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_682 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_683 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_684 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_685 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_686 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_687 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_688 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_689 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_690 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_691 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_692 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_693 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_694 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_695 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_696 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_697 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_698 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_699 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_700 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_701 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_702 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_703 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_704 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_705 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_706 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_707 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_708 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_709 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_710 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_711 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_712 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_713 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_714 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_715 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_716 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_717 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_718 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_719 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_720 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_721 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_722 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_723 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_724 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_725 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_726 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_727 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_728 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_729 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_730 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_731 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_732 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_733 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_734 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_735 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_736 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_737 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_738 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_739 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_740 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_741 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_742 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_743 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_744 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_745 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_746 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_747 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_748 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_749 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_750 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_751 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_752 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_753 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_754 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_755 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_756 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_757 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_758 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_759 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_760 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_761 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_762 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_763 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_764 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_765 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_766 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_767 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_768 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_769 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_770 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_771 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_772 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_773 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_774 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_775 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_776 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_777 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_778 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_779 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_780 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_781 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_782 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_783 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_784 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_785 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_786 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_787 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_788 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_789 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_790 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_791 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_792 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_793 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_794 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_795 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_796 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_797 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_798 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_799 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_800 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_801 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_802 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_803 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_804 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_805 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_806 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_807 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_808 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_809 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_810 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_811 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_812 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_813 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_814 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_815 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_816 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_817 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_818 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_819 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_820 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_821 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_822 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_823 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_824 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_825 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_826 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_827 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_828 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_829 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_830 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_831 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_832 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_833 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_834 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_835 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_836 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_837 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_838 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_839 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_840 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_841 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_842 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_843 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_844 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_845 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_846 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_847 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_848 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_849 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_850 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_851 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_852 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_853 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_854 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_855 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_856 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_857 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_858 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_859 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_860 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_861 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_862 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_863 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_864 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_865 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_866 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_867 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_868 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_869 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_870 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_871 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_872 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_873 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_874 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_875 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_876 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_877 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_878 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_879 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_880 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_881 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_882 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_883 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_884 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_885 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_886 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_887 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_888 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_889 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_890 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_891 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_892 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_893 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_894 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_895 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_896 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_897 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_898 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_899 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_900 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_901 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_902 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_903 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_904 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_905 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_906 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_907 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_908 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_909 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_910 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_911 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_912 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_913 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_914 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_915 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_916 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_917 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_918 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_919 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_920 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_921 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_922 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_923 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_924 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_925 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_926 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_927 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_928 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_929 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_930 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_931 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_932 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_933 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_934 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_935 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_936 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_937 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_938 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_939 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_940 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_941 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_942 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_943 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_944 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_945 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_946 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_947 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_948 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_949 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_950 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_951 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_952 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_953 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_954 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_955 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_956 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_957 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_958 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_959 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_960 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_961 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_962 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_963 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_964 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_965 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_966 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_967 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_968 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_969 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_970 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_971 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_972 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_973 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_974 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_975 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_976 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_977 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_978 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_979 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_980 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_981 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_982 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_983 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_984 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_985 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_986 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_987 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_988 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_989 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_990 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_991 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_992 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_993 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_994 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_995 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_996 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_997 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_998 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_999 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1000 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1001 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1002 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1003 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1004 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1005 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1006 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1007 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1008 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1009 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1010 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1011 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1012 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1013 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1014 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1015 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1016 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1017 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1018 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1019 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1020 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1021 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1022 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1023 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1024 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1025 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1026 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1027 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1028 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1029 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1030 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1031 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1032 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1033 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1034 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1035 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1036 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1037 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1038 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1039 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1040 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1041 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1042 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1043 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1044 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1045 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1046 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1047 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1048 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1049 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1050 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1051 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1052 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1053 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1054 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1055 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1056 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1057 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1058 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1059 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1060 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1061 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1062 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1063 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1064 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1065 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1066 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1067 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1068 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1069 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1070 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1071 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1072 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1073 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1074 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1075 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1076 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1077 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1078 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1079 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1080 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1081 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1082 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1083 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1084 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1085 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1086 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1087 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1088 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1089 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1090 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1091 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1092 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1093 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1094 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1095 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1096 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1097 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1098 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1099 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1100 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1101 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1102 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1103 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1104 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1105 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1106 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1107 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1108 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1109 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1110 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1111 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1112 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1113 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1114 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1115 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1116 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1117 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1118 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1119 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1120 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1121 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1122 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1123 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1124 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1125 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1126 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1127 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1128 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1129 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1130 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1131 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1132 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1133 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1134 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1135 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1136 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1137 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1138 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1139 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1140 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1141 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1142 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1143 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1144 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1145 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1146 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1147 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1148 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1149 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1150 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1151 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1152 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1153 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1154 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1155 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1156 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1157 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1158 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1159 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1160 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1161 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1162 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1163 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1164 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1165 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1166 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1167 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1168 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1169 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1170 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1171 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1172 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1173 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1174 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1175 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1176 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1177 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1178 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1179 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1180 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1181 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1182 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1183 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1184 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1185 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1186 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1187 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1188 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1189 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1190 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1191 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1192 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1193 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1194 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1195 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1196 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1197 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1198 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1199 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1200 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1201 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1202 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1203 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1204 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1205 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1206 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1207 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1208 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1209 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1210 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1211 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1212 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1213 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1214 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1215 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1216 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1217 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1218 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1219 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1220 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1221 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1222 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1223 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1224 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1225 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1226 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1227 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1228 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1229 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1230 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1231 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1232 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1233 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1234 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1235 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1236 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1237 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1238 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1239 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1240 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1241 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1242 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1243 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1244 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1245 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1246 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1247 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1248 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1249 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1250 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1251 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1252 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1253 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1254 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1255 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1256 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1257 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1258 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1259 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1260 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1261 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1262 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1263 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1264 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1265 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1266 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1267 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1268 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1269 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1270 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1271 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1272 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1273 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1274 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1275 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1276 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1277 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1278 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1279 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1280 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1281 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1282 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1283 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1284 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1285 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1286 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1287 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1288 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1289 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1290 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1291 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1292 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1293 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1294 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1295 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1296 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1297 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1298 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1299 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1300 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1301 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1302 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1303 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1304 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1305 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1306 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1307 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1308 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1309 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1310 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1311 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1312 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1313 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1314 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1315 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1316 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1317 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1318 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1319 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1320 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1321 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1322 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1323 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1324 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1325 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1326 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1327 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1328 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1329 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1330 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1331 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1332 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1333 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1334 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1335 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1336 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1337 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1338 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1339 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1340 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1341 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1342 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1343 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1344 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1345 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1346 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1347 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1348 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1349 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1350 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1351 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1352 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1353 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1354 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1355 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1356 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1357 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1358 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1359 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1360 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1361 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1362 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1363 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1364 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1365 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1366 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1367 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1368 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1369 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1370 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1371 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1372 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1373 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1374 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1375 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1376 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1377 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1378 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1379 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1380 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1381 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1382 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1383 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1384 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1385 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1386 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1387 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1388 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1389 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1390 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1391 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1392 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1393 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1394 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1395 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1396 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1397 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1398 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1399 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1400 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1401 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1402 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1403 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1404 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1405 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1406 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1407 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1408 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1409 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1410 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1411 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1412 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1413 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1414 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1415 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1416 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1417 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1418 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1419 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1420 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1421 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1422 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1423 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1424 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1425 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1426 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1427 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1428 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1429 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1430 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1431 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1432 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1433 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1434 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1435 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1436 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1437 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1438 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1439 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1440 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1441 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1442 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1443 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1444 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1445 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1446 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1447 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1448 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1449 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1450 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1451 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1452 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1453 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1454 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1455 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1456 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1457 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1458 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1459 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1460 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1461 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1462 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1463 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1464 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1465 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1466 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1467 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1468 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1469 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1470 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1471 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1472 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1473 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1474 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1475 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1476 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1477 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1478 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1479 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1480 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1481 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1482 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1483 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1484 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1485 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1486 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1487 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1488 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1489 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1490 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1491 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1492 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1496 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1497 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1498 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1499 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1500 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1501 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1502 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1503 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1504 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1505 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1506 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1507 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1508 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1509 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1510 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1511 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1512 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1513 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1514 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1515 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1516 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1517 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1518 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1519 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1520 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1521 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1522 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1523 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1524 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1525 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1526 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1527 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1528 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1529 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1530 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1531 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1532 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1533 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1534 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1535 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1536 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1537 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1538 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1539 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1540 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1541 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1542 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1543 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1544 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1545 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1546 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1547 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1548 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1549 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1550 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1551 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1552 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1553 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1554 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1555 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1556 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1557 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1558 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1559 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1560 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1561 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1562 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1563 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1564 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1565 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1566 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1567 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1568 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1569 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1570 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1571 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1572 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1573 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1574 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1575 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1576 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1577 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1578 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1579 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1580 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1581 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1582 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1583 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1584 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1585 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1586 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1587 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1588 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1589 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1590 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1591 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1592 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1593 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1594 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1595 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1596 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1597 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1598 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1599 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1600 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1601 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1602 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1603 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1604 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1605 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1606 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1607 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1608 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1609 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1610 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1611 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1612 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1613 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1614 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1615 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1616 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1617 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1618 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1619 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1620 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1621 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1622 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1623 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1624 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1625 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1626 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1627 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1628 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1629 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1630 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1631 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1632 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1633 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1634 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1635 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1636 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1637 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1638 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1639 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1640 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1641 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1642 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1643 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1644 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1645 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1646 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1647 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1648 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1649 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1650 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1651 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1652 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1653 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1654 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1655 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1656 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1657 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1658 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1659 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1660 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1661 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1662 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1663 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1664 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1665 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1666 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1667 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1668 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1669 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1670 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1671 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1672 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1673 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1674 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1675 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1676 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1677 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1678 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1679 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1680 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1681 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1682 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1683 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1684 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1685 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1686 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1687 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1688 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1689 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1690 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1691 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1692 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1693 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1694 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1695 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1696 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1697 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1698 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1699 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1700 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1701 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1702 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1703 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1704 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1705 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1706 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1707 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1708 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1709 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1710 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1711 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1712 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1713 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1714 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1715 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1716 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1717 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1718 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1719 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1720 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1721 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1722 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1723 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1724 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1725 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1726 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1727 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1728 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1729 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1730 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1731 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1732 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1733 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1734 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1735 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1736 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1737 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1738 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1739 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1740 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1741 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1742 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1743 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1745 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1746 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1747 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1748 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1749 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1750 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1751 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1752 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1753 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1754 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1755 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1756 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1757 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1758 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1759 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1760 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1761 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1762 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1763 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1764 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1765 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1766 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1767 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1768 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1769 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1770 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1771 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1772 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1773 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1774 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1775 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1776 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1777 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1778 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1779 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1780 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1781 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1782 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1783 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1784 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1785 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1786 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1787 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1788 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1789 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1790 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1791 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1792 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1793 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1794 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1795 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1796 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1797 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1798 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1799 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1800 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1801 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1802 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1803 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1804 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1805 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1806 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1807 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1808 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1809 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1810 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1811 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1812 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1813 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1814 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1815 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1816 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1817 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1818 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1819 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1820 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1821 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1822 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1823 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1824 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1825 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1826 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1827 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1828 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1829 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1830 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1831 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1832 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1833 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1834 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1835 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1836 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame world_func_detail_Brush_1837 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,3404.59136,-4942.6276,1.000000;;
 }
}

Frame Stair_2 {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh  {
  1065;
  -127.692595;144.653798;-5.142400;,
  -127.692595;153.053798;-0.342300;,
  -127.692595;144.653798;-0.342300;,
  -127.692595;153.053798;-0.342300;,
  -127.692595;144.653798;-5.142400;,
  -127.692595;153.053798;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;153.053798;-5.142400;,
  -127.692595;153.053798;-5.142400;,
  -146.892595;153.053798;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;144.653798;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;144.653798;-0.342300;,
  -146.892595;144.653798;-5.142400;,
  -146.892595;144.653798;-0.342300;,
  -127.692595;144.653798;-5.142400;,
  -127.692595;144.653798;-0.342300;,
  -127.692595;156.653798;-3.942400;,
  -127.692595;153.053798;-0.342300;,
  -127.692595;154.253798;-6.342500;,
  -127.692595;153.053798;-0.342300;,
  -127.692595;156.653798;-3.942400;,
  -127.692595;156.653798;-0.342300;,
  -127.692595;153.053798;-6.342300;,
  -127.692595;154.253798;-6.342500;,
  -127.692595;153.053798;-0.342300;,
  -127.692595;153.053798;-6.342300;,
  -146.892595;154.253798;-6.342500;,
  -127.692595;154.253798;-6.342500;,
  -146.892595;154.253798;-6.342500;,
  -127.692595;153.053798;-6.342300;,
  -146.892595;153.053798;-6.342300;,
  -127.692595;153.053798;-0.342300;,
  -146.892595;153.053798;-6.342300;,
  -127.692595;153.053798;-6.342300;,
  -146.892595;153.053798;-6.342300;,
  -127.692595;153.053798;-0.342300;,
  -146.892595;153.053798;-0.342300;,
  -146.892595;156.653798;-0.342300;,
  -127.692595;156.653798;-3.942400;,
  -146.892595;156.653798;-3.942400;,
  -127.692595;156.653798;-3.942400;,
  -146.892595;156.653798;-0.342300;,
  -127.692595;156.653798;-0.342300;,
  -146.892595;154.253798;-6.342500;,
  -127.692595;156.653798;-3.942400;,
  -127.692595;154.253798;-6.342500;,
  -127.692595;156.653798;-3.942400;,
  -146.892595;154.253798;-6.342500;,
  -146.892595;156.653798;-3.942400;,
  -122.892595;142.254003;-0.342300;,
  -108.492595;135.054003;-5.142400;,
  -108.492595;135.054003;-0.342300;,
  -108.492595;135.054003;-5.142400;,
  -122.892595;142.254003;-0.342300;,
  -122.892595;142.254003;-5.142400;,
  -122.892595;143.453798;-0.342300;,
  -122.892595;142.254003;-5.142400;,
  -122.892595;142.254003;-0.342300;,
  -122.892595;142.254003;-5.142400;,
  -122.892595;143.453798;-0.342300;,
  -122.892595;143.453798;-5.142400;,
  -108.492595;143.453798;-0.342300;,
  -108.492595;135.054003;-5.142400;,
  -108.492595;143.453798;-5.142400;,
  -108.492595;135.054003;-5.142400;,
  -108.492595;143.453798;-0.342300;,
  -108.492595;135.054003;-0.342300;,
  -108.492595;143.453798;-5.142400;,
  -122.892595;142.254003;-5.142400;,
  -122.892595;143.453798;-5.142400;,
  -122.892595;142.254003;-5.142400;,
  -108.492595;143.453798;-5.142400;,
  -108.492595;135.054003;-5.142400;,
  -122.892595;143.453798;-0.342300;,
  -122.892595;147.053798;-3.942400;,
  -122.892595;144.653798;-6.342500;,
  -122.892595;147.053798;-3.942400;,
  -122.892595;143.453798;-0.342300;,
  -122.892595;147.053798;-0.342300;,
  -122.892595;143.453798;-6.342300;,
  -122.892595;143.453798;-0.342300;,
  -122.892595;144.653798;-6.342500;,
  -108.492595;147.053798;-3.942400;,
  -108.492595;143.453798;-0.342300;,
  -108.492595;144.653798;-6.342500;,
  -108.492595;143.453798;-0.342300;,
  -108.492595;147.053798;-3.942400;,
  -108.492595;147.053798;-0.342300;,
  -108.492595;143.453798;-6.342300;,
  -108.492595;144.653798;-6.342500;,
  -108.492595;143.453798;-0.342300;,
  -122.892595;144.653798;-6.342500;,
  -108.492595;143.453798;-6.342300;,
  -122.892595;143.453798;-6.342300;,
  -108.492595;143.453798;-6.342300;,
  -122.892595;144.653798;-6.342500;,
  -108.492595;144.653798;-6.342500;,
  -122.892595;143.453798;-6.342300;,
  -108.492595;143.453798;-0.342300;,
  -122.892595;143.453798;-0.342300;,
  -108.492595;143.453798;-0.342300;,
  -122.892595;143.453798;-6.342300;,
  -108.492595;143.453798;-6.342300;,
  -122.892595;147.053798;-0.342300;,
  -108.492595;147.053798;-3.942400;,
  -122.892595;147.053798;-3.942400;,
  -108.492595;147.053798;-3.942400;,
  -122.892595;147.053798;-0.342300;,
  -108.492595;147.053798;-0.342300;,
  -122.892595;147.053798;-3.942400;,
  -108.492595;144.653798;-6.342500;,
  -122.892595;144.653798;-6.342500;,
  -108.492595;144.653798;-6.342500;,
  -122.892595;147.053798;-3.942400;,
  -108.492595;147.053798;-3.942400;,
  -103.692595;133.853901;-5.142400;,
  -89.292602;133.853901;-0.342300;,
  -89.292602;133.853901;-5.142400;,
  -89.292602;133.853901;-0.342300;,
  -103.692595;133.853901;-5.142400;,
  -103.692595;133.853901;-0.342300;,
  -103.692595;132.653901;-5.142400;,
  -89.292602;125.453798;-0.342300;,
  -103.692595;132.653901;-0.342300;,
  -89.292602;125.453798;-0.342300;,
  -103.692595;132.653901;-5.142400;,
  -89.292602;125.453798;-5.142400;,
  -103.692595;133.853901;-5.142400;,
  -103.692595;132.653901;-0.342300;,
  -103.692595;133.853901;-0.342300;,
  -103.692595;132.653901;-0.342300;,
  -103.692595;133.853901;-5.142400;,
  -103.692595;132.653901;-5.142400;,
  -89.292602;133.853901;-5.142400;,
  -89.292602;125.453798;-0.342300;,
  -89.292602;125.453798;-5.142400;,
  -89.292602;125.453798;-0.342300;,
  -89.292602;133.853901;-5.142400;,
  -89.292602;133.853901;-0.342300;,
  -89.292602;133.853901;-5.142400;,
  -103.692595;132.653901;-5.142400;,
  -103.692595;133.853901;-5.142400;,
  -103.692595;132.653901;-5.142400;,
  -89.292602;133.853901;-5.142400;,
  -89.292602;125.453798;-5.142400;,
  -103.692595;133.853901;-0.342300;,
  -103.692595;137.453798;-3.942400;,
  -103.692595;135.053210;-6.342300;,
  -103.692595;137.453798;-3.942400;,
  -103.692595;133.853901;-0.342300;,
  -103.692595;137.453798;-0.342300;,
  -103.692595;133.853901;-6.342300;,
  -103.692595;133.853901;-0.342300;,
  -103.692595;135.053210;-6.342300;,
  -89.292602;137.453798;-3.942400;,
  -89.292602;133.853901;-0.342300;,
  -89.292602;135.053210;-6.342300;,
  -89.292602;133.853901;-0.342300;,
  -89.292602;137.453798;-3.942400;,
  -89.292602;137.453798;-0.342300;,
  -89.292602;133.853901;-6.342300;,
  -89.292602;135.053210;-6.342300;,
  -89.292602;133.853901;-0.342300;,
  -103.692595;135.053210;-6.342300;,
  -89.292602;133.853901;-6.342300;,
  -103.692595;133.853901;-6.342300;,
  -89.292602;133.853901;-6.342300;,
  -103.692595;135.053210;-6.342300;,
  -89.292602;135.053210;-6.342300;,
  -103.692595;133.853901;-6.342300;,
  -89.292602;133.853901;-0.342300;,
  -103.692595;133.853901;-0.342300;,
  -89.292602;133.853901;-0.342300;,
  -103.692595;133.853901;-6.342300;,
  -89.292602;133.853901;-6.342300;,
  -103.692595;137.453798;-0.342300;,
  -89.292602;137.453798;-3.942400;,
  -103.692595;137.453798;-3.942400;,
  -89.292602;137.453798;-3.942400;,
  -103.692595;137.453798;-0.342300;,
  -89.292602;137.453798;-0.342300;,
  -103.692595;137.453798;-3.942400;,
  -89.292602;135.053210;-6.342300;,
  -103.692595;135.053210;-6.342300;,
  -89.292602;135.053210;-6.342300;,
  -103.692595;137.453798;-3.942400;,
  -89.292602;137.453798;-3.942400;,
  -84.492602;124.253798;-5.142400;,
  -70.092595;124.253798;-0.342300;,
  -70.092595;124.253798;-5.142400;,
  -70.092595;124.253798;-0.342300;,
  -84.492602;124.253798;-5.142400;,
  -84.492602;124.253798;-0.342300;,
  -84.492602;123.053798;-5.142400;,
  -70.092595;115.853798;-0.342300;,
  -84.492602;123.053798;-0.342300;,
  -70.092595;115.853798;-0.342300;,
  -84.492602;123.053798;-5.142400;,
  -70.092595;115.853798;-5.142400;,
  -84.492602;124.253798;-5.142400;,
  -84.492602;123.053798;-0.342300;,
  -84.492602;124.253798;-0.342300;,
  -84.492602;123.053798;-0.342300;,
  -84.492602;124.253798;-5.142400;,
  -84.492602;123.053798;-5.142400;,
  -70.092595;124.253798;-5.142400;,
  -70.092595;115.853798;-0.342300;,
  -70.092595;115.853798;-5.142400;,
  -70.092595;115.853798;-0.342300;,
  -70.092595;124.253798;-5.142400;,
  -70.092595;124.253798;-0.342300;,
  -70.092595;124.253798;-5.142400;,
  -84.492602;123.053798;-5.142400;,
  -84.492602;124.253798;-5.142400;,
  -84.492602;123.053798;-5.142400;,
  -70.092595;124.253798;-5.142400;,
  -70.092595;115.853798;-5.142400;,
  -84.492602;124.253798;-0.342300;,
  -84.492602;127.853798;-3.942400;,
  -84.492602;125.453798;-6.342500;,
  -84.492602;127.853798;-3.942400;,
  -84.492602;124.253798;-0.342300;,
  -84.492602;127.853798;-0.342300;,
  -84.492602;124.253798;-6.342300;,
  -84.492602;124.253798;-0.342300;,
  -84.492602;125.453798;-6.342500;,
  -70.092595;127.853798;-3.942400;,
  -70.092595;124.253798;-0.342300;,
  -70.092595;125.453798;-6.342500;,
  -70.092595;124.253798;-0.342300;,
  -70.092595;127.853798;-3.942400;,
  -70.092595;127.853798;-0.342300;,
  -70.092595;124.253798;-6.342300;,
  -70.092595;125.453798;-6.342500;,
  -70.092595;124.253798;-0.342300;,
  -84.492602;125.453798;-6.342500;,
  -70.092595;124.253798;-6.342300;,
  -84.492602;124.253798;-6.342300;,
  -70.092595;124.253798;-6.342300;,
  -84.492602;125.453798;-6.342500;,
  -70.092595;125.453798;-6.342500;,
  -84.492602;124.253798;-6.342300;,
  -70.092595;124.253798;-0.342300;,
  -84.492602;124.253798;-0.342300;,
  -70.092595;124.253798;-0.342300;,
  -84.492602;124.253798;-6.342300;,
  -70.092595;124.253798;-6.342300;,
  -84.492602;127.853798;-0.342300;,
  -70.092595;127.853798;-3.942400;,
  -84.492602;127.853798;-3.942400;,
  -70.092595;127.853798;-3.942400;,
  -84.492602;127.853798;-0.342300;,
  -70.092595;127.853798;-0.342300;,
  -84.492602;127.853798;-3.942400;,
  -70.092595;125.453798;-6.342500;,
  -84.492602;125.453798;-6.342500;,
  -70.092595;125.453798;-6.342500;,
  -84.492602;127.853798;-3.942400;,
  -70.092595;127.853798;-3.942400;,
  -65.292602;114.653798;-5.142400;,
  -65.292602;113.453798;-0.342300;,
  -65.292602;114.653798;-0.342300;,
  -65.292602;113.453798;-0.342300;,
  -65.292602;114.653798;-5.142400;,
  -65.292602;113.453798;-5.142400;,
  -50.892602;114.653798;-5.142400;,
  -50.892602;106.253798;-0.342300;,
  -50.892602;106.253798;-5.142400;,
  -50.892602;106.253798;-0.342300;,
  -50.892602;114.653798;-5.142400;,
  -50.892602;114.653798;-0.342300;,
  -50.892602;114.653798;-5.142400;,
  -65.292602;113.453798;-5.142400;,
  -65.292602;114.653798;-5.142400;,
  -65.292602;113.453798;-5.142400;,
  -50.892602;114.653798;-5.142400;,
  -50.892602;106.253798;-5.142400;,
  -65.292602;113.453798;-5.142400;,
  -50.892602;106.253798;-0.342300;,
  -65.292602;113.453798;-0.342300;,
  -50.892602;106.253798;-0.342300;,
  -65.292602;113.453798;-5.142400;,
  -50.892602;106.253798;-5.142400;,
  -65.292602;114.653798;-0.342300;,
  -65.292602;118.253798;-3.942400;,
  -65.292602;115.853798;-6.342500;,
  -65.292602;118.253798;-3.942400;,
  -65.292602;114.653798;-0.342300;,
  -65.292602;118.253798;-0.342300;,
  -65.292602;114.653798;-6.342300;,
  -65.292602;114.653798;-0.342300;,
  -65.292602;115.853798;-6.342500;,
  -50.892602;118.253798;-3.942400;,
  -50.892602;114.653798;-0.342300;,
  -50.892602;115.853798;-6.342500;,
  -50.892602;114.653798;-0.342300;,
  -50.892602;118.253798;-3.942400;,
  -50.892602;118.253798;-0.342300;,
  -50.892602;114.653798;-6.342300;,
  -50.892602;115.853798;-6.342500;,
  -50.892602;114.653798;-0.342300;,
  -65.292602;115.853798;-6.342500;,
  -50.892602;114.653798;-6.342300;,
  -65.292602;114.653798;-6.342300;,
  -50.892602;114.653798;-6.342300;,
  -65.292602;115.853798;-6.342500;,
  -50.892602;115.853798;-6.342500;,
  -65.292602;114.653798;-6.342300;,
  -50.892602;114.653798;-0.342300;,
  -65.292602;114.653798;-0.342300;,
  -50.892602;114.653798;-0.342300;,
  -65.292602;114.653798;-6.342300;,
  -50.892602;114.653798;-6.342300;,
  -65.292602;118.253798;-0.342300;,
  -50.892602;118.253798;-3.942400;,
  -65.292602;118.253798;-3.942400;,
  -50.892602;118.253798;-3.942400;,
  -65.292602;118.253798;-0.342300;,
  -50.892602;118.253798;-0.342300;,
  -65.292602;118.253798;-3.942400;,
  -50.892602;115.853798;-6.342500;,
  -65.292602;115.853798;-6.342500;,
  -50.892602;115.853798;-6.342500;,
  -65.292602;118.253798;-3.942400;,
  -50.892602;118.253798;-3.942400;,
  -46.092602;105.053805;-5.142400;,
  -46.092602;103.853798;-0.342300;,
  -46.092602;105.053805;-0.342300;,
  -46.092602;103.853798;-0.342300;,
  -46.092602;105.053805;-5.142400;,
  -46.092602;103.853798;-5.142400;,
  -31.692602;105.053805;-5.142400;,
  -31.692602;96.653798;-0.342300;,
  -31.692602;96.653798;-5.142400;,
  -31.692602;96.653798;-0.342300;,
  -31.692602;105.053805;-5.142400;,
  -31.692602;105.053805;-0.342300;,
  -31.692602;105.053805;-5.142400;,
  -46.092602;103.853798;-5.142400;,
  -46.092602;105.053805;-5.142400;,
  -46.092602;103.853798;-5.142400;,
  -31.692602;105.053805;-5.142400;,
  -31.692602;96.653798;-5.142400;,
  -46.092602;105.053805;-5.142400;,
  -31.692602;105.053805;-0.342300;,
  -31.692602;105.053805;-5.142400;,
  -31.692602;105.053805;-0.342300;,
  -46.092602;105.053805;-5.142400;,
  -46.092602;105.053805;-0.342300;,
  -46.092602;103.853798;-5.142400;,
  -31.692602;96.653798;-0.342300;,
  -46.092602;103.853798;-0.342300;,
  -31.692602;96.653798;-0.342300;,
  -46.092602;103.853798;-5.142400;,
  -31.692602;96.653798;-5.142400;,
  -31.692602;108.653798;-3.942400;,
  -31.692602;105.053805;-0.342300;,
  -31.692602;106.253798;-6.342500;,
  -31.692602;105.053805;-0.342300;,
  -31.692602;108.653798;-3.942400;,
  -31.692602;108.653798;-0.342300;,
  -31.692602;105.053805;-6.342300;,
  -31.692602;106.253798;-6.342500;,
  -31.692602;105.053805;-0.342300;,
  -31.692602;106.253798;-6.342500;,
  -46.092602;105.053805;-6.342300;,
  -46.092602;106.253798;-6.342500;,
  -46.092602;105.053805;-6.342300;,
  -31.692602;106.253798;-6.342500;,
  -31.692602;105.053805;-6.342300;,
  -46.092602;105.053805;-0.342300;,
  -31.692602;105.053805;-6.342300;,
  -31.692602;105.053805;-0.342300;,
  -31.692602;105.053805;-6.342300;,
  -46.092602;105.053805;-0.342300;,
  -46.092602;105.053805;-6.342300;,
  -31.692602;108.653798;-0.342300;,
  -46.092602;108.653798;-3.942400;,
  -46.092602;108.653798;-0.342300;,
  -46.092602;108.653798;-3.942400;,
  -31.692602;108.653798;-0.342300;,
  -31.692602;108.653798;-3.942400;,
  -31.692602;106.253798;-6.342500;,
  -46.092602;108.653798;-3.942400;,
  -31.692602;108.653798;-3.942400;,
  -46.092602;108.653798;-3.942400;,
  -31.692602;106.253798;-6.342500;,
  -46.092602;106.253798;-6.342500;,
  -46.092602;108.653798;-3.942400;,
  -46.092602;105.053805;-6.342300;,
  -46.092602;108.653798;-0.342300;,
  -46.092602;105.053805;-6.342300;,
  -46.092602;108.653798;-3.942400;,
  -46.092602;106.253798;-6.342500;,
  -46.092602;105.053805;-6.342300;,
  -46.092602;105.053805;-0.342300;,
  -46.092602;108.653798;-0.342300;,
  -26.892598;95.453798;-5.142400;,
  -26.892598;94.253997;-0.342300;,
  -26.892598;95.453798;-0.342300;,
  -26.892598;94.253997;-0.342300;,
  -26.892598;95.453798;-5.142400;,
  -26.892598;94.253997;-5.142400;,
  -12.492601;95.453798;-5.142400;,
  -12.492601;87.054003;-0.342300;,
  -12.492601;87.054003;-5.142400;,
  -12.492601;87.054003;-0.342300;,
  -12.492601;95.453798;-5.142400;,
  -12.492601;95.453798;-0.342300;,
  -12.492601;95.453798;-5.142400;,
  -26.892598;94.253997;-5.142400;,
  -26.892598;95.453798;-5.142400;,
  -26.892598;94.253997;-5.142400;,
  -12.492601;95.453798;-5.142400;,
  -12.492601;87.054003;-5.142400;,
  -26.892598;95.453798;-5.142400;,
  -12.492601;95.453798;-0.342300;,
  -12.492601;95.453798;-5.142400;,
  -12.492601;95.453798;-0.342300;,
  -26.892598;95.453798;-5.142400;,
  -26.892598;95.453798;-0.342300;,
  -26.892598;94.253997;-5.142400;,
  -12.492601;87.054003;-0.342300;,
  -26.892598;94.253997;-0.342300;,
  -12.492601;87.054003;-0.342300;,
  -26.892598;94.253997;-5.142400;,
  -12.492601;87.054003;-5.142400;,
  -26.892598;95.453798;-0.342300;,
  -12.492601;95.453798;-6.342300;,
  -12.492601;95.453798;-0.342300;,
  -12.492601;95.453798;-6.342300;,
  -26.892598;95.453798;-0.342300;,
  -26.892598;95.453798;-6.342300;,
  -26.892598;99.053805;-0.342300;,
  -12.492601;99.053805;-3.942300;,
  -26.892598;99.053805;-3.942300;,
  -12.492601;99.053805;-3.942300;,
  -26.892598;99.053805;-0.342300;,
  -12.492601;99.053805;-0.342300;,
  -26.892598;99.053805;-3.942300;,
  -12.492601;96.653197;-6.342300;,
  -26.892598;96.653197;-6.342300;,
  -12.492601;96.653197;-6.342300;,
  -26.892598;99.053805;-3.942300;,
  -12.492601;99.053805;-3.942300;,
  -26.892598;99.053805;-3.942300;,
  -26.892598;95.453798;-6.342300;,
  -26.892598;99.053805;-0.342300;,
  -26.892598;95.453798;-6.342300;,
  -26.892598;99.053805;-3.942300;,
  -26.892598;96.653197;-6.342300;,
  -26.892598;95.453798;-0.342300;,
  -26.892598;99.053805;-0.342300;,
  -26.892598;95.453798;-6.342300;,
  -12.492601;95.453798;-6.342300;,
  -12.492601;99.053805;-3.942300;,
  -12.492601;99.053805;-0.342300;,
  -12.492601;99.053805;-3.942300;,
  -12.492601;95.453798;-6.342300;,
  -12.492601;96.653197;-6.342300;,
  -12.492601;95.453798;-0.342300;,
  -12.492601;95.453798;-6.342300;,
  -12.492601;99.053805;-0.342300;,
  -26.892598;96.653197;-6.342300;,
  -12.492601;95.453798;-6.342300;,
  -26.892598;95.453798;-6.342300;,
  -12.492601;95.453798;-6.342300;,
  -26.892598;96.653197;-6.342300;,
  -12.492601;96.653197;-6.342300;,
  -7.692600;85.853798;-5.142400;,
  -7.692600;84.653798;-0.342300;,
  -7.692600;85.853798;-0.342300;,
  -7.692600;84.653798;-0.342300;,
  -7.692600;85.853798;-5.142400;,
  -7.692600;84.653798;-5.142400;,
  6.707400;85.853798;-5.142400;,
  6.707400;77.453798;-0.342300;,
  6.707400;77.453798;-5.142400;,
  6.707400;77.453798;-0.342300;,
  6.707400;85.853798;-5.142400;,
  6.707400;85.853798;-0.342300;,
  6.707400;85.853798;-5.142400;,
  -7.692600;84.653798;-5.142400;,
  -7.692600;85.853798;-5.142400;,
  -7.692600;84.653798;-5.142400;,
  6.707400;85.853798;-5.142400;,
  6.707400;77.453798;-5.142400;,
  -7.692600;85.853798;-5.142400;,
  6.707400;85.853798;-0.342300;,
  6.707400;85.853798;-5.142400;,
  6.707400;85.853798;-0.342300;,
  -7.692600;85.853798;-5.142400;,
  -7.692600;85.853798;-0.342300;,
  -7.692600;84.653798;-5.142400;,
  6.707400;77.453798;-0.342300;,
  -7.692600;84.653798;-0.342300;,
  6.707400;77.453798;-0.342300;,
  -7.692600;84.653798;-5.142400;,
  6.707400;77.453798;-5.142400;,
  -7.692600;85.853798;-6.342300;,
  6.707400;85.853798;-0.342300;,
  -7.692600;85.853798;-0.342300;,
  6.707400;85.853798;-0.342300;,
  -7.692600;85.853798;-6.342300;,
  6.707400;85.853798;-6.342300;,
  -7.692600;89.453798;-3.942400;,
  6.707400;89.453798;-0.342300;,
  6.707400;89.453798;-3.942400;,
  6.707400;89.453798;-0.342300;,
  -7.692600;89.453798;-3.942400;,
  -7.692600;89.453798;-0.342300;,
  -7.692600;89.453798;-3.942400;,
  6.707400;87.053805;-6.342500;,
  -7.692600;87.053805;-6.342500;,
  6.707400;87.053805;-6.342500;,
  -7.692600;89.453798;-3.942400;,
  6.707400;89.453798;-3.942400;,
  -7.692600;85.853798;-0.342300;,
  -7.692600;89.453798;-3.942400;,
  -7.692600;87.053805;-6.342500;,
  -7.692600;89.453798;-3.942400;,
  -7.692600;85.853798;-0.342300;,
  -7.692600;89.453798;-0.342300;,
  -7.692600;85.853798;-6.342300;,
  -7.692600;85.853798;-0.342300;,
  -7.692600;87.053805;-6.342500;,
  6.707400;85.853798;-0.342300;,
  6.707400;89.453798;-3.942400;,
  6.707400;89.453798;-0.342300;,
  6.707400;89.453798;-3.942400;,
  6.707400;85.853798;-0.342300;,
  6.707400;87.053805;-6.342500;,
  6.707400;85.853798;-6.342300;,
  6.707400;87.053805;-6.342500;,
  6.707400;85.853798;-0.342300;,
  -7.692600;87.053805;-6.342500;,
  6.707400;85.853798;-6.342300;,
  -7.692600;85.853798;-6.342300;,
  6.707400;85.853798;-6.342300;,
  -7.692600;87.053805;-6.342500;,
  6.707400;87.053805;-6.342500;,
  11.507399;76.253798;-5.142400;,
  11.507399;75.053702;-0.342300;,
  11.507399;76.253798;-0.342300;,
  11.507399;75.053702;-0.342300;,
  11.507399;76.253798;-5.142400;,
  11.507399;75.053702;-5.142400;,
  25.907400;76.253798;-5.142400;,
  25.907400;67.853696;-0.342300;,
  25.907400;67.853696;-5.142400;,
  25.907400;67.853696;-0.342300;,
  25.907400;76.253798;-5.142400;,
  25.907400;76.253798;-0.342300;,
  25.907400;76.253798;-5.142400;,
  11.507399;75.053702;-5.142400;,
  11.507399;76.253798;-5.142400;,
  11.507399;75.053702;-5.142400;,
  25.907400;76.253798;-5.142400;,
  25.907400;67.853696;-5.142400;,
  11.507399;76.253798;-5.142400;,
  25.907400;76.253798;-0.342300;,
  25.907400;76.253798;-5.142400;,
  25.907400;76.253798;-0.342300;,
  11.507399;76.253798;-5.142400;,
  11.507399;76.253798;-0.342300;,
  11.507399;75.053702;-5.142400;,
  25.907400;67.853696;-0.342300;,
  11.507399;75.053702;-0.342300;,
  25.907400;67.853696;-0.342300;,
  11.507399;75.053702;-5.142400;,
  25.907400;67.853696;-5.142400;,
  11.507399;79.853798;-3.942400;,
  25.907400;79.853798;-0.342300;,
  25.907400;79.853798;-3.942400;,
  25.907400;79.853798;-0.342300;,
  11.507399;79.853798;-3.942400;,
  11.507399;79.853798;-0.342300;,
  11.507399;79.853798;-3.942400;,
  25.907400;77.453798;-6.342500;,
  11.507399;77.453798;-6.342500;,
  25.907400;77.453798;-6.342500;,
  11.507399;79.853798;-3.942400;,
  25.907400;79.853798;-3.942400;,
  11.507399;79.853798;-3.942400;,
  11.507399;76.253798;-0.342300;,
  11.507399;79.853798;-0.342300;,
  11.507399;76.253798;-0.342300;,
  11.507399;79.853798;-3.942400;,
  11.507399;76.253798;-6.342300;,
  11.507399;79.853798;-3.942400;,
  11.507399;77.453798;-6.342500;,
  11.507399;76.253798;-6.342300;,
  25.907400;76.253798;-0.342300;,
  25.907400;77.453798;-6.342500;,
  25.907400;79.853798;-0.342300;,
  25.907400;77.453798;-6.342500;,
  25.907400;76.253798;-0.342300;,
  25.907400;76.253798;-6.342300;,
  25.907400;79.853798;-3.942400;,
  25.907400;79.853798;-0.342300;,
  25.907400;77.453798;-6.342500;,
  11.507399;77.453798;-6.342500;,
  25.907400;76.253798;-6.342300;,
  11.507399;76.253798;-6.342300;,
  25.907400;76.253798;-6.342300;,
  11.507399;77.453798;-6.342500;,
  25.907400;77.453798;-6.342500;,
  25.907400;76.253798;-6.342300;,
  11.507399;76.253798;-0.342300;,
  11.507399;76.253798;-6.342300;,
  11.507399;76.253798;-0.342300;,
  25.907400;76.253798;-6.342300;,
  25.907400;76.253798;-0.342300;,
  30.707398;66.653798;-5.142400;,
  30.707398;65.453798;-0.342300;,
  30.707398;66.653798;-0.342300;,
  30.707398;65.453798;-0.342300;,
  30.707398;66.653798;-5.142400;,
  30.707398;65.453798;-5.142400;,
  45.107398;66.653798;-5.142400;,
  45.107398;58.253798;-0.342300;,
  45.107398;58.253798;-5.142400;,
  45.107398;58.253798;-0.342300;,
  45.107398;66.653798;-5.142400;,
  45.107398;66.653798;-0.342300;,
  45.107398;66.653798;-5.142400;,
  30.707398;65.453798;-5.142400;,
  30.707398;66.653798;-5.142400;,
  30.707398;65.453798;-5.142400;,
  45.107398;66.653798;-5.142400;,
  45.107398;58.253798;-5.142400;,
  30.707398;66.653798;-5.142400;,
  45.107398;66.653798;-0.342300;,
  45.107398;66.653798;-5.142400;,
  45.107398;66.653798;-0.342300;,
  30.707398;66.653798;-5.142400;,
  30.707398;66.653798;-0.342300;,
  30.707398;65.453798;-5.142400;,
  45.107398;58.253798;-0.342300;,
  30.707398;65.453798;-0.342300;,
  45.107398;58.253798;-0.342300;,
  30.707398;65.453798;-5.142400;,
  45.107398;58.253798;-5.142400;,
  30.707398;67.853203;-6.342300;,
  45.107398;70.253798;-3.942300;,
  45.107398;67.853203;-6.342300;,
  45.107398;70.253798;-3.942300;,
  30.707398;67.853203;-6.342300;,
  30.707398;70.253798;-3.942300;,
  30.707398;66.653798;-0.342300;,
  30.707398;70.253798;-3.942300;,
  30.707398;67.853203;-6.342300;,
  30.707398;70.253798;-3.942300;,
  30.707398;66.653798;-0.342300;,
  30.707398;70.253798;-0.342300;,
  30.707398;67.853203;-6.342300;,
  30.707398;66.653798;-6.342300;,
  30.707398;66.653798;-0.342300;,
  45.107398;66.653798;-0.342300;,
  45.107398;67.853203;-6.342300;,
  45.107398;70.253798;-0.342300;,
  45.107398;67.853203;-6.342300;,
  45.107398;66.653798;-0.342300;,
  45.107398;66.653798;-6.342300;,
  45.107398;67.853203;-6.342300;,
  45.107398;70.253798;-3.942300;,
  45.107398;70.253798;-0.342300;,
  30.707398;67.853203;-6.342300;,
  45.107398;66.653798;-6.342300;,
  30.707398;66.653798;-6.342300;,
  45.107398;66.653798;-6.342300;,
  30.707398;67.853203;-6.342300;,
  45.107398;67.853203;-6.342300;,
  30.707398;66.653798;-6.342300;,
  45.107398;66.653798;-0.342300;,
  30.707398;66.653798;-0.342300;,
  45.107398;66.653798;-0.342300;,
  30.707398;66.653798;-6.342300;,
  45.107398;66.653798;-6.342300;,
  30.707398;70.253798;-0.342300;,
  45.107398;70.253798;-3.942300;,
  30.707398;70.253798;-3.942300;,
  45.107398;70.253798;-3.942300;,
  30.707398;70.253798;-0.342300;,
  45.107398;70.253798;-0.342300;,
  49.907398;57.053798;-5.142400;,
  49.907398;55.853805;-0.342300;,
  49.907398;57.053798;-0.342300;,
  49.907398;55.853805;-0.342300;,
  49.907398;57.053798;-5.142400;,
  49.907398;55.853805;-5.142400;,
  64.307405;57.053798;-5.142400;,
  64.307405;48.653802;-0.342300;,
  64.307405;48.653802;-5.142400;,
  64.307405;48.653802;-0.342300;,
  64.307405;57.053798;-5.142400;,
  64.307405;57.053798;-0.342300;,
  64.307405;57.053798;-5.142400;,
  49.907398;55.853805;-5.142400;,
  49.907398;57.053798;-5.142400;,
  49.907398;55.853805;-5.142400;,
  64.307405;57.053798;-5.142400;,
  64.307405;48.653802;-5.142400;,
  49.907398;55.853805;-5.142400;,
  64.307405;48.653802;-0.342300;,
  49.907398;55.853805;-0.342300;,
  64.307405;48.653802;-0.342300;,
  49.907398;55.853805;-5.142400;,
  64.307405;48.653802;-5.142400;,
  49.907398;57.053798;-0.342300;,
  49.907398;60.653798;-3.942400;,
  49.907398;58.253798;-6.342500;,
  49.907398;60.653798;-3.942400;,
  49.907398;57.053798;-0.342300;,
  49.907398;60.653798;-0.342300;,
  49.907398;57.053798;-6.342300;,
  49.907398;57.053798;-0.342300;,
  49.907398;58.253798;-6.342500;,
  64.307405;60.653798;-3.942400;,
  64.307405;57.053798;-0.342300;,
  64.307405;58.253798;-6.342500;,
  64.307405;57.053798;-0.342300;,
  64.307405;60.653798;-3.942400;,
  64.307405;60.653798;-0.342300;,
  64.307405;57.053798;-6.342300;,
  64.307405;58.253798;-6.342500;,
  64.307405;57.053798;-0.342300;,
  49.907398;58.253798;-6.342500;,
  64.307405;57.053798;-6.342300;,
  49.907398;57.053798;-6.342300;,
  64.307405;57.053798;-6.342300;,
  49.907398;58.253798;-6.342500;,
  64.307405;58.253798;-6.342500;,
  49.907398;57.053798;-6.342300;,
  64.307405;57.053798;-0.342300;,
  49.907398;57.053798;-0.342300;,
  64.307405;57.053798;-0.342300;,
  49.907398;57.053798;-6.342300;,
  64.307405;57.053798;-6.342300;,
  49.907398;60.653798;-0.342300;,
  64.307405;60.653798;-3.942400;,
  49.907398;60.653798;-3.942400;,
  64.307405;60.653798;-3.942400;,
  49.907398;60.653798;-0.342300;,
  64.307405;60.653798;-0.342300;,
  49.907398;60.653798;-3.942400;,
  64.307405;58.253798;-6.342500;,
  49.907398;58.253798;-6.342500;,
  64.307405;58.253798;-6.342500;,
  49.907398;60.653798;-3.942400;,
  64.307405;60.653798;-3.942400;,
  69.107398;47.453802;-5.142400;,
  69.107398;46.254003;-0.342300;,
  69.107398;47.453802;-0.342300;,
  69.107398;46.254003;-0.342300;,
  69.107398;47.453802;-5.142400;,
  69.107398;46.254003;-5.142400;,
  83.507398;47.453802;-5.142400;,
  83.507398;39.054000;-0.342300;,
  83.507398;39.054000;-5.142400;,
  83.507398;39.054000;-0.342300;,
  83.507398;47.453802;-5.142400;,
  83.507398;47.453802;-0.342300;,
  83.507398;47.453802;-5.142400;,
  69.107398;46.254003;-5.142400;,
  69.107398;47.453802;-5.142400;,
  69.107398;46.254003;-5.142400;,
  83.507398;47.453802;-5.142400;,
  83.507398;39.054000;-5.142400;,
  69.107398;46.254003;-5.142400;,
  83.507398;39.054000;-0.342300;,
  69.107398;46.254003;-0.342300;,
  83.507398;39.054000;-0.342300;,
  69.107398;46.254003;-5.142400;,
  83.507398;39.054000;-5.142400;,
  69.107398;47.453802;-0.342300;,
  69.107398;51.053798;-3.942400;,
  69.107398;48.653802;-6.342500;,
  69.107398;51.053798;-3.942400;,
  69.107398;47.453802;-0.342300;,
  69.107398;51.053798;-0.342300;,
  69.107398;47.453802;-6.342300;,
  69.107398;47.453802;-0.342300;,
  69.107398;48.653802;-6.342500;,
  83.507398;51.053798;-3.942400;,
  83.507398;47.453802;-0.342300;,
  83.507398;48.653802;-6.342500;,
  83.507398;47.453802;-0.342300;,
  83.507398;51.053798;-3.942400;,
  83.507398;51.053798;-0.342300;,
  83.507398;47.453802;-6.342300;,
  83.507398;48.653802;-6.342500;,
  83.507398;47.453802;-0.342300;,
  69.107398;48.653802;-6.342500;,
  83.507398;47.453802;-6.342300;,
  69.107398;47.453802;-6.342300;,
  83.507398;47.453802;-6.342300;,
  69.107398;48.653802;-6.342500;,
  83.507398;48.653802;-6.342500;,
  69.107398;47.453802;-6.342300;,
  83.507398;47.453802;-0.342300;,
  69.107398;47.453802;-0.342300;,
  83.507398;47.453802;-0.342300;,
  69.107398;47.453802;-6.342300;,
  83.507398;47.453802;-6.342300;,
  69.107398;51.053798;-0.342300;,
  83.507398;51.053798;-3.942400;,
  69.107398;51.053798;-3.942400;,
  83.507398;51.053798;-3.942400;,
  69.107398;51.053798;-0.342300;,
  83.507398;51.053798;-0.342300;,
  69.107398;51.053798;-3.942400;,
  83.507398;48.653802;-6.342500;,
  69.107398;48.653802;-6.342500;,
  83.507398;48.653802;-6.342500;,
  69.107398;51.053798;-3.942400;,
  83.507398;51.053798;-3.942400;,
  88.307405;37.853802;-5.142400;,
  88.307405;36.653802;-0.342300;,
  88.307405;37.853802;-0.342300;,
  88.307405;36.653802;-0.342300;,
  88.307405;37.853802;-5.142400;,
  88.307405;36.653802;-5.142400;,
  102.707398;37.853802;-5.142400;,
  102.707398;29.453802;-0.342300;,
  102.707398;29.453802;-5.142400;,
  102.707398;29.453802;-0.342300;,
  102.707398;37.853802;-5.142400;,
  102.707398;37.853802;-0.342300;,
  102.707398;37.853802;-5.142400;,
  88.307405;36.653802;-5.142400;,
  88.307405;37.853802;-5.142400;,
  88.307405;36.653802;-5.142400;,
  102.707398;37.853802;-5.142400;,
  102.707398;29.453802;-5.142400;,
  88.307405;36.653802;-5.142400;,
  102.707398;29.453802;-0.342300;,
  88.307405;36.653802;-0.342300;,
  102.707398;29.453802;-0.342300;,
  88.307405;36.653802;-5.142400;,
  102.707398;29.453802;-5.142400;,
  88.307405;37.853802;-0.342300;,
  88.307405;41.453802;-3.942400;,
  88.307405;39.053798;-6.342500;,
  88.307405;41.453802;-3.942400;,
  88.307405;37.853802;-0.342300;,
  88.307405;41.453802;-0.342300;,
  88.307405;37.853802;-6.342300;,
  88.307405;37.853802;-0.342300;,
  88.307405;39.053798;-6.342500;,
  102.707398;41.453802;-3.942400;,
  102.707398;37.853802;-0.342300;,
  102.707398;39.053798;-6.342500;,
  102.707398;37.853802;-0.342300;,
  102.707398;41.453802;-3.942400;,
  102.707398;41.453802;-0.342300;,
  102.707398;37.853802;-6.342300;,
  102.707398;39.053798;-6.342500;,
  102.707398;37.853802;-0.342300;,
  88.307405;39.053798;-6.342500;,
  102.707398;37.853802;-6.342300;,
  88.307405;37.853802;-6.342300;,
  102.707398;37.853802;-6.342300;,
  88.307405;39.053798;-6.342500;,
  102.707398;39.053798;-6.342500;,
  88.307405;37.853802;-6.342300;,
  102.707398;37.853802;-0.342300;,
  88.307405;37.853802;-0.342300;,
  102.707398;37.853802;-0.342300;,
  88.307405;37.853802;-6.342300;,
  102.707398;37.853802;-6.342300;,
  88.307405;41.453802;-0.342300;,
  102.707398;41.453802;-3.942400;,
  88.307405;41.453802;-3.942400;,
  102.707398;41.453802;-3.942400;,
  88.307405;41.453802;-0.342300;,
  102.707398;41.453802;-0.342300;,
  88.307405;41.453802;-3.942400;,
  102.707398;39.053798;-6.342500;,
  88.307405;39.053798;-6.342500;,
  102.707398;39.053798;-6.342500;,
  88.307405;41.453802;-3.942400;,
  102.707398;41.453802;-3.942400;,
  121.907405;28.253798;-5.142400;,
  121.907405;19.853701;-0.342300;,
  121.907405;19.853701;-5.142400;,
  121.907405;19.853701;-0.342300;,
  121.907405;28.253798;-5.142400;,
  121.907405;28.253798;-0.342300;,
  121.907405;28.253798;-5.142400;,
  107.507405;27.053699;-5.142400;,
  107.507405;28.253798;-5.142400;,
  107.507405;27.053699;-5.142400;,
  121.907405;28.253798;-5.142400;,
  121.907405;19.853701;-5.142400;,
  121.907405;19.853701;-5.142400;,
  107.507405;27.053699;-0.342300;,
  107.507405;27.053699;-5.142400;,
  107.507405;27.053699;-0.342300;,
  121.907405;19.853701;-5.142400;,
  121.907405;19.853701;-0.342300;,
  107.507405;28.253798;-5.142400;,
  107.507405;27.053699;-0.342300;,
  107.507405;28.253798;-0.342300;,
  107.507405;27.053699;-0.342300;,
  107.507405;28.253798;-5.142400;,
  107.507405;27.053699;-5.142400;,
  107.507405;28.253798;-0.342300;,
  107.507405;31.853798;-3.942300;,
  107.507405;29.454400;-6.342300;,
  107.507405;31.853798;-3.942300;,
  107.507405;28.253798;-0.342300;,
  107.507405;31.853798;-0.342300;,
  107.507405;28.253798;-6.342300;,
  107.507405;28.253798;-0.342300;,
  107.507405;29.454400;-6.342300;,
  121.907405;31.853798;-3.943800;,
  121.907405;28.253798;-0.342300;,
  121.907405;29.455901;-6.342300;,
  121.907405;28.253798;-0.342300;,
  121.907405;31.853798;-3.943800;,
  121.907405;31.853798;-0.342300;,
  121.907405;28.253798;-6.342300;,
  121.907405;29.455901;-6.342300;,
  121.907405;28.253798;-0.342300;,
  107.507405;29.454400;-6.342300;,
  121.907405;28.253798;-6.342300;,
  107.507405;28.253798;-6.342300;,
  121.907405;28.253798;-6.342300;,
  107.507405;29.454400;-6.342300;,
  121.907405;29.455901;-6.342300;,
  107.507405;28.253798;-6.342300;,
  121.907405;28.253798;-0.342300;,
  107.507405;28.253798;-0.342300;,
  121.907405;28.253798;-0.342300;,
  107.507405;28.253798;-6.342300;,
  121.907405;28.253798;-6.342300;,
  107.507405;31.853798;-0.342300;,
  121.907405;31.853798;-3.943800;,
  107.507405;31.853798;-3.942300;,
  121.907405;31.853798;-3.943800;,
  107.507405;31.853798;-0.342300;,
  121.907405;31.853798;-0.342300;,
  107.507405;31.853798;-3.942300;,
  121.907405;29.455901;-6.342300;,
  107.507405;29.454400;-6.342300;,
  121.907405;29.455901;-6.342300;,
  107.507405;31.853798;-3.942300;,
  121.907405;31.853798;-3.943800;,
  141.107405;18.653798;-5.142400;,
  126.707392;17.453800;-5.142400;,
  126.707392;18.653798;-5.142400;,
  126.707392;17.453800;-5.142400;,
  141.107405;18.653798;-5.142400;,
  141.107405;10.253800;-5.142400;,
  126.707392;17.453800;-5.142400;,
  141.107405;10.253800;-0.342300;,
  126.707392;17.453800;-0.342300;,
  141.107405;10.253800;-0.342300;,
  126.707392;17.453800;-5.142400;,
  141.107405;10.253800;-5.142400;,
  126.707392;18.653798;-5.142400;,
  126.707392;17.453800;-0.342300;,
  126.707392;18.653798;-0.342300;,
  126.707392;17.453800;-0.342300;,
  126.707392;18.653798;-5.142400;,
  126.707392;17.453800;-5.142400;,
  141.107405;18.653798;-5.142400;,
  141.107405;10.253800;-0.342300;,
  141.107405;10.253800;-5.142400;,
  141.107405;10.253800;-0.342300;,
  141.107405;18.653798;-5.142400;,
  141.107405;18.653798;-0.342300;,
  126.707392;18.653798;-0.342300;,
  126.707392;22.253800;-3.942400;,
  126.707392;19.853800;-6.342500;,
  126.707392;22.253800;-3.942400;,
  126.707392;18.653798;-0.342300;,
  126.707392;22.253800;-0.342300;,
  126.707392;18.653798;-6.342300;,
  126.707392;18.653798;-0.342300;,
  126.707392;19.853800;-6.342500;,
  141.107405;22.253800;-3.942400;,
  141.107405;18.653798;-0.342300;,
  141.107405;19.853800;-6.342500;,
  141.107405;18.653798;-0.342300;,
  141.107405;22.253800;-3.942400;,
  141.107405;22.253800;-0.342300;,
  141.107405;18.653798;-6.342300;,
  141.107405;19.853800;-6.342500;,
  141.107405;18.653798;-0.342300;,
  126.707392;19.853800;-6.342500;,
  141.107405;18.653798;-6.342300;,
  126.707392;18.653798;-6.342300;,
  141.107405;18.653798;-6.342300;,
  126.707392;19.853800;-6.342500;,
  141.107405;19.853800;-6.342500;,
  126.707392;18.653798;-6.342300;,
  141.107405;18.653798;-0.342300;,
  126.707392;18.653798;-0.342300;,
  141.107405;18.653798;-0.342300;,
  126.707392;18.653798;-6.342300;,
  141.107405;18.653798;-6.342300;,
  126.707392;22.253800;-0.342300;,
  141.107405;22.253800;-3.942400;,
  126.707392;22.253800;-3.942400;,
  141.107405;22.253800;-3.942400;,
  126.707392;22.253800;-0.342300;,
  141.107405;22.253800;-0.342300;,
  126.707392;22.253800;-3.942400;,
  141.107405;19.853800;-6.342500;,
  126.707392;19.853800;-6.342500;,
  141.107405;19.853800;-6.342500;,
  126.707392;22.253800;-3.942400;,
  141.107405;22.253800;-3.942400;,
  -146.892595;0.653800;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  160.307405;0.653800;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;0.653800;-5.142400;,
  -146.892595;144.653798;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;144.653798;-0.342300;,
  -127.692595;144.653798;-0.342300;,
  -146.892595;144.653798;-0.342300;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;144.653798;-5.142400;,
  160.307405;0.653800;-5.142400;,
  -127.692595;144.653798;-0.342300;,
  160.307405;0.653800;-0.342300;,
  -127.692595;144.653798;-0.342300;,
  160.307405;0.653800;-5.142400;,
  -127.692595;144.653798;-5.142400;,
  -146.892595;144.653798;-0.342300;,
  -130.092890;144.653798;30.857501;,
  -130.092890;144.653798;-0.342500;,
  -130.092890;144.653798;30.857501;,
  -146.892595;144.653798;-0.342300;,
  -146.892595;144.653798;30.857600;,
  157.907392;0.653800;-0.342300;,
  -130.092890;144.653798;30.857501;,
  157.907392;0.653800;30.857600;,
  -130.092890;144.653798;30.857501;,
  157.907392;0.653800;-0.342300;,
  -130.092890;144.653798;-0.342500;,
  -127.692595;144.653798;30.857600;,
  -146.892595;144.653798;33.257600;,
  -127.692595;144.653798;33.257600;,
  -146.892595;144.653798;33.257600;,
  -127.692595;144.653798;30.857600;,
  -146.892595;144.653798;30.857600;,
  160.307405;0.653800;30.857600;,
  -127.692595;144.653798;33.257600;,
  160.307405;0.653800;33.257600;,
  -127.692595;144.653798;33.257600;,
  160.307405;0.653800;30.857600;,
  -127.692595;144.653798;30.857600;,
  -146.892595;0.653800;30.857600;,
  -127.692595;144.653798;30.857600;,
  160.307405;0.653800;30.857600;,
  -127.692595;144.653798;30.857600;,
  -146.892595;0.653800;30.857600;,
  -146.892595;144.653798;30.857600;;
  355;
  3;0,1,2;,
  3;3,4,5;,
  3;6,7,8;,
  3;9,10,11;,
  3;12,13,14;,
  3;15,16,17;,
  3;18,19,20;,
  3;21,22,23;,
  3;24,25,26;,
  3;27,28,29;,
  3;30,31,32;,
  3;33,34,35;,
  3;36,37,38;,
  3;39,40,41;,
  3;42,43,44;,
  3;45,46,47;,
  3;48,49,50;,
  3;51,52,53;,
  3;54,55,56;,
  3;57,58,59;,
  3;60,61,62;,
  3;63,64,65;,
  3;66,67,68;,
  3;69,70,71;,
  3;72,73,74;,
  3;75,76,77;,
  3;78,79,80;,
  3;81,82,83;,
  3;84,85,86;,
  3;87,88,89;,
  3;90,91,92;,
  3;93,94,95;,
  3;96,97,98;,
  3;99,100,101;,
  3;102,103,104;,
  3;105,106,107;,
  3;108,109,110;,
  3;111,112,113;,
  3;114,115,116;,
  3;117,118,119;,
  3;120,121,122;,
  3;123,124,125;,
  3;126,127,128;,
  3;129,130,131;,
  3;132,133,134;,
  3;135,136,137;,
  3;138,139,140;,
  3;141,142,143;,
  3;144,145,146;,
  3;147,148,149;,
  3;150,151,152;,
  3;153,154,155;,
  3;156,157,158;,
  3;159,160,161;,
  3;162,163,164;,
  3;165,166,167;,
  3;168,169,170;,
  3;171,172,173;,
  3;174,175,176;,
  3;177,178,179;,
  3;180,181,182;,
  3;183,184,185;,
  3;186,187,188;,
  3;189,190,191;,
  3;192,193,194;,
  3;195,196,197;,
  3;198,199,200;,
  3;201,202,203;,
  3;204,205,206;,
  3;207,208,209;,
  3;210,211,212;,
  3;213,214,215;,
  3;216,217,218;,
  3;219,220,221;,
  3;222,223,224;,
  3;225,226,227;,
  3;228,229,230;,
  3;231,232,233;,
  3;234,235,236;,
  3;237,238,239;,
  3;240,241,242;,
  3;243,244,245;,
  3;246,247,248;,
  3;249,250,251;,
  3;252,253,254;,
  3;255,256,257;,
  3;258,259,260;,
  3;261,262,263;,
  3;264,265,266;,
  3;267,268,269;,
  3;270,271,272;,
  3;273,274,275;,
  3;276,277,278;,
  3;279,280,281;,
  3;282,283,284;,
  3;285,286,287;,
  3;288,289,290;,
  3;291,292,293;,
  3;294,295,296;,
  3;297,298,299;,
  3;300,301,302;,
  3;303,304,305;,
  3;306,307,308;,
  3;309,310,311;,
  3;312,313,314;,
  3;315,316,317;,
  3;318,319,320;,
  3;321,322,323;,
  3;324,325,326;,
  3;327,328,329;,
  3;330,331,332;,
  3;333,334,335;,
  3;336,337,338;,
  3;339,340,341;,
  3;342,343,344;,
  3;345,346,347;,
  3;348,349,350;,
  3;351,352,353;,
  3;354,355,356;,
  3;357,358,359;,
  3;360,361,362;,
  3;363,364,365;,
  3;366,367,368;,
  3;369,370,371;,
  3;372,373,374;,
  3;375,376,377;,
  3;378,379,380;,
  3;381,382,383;,
  3;384,385,386;,
  3;387,388,389;,
  3;390,391,392;,
  3;393,394,395;,
  3;396,397,398;,
  3;399,400,401;,
  3;402,403,404;,
  3;405,406,407;,
  3;408,409,410;,
  3;411,412,413;,
  3;414,415,416;,
  3;417,418,419;,
  3;420,421,422;,
  3;423,424,425;,
  3;426,427,428;,
  3;429,430,431;,
  3;432,433,434;,
  3;435,436,437;,
  3;438,439,440;,
  3;441,442,443;,
  3;444,445,446;,
  3;447,448,449;,
  3;450,451,452;,
  3;453,454,455;,
  3;456,457,458;,
  3;459,460,461;,
  3;462,463,464;,
  3;465,466,467;,
  3;468,469,470;,
  3;471,472,473;,
  3;474,475,476;,
  3;477,478,479;,
  3;480,481,482;,
  3;483,484,485;,
  3;486,487,488;,
  3;489,490,491;,
  3;492,493,494;,
  3;495,496,497;,
  3;498,499,500;,
  3;501,502,503;,
  3;504,505,506;,
  3;507,508,509;,
  3;510,511,512;,
  3;513,514,515;,
  3;516,517,518;,
  3;519,520,521;,
  3;522,523,524;,
  3;525,526,527;,
  3;528,529,530;,
  3;531,532,533;,
  3;534,535,536;,
  3;537,538,539;,
  3;540,541,542;,
  3;543,544,545;,
  3;546,547,548;,
  3;549,550,551;,
  3;552,553,554;,
  3;555,556,557;,
  3;558,559,560;,
  3;561,562,563;,
  3;564,565,566;,
  3;567,568,569;,
  3;570,571,572;,
  3;573,574,575;,
  3;576,577,578;,
  3;579,580,581;,
  3;582,583,584;,
  3;585,586,587;,
  3;588,589,590;,
  3;591,592,593;,
  3;594,595,596;,
  3;597,598,599;,
  3;600,601,602;,
  3;603,604,605;,
  3;606,607,608;,
  3;609,610,611;,
  3;612,613,614;,
  3;615,616,617;,
  3;618,619,620;,
  3;621,622,623;,
  3;624,625,626;,
  3;627,628,629;,
  3;630,631,632;,
  3;633,634,635;,
  3;636,637,638;,
  3;639,640,641;,
  3;642,643,644;,
  3;645,646,647;,
  3;648,649,650;,
  3;651,652,653;,
  3;654,655,656;,
  3;657,658,659;,
  3;660,661,662;,
  3;663,664,665;,
  3;666,667,668;,
  3;669,670,671;,
  3;672,673,674;,
  3;675,676,677;,
  3;678,679,680;,
  3;681,682,683;,
  3;684,685,686;,
  3;687,688,689;,
  3;690,691,692;,
  3;693,694,695;,
  3;696,697,698;,
  3;699,700,701;,
  3;702,703,704;,
  3;705,706,707;,
  3;708,709,710;,
  3;711,712,713;,
  3;714,715,716;,
  3;717,718,719;,
  3;720,721,722;,
  3;723,724,725;,
  3;726,727,728;,
  3;729,730,731;,
  3;732,733,734;,
  3;735,736,737;,
  3;738,739,740;,
  3;741,742,743;,
  3;744,745,746;,
  3;747,748,749;,
  3;750,751,752;,
  3;753,754,755;,
  3;756,757,758;,
  3;759,760,761;,
  3;762,763,764;,
  3;765,766,767;,
  3;768,769,770;,
  3;771,772,773;,
  3;774,775,776;,
  3;777,778,779;,
  3;780,781,782;,
  3;783,784,785;,
  3;786,787,788;,
  3;789,790,791;,
  3;792,793,794;,
  3;795,796,797;,
  3;798,799,800;,
  3;801,802,803;,
  3;804,805,806;,
  3;807,808,809;,
  3;810,811,812;,
  3;813,814,815;,
  3;816,817,818;,
  3;819,820,821;,
  3;822,823,824;,
  3;825,826,827;,
  3;828,829,830;,
  3;831,832,833;,
  3;834,835,836;,
  3;837,838,839;,
  3;840,841,842;,
  3;843,844,845;,
  3;846,847,848;,
  3;849,850,851;,
  3;852,853,854;,
  3;855,856,857;,
  3;858,859,860;,
  3;861,862,863;,
  3;864,865,866;,
  3;867,868,869;,
  3;870,871,872;,
  3;873,874,875;,
  3;876,877,878;,
  3;879,880,881;,
  3;882,883,884;,
  3;885,886,887;,
  3;888,889,890;,
  3;891,892,893;,
  3;894,895,896;,
  3;897,898,899;,
  3;900,901,902;,
  3;903,904,905;,
  3;906,907,908;,
  3;909,910,911;,
  3;912,913,914;,
  3;915,916,917;,
  3;918,919,920;,
  3;921,922,923;,
  3;924,925,926;,
  3;927,928,929;,
  3;930,931,932;,
  3;933,934,935;,
  3;936,937,938;,
  3;939,940,941;,
  3;942,943,944;,
  3;945,946,947;,
  3;948,949,950;,
  3;951,952,953;,
  3;954,955,956;,
  3;957,958,959;,
  3;960,961,962;,
  3;963,964,965;,
  3;966,967,968;,
  3;969,970,971;,
  3;972,973,974;,
  3;975,976,977;,
  3;978,979,980;,
  3;981,982,983;,
  3;984,985,986;,
  3;987,988,989;,
  3;990,991,992;,
  3;993,994,995;,
  3;996,997,998;,
  3;999,1000,1001;,
  3;1002,1003,1004;,
  3;1005,1006,1007;,
  3;1008,1009,1010;,
  3;1011,1012,1013;,
  3;1014,1015,1016;,
  3;1017,1018,1019;,
  3;1020,1021,1022;,
  3;1023,1024,1025;,
  3;1026,1027,1028;,
  3;1029,1030,1031;,
  3;1032,1033,1034;,
  3;1035,1036,1037;,
  3;1038,1039,1040;,
  3;1041,1042,1043;,
  3;1044,1045,1046;,
  3;1047,1048,1049;,
  3;1050,1051,1052;,
  3;1053,1054,1055;,
  3;1056,1057,1058;,
  3;1059,1060,1061;,
  3;1062,1063,1064;;

  MeshNormals  {
   1065;
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   0.000000;0.707007;-0.707207;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   -0.000100;0.707207;-0.707007;,
   -0.000100;0.707207;-0.707007;,
   -0.000100;0.707207;-0.707007;,
   -0.000100;0.707207;-0.707007;,
   -0.000100;0.707207;-0.707007;,
   -0.000100;0.707207;-0.707007;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -0.447214;-0.894427;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-0.000100;-1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.707107;-0.707107;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.447214;0.894427;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;;
   355;
   3;0,1,2;,
   3;3,4,5;,
   3;6,7,8;,
   3;9,10,11;,
   3;12,13,14;,
   3;15,16,17;,
   3;18,19,20;,
   3;21,22,23;,
   3;24,25,26;,
   3;27,28,29;,
   3;30,31,32;,
   3;33,34,35;,
   3;36,37,38;,
   3;39,40,41;,
   3;42,43,44;,
   3;45,46,47;,
   3;48,49,50;,
   3;51,52,53;,
   3;54,55,56;,
   3;57,58,59;,
   3;60,61,62;,
   3;63,64,65;,
   3;66,67,68;,
   3;69,70,71;,
   3;72,73,74;,
   3;75,76,77;,
   3;78,79,80;,
   3;81,82,83;,
   3;84,85,86;,
   3;87,88,89;,
   3;90,91,92;,
   3;93,94,95;,
   3;96,97,98;,
   3;99,100,101;,
   3;102,103,104;,
   3;105,106,107;,
   3;108,109,110;,
   3;111,112,113;,
   3;114,115,116;,
   3;117,118,119;,
   3;120,121,122;,
   3;123,124,125;,
   3;126,127,128;,
   3;129,130,131;,
   3;132,133,134;,
   3;135,136,137;,
   3;138,139,140;,
   3;141,142,143;,
   3;144,145,146;,
   3;147,148,149;,
   3;150,151,152;,
   3;153,154,155;,
   3;156,157,158;,
   3;159,160,161;,
   3;162,163,164;,
   3;165,166,167;,
   3;168,169,170;,
   3;171,172,173;,
   3;174,175,176;,
   3;177,178,179;,
   3;180,181,182;,
   3;183,184,185;,
   3;186,187,188;,
   3;189,190,191;,
   3;192,193,194;,
   3;195,196,197;,
   3;198,199,200;,
   3;201,202,203;,
   3;204,205,206;,
   3;207,208,209;,
   3;210,211,212;,
   3;213,214,215;,
   3;216,217,218;,
   3;219,220,221;,
   3;222,223,224;,
   3;225,226,227;,
   3;228,229,230;,
   3;231,232,233;,
   3;234,235,236;,
   3;237,238,239;,
   3;240,241,242;,
   3;243,244,245;,
   3;246,247,248;,
   3;249,250,251;,
   3;252,253,254;,
   3;255,256,257;,
   3;258,259,260;,
   3;261,262,263;,
   3;264,265,266;,
   3;267,268,269;,
   3;270,271,272;,
   3;273,274,275;,
   3;276,277,278;,
   3;279,280,281;,
   3;282,283,284;,
   3;285,286,287;,
   3;288,289,290;,
   3;291,292,293;,
   3;294,295,296;,
   3;297,298,299;,
   3;300,301,302;,
   3;303,304,305;,
   3;306,307,308;,
   3;309,310,311;,
   3;312,313,314;,
   3;315,316,317;,
   3;318,319,320;,
   3;321,322,323;,
   3;324,325,326;,
   3;327,328,329;,
   3;330,331,332;,
   3;333,334,335;,
   3;336,337,338;,
   3;339,340,341;,
   3;342,343,344;,
   3;345,346,347;,
   3;348,349,350;,
   3;351,352,353;,
   3;354,355,356;,
   3;357,358,359;,
   3;360,361,362;,
   3;363,364,365;,
   3;366,367,368;,
   3;369,370,371;,
   3;372,373,374;,
   3;375,376,377;,
   3;378,379,380;,
   3;381,382,383;,
   3;384,385,386;,
   3;387,388,389;,
   3;390,391,392;,
   3;393,394,395;,
   3;396,397,398;,
   3;399,400,401;,
   3;402,403,404;,
   3;405,406,407;,
   3;408,409,410;,
   3;411,412,413;,
   3;414,415,416;,
   3;417,418,419;,
   3;420,421,422;,
   3;423,424,425;,
   3;426,427,428;,
   3;429,430,431;,
   3;432,433,434;,
   3;435,436,437;,
   3;438,439,440;,
   3;441,442,443;,
   3;444,445,446;,
   3;447,448,449;,
   3;450,451,452;,
   3;453,454,455;,
   3;456,457,458;,
   3;459,460,461;,
   3;462,463,464;,
   3;465,466,467;,
   3;468,469,470;,
   3;471,472,473;,
   3;474,475,476;,
   3;477,478,479;,
   3;480,481,482;,
   3;483,484,485;,
   3;486,487,488;,
   3;489,490,491;,
   3;492,493,494;,
   3;495,496,497;,
   3;498,499,500;,
   3;501,502,503;,
   3;504,505,506;,
   3;507,508,509;,
   3;510,511,512;,
   3;513,514,515;,
   3;516,517,518;,
   3;519,520,521;,
   3;522,523,524;,
   3;525,526,527;,
   3;528,529,530;,
   3;531,532,533;,
   3;534,535,536;,
   3;537,538,539;,
   3;540,541,542;,
   3;543,544,545;,
   3;546,547,548;,
   3;549,550,551;,
   3;552,553,554;,
   3;555,556,557;,
   3;558,559,560;,
   3;561,562,563;,
   3;564,565,566;,
   3;567,568,569;,
   3;570,571,572;,
   3;573,574,575;,
   3;576,577,578;,
   3;579,580,581;,
   3;582,583,584;,
   3;585,586,587;,
   3;588,589,590;,
   3;591,592,593;,
   3;594,595,596;,
   3;597,598,599;,
   3;600,601,602;,
   3;603,604,605;,
   3;606,607,608;,
   3;609,610,611;,
   3;612,613,614;,
   3;615,616,617;,
   3;618,619,620;,
   3;621,622,623;,
   3;624,625,626;,
   3;627,628,629;,
   3;630,631,632;,
   3;633,634,635;,
   3;636,637,638;,
   3;639,640,641;,
   3;642,643,644;,
   3;645,646,647;,
   3;648,649,650;,
   3;651,652,653;,
   3;654,655,656;,
   3;657,658,659;,
   3;660,661,662;,
   3;663,664,665;,
   3;666,667,668;,
   3;669,670,671;,
   3;672,673,674;,
   3;675,676,677;,
   3;678,679,680;,
   3;681,682,683;,
   3;684,685,686;,
   3;687,688,689;,
   3;690,691,692;,
   3;693,694,695;,
   3;696,697,698;,
   3;699,700,701;,
   3;702,703,704;,
   3;705,706,707;,
   3;708,709,710;,
   3;711,712,713;,
   3;714,715,716;,
   3;717,718,719;,
   3;720,721,722;,
   3;723,724,725;,
   3;726,727,728;,
   3;729,730,731;,
   3;732,733,734;,
   3;735,736,737;,
   3;738,739,740;,
   3;741,742,743;,
   3;744,745,746;,
   3;747,748,749;,
   3;750,751,752;,
   3;753,754,755;,
   3;756,757,758;,
   3;759,760,761;,
   3;762,763,764;,
   3;765,766,767;,
   3;768,769,770;,
   3;771,772,773;,
   3;774,775,776;,
   3;777,778,779;,
   3;780,781,782;,
   3;783,784,785;,
   3;786,787,788;,
   3;789,790,791;,
   3;792,793,794;,
   3;795,796,797;,
   3;798,799,800;,
   3;801,802,803;,
   3;804,805,806;,
   3;807,808,809;,
   3;810,811,812;,
   3;813,814,815;,
   3;816,817,818;,
   3;819,820,821;,
   3;822,823,824;,
   3;825,826,827;,
   3;828,829,830;,
   3;831,832,833;,
   3;834,835,836;,
   3;837,838,839;,
   3;840,841,842;,
   3;843,844,845;,
   3;846,847,848;,
   3;849,850,851;,
   3;852,853,854;,
   3;855,856,857;,
   3;858,859,860;,
   3;861,862,863;,
   3;864,865,866;,
   3;867,868,869;,
   3;870,871,872;,
   3;873,874,875;,
   3;876,877,878;,
   3;879,880,881;,
   3;882,883,884;,
   3;885,886,887;,
   3;888,889,890;,
   3;891,892,893;,
   3;894,895,896;,
   3;897,898,899;,
   3;900,901,902;,
   3;903,904,905;,
   3;906,907,908;,
   3;909,910,911;,
   3;912,913,914;,
   3;915,916,917;,
   3;918,919,920;,
   3;921,922,923;,
   3;924,925,926;,
   3;927,928,929;,
   3;930,931,932;,
   3;933,934,935;,
   3;936,937,938;,
   3;939,940,941;,
   3;942,943,944;,
   3;945,946,947;,
   3;948,949,950;,
   3;951,952,953;,
   3;954,955,956;,
   3;957,958,959;,
   3;960,961,962;,
   3;963,964,965;,
   3;966,967,968;,
   3;969,970,971;,
   3;972,973,974;,
   3;975,976,977;,
   3;978,979,980;,
   3;981,982,983;,
   3;984,985,986;,
   3;987,988,989;,
   3;990,991,992;,
   3;993,994,995;,
   3;996,997,998;,
   3;999,1000,1001;,
   3;1002,1003,1004;,
   3;1005,1006,1007;,
   3;1008,1009,1010;,
   3;1011,1012,1013;,
   3;1014,1015,1016;,
   3;1017,1018,1019;,
   3;1020,1021,1022;,
   3;1023,1024,1025;,
   3;1026,1027,1028;,
   3;1029,1030,1031;,
   3;1032,1033,1034;,
   3;1035,1036,1037;,
   3;1038,1039,1040;,
   3;1041,1042,1043;,
   3;1044,1045,1046;,
   3;1047,1048,1049;,
   3;1050,1051,1052;,
   3;1053,1054,1055;,
   3;1056,1057,1058;,
   3;1059,1060,1061;,
   3;1062,1063,1064;;
  }

  MeshMaterialList  {
   3;
   355;
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   2,
   2,
   0,
   0,
   2,
   2,
   2,
   2,
   2,
   2,
   0,
   0,
   0,
   0;
   { Stair_2_mso_material_2Sub0 }
   { Stair_2_mso_material_0Sub1 }
   { Stair_2_mso_material_3Sub2 }
  }

  MeshTextureCoords  {
   1065;
   -21.562499;-2.750000;,
   -21.687501;-2.968800;,
   -21.687501;-2.750000;,
   -21.687501;-2.968800;,
   -21.562499;-2.750000;,
   -21.562499;-2.968800;,
   -1.562500;-2.750000;,
   -1.062500;-2.968800;,
   -1.562500;-2.968800;,
   -1.062500;-2.968800;,
   -1.562500;-2.750000;,
   -1.062500;-2.750000;,
   5.002000;-42.500000;,
   4.002000;-42.750000;,
   4.002000;-42.500000;,
   4.002000;-42.750000;,
   5.002000;-42.500000;,
   5.002000;-42.750000;,
   -21.593800;-2.562500;,
   -21.687501;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -21.593800;-2.562500;,
   -21.687501;-2.562500;,
   -21.531299;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -1.562500;-2.468800;,
   -1.062500;-2.500000;,
   -1.562500;-2.500000;,
   -1.062500;-2.500000;,
   -1.562500;-2.468800;,
   -1.062500;-2.468800;,
   -1.562500;22.671899;,
   -1.062500;22.515600;,
   -1.562500;22.515600;,
   -1.062500;22.515600;,
   -1.562500;22.671899;,
   -1.062500;22.671899;,
   -1.062500;-20.687501;,
   -1.562500;-20.593800;,
   -1.062500;-20.593800;,
   -1.562500;-20.593800;,
   -1.062500;-20.687501;,
   -1.562500;-20.687501;,
   -1.062500;-17.477899;,
   -1.562500;-17.566299;,
   -1.562500;-17.477899;,
   -1.562500;-17.566299;,
   -1.062500;-17.477899;,
   -1.062500;-17.566299;,
   5.252000;-42.750000;,
   6.002000;-42.500000;,
   6.002000;-42.750000;,
   6.002000;-42.500000;,
   5.252000;-42.750000;,
   5.252000;-42.500000;,
   22.437501;-2.718800;,
   22.312499;-2.687500;,
   22.437501;-2.687500;,
   22.312499;-2.687500;,
   22.437501;-2.718800;,
   22.312499;-2.718800;,
   -22.187501;-2.718800;,
   -22.062499;-2.500000;,
   -22.062499;-2.718800;,
   -22.062499;-2.500000;,
   -22.187501;-2.718800;,
   -22.187501;-2.500000;,
   -2.062500;-2.718800;,
   -1.687500;-2.687500;,
   -1.687500;-2.718800;,
   -1.687500;-2.687500;,
   -2.062500;-2.718800;,
   -2.062500;-2.500000;,
   21.937501;-2.468800;,
   21.843800;-2.562500;,
   21.781200;-2.500000;,
   21.843800;-2.562500;,
   21.937501;-2.468800;,
   21.937501;-2.562500;,
   21.781299;-2.468800;,
   21.937501;-2.468800;,
   21.781200;-2.500000;,
   -21.593800;-2.562500;,
   -21.687501;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -21.593800;-2.562500;,
   -21.687501;-2.562500;,
   -21.531299;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -2.187500;-2.500000;,
   -2.562500;-2.468800;,
   -2.187500;-2.468800;,
   -2.562500;-2.468800;,
   -2.187500;-2.500000;,
   -2.562500;-2.500000;,
   -2.187500;22.515600;,
   -2.562500;22.671899;,
   -2.187500;22.671899;,
   -2.562500;22.671899;,
   -2.187500;22.515600;,
   -2.562500;22.515600;,
   -2.187500;-20.687501;,
   -2.562500;-20.593800;,
   -2.187500;-20.593800;,
   -2.562500;-20.593800;,
   -2.187500;-20.687501;,
   -2.562500;-20.687501;,
   -2.187500;-17.567301;,
   -2.562500;-17.478901;,
   -2.187500;-17.478901;,
   -2.562500;-17.478901;,
   -2.187500;-17.567301;,
   -2.562500;-17.567301;,
   6.252000;-42.500000;,
   7.002000;-42.750000;,
   7.002000;-42.500000;,
   7.002000;-42.750000;,
   6.252000;-42.500000;,
   6.252000;-42.750000;,
   6.252000;-42.500000;,
   7.002000;-42.750000;,
   6.252000;-42.750000;,
   7.002000;-42.750000;,
   6.252000;-42.500000;,
   7.002000;-42.500000;,
   21.812499;-2.468800;,
   21.937501;-2.437500;,
   21.937501;-2.468800;,
   21.937501;-2.437500;,
   21.812499;-2.468800;,
   21.812499;-2.437500;,
   -21.562499;-2.468800;,
   -21.687501;-2.250000;,
   -21.562499;-2.250000;,
   -21.687501;-2.250000;,
   -21.562499;-2.468800;,
   -21.687501;-2.468800;,
   -2.562500;-2.468800;,
   -2.187500;-2.437500;,
   -2.187500;-2.468800;,
   -2.187500;-2.437500;,
   -2.562500;-2.468800;,
   -2.562500;-2.250000;,
   21.937501;-2.468800;,
   21.843800;-2.562500;,
   21.781299;-2.500000;,
   21.843800;-2.562500;,
   21.937501;-2.468800;,
   21.937501;-2.562500;,
   21.781299;-2.468800;,
   21.937501;-2.468800;,
   21.781299;-2.500000;,
   -21.593800;-2.562500;,
   -21.687501;-2.468800;,
   -21.531299;-2.500000;,
   -21.687501;-2.468800;,
   -21.593800;-2.562500;,
   -21.687501;-2.562500;,
   -21.531299;-2.468800;,
   -21.531299;-2.500000;,
   -21.687501;-2.468800;,
   -2.187500;-2.500000;,
   -2.562500;-2.468800;,
   -2.187500;-2.468800;,
   -2.562500;-2.468800;,
   -2.187500;-2.500000;,
   -2.562500;-2.500000;,
   -2.187500;22.515600;,
   -2.562500;22.671899;,
   -2.187500;22.671899;,
   -2.562500;22.671899;,
   -2.187500;22.515600;,
   -2.562500;22.515600;,
   -2.187500;-20.687501;,
   -2.562500;-20.593800;,
   -2.187500;-20.593800;,
   -2.562500;-20.593800;,
   -2.187500;-20.687501;,
   -2.562500;-20.687501;,
   -2.187500;-16.566299;,
   -2.562500;-16.477899;,
   -2.187500;-16.477899;,
   -2.562500;-16.477899;,
   -2.187500;-16.566299;,
   -2.562500;-16.566299;,
   7.252000;-42.500000;,
   8.002000;-42.750000;,
   8.002000;-42.500000;,
   8.002000;-42.750000;,
   7.252000;-42.500000;,
   7.252000;-42.750000;,
   7.252000;-42.500000;,
   8.002000;-42.750000;,
   7.252000;-42.750000;,
   8.002000;-42.750000;,
   7.252000;-42.500000;,
   8.002000;-42.500000;,
   22.312499;-2.218800;,
   22.437501;-2.187500;,
   22.437501;-2.218800;,
   22.437501;-2.187500;,
   22.312499;-2.218800;,
   22.312499;-2.187500;,
   -22.062499;-2.218800;,
   -22.187501;-2.000000;,
   -22.062499;-2.000000;,
   -22.187501;-2.000000;,
   -22.062499;-2.218800;,
   -22.187501;-2.218800;,
   -3.062500;-2.218800;,
   -2.687500;-2.187500;,
   -2.687500;-2.218800;,
   -2.687500;-2.187500;,
   -3.062500;-2.218800;,
   -3.062500;-2.000000;,
   21.937501;-2.468800;,
   21.843701;-2.562500;,
   21.781200;-2.500000;,
   21.843701;-2.562500;,
   21.937501;-2.468800;,
   21.937501;-2.562500;,
   21.781299;-2.468800;,
   21.937501;-2.468800;,
   21.781200;-2.500000;,
   -21.593701;-2.562500;,
   -21.687501;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -21.593701;-2.562500;,
   -21.687501;-2.562500;,
   -21.531299;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -3.187500;-2.500000;,
   -3.562500;-2.468800;,
   -3.187500;-2.468800;,
   -3.562500;-2.468800;,
   -3.187500;-2.500000;,
   -3.562500;-2.500000;,
   -3.187500;22.515600;,
   -3.562500;22.671899;,
   -3.187500;22.671899;,
   -3.562500;22.671899;,
   -3.187500;22.515600;,
   -3.562500;22.515600;,
   -3.187500;-20.687501;,
   -3.562500;-20.593701;,
   -3.187500;-20.593701;,
   -3.562500;-20.593701;,
   -3.187500;-20.687501;,
   -3.562500;-20.687501;,
   -3.187500;-16.567200;,
   -3.562500;-16.478800;,
   -3.187500;-16.478800;,
   -3.562500;-16.478800;,
   -3.187500;-16.567200;,
   -3.562500;-16.567200;,
   21.812499;-2.468800;,
   21.937501;-2.437500;,
   21.937501;-2.468800;,
   21.937501;-2.437500;,
   21.812499;-2.468800;,
   21.812499;-2.437500;,
   -21.562499;-2.468800;,
   -21.687501;-2.250000;,
   -21.562499;-2.250000;,
   -21.687501;-2.250000;,
   -21.562499;-2.468800;,
   -21.687501;-2.468800;,
   -3.562500;-2.468800;,
   -3.187500;-2.437500;,
   -3.187500;-2.468800;,
   -3.187500;-2.437500;,
   -3.562500;-2.468800;,
   -3.562500;-2.250000;,
   8.252000;-42.500000;,
   9.002000;-42.750000;,
   8.252000;-42.750000;,
   9.002000;-42.750000;,
   8.252000;-42.500000;,
   9.002000;-42.500000;,
   21.937501;-2.468800;,
   21.843701;-2.562500;,
   21.781200;-2.500000;,
   21.843701;-2.562500;,
   21.937501;-2.468800;,
   21.937501;-2.562500;,
   21.781299;-2.468800;,
   21.937501;-2.468800;,
   21.781200;-2.500000;,
   -21.593701;-2.562500;,
   -21.687501;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -21.593701;-2.562500;,
   -21.687501;-2.562500;,
   -21.531299;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -3.187500;-2.500000;,
   -3.562500;-2.468800;,
   -3.187500;-2.468800;,
   -3.562500;-2.468800;,
   -3.187500;-2.500000;,
   -3.562500;-2.500000;,
   -3.187500;22.515600;,
   -3.562500;22.671899;,
   -3.187500;22.671899;,
   -3.562500;22.671899;,
   -3.187500;22.515600;,
   -3.562500;22.515600;,
   -3.187500;-20.687501;,
   -3.562500;-20.593701;,
   -3.187500;-20.593701;,
   -3.562500;-20.593701;,
   -3.187500;-20.687501;,
   -3.562500;-20.687501;,
   -3.187500;-16.566200;,
   -3.562500;-16.477800;,
   -3.187500;-16.477800;,
   -3.562500;-16.477800;,
   -3.187500;-16.566200;,
   -3.562500;-16.566200;,
   22.312499;-1.718800;,
   22.437501;-1.687500;,
   22.437501;-1.718800;,
   22.437501;-1.687500;,
   22.312499;-1.718800;,
   22.312499;-1.687500;,
   -22.062499;-1.718800;,
   -22.187501;-1.500000;,
   -22.062499;-1.500000;,
   -22.187501;-1.500000;,
   -22.062499;-1.718800;,
   -22.187501;-1.718800;,
   -4.062500;-1.718800;,
   -3.687500;-1.687500;,
   -3.687500;-1.718800;,
   -3.687500;-1.687500;,
   -4.062500;-1.718800;,
   -4.062500;-1.500000;,
   9.252000;-42.500000;,
   10.002000;-42.750000;,
   10.002000;-42.500000;,
   10.002000;-42.750000;,
   9.252000;-42.500000;,
   9.252000;-42.750000;,
   9.252000;-42.500000;,
   10.002000;-42.750000;,
   9.252000;-42.750000;,
   10.002000;-42.750000;,
   9.252000;-42.500000;,
   10.002000;-42.500000;,
   -21.593800;-2.562500;,
   -21.687501;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -21.593800;-2.562500;,
   -21.687501;-2.562500;,
   -21.531299;-2.468800;,
   -21.531200;-2.500000;,
   -21.687501;-2.468800;,
   -4.562500;-2.500000;,
   -4.187500;-2.468800;,
   -4.187500;-2.500000;,
   -4.187500;-2.468800;,
   -4.562500;-2.500000;,
   -4.562500;-2.468800;,
   -4.187500;22.671899;,
   -4.562500;22.515600;,
   -4.562500;22.671899;,
   -4.562500;22.515600;,
   -4.187500;22.671899;,
   -4.187500;22.515600;,
   -4.562500;-20.687501;,
   -4.187500;-20.593800;,
   -4.187500;-20.687501;,
   -4.187500;-20.593800;,
   -4.562500;-20.687501;,
   -4.562500;-20.593800;,
   -4.562500;-16.478800;,
   -4.187500;-16.567200;,
   -4.562500;-16.567200;,
   -4.187500;-16.567200;,
   -4.562500;-16.478800;,
   -4.187500;-16.478800;,
   21.843800;-2.562500;,
   21.781299;-2.468800;,
   21.937501;-2.562500;,
   21.781299;-2.468800;,
   21.843800;-2.562500;,
   21.781200;-2.500000;,
   21.781299;-2.468800;,
   21.937501;-2.468800;,
   21.937501;-2.562500;,
   21.812499;-1.468800;,
   21.937501;-1.437500;,
   21.937501;-1.468800;,
   21.937501;-1.437500;,
   21.812499;-1.468800;,
   21.812499;-1.437500;,
   -21.562499;-1.468800;,
   -21.687501;-1.250000;,
   -21.562499;-1.250000;,
   -21.687501;-1.250000;,
   -21.562499;-1.468800;,
   -21.687501;-1.468800;,
   -4.562500;-1.468800;,
   -4.187500;-1.437500;,
   -4.187500;-1.468800;,
   -4.187500;-1.437500;,
   -4.562500;-1.468800;,
   -4.562500;-1.250000;,
   10.252000;-42.500000;,
   11.002000;-42.750000;,
   11.002000;-42.500000;,
   11.002000;-42.750000;,
   10.252000;-42.500000;,
   10.252000;-42.750000;,
   10.252000;-42.500000;,
   11.002000;-42.750000;,
   10.252000;-42.750000;,
   11.002000;-42.750000;,
   10.252000;-42.500000;,
   11.002000;-42.500000;,
   -4.187500;22.671899;,
   -4.562500;22.515600;,
   -4.562500;22.671899;,
   -4.562500;22.515600;,
   -4.187500;22.671899;,
   -4.187500;22.515600;,
   -4.187500;-20.687501;,
   -4.562500;-20.593800;,
   -4.187500;-20.593800;,
   -4.562500;-20.593800;,
   -4.187500;-20.687501;,
   -4.562500;-20.687501;,
   -4.187500;-16.566200;,
   -4.562500;-16.477800;,
   -4.187500;-16.477800;,
   -4.562500;-16.477800;,
   -4.187500;-16.566200;,
   -4.562500;-16.566200;,
   21.843800;-1.562500;,
   21.781299;-1.468800;,
   21.937501;-1.562500;,
   21.781299;-1.468800;,
   21.843800;-1.562500;,
   21.781299;-1.500000;,
   21.937501;-1.468800;,
   21.937501;-1.562500;,
   21.781299;-1.468800;,
   -21.531299;-1.468800;,
   -21.593800;-1.562500;,
   -21.687501;-1.562500;,
   -21.593800;-1.562500;,
   -21.531299;-1.468800;,
   -21.531299;-1.500000;,
   -21.687501;-1.468800;,
   -21.531299;-1.468800;,
   -21.687501;-1.562500;,
   -4.187500;-1.500000;,
   -4.562500;-1.468800;,
   -4.187500;-1.468800;,
   -4.562500;-1.468800;,
   -4.187500;-1.500000;,
   -4.562500;-1.500000;,
   22.312499;-1.218800;,
   22.437501;-1.187500;,
   22.437501;-1.218800;,
   22.437501;-1.187500;,
   22.312499;-1.218800;,
   22.312499;-1.187500;,
   -22.062499;-1.218800;,
   -22.187501;-1.000000;,
   -22.062499;-1.000000;,
   -22.187501;-1.000000;,
   -22.062499;-1.218800;,
   -22.187501;-1.218800;,
   -5.062500;-1.218800;,
   -4.687500;-1.187500;,
   -4.687500;-1.218800;,
   -4.687500;-1.187500;,
   -5.062500;-1.218800;,
   -5.062500;-1.000000;,
   11.252000;-42.500000;,
   12.002000;-42.750000;,
   12.002000;-42.500000;,
   12.002000;-42.750000;,
   11.252000;-42.500000;,
   11.252000;-42.750000;,
   11.252000;-42.500000;,
   12.002000;-42.750000;,
   11.252000;-42.750000;,
   12.002000;-42.750000;,
   11.252000;-42.500000;,
   12.002000;-42.500000;,
   -5.187500;22.515600;,
   -5.562500;22.671899;,
   -5.187500;22.671899;,
   -5.562500;22.671899;,
   -5.187500;22.515600;,
   -5.562500;22.515600;,
   -5.187500;-20.593800;,
   -5.562500;-20.687501;,
   -5.562500;-20.593800;,
   -5.562500;-20.687501;,
   -5.187500;-20.593800;,
   -5.187500;-20.687501;,
   -5.187500;-16.567200;,
   -5.562500;-16.478800;,
   -5.187500;-16.478800;,
   -5.562500;-16.478800;,
   -5.187500;-16.567200;,
   -5.562500;-16.567200;,
   21.937501;-1.468800;,
   21.843800;-1.562500;,
   21.781200;-1.500000;,
   21.843800;-1.562500;,
   21.937501;-1.468800;,
   21.937501;-1.562500;,
   21.781299;-1.468800;,
   21.937501;-1.468800;,
   21.781200;-1.500000;,
   -21.687501;-1.468800;,
   -21.593800;-1.562500;,
   -21.687501;-1.562500;,
   -21.593800;-1.562500;,
   -21.687501;-1.468800;,
   -21.531200;-1.500000;,
   -21.531299;-1.468800;,
   -21.531200;-1.500000;,
   -21.687501;-1.468800;,
   -5.187500;-1.500000;,
   -5.562500;-1.468800;,
   -5.187500;-1.468800;,
   -5.562500;-1.468800;,
   -5.187500;-1.500000;,
   -5.562500;-1.500000;,
   21.812499;-0.968800;,
   21.937501;-0.937500;,
   21.937501;-0.968800;,
   21.937501;-0.937500;,
   21.812499;-0.968800;,
   21.812499;-0.937500;,
   -21.562499;-0.968800;,
   -21.687501;-0.750000;,
   -21.562499;-0.750000;,
   -21.687501;-0.750000;,
   -21.562499;-0.968800;,
   -21.687501;-0.968800;,
   -5.562500;-0.968800;,
   -5.187500;-0.937500;,
   -5.187500;-0.968800;,
   -5.187500;-0.937500;,
   -5.562500;-0.968800;,
   -5.562500;-0.750000;,
   12.252000;-42.500000;,
   13.002000;-42.750000;,
   13.002000;-42.500000;,
   13.002000;-42.750000;,
   12.252000;-42.500000;,
   12.252000;-42.750000;,
   12.252000;-42.500000;,
   13.002000;-42.750000;,
   12.252000;-42.750000;,
   13.002000;-42.750000;,
   12.252000;-42.500000;,
   13.002000;-42.500000;,
   -5.187500;-20.593800;,
   -5.562500;-20.687501;,
   -5.562500;-20.593800;,
   -5.562500;-20.687501;,
   -5.187500;-20.593800;,
   -5.187500;-20.687501;,
   -5.187500;-16.566200;,
   -5.562500;-16.477800;,
   -5.187500;-16.477800;,
   -5.562500;-16.477800;,
   -5.187500;-16.566200;,
   -5.562500;-16.566200;,
   21.843800;-1.562500;,
   21.937501;-1.468800;,
   21.937501;-1.562500;,
   21.937501;-1.468800;,
   21.843800;-1.562500;,
   21.781299;-1.468800;,
   21.843800;-1.562500;,
   21.781200;-1.500000;,
   21.781299;-1.468800;,
   -21.687501;-1.468800;,
   -21.531200;-1.500000;,
   -21.687501;-1.562500;,
   -21.531200;-1.500000;,
   -21.687501;-1.468800;,
   -21.531299;-1.468800;,
   -21.593800;-1.562500;,
   -21.687501;-1.562500;,
   -21.531200;-1.500000;,
   -5.187500;-1.500000;,
   -5.562500;-1.468800;,
   -5.187500;-1.468800;,
   -5.562500;-1.468800;,
   -5.187500;-1.500000;,
   -5.562500;-1.500000;,
   -5.562500;22.515600;,
   -5.187500;22.671899;,
   -5.187500;22.515600;,
   -5.187500;22.671899;,
   -5.562500;22.515600;,
   -5.562500;22.671899;,
   22.312499;-0.718800;,
   22.437501;-0.687500;,
   22.437501;-0.718800;,
   22.437501;-0.687500;,
   22.312499;-0.718800;,
   22.312499;-0.687500;,
   -22.062499;-0.718800;,
   -22.187501;-0.500000;,
   -22.062499;-0.500000;,
   -22.187501;-0.500000;,
   -22.062499;-0.718800;,
   -22.187501;-0.718800;,
   -6.062500;-0.718800;,
   -5.687500;-0.687500;,
   -5.687500;-0.718800;,
   -5.687500;-0.687500;,
   -6.062500;-0.718800;,
   -6.062500;-0.500000;,
   13.252000;-42.500000;,
   14.002000;-42.750000;,
   14.002000;-42.500000;,
   14.002000;-42.750000;,
   13.252000;-42.500000;,
   13.252000;-42.750000;,
   13.252000;-42.500000;,
   14.002000;-42.750000;,
   13.252000;-42.750000;,
   14.002000;-42.750000;,
   13.252000;-42.500000;,
   14.002000;-42.500000;,
   -6.187500;-16.478701;,
   -6.562500;-16.567101;,
   -6.562500;-16.478701;,
   -6.562500;-16.567101;,
   -6.187500;-16.478701;,
   -6.187500;-16.567101;,
   21.937501;-1.468800;,
   21.843800;-1.562500;,
   21.781299;-1.500000;,
   21.843800;-1.562500;,
   21.937501;-1.468800;,
   21.937501;-1.562500;,
   21.781299;-1.500000;,
   21.781299;-1.468800;,
   21.937501;-1.468800;,
   -21.687501;-1.468800;,
   -21.531299;-1.500000;,
   -21.687501;-1.562500;,
   -21.531299;-1.500000;,
   -21.687501;-1.468800;,
   -21.531299;-1.468800;,
   -21.531299;-1.500000;,
   -21.593800;-1.562500;,
   -21.687501;-1.562500;,
   -6.187500;-1.500000;,
   -6.562500;-1.468800;,
   -6.187500;-1.468800;,
   -6.562500;-1.468800;,
   -6.187500;-1.500000;,
   -6.562500;-1.500000;,
   -6.187500;22.515600;,
   -6.562500;22.671899;,
   -6.187500;22.671899;,
   -6.562500;22.671899;,
   -6.187500;22.515600;,
   -6.562500;22.515600;,
   -6.187500;-20.687501;,
   -6.562500;-20.593800;,
   -6.187500;-20.593800;,
   -6.562500;-20.593800;,
   -6.187500;-20.687501;,
   -6.562500;-20.687501;,
   21.812499;-0.468800;,
   21.937501;-0.437500;,
   21.937501;-0.468800;,
   21.937501;-0.437500;,
   21.812499;-0.468800;,
   21.812499;-0.437500;,
   -21.562499;-0.468800;,
   -21.687501;-0.250000;,
   -21.562499;-0.250000;,
   -21.687501;-0.250000;,
   -21.562499;-0.468800;,
   -21.687501;-0.468800;,
   -6.562500;-0.468800;,
   -6.187500;-0.437500;,
   -6.187500;-0.468800;,
   -6.187500;-0.437500;,
   -6.562500;-0.468800;,
   -6.562500;-0.250000;,
   14.252000;-42.500000;,
   15.002000;-42.750000;,
   14.252000;-42.750000;,
   15.002000;-42.750000;,
   14.252000;-42.500000;,
   15.002000;-42.500000;,
   21.937501;-0.468800;,
   21.843701;-0.562500;,
   21.781200;-0.500000;,
   21.843701;-0.562500;,
   21.937501;-0.468800;,
   21.937501;-0.562500;,
   21.781299;-0.468800;,
   21.937501;-0.468800;,
   21.781200;-0.500000;,
   -21.593701;-0.562500;,
   -21.687501;-0.468800;,
   -21.531200;-0.500000;,
   -21.687501;-0.468800;,
   -21.593701;-0.562500;,
   -21.687501;-0.562500;,
   -21.531299;-0.468800;,
   -21.531200;-0.500000;,
   -21.687501;-0.468800;,
   -6.187500;-0.500000;,
   -6.562500;-0.468800;,
   -6.187500;-0.468800;,
   -6.562500;-0.468800;,
   -6.187500;-0.500000;,
   -6.562500;-0.500000;,
   -6.187500;22.515600;,
   -6.562500;22.671899;,
   -6.187500;22.671899;,
   -6.562500;22.671899;,
   -6.187500;22.515600;,
   -6.562500;22.515600;,
   -6.187500;-20.687501;,
   -6.562500;-20.593701;,
   -6.187500;-20.593701;,
   -6.562500;-20.593701;,
   -6.187500;-20.687501;,
   -6.562500;-20.687501;,
   -6.187500;-15.566099;,
   -6.562500;-15.477699;,
   -6.187500;-15.477699;,
   -6.562500;-15.477699;,
   -6.187500;-15.566099;,
   -6.562500;-15.566099;,
   22.312499;-0.218800;,
   22.437501;-0.187500;,
   22.437501;-0.218800;,
   22.437501;-0.187500;,
   22.312499;-0.218800;,
   22.312499;-0.187500;,
   -22.062499;-0.218800;,
   -22.187501;0.000000;,
   -22.062499;0.000000;,
   -22.187501;0.000000;,
   -22.062499;-0.218800;,
   -22.187501;-0.218800;,
   -7.062500;-0.218800;,
   -6.687500;-0.187500;,
   -6.687500;-0.218800;,
   -6.687500;-0.187500;,
   -7.062500;-0.218800;,
   -7.062500;0.000000;,
   15.252000;-42.500000;,
   16.002002;-42.750000;,
   15.252000;-42.750000;,
   16.002002;-42.750000;,
   15.252000;-42.500000;,
   16.002002;-42.500000;,
   21.937501;-0.468800;,
   21.843800;-0.562500;,
   21.781200;-0.500000;,
   21.843800;-0.562500;,
   21.937501;-0.468800;,
   21.937501;-0.562500;,
   21.781299;-0.468800;,
   21.937501;-0.468800;,
   21.781200;-0.500000;,
   -21.593800;-0.562500;,
   -21.687501;-0.468800;,
   -21.531200;-0.500000;,
   -21.687501;-0.468800;,
   -21.593800;-0.562500;,
   -21.687501;-0.562500;,
   -21.531299;-0.468800;,
   -21.531200;-0.500000;,
   -21.687501;-0.468800;,
   -7.187500;-0.500000;,
   -7.562500;-0.468800;,
   -7.187500;-0.468800;,
   -7.562500;-0.468800;,
   -7.187500;-0.500000;,
   -7.562500;-0.500000;,
   -7.187500;22.515600;,
   -7.562500;22.671899;,
   -7.187500;22.671899;,
   -7.562500;22.671899;,
   -7.187500;22.515600;,
   -7.562500;22.515600;,
   -7.187500;-20.687501;,
   -7.562500;-20.593800;,
   -7.187500;-20.593800;,
   -7.562500;-20.593800;,
   -7.187500;-20.687501;,
   -7.562500;-20.687501;,
   -7.187500;-15.567101;,
   -7.562500;-15.478701;,
   -7.187500;-15.478701;,
   -7.562500;-15.478701;,
   -7.187500;-15.567101;,
   -7.562500;-15.567101;,
   21.812499;0.031200;,
   21.937501;0.062500;,
   21.937501;0.031200;,
   21.937501;0.062500;,
   21.812499;0.031200;,
   21.812499;0.062500;,
   -21.562499;0.031200;,
   -21.687501;0.250000;,
   -21.562499;0.250000;,
   -21.687501;0.250000;,
   -21.562499;0.031200;,
   -21.687501;0.031200;,
   -7.562500;0.031200;,
   -7.187500;0.062500;,
   -7.187500;0.031200;,
   -7.187500;0.062500;,
   -7.562500;0.031200;,
   -7.562500;0.250000;,
   16.252002;-42.500000;,
   17.002002;-42.750000;,
   16.252002;-42.750000;,
   17.002002;-42.750000;,
   16.252002;-42.500000;,
   17.002002;-42.500000;,
   21.937501;-0.468800;,
   21.843800;-0.562500;,
   21.781200;-0.500000;,
   21.843800;-0.562500;,
   21.937501;-0.468800;,
   21.937501;-0.562500;,
   21.781299;-0.468800;,
   21.937501;-0.468800;,
   21.781200;-0.500000;,
   -21.593800;-0.562500;,
   -21.687501;-0.468800;,
   -21.531200;-0.500000;,
   -21.687501;-0.468800;,
   -21.593800;-0.562500;,
   -21.687501;-0.562500;,
   -21.531299;-0.468800;,
   -21.531200;-0.500000;,
   -21.687501;-0.468800;,
   -7.187500;-0.500000;,
   -7.562500;-0.468800;,
   -7.187500;-0.468800;,
   -7.562500;-0.468800;,
   -7.187500;-0.500000;,
   -7.562500;-0.500000;,
   -7.187500;22.515600;,
   -7.562500;22.671899;,
   -7.187500;22.671899;,
   -7.562500;22.671899;,
   -7.187500;22.515600;,
   -7.562500;22.515600;,
   -7.187500;-20.687501;,
   -7.562500;-20.593800;,
   -7.187500;-20.593800;,
   -7.562500;-20.593800;,
   -7.187500;-20.687501;,
   -7.562500;-20.687501;,
   -7.187500;-15.566099;,
   -7.562500;-15.477699;,
   -7.187500;-15.477699;,
   -7.562500;-15.477699;,
   -7.187500;-15.566099;,
   -7.562500;-15.566099;,
   -22.062499;0.281200;,
   -22.187501;0.500000;,
   -22.062499;0.500000;,
   -22.187501;0.500000;,
   -22.062499;0.281200;,
   -22.187501;0.281200;,
   -8.062500;0.281200;,
   -7.687500;0.312500;,
   -7.687500;0.281200;,
   -7.687500;0.312500;,
   -8.062500;0.281200;,
   -8.062500;0.500000;,
   18.002002;-42.500000;,
   17.252002;-42.750000;,
   17.252002;-42.500000;,
   17.252002;-42.750000;,
   18.002002;-42.500000;,
   18.002002;-42.750000;,
   22.312499;0.281200;,
   22.437501;0.312500;,
   22.437501;0.281200;,
   22.437501;0.312500;,
   22.312499;0.281200;,
   22.312499;0.312500;,
   21.937501;-0.468800;,
   21.843800;-0.562500;,
   21.781299;-0.500000;,
   21.843800;-0.562500;,
   21.937501;-0.468800;,
   21.937501;-0.562500;,
   21.781299;-0.468800;,
   21.937501;-0.468800;,
   21.781299;-0.500000;,
   -21.593701;-0.562500;,
   -21.687501;-0.468800;,
   -21.531299;-0.500100;,
   -21.687501;-0.468800;,
   -21.593701;-0.562500;,
   -21.687501;-0.562500;,
   -21.531299;-0.468800;,
   -21.531299;-0.500100;,
   -21.687501;-0.468800;,
   -8.187500;-0.500000;,
   -8.562500;-0.468800;,
   -8.187500;-0.468800;,
   -8.562500;-0.468800;,
   -8.187500;-0.500000;,
   -8.562500;-0.500100;,
   -8.187500;22.515600;,
   -8.562500;22.671899;,
   -8.187500;22.671899;,
   -8.562500;22.671899;,
   -8.187500;22.515600;,
   -8.562500;22.515600;,
   -8.187500;-20.687501;,
   -8.562500;-20.593701;,
   -8.187500;-20.593800;,
   -8.562500;-20.593701;,
   -8.187500;-20.687501;,
   -8.562500;-20.687501;,
   -8.187500;-15.567000;,
   -8.562500;-15.478701;,
   -8.187500;-15.478701;,
   -8.562500;-15.478701;,
   -8.187500;-15.567000;,
   -8.562500;-15.567000;,
   -8.562500;0.531200;,
   -8.187500;0.562500;,
   -8.187500;0.531200;,
   -8.187500;0.562500;,
   -8.562500;0.531200;,
   -8.562500;0.750000;,
   18.252002;-42.500000;,
   19.002002;-42.750000;,
   18.252002;-42.750000;,
   19.002002;-42.750000;,
   18.252002;-42.500000;,
   19.002002;-42.500000;,
   21.812499;0.531200;,
   21.937501;0.562500;,
   21.937501;0.531200;,
   21.937501;0.562500;,
   21.812499;0.531200;,
   21.812499;0.562500;,
   -21.562499;0.531200;,
   -21.687501;0.750000;,
   -21.562499;0.750000;,
   -21.687501;0.750000;,
   -21.562499;0.531200;,
   -21.687501;0.531200;,
   21.937501;0.531200;,
   21.843701;0.437500;,
   21.781200;0.500000;,
   21.843701;0.437500;,
   21.937501;0.531200;,
   21.937501;0.437500;,
   21.781299;0.531200;,
   21.937501;0.531200;,
   21.781200;0.500000;,
   -21.593701;0.437500;,
   -21.687501;0.531200;,
   -21.531200;0.500000;,
   -21.687501;0.531200;,
   -21.593701;0.437500;,
   -21.687501;0.437500;,
   -21.531299;0.531200;,
   -21.531200;0.500000;,
   -21.687501;0.531200;,
   -8.187500;0.500000;,
   -8.562500;0.531200;,
   -8.187500;0.531200;,
   -8.562500;0.531200;,
   -8.187500;0.500000;,
   -8.562500;0.500000;,
   -8.187500;22.515600;,
   -8.562500;22.671899;,
   -8.187500;22.671899;,
   -8.562500;22.671899;,
   -8.187500;22.515600;,
   -8.562500;22.515600;,
   -8.187500;-20.687501;,
   -8.562500;-20.593701;,
   -8.187500;-20.593701;,
   -8.562500;-20.593701;,
   -8.187500;-20.687501;,
   -8.562500;-20.687501;,
   -8.187500;-15.566000;,
   -8.562500;-15.477699;,
   -8.187500;-15.477699;,
   -8.562500;-15.477699;,
   -8.187500;-15.566000;,
   -8.562500;-15.566000;,
   -1.062500;1.000000;,
   -1.562500;-2.750000;,
   -9.062500;1.000000;,
   -1.562500;-2.750000;,
   -1.062500;1.000000;,
   -1.062500;-2.750000;,
   43.388698;-3.117200;,
   43.638698;-2.117200;,
   43.638698;-3.117200;,
   43.638698;-2.117200;,
   43.388698;-3.117200;,
   43.388698;-2.117200;,
   43.312499;-16.388501;,
   43.562499;0.382000;,
   43.562499;-16.388501;,
   43.562499;0.382000;,
   43.312499;-16.388501;,
   43.312499;0.382000;,
   43.638698;-2.117200;,
   45.263699;-2.992200;,
   43.638698;-2.992200;,
   45.263699;-2.992200;,
   43.638698;-2.117200;,
   45.263699;-2.117200;,
   43.638698;-16.776699;,
   45.263699;-0.006200;,
   45.263699;-16.776699;,
   45.263699;-0.006200;,
   43.638698;-16.776699;,
   43.638698;-0.006200;,
   45.263699;-3.117200;,
   45.388698;-2.117200;,
   45.388698;-3.117200;,
   45.388698;-2.117200;,
   45.263699;-3.117200;,
   45.263699;-2.117200;,
   45.187501;-16.388501;,
   45.312499;0.382000;,
   45.312499;-16.388501;,
   45.312499;0.382000;,
   45.187501;-16.388501;,
   45.187501;0.382000;,
   3.312500;1.500000;,
   4.312500;-6.000000;,
   19.312499;1.500000;,
   4.312500;-6.000000;,
   3.312500;1.500000;,
   3.312500;-6.000000;;
  }
 }
}