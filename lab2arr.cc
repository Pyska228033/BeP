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


int main()
{   
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    
    DynamicArray<int> d = DynamicArray<int>(v,5);
    d.print();

    DynamicArray<int> d1 = DynamicArray<int>(v,6);
    d1.print();
    
    DynamicArray<int> d2 = DynamicArray<int>(d,d1);
    d2.Resize(10);
    d2.Set(4,7);
    int f = d2.Get(4);
    cout<<f<<endl;
    d2.print();
   // cout<<(sizeof(d1)/sizeof(int));
    

    return 0;
}
