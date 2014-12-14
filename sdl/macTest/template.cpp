#include <iostream>
#include <SDL2/SDL.h>

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
            640,
            480,
            SDL_WINDOW_SHOWN
            );

    if(window == nullptr){
        std::cout << "Window creation error " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

