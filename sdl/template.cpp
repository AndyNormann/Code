#include <iostream>
#include <SDL2/SDL.h>
#include "helper.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 40;


int main(int argc, const char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //Window
    SDL_Window *window = SDL_CreateWindow(
            "Hello, is it me you're looking for?",
            0,
            0,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
            );

    if(window == nullptr){
        logSDLError(std::cout, "Window creation");
        SDL_Quit();
        return 1;
    }


    //Renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr){
        cleanup(window);
        logSDLError(std::cout, "Renderer creation");
        SDL_Quit();
        return 1;
    }
 
    //Load Textures
    SDL_Texture *image = loadTexture("image.png", renderer);
    SDL_Texture *background = loadTexture("background.png", renderer);

    if(image == nullptr || background == nullptr){
        cleanup(window, renderer, image, renderer);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    //Determine clips
    int iW = 100, iH = 100;
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;

    SDL_Rect clips[4];
    for (int i = 0; i < 4; i++) {
        clips[i].x = i / 2 * iW;
        clips[i].y = i % 2 * iH;
        clips[i].w = iW;
        clips[i].h = iH;
    }


    int useClip = 0;

    SDL_Event e;
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)
                quit = true;
            if(e.type == SDL_KEYDOWN){
                switch(e.key.keysym.sym){
                    case SDLK_1:
                        useClip = 0;
                        break;
                    case SDLK_2:
                        useClip = 1;
                        break;
                    case SDLK_3:
                        useClip = 2;
                        break;
                    case SDLK_4:
                        useClip = 3;
                        break;
                    default:
                        break;
                }
            }
        }

        SDL_RenderClear(renderer);
        renderTexture(image, renderer, x, y, &clips[useClip]);
        SDL_RenderPresent(renderer);
    }

    cleanup(window, renderer, image, background);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
