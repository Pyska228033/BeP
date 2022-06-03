#ifndef BINARTREE_HPP
#define BINARTREE_HPP

#include "node.hpp"
#include <iostream>
#include <cstring>


using namespace std;
template <class T>
class Binartree
{
private:
    T great;
    Binartree* left; 
    Binartree* right; 
public:
    Binartree();
    Binartree(T data);
    Binartree* Getleft();
    Binartree* Getright();
    T Getgreat();
    Binartree<T>* find(Binartree<T>* a, T b);
    void del(Binartree<T>* a, T b,Binartree<T>* c = nullptr);
    void PKL(Binartree<T>* a);
    void PLK(Binartree<T>* a);
    void KLP(Binartree<T>* a);
    void KPL(Binartree<T>* a);
    void LPK(Binartree<T>* a);
    void LKP(Binartree<T>* a);
    void add(Binartree<T>*& a, T b);
    void print(Binartree<T>*& a);
    void deltree(Binartree<T>* a);
    bool ContainsNode(Binartree<T>* a,T data);
    bool ContainsSubTree(Binartree<T>* a,Binartree<T>* Sub);
    Binartree<T>* GetsubTree(Binartree<T>* a,T b);
    void Concat(Binartree<T>* a,Binartree<T>* b);
    string* WriteIntoStr(Binartree<T>* b,string *str);
    Binartree<T>* Where(bool (*f) (T data),Binartree<T>* b,Binartree<T>* c);
    Binartree<T>* Map(T (*f) (T data),Binartree<T>* b,Binartree<T>* c);
};
template <class T>
Binartree<T>::Binartree(T data)
{
    this -> great = data;
    this -> left = nullptr;
    this -> right = nullptr;
}
template <class T>
Binartree<T>::Binartree()
{
    this -> left = nullptr;
    this -> right = nullptr;
}
template <class T>
Binartree<T>* Binartree<T>::Getleft()
{
    return this -> left;
}
template <class T>
Binartree<T>* Binartree<T>::Getright()
{
    return this -> right;
}
template <class T>
T Binartree<T>::Getgreat()
{
    return this ->great;
}
template <class T>
string* Binartree<T>::WriteIntoStr(Binartree<T>* b,string* str)
{
    if (b == nullptr)
        return nullptr;
    *str = *str + to_string(b -> Getgreat());
    *str = *str + " ";
    if (b -> Getleft() != nullptr)
        WriteIntoStr(b -> Getleft(),str);
    if (b -> Getright() != nullptr)
        WriteIntoStr(b -> Getright(),str);
    return str;
}

template <class T>
Binartree<T>* Binartree<T>::Where(bool (*f) (T data),Binartree<T>* b,Binartree<T>* c)
{
    if (b != nullptr)
    {
        if (f(b -> Getgreat()))
            c -> add( c, b -> Getgreat());
        if (b -> Getleft() != nullptr)
            Where( f, b -> Getleft(), c);
        if (b -> Getright() != nullptr)
            Where( f, b -> Getright(),c);
    }
    return c;
}

template <class T>
Binartree<T>* Binartree<T>::Map(T (*f) (T data),Binartree<T>* b,Binartree<T>* c)
{
    if (b == nullptr)
        return nullptr;

    if (b != nullptr)
    {
        if (b -> Getgreat())
            c -> add(c, f(b -> Getgreat()));

        if (b -> Getleft() != nullptr)
            Map( f, b -> Getleft(), c);

        if (b -> Getright() != nullptr)
            Map( f, b -> Getright(), c);
    }
    return c;
}

template <class T>
void Binartree<T>::Concat(Binartree<T>* a,Binartree<T>* b)
{

    if (a -> Getleft() != nullptr)
        Concat(a -> left, b);
    if (a -> Getright() != nullptr)
        Concat(a -> Getright(), b);
    b -> add(b,a -> Getgreat());
}

template <class T>
bool Binartree<T>::ContainsNode(Binartree<T>* a,T data)
{
    Binartree<T>* b = nullptr;
    b = a -> find(a,data);

    if (b == nullptr)
        return false;
    else
        return true;
}

template <class T>
bool Binartree<T>::ContainsSubTree(Binartree<T>* a,Binartree<T>* Sub)
{

    bool b = a -> ContainsNode( a, Sub -> Getgreat());
    if (b == false)
        return false;
    if (a -> Getleft() != nullptr) {
        b = ContainsSubTree( a, Sub -> Getleft());
        if (b == false)
            return false;
    }
    if (a -> Get_right() != nullptr){
        b = ContainsSubTree( a, Sub -> Getright());
         if (b == false)
            return false;
    }
    if (b == true)
    {
        return true;
    }
}

template <class T>
Binartree<T>* getmin(Binartree<T>* a, Binartree<T>*& b)
{
    if (a == nullptr)
    {
        return nullptr;
    }
    if (a -> Getleft() != nullptr)
    {
        Binartree<T>* k = getmin(a -> Getleft(), a);
        b = a;
        return k;
    }
    else
    {
        return a;
    }
}

template <class T>
Binartree<T>* Binartree<T>::GetsubTree(Binartree<T>* a,T b)
{
    Binartree<T>* k = find(a,b);
    return k;
}

template <class T>
Binartree<T>* Binartree<T>::find(Binartree<T>* a, T b)
{
    if (a != nullptr)
    {
        if(a -> great == b)
        {
            return a;
        }

        else if(b < a -> great)
        {
            return find(a -> left, b);
        }

        else if(b > a -> great)
        {
            return find(a -> right, b);
        }

    }
    else
        return nullptr;

}


template <class T>
void Binartree<T>::del(Binartree<T>* a, T b ,Binartree<T>* c)
{
    if (a != nullptr)
    {
        if (b == a -> great)
        {
            if ((a -> left == nullptr) && (a -> right == nullptr))
            {
                if (c != nullptr && c -> great <= a -> great)
                    c -> right = nullptr;
                else
                    c -> left = nullptr;
                delete a;
            }
            else if (a -> left == nullptr && a -> right != nullptr)
            {
                if (c != nullptr && c -> great <= a -> great)

                    c -> right = a -> right;

                else
                    c -> left = a -> right;
                delete a;
            }
            else if (a -> left != nullptr && a -> right == nullptr) 
            {
                if (c != nullptr &&  c -> great <= a -> great)
                    c -> right = a -> left;
                else
                    c -> left = a -> left;
                delete a;
            }
            else if (a -> left != nullptr && a -> right != nullptr)
            {
                Binartree<T>* c = nullptr;
                Binartree<T>* d = getmin(a -> right, c);

                if (d -> right == nullptr) 
                {
                    if (c != nullptr)
                        c -> left = nullptr;
                }
                else {
                    if (c != nullptr)
                        c -> left = d -> right;
                }
                a -> great = d -> great;
                delete d;
            }

        }
        else if (b < a -> great) 
        {
            del(a -> left, b, a); 
        }
        else if (b > a -> great)
        {
            del(a -> right, b, a); 
        }
    }
    else
    {
        cout << " elementa net " << endl;
    }
}

template <class T>
void Binartree<T>::KLP(Binartree<T>* a)
{
    if (a != nullptr)
    {
        cout << a -> great << "\t";
        KLP(a -> left);
        KLP(a -> right);
    }
}

template <class T>
void Binartree<T>::KPL(Binartree<T>* a)
{
    if (a != nullptr)
    {
        cout << a -> great << "\t";
        KPL(a -> right);
        KPL(a -> left);
    }
}

template <class T>
void Binartree<T>::LPK(Binartree<T>* a)
{
    if (a != nullptr)
    {
        LPK(a -> left);
        LPK(a -> right);
        cout << a -> great << "\t";
    }
}

template <class T>
void Binartree<T>::LKP(Binartree<T>* a)
{
    if (a != nullptr)
    {
        LKP(a -> left);
        cout << a -> great << "\t";
        LKP(a -> right);
    }
}

template <class T>
void Binartree<T>::PKL(Binartree<T>* a)
{
    if (a != nullptr)
    {
        PKL(a -> right);
        cout << a -> great << "\t";
        PKL(a -> left);
    }

}

template <class T>
void Binartree<T>::PLK(Binartree<T>* a)
{
    if (a != nullptr)
    {
        PLK(a -> right);
        PLK(a -> left);
        cout << a -> great << "\t";
    }
}

template <class T>
void Binartree<T>::add(Binartree<T>*& a, T b)
{

    if (a == nullptr)
    {
        a = new Binartree<T>;
        a -> great = b;
        a -> left = a -> right = nullptr;
        return;
    }

    if (b < a -> great)
    {
        if (a -> left != nullptr) add(a -> left, b);
        else
        {
            a -> left = new Binartree<T>;
            a -> left -> left = a -> left -> right = nullptr;
            a -> left -> great = b;
        }

    }
    if (b >= a -> great)
    {
        if (a -> right != nullptr) add(a -> right, b);
        else
        {
            a -> right = new Binartree<T>;
            a -> right -> right = a -> right -> left = nullptr;
            a -> right -> great = b;
        }
    }
}

template <class T>
void Binartree<T>::print(Binartree<T>*& a) {
    if (a != nullptr)
    {

        print(a -> left);
        cout << a -> great << " __ ";
        print(a -> right);
        cout << endl;
    }
}

template <class T>
void Binartree<T>::deltree(Binartree<T>* a)
{
    if (a != nullptr)
    {
        deltree(a -> Getleft());
        deltree(a -> Getright());

        delete a;
        a = nullptr;
    }
}
#endif