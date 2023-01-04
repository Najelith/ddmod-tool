#version 120
#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform sampler2D texture;
uniform sampler2D diffusetx;
uniform sampler2D speculartx;
uniform sampler2D lighttx;
uniform sampler2D normaltx;
uniform sampler3D poss;
uniform sampler3D poxx;
uniform float clr;
uniform float clg;
uniform float clb;

uniform float mousex;
uniform float mousey;

uniform float timer;
uniform int selsize;
uniform int selected_mesh_part[100];
uniform float lh;

uniform float cmr;
uniform float cmg;
uniform float cmb;


//values used for shading algorithm...
uniform vec2 Resolution;      //resolution of screen
uniform vec3 LightPos;        //light position, normalized
uniform vec4 LightColor;      //light RGBA -- alpha is intensity
uniform vec4 AmbientColor;    //ambient RGBA -- alpha is intensity
uniform vec3 Falloff;         //attenuation coefficients

varying vec4 v_texcoord;
varying vec4 v_normal;


//! [0]
void main()
{

    // calc vol mag
   //float mag =  v_texcoord.x * v_texcoord.x + v_texcoord.y * v_texcoord.y + v_texcoord.z * v_texcoord.z;

    // Set fragment color from texture
    //gl_FragColor = vec4(mix(vec3(clr,clg,clb),vec3(cmr,cmg,cmb),mag/float(600*600+600*600+600*600)),1f);

   vec4 bah = texture2D(diffusetx,v_texcoord.st);//gl_TexCoord[0].st);//vec4(1,1,1,1);
   if (bah.g <= 0.08 && bah.r <= 0.08 && bah.b <= 0.08){
  //  bah.a = 0.0;
   }
/* //old
   // Phong shading
   vec3 LightDir = normalize(vec3(0.0,0.0,1.0));
   vec3 Norm = normalize(texture2D(normaltx, v_texcoord.st).xyzw * 2.0 - 1.0);

   vec3 ViewDir = normalize(vec3(0.0,0.0,-1.0));
   vec3 ReflectDir = reflect(-LightDir,Norm);
   float specularContribution = pow(max(dot(ViewDir, ReflectDir), 0.0), 32);
   // Calculate diffuse component
   vec4 I = texture2D(diffusetx,v_texcoord.st) * max(dot(LightDir, Norm), 0.0);
   vec3 diffuse = clamp(I, 0.0, 1.0);
   // Calculate specular component
   vec3 specular = texture2D(speculartx,v_texcoord.st) * specularContribution;
  vec3 texColor = texture2D(lighttx,v_texcoord.st);
   vec3 outColor =   (diffuse  + specular + texColor );//diffuse + specular; //texColor * (diffuse + specular + ambient);
  bah.xyz = outColor.xyz;
  */
   //RGBA of our diffuse color
           vec4 DiffuseColor = texture2D(diffusetx, v_texcoord.st);

           //RGB of our normal map
           vec3 NormalMap = texture2D(normaltx, v_texcoord.st).rgb;

           //The delta position of light
           vec3 LightDir = vec3(LightPos.xy - (gl_FragCoord.xy / Resolution.xy), LightPos.z);

           //Correct for aspect ratio
           LightDir.x *= Resolution.x / Resolution.y;

           //Determine distance (used for attenuation) BEFORE we normalize our LightDir
           float D = length(LightDir);

           //normalize our vectors
           vec3 N = normalize(NormalMap * 2.0 - 1.0);
           vec3 L = normalize(LightDir);

           //Pre-multiply light color with intensity
           //Then perform "N dot L" to determine our diffuse term
           vec3 Diffuse = (LightColor.rgb * LightColor.a) * max(dot(N, L), 0.0);

           //pre-multiply ambient color with intensity
           vec3 Ambient = AmbientColor.rgb * AmbientColor.a;

           //calculate attenuation
           float Attenuation = 1.0 / ( Falloff.x + (Falloff.y*D) + (Falloff.z*D*D) );

           //the calculation which brings it all together
           vec3 Intensity = Ambient + Diffuse * Attenuation;
           vec3 FinalColor = DiffuseColor.rgb * Intensity;


  for(int i=0;i<selsize;i++){
      if(v_texcoord.w == selected_mesh_part[i]){
          bah.a = timer;
          break;
      }

  }
           bah.rgb =   vec4(FinalColor, DiffuseColor.a).rgb;
  //bah.a = 0.5;
    gl_FragColor = bah;//vec4(outColor,1.0); //bah;//mix(bah,vec4(bah.xyz,0.1),lh);

            //vec4(0,0,0,1);//texture3D(poss,v_texcoord);//vec4(1f,1f,1f,1f);//texture2D(texture, v_texcoord);
}
//! [0]

