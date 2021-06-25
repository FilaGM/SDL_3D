#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <iomanip>

#include "src/headers/VMath.h"
#include "src/headers/VRenderer.h"

int screen_width = 680;
int screen_height = 480;

int FOV = 90;

bool HandleEnvents(bool exit){
    SDL_Event event;
    while(SDL_PollEvent(&event) > 0) {
        switch(event.type) {
            case SDL_QUIT:
            exit = true;
            break;
        }
    }
    return exit;
}

int wmain(int argc, char *argv[])
{
    SDL_Window *win = NULL;
    SDL_Renderer *render = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    
    win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width, screen_height, 0);
    render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    double** cube;
    cube = CreateVectorObject(10,10,10,8);
    cube[0][0] = -20; cube[0][1] = -20; cube[0][2] = -20;
    cube[1][0] =  20; cube[0][1] = -20; cube[0][2] = -20;
    cube[2][0] =  20; cube[0][1] = -20; cube[0][2] =  20;
    cube[3][0] = -20; cube[0][1] = -20; cube[0][2] =  20;

    cube[0][0] = -20; cube[0][1] =  20; cube[0][2] = -20;
    cube[1][0] =  20; cube[0][1] =  20; cube[0][2] = -20;
    cube[2][0] =  20; cube[0][1] =  20; cube[0][2] =  20;
    cube[3][0] = -20; cube[0][1] =  20; cube[0][2] =  20;


    bool exit = false;
    while(!exit){
        exit = HandleEnvents(exit);

        SDL_SetRenderDrawColor(render,0,0,0,255);
        SDL_RenderClear(render);

        double V1[3] = {200,300,0};
        double camera[3] = {0,0,0};


        SDL_SetRenderDrawColor(render,100,100,100,255);
        RenderVectorObject(render,cube,9,FOV,screen_width,screen_height,camera);

        SDL_RenderPresent(render);
        SDL_Delay(1000/30);
    }

 
    return 0;
}