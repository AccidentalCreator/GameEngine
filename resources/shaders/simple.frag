varying vec4 ex_Color;
varying vec2 out_TexCoord;

uniform sampler2D ourTexture;

void main()
{
  //gl_FragColor = ex_Color;
  //gl_FragColor = ex_Color * texture(ourTexture, out_TexCoord);
  gl_FragColor = texture(ourTexture, out_TexCoord);
  //gl_FragColor.x = out_TexCoord.x;
  //gl_FragColor.y = out_TexCoord.y;
}
