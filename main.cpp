#include "SDL/SDL.h"

int main (int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("window", 100, 100, 800, 600, 0);
    bool isRunning = true;
    SDL_Event event;
    while(isRunning) {
        while(!SDL_PollEvent(& event)) {
            switch(event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE) {
                        isRunning = false;
                        break;
                    }
            }
        }
    }
    SDL_DestroyWindow(window);

    return 0;
}