#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



void intprint(vector* D)
{
    printf("x = %f\n y = %f\n z = %f\n", *((float*)(D -> x)),*((float*)(D -> y)),*((float*)(D -> z)));
}