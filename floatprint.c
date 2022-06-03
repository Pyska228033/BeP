#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



void floatprint(vector* D)
{
    printf("x = (%f+%fi)\n y = (%f+%fi)\n z = (%f+%fi)\n", *((float*)(D -> x)),*((float*)((D -> x))+1),*((float*)(D -> y)),*((float*)((D -> y))+1),*((float*)(D -> z)),*((float*)((D -> z))+1));
}