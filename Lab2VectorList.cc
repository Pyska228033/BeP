#include <iostream>
#include <cmath>
#include <assert.h>
#include "complex.hpp"
#include <complex>

using namespace std;

Complex sqrt(Complex  &comp);

template <class T>
class Nudl
{
    public:
   
    T data;
    Nudl* next;
    
};

template <class T>
class List 
{
    private:
    
    Nudl<T>*ne1 = new Nudl<T>[100];
    
    public:
    
    List()
    {
        ne1 -> next = NULL;   
    }
    
    List(T* arr, int n)
    {
        Nudl<T>* ne = new Nudl<T>;
        
        ne -> data = *arr;
        ne -> next = NULL;
        ne1 = ne;
        
        for(int i = 1; i < n; i++)
        {
            Nudl<T>* ne2 = new Nudl<T>;    
            ne2 -> data = *(arr + i);
            ne2 -> next = NULL;
                
            while(ne -> next != NULL)
            {
                ne = ne -> next;
            }
            ne -> next = ne2;
        }
    
    }
    
    List(List<T> d, List<T> b)
    {
        Nudl<T>* ne2 = new Nudl<T>;
        
        ne2 = d.ne1;
        ne1 = ne2;
        
        while(ne2 -> next != NULL)
        {
          ne2 = ne2 -> next;
        }
        
        ne2 -> next = b.ne1;
        
    }
    
    int GetLength()
    {
        int n = 0;
        Nudl<T>* ne2 = new Nudl<T>;
        ne2 = ne1;
        while(ne2 != NULL)
        {
           n++;
           ne2 = ne2 -> next;
        }
        
        return n;
    }
    
    T GetFirst()
    {
        Nudl<T>* ne = new Nudl<T>;
        ne = ne1;
        int n= 0;
        
        while(ne != NULL)
        {
            ne = ne -> next;
            n ++;
        }
        
        if((n == 1 && (ne -> data) == 1357))
        assert(0);
        
        T k;
        
        k = (ne1 -> data);
        
        return k;
    }
    
    T GetLast()
    {
        Nudl<T>* ne = new Nudl<T>;
        ne = ne1;
        int n= 0;
        
        while(ne != NULL)
        {
            ne = ne -> next;
            n ++;
        }
        
        if((n == 1 && (ne -> data) == 1357))
        assert(0);
        
        T k;
        
        while(ne1 -> next != NULL)
        {
            ne1 = ne1 -> next;
        }
        
        k = ne1 -> data;
        
        return k;
    }
    
    T Get(int n)
    {
        
        if(n >= this -> GetLength() || this -> GetLength() <= 0)
        assert(0);
        
        T k;
        
        Nudl<T>* ne2 = new Nudl<T>;
        ne2 = ne1;
        for(int i = 0; i < n; i++)
        {
            ne2 = ne2 -> next;
        }
        
        k = ne2 -> data;
        
        return k;
    }
    
    List<T>* GetSubList(int str, int end)
    {
        Nudl<T>* ne = new Nudl<T>;
        ne = ne1;
        int n= 0;
        
        while(ne != NULL)
        {
            ne = ne -> next;
            n ++;
        }
        
        if((n == 1 && (ne -> data) == 1357) || str < 0 || end < 0 || end < str)
        assert(0);
        
       List<T>* d = new List<T>();
       
       for(int i = 0; i < str; i++)
       {
           ne1 = ne1 -> next;
       }
       
       (d -> ne1) = ne1;
       
       for(int i = 0; i < (end - str); i++)
       {
          ne1 = ne1 -> next;
       }
       ne1 -> next = NULL;
       
       return d;
       
    }
    
    void Append(T item)
    {
        Nudl<T>* ne = new Nudl<T>;
        Nudl<T>* ne2 = new Nudl<T>;
        
        ne = ne1;
        
        ne2 -> data = item;
        ne2 -> next = NULL;
        
        while(ne -> next != NULL)
        {
            ne = ne -> next;
        }
        
        ne -> next = ne2;
    }
    
    void Prepend(T item)
    {
        Nudl<T>* ne2 = new Nudl<T>;
        
        ne2 -> data = item;
        ne2 -> next = ne1;
        
        ne1 = ne2;
    }

    void InsertAt(T item, int n)
    {
        Nudl<T>* ne6 = new Nudl<T>;
        ne6 = ne1;
        int h= 0;
        
        while(ne6 != NULL)
        {
            ne6 = ne6 -> next;
            h ++;
        }
        
        if(n >= h || n <= 0)
        assert(0);
        
        Nudl<T>* ne = new Nudl<T>;
        Nudl<T>* ne2 = new Nudl<T>;
        
        ne = ne1;
        
        for(int i = 1; i < n; i++)
        {
            ne = ne -> next;
        }
        
        Nudl<T>* ne3 = new Nudl<T>;
        
        ne3 = ne -> next;
        
        ne2 -> data = item;
        ne2 -> next = ne3;
        
        ne -> next = ne2;
    }
    
    List<T>* Concat(List<T> *b)
    {
        List<T>* d = new List<T>();
        
        (d -> ne1) = ne1;
        
        while(ne1 -> next != NULL)
        {
            ne1 = ne1 -> next;
        }
        
        ne1 -> next = (b -> ne1);
        
        return d;
        
    }
    
    void printList()
    {
        Nudl<T>* ne = new Nudl<T>;
        ne = ne1;
        
        while(ne != NULL)
        {
            cout<< ne -> data;
            ne = ne -> next;
        }
        cout<<endl;
    }
    
};

template <class T>
class VectorList
{
    private:
    List<T>* list = new List<T>;

    public:

    VectorList()
    {
        *list = List<T>();
    }

    VectorList(T* arr,int k)
    {
        *list = List<T>(arr,k);
    }

    VectorList<T>* Sum(VectorList<T>* b)
    {
        int max, min;
        T* y = new T;

        if(list -> GetLength() > b -> list -> GetLength())
        {
            max = list -> GetLength();
            min = b -> list -> GetLength();
        }
        if(list -> GetLength() < b -> list -> GetLength())
        {
            max = b -> list -> GetLength();
            min = list -> GetLength();
        }
        if(list -> GetLength() == b -> list -> GetLength())
        {
            max = list -> GetLength();
            min = max;
        }

        for(int i = 0; i < min; i++)
        {
            y[i] = (list -> Get(i)) + (b -> list -> Get(i));
        }

        if(max != min)
        {
            if(max = list -> GetLength())
            {
                for(int i = min; i < max; i++)
                {
                    y[i] = list -> Get(i);
                }
            }

            if(max = b -> list -> GetLength())
            {
                for(int i = min; i < max; i++)
                {
                    y[i] = b -> list -> Get(i);
                }
            }
        }
        VectorList<T>* c = new VectorList<T>(y,max);
        return c;

    }

    VectorList<T>* Proz(T b)
    {
        int max = list -> GetLength();
        T* y = new T;

        for(int i = 0; i < max; i++)
        {
            y[i] = list -> Get(i) * b;
        }
        VectorList<T>* c = new VectorList<T>(y,max);
        return c;
    }

    T Norm()
    {
        int n = list -> GetLength();
        T k;
        for(int i = 0; i < n; i++)
        {
            k = k + pow(list -> Get(i),2);
        }
        k = sqrt(k);
    }

    VectorList<T>* SkalProz(VectorList<T>* b)
    {
        int min;
        T* y = new T;

        if(list -> GetLength() <= b -> list -> GetLength())
        min = list -> GetLength();
        if(list -> GetLength() >= b -> list -> GetLength())
        min = b -> list -> GetLength();

        for(int i = 0; i < min; i++)
        {
            y[i] = list -> Get(i) * b -> list -> Get(i);
        }
        VectorList<T>* c = new VectorList<T>(y,min);
        return c;

    }

    void print()
    {
        list -> printList();
    }
};

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    VectorList<int> a = VectorList<int>(v,5);
    a.print();
    VectorList<int> b = VectorList<int>(v,6);
    b.print();
    VectorList<int>* c = a.Sum(&b);
    c -> print();
    VectorList<int>* c1 = a.Proz(4);
    c1 -> print();
    VectorList<int>* c2 = a.SkalProz(&b);
    c2 -> print();
    List<int> k = List(int)(v,3);
    
    return 0;
}