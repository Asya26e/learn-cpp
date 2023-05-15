// prak_15(6).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class A
{
public:
    virtual int f()
    {
        cout << "A";
        return 1;
    }
    A() 
    { 
        cout << "Constructor A" << endl; 
    }
};


class B : public virtual A
{
public:
    int f() override
    {
        cout << "B";
        return 2;
    }
    B()
    {
        cout << "Constructor B" << endl;
    }
};

class C : public virtual A
{
public:
    int f() override
    {
        cout << "C";
        return 3;
    }
    C()
    {
        cout << "Constructor C" << endl;
    }
};

class D : public virtual B, public virtual C
{
public:
    int f() override
    {
        cout << "C";
        return 4;
    }
    D()
    {
        cout << "Constructor C" << endl;
    }
};


class E :public virtual C, public virtual D
{
public:
    int f() override
    {
        cout << "E";
        return 5;
    }
    E()
    {
        cout << "Constructor E" << endl;
    }
};


class F :public virtual B, public virtual D, public virtual E
{
public:
    int f() override
    {
        cout << "F";
        return 6;
    }
    F()
    {
        cout << "Constructor F" << endl;
    }
};


int main() {
    F object;
    object.f();
    return 0;
}