varying vec4 ex_Color;
varying vec2 out_TexCoord;

uniform sampler2D ourTexture;

void main()
{
  //gl_FragColor = ex_Color;
  gl_FragColor = ex_Color * texture(ourTexture, out_TexCoord);
}
