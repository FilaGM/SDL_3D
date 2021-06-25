#ifndef VMath_H_
#define VMath_H_

extern double PI;

int ToRad(int degrees);

double* VMult3D(double* V[3],double xyz[3]);

double** GetXRotationMatrix(int degrees);
double** GetYRotationMatrix(int degrees);
double** GetZRotationMatrix(int degrees);

double** CreateVectorObject(int x,int y,int z,int vectorCount);

#endif