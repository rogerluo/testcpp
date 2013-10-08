#pragma once
#include <iostream>
using namespace std;
class B1
{
public:
	virtual ~B1(){ cout << __FUNCTION__ <<endl; }
    int x;
    virtual void v1(){ cout << "B1::v1" << endl; }
    void f1(){cout << "B1::f1" << endl; }
};

class B2
{
public:
    int y;
    virtual void v2(){ cout << "B2::v2" << endl; }
    void f2(){ cout << "B2::f2" << endl; }
};

class B3
{
public:
    int z;
    virtual void v3(){ cout << "B3::v3" << endl; }
    void f3(){ cout << "B3::f3" << endl; }
};

class D : public B1, public B2, public B3
{
public:
    int a;
    void v3(){ cout << "D::v3" << endl; }
    virtual void vD(){ cout << "D::vD" << endl; }
};


