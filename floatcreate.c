#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* floatcreate(float x2, float y2, float z2, float x3, float y3, float z3)
{
    
vector* new = (vector *)malloc(sizeof(vector));
 

    (new -> x) = (float *)malloc(sizeof(float) * 2);
    (new -> y) = (float *)malloc(sizeof(float) * 2);
    (new -> z) = (float *)malloc(sizeof(float) * 2);

    *((float*)(new -> x)) = x2;
    *((float*)(new -> y)) = y2;
    *((float*)(new -> z)) = z2;
    *((float*)((new -> x))+1) = x3;
    *((float*)((new -> y))+1) = y3;
    *((float*)((new -> z))+1) = z3;
    

    return new;

}