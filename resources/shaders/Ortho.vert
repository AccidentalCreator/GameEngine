uniform mat4 in_Projection;
uniform mat4 in_Model;

attribute vec3 in_Position;
attribute vec2 in_TexCoord;

varying vec2 out_TexCoord;

void main()
{
  gl_Position = in_Projection * in_Model * vec4(in_Position.xy, 0, 1);

  out_TexCoord = in_TexCoord;
}

