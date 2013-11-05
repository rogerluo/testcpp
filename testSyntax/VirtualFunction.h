#pragma once
#include <iostream>
using namespace std;
class B1
{
public:
	B1(int i):x(i){}
	//~B1(){ cout << __FUNCTION__ <<endl; }
    int x;
	virtual void g1(){ cout << "B1::g1" << endl; }
	virtual void g2(){ cout << "B1::g2" << endl; }
	virtual void g3(){ cout << "B1::g3" << endl; }
    virtual void v1(){ cout << "B1::v1 with " << x << endl; }
	virtual void v2(){ cout << "B1::v2 with " << x << endl; }
	virtual void v3(){ cout << "B1::v3 with " << x << endl; }
};

class D1 : public B1
{
public:
	D1(int i):B1(i){}
	virtual void g1(){ cout << "D1::g1" << endl; }
    virtual void v1(){ cout << "D1::v1 with " << x << endl; }
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

void PrintVirutalFucAddr();
