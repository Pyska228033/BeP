typedef struct vector
{
    void* x;
    void* y;
    void* z;
    
    
}vector;
vector* floatcreate(float x2, float y2, float z2, float x3, float y3, float z3);
vector* floatpr(vector* A,vector* B);
vector* floatsum(vector* A1,vector* B1);
vector* intcreate(float x1, float y1, float z1);
vector* intpr(vector* A,vector* B);
vector* intsum(vector* A1,vector* B1);
vector* floatvectorproiz(vector* A,vector* B);
vector* intvectorproz(vector* A,vector* B);
void floatprint(vector* D);
void intprint(vector* D);
void freevector (vector* A);