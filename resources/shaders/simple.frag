varying vec4 ex_Color;
varying vec2 out_TexCoord;

uniform sampler2D in_Texture;

void main()
{
  //gl_FragColor = ex_Color;
  //gl_FragColor = ex_Color * texture(in_Texture;out_TexCoord);
  gl_FragColor = texture(in_Texture, out_TexCoord);
  //gl_FragColor.x = out_TexCoord.x;
  //gl_FragColor.y = out_TexCoord.y;
}
