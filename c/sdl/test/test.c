#include <stdio.h>
#include <SDL2/SDL.h>

static const int WINDOW_HEIGHT = 1200;
static const int WINDOW_WIDTH = 800;

static SDL_Window *g_window = NULL;
static SDL_Renderer *g_renderer = NULL;

int init_window_and_renderer(void);
void close_window_and_renderer(void);

int main()
{
    if (init_window_and_renderer() != 0){
        return -1;
    }

    int quit = 0;
    SDL_Event e;

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    while(quit == 0){
        while(SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                    case SDLK_UP:
                        up = 1;
                        break;
                    case SDLK_DOWN:
                        down = 1;
                        break;
                    case SDLK_LEFT:
                        left = 1;
                        break;
                    case SDLK_RIGHT:
                        right = 1;
                        break;
                }
            } else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        up = 0;
                        break;
                    case SDLK_DOWN:
                        down = 0;
                        break;
                    case SDLK_LEFT:
                        left = 0;
                        break;
                    case SDLK_RIGHT:
                        right = 0;
                        break;
                }
            }
        }

        if (up == 1) {
        } 
        if (down == 1) {
        } 
        if (left == 1) {
        } 
        if (right == 1) {
        } 

        if (up == 0) {
        } 
        if (down == 0) {
        } 
        if (left == 0) {
        } 
        if (right == 0) {
        } 

        SDL_RenderClear(g_renderer);
        SDL_RenderPresent(g_renderer);
    }

    close_window_and_renderer();
    return 0;
}

int init_window_and_renderer()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error, failed to init SDL: %s\n", SDL_GetError());
        return -1;
    }
    g_window = SDL_CreateWindow("Suh Dude", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_HEIGHT, WINDOW_WIDTH, SDL_WINDOW_SHOWN);
    if (!g_window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        return -2;
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

    if (!g_renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        return -3;
    }

    SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_UpdateWindowSurface(g_window);
    return 0;
}

void close_window_and_renderer()
{
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);

    g_renderer = NULL;
    g_window = NULL;

    SDL_Quit();
}
