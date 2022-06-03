#include <stdio.h>

#include <stdlib.h>
#include "allf.h"


void freevector (vector* A)
{
    free(A -> x);
    free(A -> y);
    free(A -> z);
    
}