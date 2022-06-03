#include <stdio.h>

#include <stdlib.h>
#include "allf.h"



vector* intvectorproz(vector* A,vector* B)
{

float xc1,  yc1, zc1;

xc1 = *((float*)(A -> y)) * (*((float*)(B -> z))) - *((float*)(A -> z)) * (*((float*)(B -> y)));
yc1 = *((float*)(A -> z)) * (*((float*)(B -> x))) - *((float*)(A -> x)) * (*((float*)(B -> z)));
zc1 = *((float*)(A -> x)) * (*((float*)(B -> y))) - *((float*)(A -> y)) * (*((float*)(B -> x)));

vector* C1 = intcreate(xc1,yc1,zc1);

return C1;

}