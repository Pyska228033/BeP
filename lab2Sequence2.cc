#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class DynamicArray
{
    public:
    
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

    DynamicArray<T>* GetSubsequence(int startindex, int endindex)
    {
        DynamicArray<T>* a = new DynamicArray<T>;

        for (int i = startindex; i < endindex; i++)
        {
            a -> n = (endindex - startindex);
            a -> x[i] = this -> x[i];
        }
        return a;
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
    //virtual int GetLength() = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    //virtual void Append(T item) = 0;
    //virtual void Prepend(T item) = 0;
    //virtual void InsertAt(T item, int index) = 0;
    //virtual Sequence <T>* Concat(Sequence <T> *list) = 0;

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
        (arr -> n) = (b.arr -> n) + (d.arr -> n);

        for(int i = 0; i < d.arr -> n; i++)
        {
            arr -> x[i] = d.arr -> x[i];
        }

        int l = d.arr -> n;
        for( int i = 0; i < b.arr -> n; i++)
        {
            arr -> x[l] = b.arr -> x[i];
            l++;
        }
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
        T k = arr -> Get((arr -> n) - 1);

        return k;
    }

    T Get(int index) override
    {
        T k = arr -> Get(index);

        return k;
    }

    ArraySequence* GetSubsequence(int startIndex, int endIndex) override
    {
        ArraySequence* a = new ArraySequence<T>;

        a -> arr = arr -> GetSubsequence(startIndex,endIndex);

        return a;
    }

    void print()
    {
        for(int i = 0; i < arr -> n; i++)
        {
            cout << arr -> x[i];
        }
        cout << endl;
    }
};    

int main()
{

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ArraySequence<int> d = ArraySequence<int>(v,5);
    d.print();

    ArraySequence<int> d1 = ArraySequence<int>(v,6);
    d1.print();

    int k = d1.Get(3);
    cout<< k;

    return 0;
}