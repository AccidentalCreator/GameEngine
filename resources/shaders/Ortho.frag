varying vec2 out_TexCoord;

uniform sampler2D ourTexture;

void main()
{
  gl_FragColor = texture(ourTexture, out_TexCoord);
}
