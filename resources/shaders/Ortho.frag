varying vec2 out_TexCoord;

uniform sampler2D in_Texture;

void main()
{
  gl_FragColor = texture(in_Texture, out_TexCoord);
}
