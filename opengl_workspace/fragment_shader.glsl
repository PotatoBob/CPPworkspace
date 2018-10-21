uniform float R_num;
uniform float G_num;
uniform float B_num;

varying vec2 textureCoordinate;
uniform sampler2D sampler;

void main(){
    //gl_FragColor = vec4(R_num, G_num, B_num, 1);
    gl_FragColor = texture2D(sampler, textureCoordinate);
}