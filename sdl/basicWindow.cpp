#include <SDL/SDL.h>
#include <string>
#include <iostream>

//screen attributes
const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 480;
const int SCREEN_BPP = 32;

//Screen surfaces
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

//Helper function declerations
SDL_Surface* load_image(std::string filename);
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cout << "Usage: " << argv[0] << " foreground_image background_image\n" << "Returns 0 if sucessful, else 1" << std::endl;
        return 1;
    }
    //image to load
    std::string message_filename(argv[1]);
    std::string background_filename(argv[2]);
    
    //init
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return 1;

    //set up screen region
    screen = SDL2_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    
    if(screen == NULL)
        return 1;
    //window caption
    SDL_WM_SetCaption("Hello World", NULL);

    //load image
    message = load_image(message_filename);
    background = load_image(background_filename);
    //Applies image to screen region
    //background
    apply_surface( 320, 0, background, screen );
    apply_surface( 0, 240, background, screen );
    apply_surface( 320, 240, background, screen );    
    //message
    apply_surface(180, 140, message, screen);


    //updates screen
    if(SDL_Flip(screen) == -1){
        return 1;
    }

    //pause
    SDL_Delay(2000);
   
    //Cleanup
    SDL_FreeSurface(message);
    SDL_FreeSurface(background);

    SDL_Quit();
    return 0;
}


SDL_Surface* load_image(std::string filename){
    SDL_Surface *loaded_image = NULL;
    
    SDL_Surface *optimized_image = NULL;

    loaded_image = SDL_LoadBMP(filename.c_str());
    
    if(loaded_image != NULL){
        optimized_image = SDL_DisplayFormat(loaded_image);
        SDL_FreeSurface(loaded_image);
    }
    return optimized_image;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination){
    //temp rectangle for holding offset
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //blitz the surface
    SDL_BlitSurface(source, NULL, destination, &offset);

}
