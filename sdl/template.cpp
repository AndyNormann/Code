#include <iostream>
#include <SDL2/SDL.h>
#include "cleanup.hpp"

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 480;

int main(int argc, const char *argv[])
{
    SDL_Window *window;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL init error: " << SDL_GetError() << std::endl;
        return 1;
    }


    window = SDL_CreateWindow(
            "Hello, is it me you're looking for?",
            0,
            0,
            SCREEN_HEIGHT,
            SCREEN_WIDTH,
            SDL_WINDOW_SHOWN
            );

    if(window == nullptr){
        std::cout << "Window creation error " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr){
        cleanup(window);
        std::cout << "SDL Renderer error" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::string image_path = "ebola.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(image_path.c_str());

    if(bmp == nullptr){
        cleanup(window, renderer);
        std::cout << "Image loading error" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if(tex == nullptr){
        cleanup(window, renderer);
        std::cout << "Texture error" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tex, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    cleanup(window, renderer, tex);

    SDL_Quit();

    return 0;
}
