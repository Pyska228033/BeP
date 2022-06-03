#include <iostream>
#include <assert.h>

using namespace std;

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
        ne1 -> data = 1357;
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
        
        while(ne1 != NULL)
        {
           n++;
           ne1 = ne1 -> next;
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
        Nudl<T>* ne = new Nudl<T>;
        ne = ne1;
        int h= 0;
        
        while(ne != NULL)
        {
            ne = ne -> next;
            h ++;
        }
        
        if(n >= h || n <= 0)
        assert(0);
        
        T k;
        
        for(int i = 0; i < n; i++)
        {
            ne1 = ne1 -> next;
        }
        
        k = ne1 -> data;
        
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


int main()
{
    


   int v[] = {1,2,3,4,5,6,7,8,9,10};
   int k[] = {1,2,3,4,5,6,7,8,9,10}; 
    
    List<int>d = List<int>(v,5);
    List<int>d1 = List<int>(k,8);
    
    //List<int>d2 = List<int>(d,d1);
    //d1.printList();
    
    //List<int>* d3 = d1.GetSubList(1,4);
    //d3 -> printList();
    
    int h = d1.GetFirst();
    cout<<h;
    
    //d.Prepend(5);
    //d.InsertAt(4,2);
    //d.printList();
    //int n = d.GetLength();
    //cout<< n;
    
    //List<int>* d3 = d1.Concat(&d);
    //d3 -> printList();
    
    return 0;
}








