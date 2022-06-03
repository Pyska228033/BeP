#include <iostream>
#include <assert.h>

using namespace std;

enum Errors 
{
    Invalid_characters = 1,
    another_Error 

};

template <class T>
class Nudl
{
    public:
   
    T data;
    Nudl* next;
};

template <class T>
class Stek 
{
    private:
    
    Nudl<T>* ne1 = new Nudl<T>;
    
    public:
    
    Stek()
    {
   
    }
    
    Stek(T* arr, int n)
    {
        ne1 -> data = *arr;
        ne1 -> next = NULL;
        
        for(int i = 1; i < n; i++)
        {
            Nudl<T>* ne2 = new Nudl<T>;    
            ne2 -> data = *(arr + i);
            ne2 -> next = ne1;

            ne1 = ne2;    
        }
    
    }

    Stek<T>* concat(Stek<T>* b)
    {
        Stek<T>* c = new Stek<T>();
        c -> ne1 = ne1;

        Nudl<T>* ne = new Nudl<T>;
        ne = c -> ne1;        

        while(ne -> next != NULL)
        {
           ne = ne -> next;
        }

        ne -> next = b -> ne1;

        return c;
    }

    Stek<T>* miniseqense(int a, int b)
    {
        Nudl<T>* ne4 = ne1;
        int k = 0;

        while(ne4 != NULL)
        {
            k++;
            ne4 = ne4 -> next;
        }
        Stek<T>* c = new Stek<T>();

        if(a < b && b < k && a > 0)
        {
            Nudl<T>* ne = new Nudl<T>;
            ne = ne1;

            for(int i = 0; i < a; i++)
            {
                ne = ne -> next;
            }

            c -> ne1 -> data = ne -> data;
            Nudl<T>* ne3 = new Nudl<T>;
            ne3 = c -> ne1;
            ne = ne -> next;

            for(int i = 0; i < (b - a); i++)
            {
                Nudl<T>* ne2 = new Nudl<T>;
                ne2 -> data = ne -> data;
                ne2 -> next = NULL;

                ne = ne -> next;

                ne3 -> next = ne2;
                ne3 = ne2;
            }
        }

        else
        {
           assert(0); 
        }
        return c;
    }

    void print()
    {
        Nudl<T>* ne = new Nudl<T>;
        ne = ne1;

        while(ne != NULL)
        {
            cout<< ne -> data;

            ne = ne -> next;
        }
        cout<< endl;
    }
};    

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Stek<int> a = Stek<int>(v,5);
    a.print();

    Stek<int> b = Stek<int>(v,5);
    b.print();

    Stek<int>* c = a.miniseqense(0,3);
    c -> print();


    return 0;
}