#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* intsum(vector* A1,vector* B1)
{

    float xc1, yc1, zc1;

        xc1 = *((float*)(A1 -> x)) + (*((float*)(B1 -> x)));
        yc1 = *((float*)(A1 -> y)) + (*((float*)(B1 -> y)));
        zc1 = *((float*)(A1 -> z)) + (*((float*)(B1 -> z)));

    vector* C1 = intcreate(xc1, yc1, zc1);

    return C1;
}