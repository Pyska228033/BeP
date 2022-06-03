#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* floatsum(vector* A1,vector* B1)
{

    float xc1, yc1, zc1, x1c1, y1c1, z1c1;

    xc1 = *((float*)(A1 -> x)) + (*((float*)(B1 -> x)));
    yc1 = *((float*)(A1 -> y)) + (*((float*)(B1 -> y)));
    zc1 = *((float*)(A1 -> z)) + (*((float*)(B1 -> z)));
    
    x1c1 = *((float*)((A1 -> x))+1) + (*((float*)((B1 -> x))+1));
    y1c1 = *((float*)((A1 -> y))+1) + (*((float*)((B1 -> y))+1));
    z1c1 = *((float*)((A1 -> z))+1) + (*((float*)((B1 -> z))+1));

    vector* C1 = floatcreate(xc1, yc1, zc1, x1c1, y1c1, z1c1);

    return C1;
}