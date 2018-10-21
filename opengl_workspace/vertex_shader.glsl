attribute vec2 position;
attribute vec2 texCoord;
varying vec2 textureCoordinate;
uniform float scale;

void main(){
    gl_Position = vec4(position*scale, 0, 1);
    textureCoordinate = texCoord;
}