#ifndef VRenderer_H_
#define VRenderer_H_
#include <SDL2/SDL.h>

void RenderVectorObject(SDL_Renderer * renderer, double** VObject,int VObjectSize, int FOV, int displayWidth,int displayHeight,double cameraPosition[3]);

double* CalculatePerspectiveFor3DVector(int FOV, int displayWidth,int displayHeight,double cameraPosition[3], double V[3]);

#endif