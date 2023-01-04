#version 120

#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform mat4 mvp_matrix;
uniform sampler3D p1;
uniform sampler3D p2;
uniform sampler3D p3;
uniform sampler3D p4;
uniform sampler3D v1;
uniform sampler3D v2;
uniform sampler3D v3;
uniform sampler3D v4;

uniform int xsize;
uniform int ysize;
uniform int zsize;

uniform float timer;

uniform float lv;
uniform float lh;

attribute vec4 a_position;
attribute vec4 a_normals;
attribute vec4 a_texcoord;

attribute vec4 a_position2;
attribute vec4 a_normals2;
attribute vec4 a_texcoord2;


varying vec4 v_texcoord;
varying vec3 v_normal;

//! [0]
void main()
{
// calculate index
   // gl_TexCoord[0] = gl_MultiTexCoord0;

    gl_Position = mvp_matrix * vec4(a_position.xyz, 1.0);//mix(a_position,a_position2,lh);//vec4(a_position.xyz, 1.0);

       //   gl_Position = mvp_matrix * vec4(bah.xyz,1f); // vec4(a_position.xyz,1f);//

//mix(vert1,vert2,lh);

    v_texcoord = a_texcoord;//.xy;
}
//! [0]
