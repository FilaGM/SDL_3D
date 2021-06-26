#include <math.h> 

double PI = 3.14159265359;

double ToRad(int degree){
    double out = 0.0;
    out = (PI / 180) * degree;
    return out;
}

double* VMult3D(double* V[3],double xyz[3]){
    static double out[3];

    for(int i = 0;i < 3;i++){
        int subOut = 0;
        for(int j = 0;j < 3;j++){
            subOut += V[i][j] * xyz[j];
        }
        out[i] = subOut;
    }

    return out;
}

double** GetXRotationMatrix(int degrees){
    double** out;

    out = new double*[3];
    for(int i = 0;i < 3;i++){
        out[i] = new double[3];
    }

    double angle = ToRad(degrees);

    out[0][0] = 1; out[0][1] = 0         ; out[0][2] =  0         ;
    out[1][0] = 0; out[1][1] = cos(angle); out[1][2] = -sin(angle);
    out[2][0] = 0; out[2][1] = sin(angle); out[2][2] =  cos(angle);

    return out;
}

double** GetYRotationMatrix(int degrees){
    double** out;

    out = new double*[3];
    for(int i = 0;i < 3;i++){
        out[i] = new double[3];
    }

    double angle = ToRad(degrees);

    out[0][0] =  cos(angle); out[0][1] = 0; out[0][2] = sin(angle);
    out[1][0] =  0         ; out[1][1] = 1; out[1][2] = 0         ;
    out[2][0] = -sin(angle); out[2][1] = 0; out[2][2] = cos(angle);

    return out;
}

double** GetZRotationMatrix(int degrees){
    double** out;

    out = new double*[3];
    for(int i = 0;i < 3;i++){
        out[i] = new double[3];
    }

    double angle = ToRad(degrees);

    out[0][0] =  cos(angle); out[0][1] = -sin(angle); out[0][2] = 0;
    out[1][0] =  sin(angle); out[1][1] =  cos(angle); out[1][2] = 0;
    out[2][0] =  0         ; out[2][1] =  0         ; out[2][2] = 0;

    return out;
}

double** CreateVectorObject(int x,int y,int z,int vectorCount){
    double** VectorArray = 0;
    vectorCount++;
    VectorArray = new double*[vectorCount];

    VectorArray[0] = new double[3];
    VectorArray[0][0] = x;
    VectorArray[0][1] = y;
    VectorArray[0][2] = z;
    
    for (int h = 1; h < vectorCount; h++)
    {
        VectorArray[h] = new double[3];
        
        for (int w = 0; w < 3; w++)
        {
            VectorArray[h][w] = 0;
        }
    }
    
    return VectorArray;
}
