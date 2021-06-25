#include <math.h>
#include <iostream>
#include <SDL2/SDL.h>

double* CalculatePerspectiveFor3DVector(int FOV, int displayWidth,int displayHeight,double cameraPosition[3], double V[3]){
    double x = V[0];
    double y = V[1];
    double z = V[2];

    double PI = 3.14159265359;

    static double out[2];

    double halfdisplayWidth = (displayWidth/2);
    int endAngle = (180 - FOV)/2;
    double cameraDistance;
    
    //getting the center distance between camera and "display"
    cameraDistance = halfdisplayWidth * tan((PI/180)*endAngle);

    double XDistanceFromCamera = cameraPosition[0]+V[0];
    double YDistanceFromCamera = cameraPosition[1]+V[1];
    double ZDistanceFromCamera = cameraPosition[2]+V[2];
    
    //calculating X position on "display" via triangle
    int angleOfPositionTriangle_x = round(atan(YDistanceFromCamera/XDistanceFromCamera) * 180 / PI);
    double outerTriangleBSize_x =  YDistanceFromCamera - cameraDistance;
    double outerTriangleASize_x = outerTriangleBSize_x * tan((PI/180)*angleOfPositionTriangle_x);

    out[0] = XDistanceFromCamera - outerTriangleASize_x;

    //calculating Y position on "display" via triangle
    int angleOfPositionTriangle_y = round(atan(ZDistanceFromCamera/YDistanceFromCamera) * 180 / PI);
    double outerTriangleBSize_y =  YDistanceFromCamera - cameraDistance;
    double outerTriangleASize_y = outerTriangleBSize_y * tan((PI/180)*angleOfPositionTriangle_y);

    out[1] = ZDistanceFromCamera - outerTriangleASize_y;

    return out;
}

void RenderVectorObject(SDL_Renderer * renderer, double** VObject,int VObjectSize, int FOV, int displayWidth,int displayHeight,double cameraPosition[3]){
    double* globalPos = VObject[0];

    double* XY1;
    double* XY2;

    for(int i = 0;i < VObjectSize;i++){
        if(i == 0){}
        else{
            XY1 = CalculatePerspectiveFor3DVector(FOV, displayWidth, displayHeight, cameraPosition, VObject[i]);

            for(int j = 0;j < VObjectSize;j++){
                if(j == 0 || j == i){}
                else{
                    XY2 = CalculatePerspectiveFor3DVector(FOV, displayWidth, displayHeight, cameraPosition, VObject[i]);

                    SDL_RenderDrawLine(renderer,(displayWidth/2) + XY1[0],(displayHeight/2) + XY1[1],(displayWidth/2) + XY2[0],(displayHeight/2) + XY2[1]);
                }
            }
        }
    }
}