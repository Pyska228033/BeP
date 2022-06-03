#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* intpr(vector* A,vector* B)
{

    float xc, yc, zc;

        xc = *((float*)(A -> x)) * (*((float*)(B -> x)));
        yc = *((float*)(A -> y)) * (*((float*)(B -> y)));
        zc = *((float*)(A -> z)) * (*((float*)(B -> z)));

    vector* C = intcreate(xc, yc, zc);

    return C;
}