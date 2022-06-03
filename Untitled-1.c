#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "allf.h"

//static char *ErrorNames[] = {
   // "Error: Invalid characters",
   // "another Error "
//};

enum Errors /*http://cppstudio.com/post/8106/*/
{
    Invalid_characters = 1,
    another_Error 

};




int main()
{
    printf("Whole or Real?\n1.Integer\n2.Material");
    
    int flag;
    
    scanf("%d",&flag);

    if(flag > 2)
    {
        //puts(ErrorNames[0]);
        assert(0);
    }

    if(flag == 1)
    {
        float x1, y1, z1;
        float x2, y2, z2;

        printf("Enter vector A:");
        scanf("%f %f %f",&x1,&y1,&z1);

        printf("Enter vector B:");
        scanf("%f %f %f",&x2,&y2,&z2);
 
    vector* A = intcreate(x1, y1, z1);
    vector* B = intcreate(x2, y2, z2);
 
    int flag1;
 
    while(flag1 != 5)
    {

        printf("What's next?\n 1.Output vectors to the screen \n 2.Multiply vectors \n 3.Sum vectors \n 4.Vector product of vectors \n 5.To finish ");
 
        scanf("%d", &flag1);

        int Error = 0;

        if(flag1 > 5)
            {
              //  puts(ErrorNames[0]);
                assert(Error);
            }

        if(flag1 == 1)
        {

            printf("Vector A:");
            intprint(A);

            printf("Vector B:");
            intprint(B);
        
        }
 
        if(flag1 == 2)
        {

            vector* C = intpr(A,B);

            printf("Vector C:");

            intprint(C);
        
        }
 
        if(flag1 == 3)
        {

            vector* C = intsum(A,B);
            printf("Vector C:");
            intprint(C);
            freevector(C);
        
        }

        if(flag1 == 4)
        {

            vector* C = intvectorproz(A,B);
            printf("Vector C:");
            intprint(C);
            freevector(C);

        }

        if(flag1 == 5)
        {

            freevector(A);
            freevector(B);

        }
    }
}

 if(flag == 2)
 {
    float x1, y1, z1, x11, y11, z11;
    float x2, y2, z2, x21, y21, z21;

    printf("Enter vector material A:");
    scanf("%f %f %f",&x1,&y1,&z1);

    printf("Enter vector mnim A:");
    scanf("%f %f %f",&x11,&y11,&z11);


    printf("Enter vector material B:");
    scanf("%f %f %f",&x2,&y2,&z2);

    printf("Enter vector mnim B:");
    scanf("%f %f %f",&x21,&y21,&z21);
 
    vector* A = floatcreate(x1, y1, z1, x11, y11, z11);
    vector* B = floatcreate(x2, y2, z2, x21, y21, z21);
 
    int flag1;
 
    while(flag1 != 5)
    {

        printf("What's next?\n 1.Output vectors to the screen \n 2.Multiply vectors \n 3.Sum vectors \n 4.Vector product of vectors \n 5.To finish ");
 
        scanf("%d", &flag1);

        if(flag1 > 5)
            {
               // puts(ErrorNames[0]);
                exit(Invalid_characters);
            }

        if(flag1 == 1)
        {

            printf("Vector A:\n");
            floatprint(A);

            printf("Vector B:\n");
            floatprint(B);
        
        }
 
        if(flag1 == 2)
        {

            vector* C = floatpr(A,B);

            printf("Vector C:");

            floatprint(C);
            freevector(C);

        }
 
        if(flag1 == 3)
        {

            vector* C = floatsum(A,B);
            printf("Vector C:");
            floatprint(C);
            freevector(C);
        
        }

        if(flag1 == 4)
        {

            vector* C = floatvectorproiz(A,B);
            printf("Vector C:");
            floatprint(C);
            freevector(C);
        
        }


        if(flag == 5)
        {

            freevector(A);
            freevector(B);

        }
    }
}
    return 0;
}