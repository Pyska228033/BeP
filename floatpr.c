#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* floatpr(vector* A,vector* B)
{

    float xc, yc, zc, x1c, y1c, z1c;

    xc = *((float*)(A -> x)) * (*((float*)(B -> x)));
    yc = *((float*)(A -> y)) * (*((float*)(B -> y)));
    zc = *((float*)(A -> z)) * (*((float*)(B -> z)));

    x1c = *((float*)((A -> x))+1) * (*((float*)((B -> x))+1));
    y1c = *((float*)((A -> y))+1) * (*((float*)((B -> y))+1));
    z1c = *((float*)((A -> z))+1) * (*((float*)((B -> z))+1));


    vector* C = floatcreate(xc, yc, zc, x1c, y1c, z1c);

    return C;
}