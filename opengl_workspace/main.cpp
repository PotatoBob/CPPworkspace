#include <time.h>
#include <stdlib.h>

#include "SDL2/SDL.h"
#include "OpenGL/gl3.h"

#include "shader_compiler.h"

int main(int argc, char** argv){
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 900, 500, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    //long vertFileSize, fragFileSize;
    char* vertexData = readFileToCharArray("vertex_shader.glsl");
    char* fragData = readFileToCharArray("fragment_shader.glsl");

    unsigned int shader = compileShaderVF(vertexData, fragData);
    glUseProgram(shader);
    int postionId = glGetAttribLocation(shader, "position");
    int texCoordId = glGetAttribLocation(shader, "texCoord");
    int scaleId = glGetUniformLocation(shader, "scale");
    int R_Id = glGetUniformLocation(shader, "R_num");
    int G_Id = glGetUniformLocation(shader, "G_num");
    int B_Id = glGetUniformLocation(shader, "B_num");

    glUniform1f(scaleId, 0.5);

    float verts[] = {
        //co-ordinates followed by texture co-ordinates
        -0.8, -0.8, 0, 1,
        0.0, 0.8,   0.5, 0,
        0.8, -0.8,  1, 1,


        /*-1, -1, //left down
        -1, -0.5, //left up
        -0.5, -0.5, //right up

        -0.5, -0.5, //right up
        -0.5, -1, //right down
        -1, -1 //left up*/
    };
    unsigned char texture[] = {
        0, 0, 0, 255,       255, 255, 255, 255,
        255, 255, 255, 255, 0, 0, 0, 255,
    };

    unsigned int texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);
    

    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glVertexAttribPointer(postionId, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glEnableVertexAttribArray(postionId);

    glVertexAttribPointer(texCoordId, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float)));
    glEnableVertexAttribArray(texCoordId);

    glClearColor(1, 0, 0, 1);

    SDL_Event event;
    bool isRunning = true;

    float scale = 0.0;
    while(isRunning){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:{
                    isRunning = false;
                    break;
                }
                case SDL_KEYDOWN :{
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        isRunning = false;
                    }
                    break;
                }
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);

        glUniform1f(scaleId, scale);
        scale += 0.01;

        glUniform1f(R_Id, rand()/(double)RAND_MAX);
        glUniform1f(G_Id, rand()/(double)RAND_MAX);
        glUniform1f(B_Id, rand()/(double)RAND_MAX);

        glDrawArrays(GL_TRIANGLES, 0, 3); //big triangle
        //glDrawArrays(GL_TRIANGLES, 3, 6); //bottom left rectangle

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    return 0;
}