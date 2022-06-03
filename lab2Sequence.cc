#include <iostream>
#include <assert.h>

using namespace std;

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
        x = NULL;
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
class Sequence
{
    

    public:
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;

};


template <class T>
class ArraySequence : public Sequence<T> 
{
    private:
    DynamicArray<T>* arr = new DynamicArray<T>;

    public:

    ArraySequence(T* items, int count)
    {
        *arr = DynamicArray<T>(items,count);
    }

    ArraySequence(ArraySequence<T> d,ArraySequence<T> b)
    {
        *arr = DynamicArray<T>(*d.arr,*b.arr);       
    }
    
    ArraySequence()
    {
        *arr = DynamicArray<T>();
    }

    T GetFirst() override
    {
        T k = arr -> Get(0);

        return k;
    }

    T GetLast() override
    {
        int h = arr -> GetSize();

        T k = arr -> Get(h - 1);

        return k;
    }

    T Get(int index) override
    {
        T k = arr -> Get(index);

        return k;
    }

    int GetLength() override
    {
        int k = arr -> GetSize();
        return k;
    }

    void InsertAt(T item, int index) override
    {
        arr -> Set(index, item);
    }

    void Append(T item) override
    {
        int k = arr -> GetSize();

        arr -> Resize(k + 1);
        arr -> Set(k, item);

    }

    void Prepend(T item) override
    {
        
    }

     ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        ArraySequence<T>* frr = new ArraySequence<T>();
        
        return frr;
    } 

    ArraySequence<T>* Concat(ArraySequence<T>* list) 
    {
        ArraySequence<T>* frr = new ArraySequence<T>(*this,*list);
        
        return frr;

    }

    void print()
    {
        arr -> print();
    }
};

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

template <class T>
class LinkedListSequence : public Sequence<T>
{
    private: 
    List<T>* arr = new List<T>;

    public:

    LinkedListSequence (T* items, int count)
    {
        *arr = List<T>(items,count);
    }

    LinkedListSequence ()
    {
        *arr = List<T>();
    }

    LinkedListSequence (LinkedListSequence <T> d, LinkedListSequence<T> b)
    {
        *arr = List<T>(*d.arr,*b.arr);
    }

    T GetFirst() override
    {
        T k = arr -> GetFirst();
        return k;
    }

    T GetLast() override
    {
        T k = arr -> GetLast();
        return k;
    }

    T Get(int index) override
    {
        T k = arr -> Get(index);
        return k;
    }

    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        LinkedListSequence<T>* a = new LinkedListSequence<T>();

        a -> arr = arr -> GetSubList(startIndex,endIndex);
        return a;
    }

    int GetLength() override
    {
        int k = arr -> GetLength();
        return k;
    }

    void Append(T item) override
    {
        arr -> Append(item);
    }

    void Prepend(T item) override
    {
        arr -> Prepend(item);
    }

    void InsertAt(T item, int index) override
    {
        arr -> InsertAt(item,index);
    }

    LinkedListSequence<T>* Concat(LinkedListSequence<T>* list) 
    {
        LinkedListSequence<T>* a = new LinkedListSequence<T>;
        a -> arr = arr -> Concat(list -> arr);
        return a;
    }

    void print()
    {
        arr -> printList(); 
    }

} ;

int main()
{

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ArraySequence<int> d = ArraySequence<int>(v,5);
    d.print();

    ArraySequence<int> d1 = ArraySequence<int>(v,6);
    d1.print();
    
    ArraySequence<int> d2 = ArraySequence<int>(d,d1);
    d2.InsertAt(2,5);

    d2.print();

    //ArraySequence<int> *a = d1.Concat(&d);
    //a -> print();

    int k = d1.GetLast();
    cout<< k << endl;

    LinkedListSequence<int> k1 = LinkedListSequence<int>(v,5);
    k1.print();

    LinkedListSequence<int> k3 = LinkedListSequence<int>(v,5);
    k3.print();

    LinkedListSequence<int>* k4 = k1.Concat(&k3);
    k4 -> print();

    LinkedListSequence<int>* k2 = k1.GetSubsequence(1,4);
    k2 -> print();

    return 0;
}