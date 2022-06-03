#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* intcreate(float x1, float y1, float z1)
{
    
    vector* new = (vector *)malloc(sizeof(vector));

    float *tmp_x = (float *)malloc(sizeof(float));
    float *tmp_y = (float *)malloc(sizeof(float));
    float *tmp_z = (float *)malloc(sizeof(float));

    *tmp_x = x1;
    *tmp_y = y1;
    *tmp_z = z1;


    (new -> x) = tmp_x;
    (new -> y) = tmp_y;
    (new -> z) = tmp_z;


    return new;

}