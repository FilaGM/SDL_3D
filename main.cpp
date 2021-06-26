#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <iomanip>

#include "src/headers/VMath.h"
#include "src/headers/VRenderer.h"

int screen_width = 680;
int screen_height = 480;

int FOV = 60;
bool KEYS[322];

bool HandleEnvents(bool exit){
    SDL_Event event;
    while(SDL_PollEvent(&event) > 0) {
        switch(event.type) {
            case SDL_KEYDOWN:
                KEYS[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                KEYS[event.key.keysym.sym] = false;
                break;
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

    for(int i = 0; i < 322; i++) {
        KEYS[i] = false;
    }
    
    win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width, screen_height, 0);
    render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    double** cube;
    cube = CreateVectorObject(0,200,0,8);
    cube[1][0] = -10; cube[1][1] = -10; cube[1][2] = -10;
    cube[2][0] =  10; cube[2][1] = -10; cube[2][2] = -10;
    cube[3][0] =  10; cube[3][1] = -10; cube[3][2] =  10;
    cube[4][0] = -10; cube[4][1] = -10; cube[4][2] =  10;

    cube[5][0] = -10; cube[5][1] =  10; cube[5][2] = -10;
    cube[6][0] =  10; cube[6][1] =  10; cube[6][2] = -10;
    cube[7][0] =  10; cube[7][1] =  10; cube[7][2] =  10;
    cube[8][0] = -10; cube[8][1] =  10; cube[8][2] =  10;


    bool exit = false;
    int adition = 1;

    double camera[3] = {0,0,0};
    while(!exit){
        exit = HandleEnvents(exit);

        SDL_SetRenderDrawColor(render,0,0,0,255);
        SDL_RenderClear(render);
        
        //double* newV;
        //newV = VMult3D(GetXRotationMatrix(1),cube[0]);

        //cube[0][0] = newV[0];
        //cube[0][1] = newV[1];
        //cube[0][2] = newV[2];

        if(KEYS[SDLK_s]){
            camera[1]++;
        }
        if(KEYS[SDLK_w]){
            camera[1]--;
        }

        if(KEYS[SDLK_d]){
            camera[0]++;
        }

        if(KEYS[SDLK_a]){
            camera[0]--;
        }

        SDL_SetRenderDrawColor(render,100,100,100,255);
        RenderVectorObject(render,cube,9,FOV,screen_width,screen_height,camera);

        SDL_RenderPresent(render);
        SDL_Delay(1000/60);
    }

 
    return 0;
}