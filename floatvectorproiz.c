#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* floatvectorproiz(vector* A,vector* B)
{

float xc1,  yc1, zc1;
float xc11, yc11, zc11;

xc1 = *((float*)(A -> y)) * (*((float*)(B -> z))) - (*((float*)((A -> y))+1)) * (*((float*)((B -> z))+1)) - (*((float*)(A -> z)) * (*((float*)(B -> y)))) + (*((float*)((A -> z))+1)) * (*((float*)((B -> y))+1));
xc11 = (*((float*)(A -> y)) * (*((float*)((B -> z))+1))) + (*((float*)(B -> z)) * (*((float*)((A -> y))+1))) - (*((float*)(A -> z)) * (*((float*)((B -> y))+1))) - (*((float*)(B -> y)) * (*((float*)((A -> z))+1)));

yc1 = *((float*)(A -> z)) * (*((float*)(B -> x))) - (*((float*)((A -> z))+1)) * (*((float*)((B -> x))+1)) - (*((float*)(A -> x)) * (*((float*)(B -> z)))) + (*((float*)((A -> x))+1) * (*((float*)((B -> z))+1)));
yc11 = (*((float*)(A -> z)) * (*((float*)((B -> x))+1))) + (*((float*)(B -> x)) * (*((float*)((A -> z))+1))) - (*((float*)(A -> x)) * (*((float*)((B -> z))+1))) - (*((float*)(B -> z)) * (*((float*)((A -> x))+1)));

zc1 = *((float*)(A -> x)) * (*((float*)(B -> y))) - (*((float*)((A -> x))+1) * (*((float*)((B -> y))+1))) - (*((float*)(A -> y)) * (*((float*)(B -> x)))) + (*((float*)((A -> y))+1) * (*((float*)((B -> x))+1)));
zc11 = *((float*)(A -> x)) * (*((float*)((B -> y))+1)) + (*((float*)(B -> y)) * (*((float*)((A -> x))+1))) - (*((float*)(A -> y)) * (*((float*)((B -> x))+1))) - (*((float*)(B -> y)) * (*((float*)((A -> x))+1)));

vector* C1 = floatcreate(xc1, yc1, zc1, xc11, yc11, zc11);

    return C1;
}