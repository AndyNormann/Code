#ifndef HELPER_H
#define HELPER_H

#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

//Cleaner
template<typename T, typename... Args>
void cleanup(T *t, Args&&... args){
    cleanup(t);
    cleanup(std::forward<Args>(args)...);
}

template<>
void cleanup<SDL_Window>(SDL_Window *win){
    if(!win){
        return;
    }
    SDL_DestroyWindow(win);
}
template<>
void cleanup<SDL_Renderer>(SDL_Renderer *ren){
    if(!ren){
        return;
    }
    SDL_DestroyRenderer(ren);
}
template<>
void cleanup<SDL_Texture>(SDL_Texture *tex){
    if(!tex){
        return;
    }
    SDL_DestroyTexture(tex);
}
template<>
void cleanup<SDL_Surface>(SDL_Surface *surf){
    if(!surf){
        return;
    }
    SDL_FreeSurface(surf);
}

//Logerror
void logSDLError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << SDL_GetError() << std::endl;
}

//LoadTexture
SDL_Texture *loadTexture(const std::string &filepath, SDL_Renderer *ren){
    SDL_Texture *texture = IMG_LoadTexture(ren, filepath.c_str());
    if(texture == nullptr){
        logSDLError(std::cout, "Load texture");
    }
    return texture;
}

//Render texture
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip = nullptr){
    SDL_RenderCopy(ren, tex, clip, &dst);
}
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip = nullptr){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    if(clip != nullptr){
        dst.w = clip->w;
        dst.h = clip->h;
    }else{
        SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    }
    renderTexture(tex, ren, dst, clip);
}
#endif
