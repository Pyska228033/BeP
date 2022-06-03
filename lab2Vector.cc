#include <iostream>
#include <cmath>
#include <assert.h>
#include "complex.hpp"
#include <complex>

using namespace std;

Complex sqrt(Complex  &comp);

template <class T>
class DynamicArray
{
    private:
    int n;
    T* x = new T;
    
    public:
    
    DynamicArray()
    {
        n = 0;
    }

    DynamicArray(T* items, int count)
    {
        n = count;
        
        for(int i = 0; i < count; i++)
        {
            x[i] = items[i]; 
        }
    }
    
    DynamicArray(int size)
    {
        n = size;
        
        for(int i = 0; i < size; i++)
        {
            x[i] = 0;
        }
    }
    
    DynamicArray(DynamicArray<T> d,DynamicArray<T> b)
    {
        n = d.n + b.n;
        int h = d.n;

        for(int i = 0; i < d.n; i++)
        {
            x[i] = d.x[i];
        }

        for(int i = 0; i < b.n; i++)
        {
            x[h] = b.x[i];
            h++;
        }
    }
  
    T Get(int index)
    {
        if((n - 1) < index)
        assert(0);
        
        T k = x[index];

       return k;
    }

    int GetSize()
    {
        return n;
    }

    void Set(int index, T value)
    {
        if((n - 1) < index )
        assert(0);
        
        x[index] = value;   
    }

    void Resize(int newSize)
    {
        n = newSize;
    }
    
    void print()
    {
        
        for(int i = 0; i < n; i++)
        {
            cout<<x[i];
        }
        cout<<endl;
    }
    
};

template <class T>
class Vector
{
    private:
    DynamicArray<T>* arr = new DynamicArray<T>;
    
    public:

    Vector()
    {
        *arr = DynamicArray<T>();
    }

    Vector(T* items, int k)
    {
       *arr = DynamicArray<T>(items,k);  
    }

    Vector<T>* Sum(Vector<T>* b)
    {
        int max, min;
        T* y = new T;

        if(arr -> GetSize() > b -> arr -> GetSize())
        {
            max = arr -> GetSize();
            min = b -> arr -> GetSize();
        }

        if(arr -> GetSize() < b -> arr -> GetSize())
        {
            max = b -> arr -> GetSize();
            min = arr -> GetSize();
        }

        if(arr -> GetSize() == b -> arr -> GetSize())
        {
            max = arr -> GetSize();
            min = max;
        }

        for(int i = 0; i < min; i++)
        {
            y[i] = arr -> Get(i) + b -> arr -> Get(i);
        }

        if(min != max)
        {
            if(max = arr -> GetSize())
            {
                for(int i = min; i < max; i++)
                {
                    y[i] = arr -> Get(i);
                }
            }

            if(max = b -> arr -> GetSize())
            {
                for(int i = min; i < max; i++)
                {
                    y[i] = b -> arr -> Get(i);
                }
            }
        }

        Vector<T>* c = new Vector<T>(y,max);
        return c;
    }

    Vector<T>* ProzSkal(T b)
    {
        T* y = new T;
        int n = arr -> GetSize();

        for(int i = 0; i < n; i++)
        {
            y[i] = arr -> Get(i) * b;
        }

        Vector<T>* c = new Vector<T>(y,n);
        return c;
    }

    T Norm()
    {
        int n = arr -> GetSize();
        T k, h;

        for(int i = 0; i < n; i++)
        {
            k = k + pow(arr -> Get(i),2);
        }
        h = sqrt(k);
        return h;
    }

    Vector<T>* Proz(Vector<T>* b)
    {
        int min;
        T* y = new T;

        if(arr -> GetSize() > b -> arr -> GetSize())
        {
            min = b -> arr -> GetSize();
        }

        if(arr -> GetSize() < b -> arr -> GetSize())
        {
            min = arr -> GetSize();
        }

        if(arr -> GetSize() == b -> arr -> GetSize())
        {
            min = arr -> GetSize();
        }

        for(int i = 0; i < min; i++)
        {
            y[i] = arr -> Get(i) * b -> arr -> Get(i);
        }

        Vector<T>* c = new Vector<T>(y,min);
        return c;
    }

    void print()
    {
        arr -> print();
    }
};

int main()
{
    int* v = new int[100];
    for(int i =0; i < 100; i++)
    {
        v[i] = i;
    }

    Vector<int> a = Vector<int>(v,50);
    a.print();
    Vector<int> b = Vector<int>(v,100);
    b.print(); 
   
    Vector<int>* c = a.Sum(&b);
    c -> print();
    

    return 0;
}