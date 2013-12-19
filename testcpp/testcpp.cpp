// testcpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
#define SHOW_FUNC std::cout<<__FUNCSIG__<<std::endl;

void noMoreMemory()
{
	cerr << "Unable to satisfy request for memory\n";
	abort();
}

class X
{
public:
	static new_handler set_new_handler(new_handler p);
	 void * operator new(size_t s);
private:
	static new_handler _cur;
	int _i[500000000];
};
new_handler X::_cur;// 0 or NULL by default
new_handler X::set_new_handler(new_handler p)
{
	SHOW_FUNC
	new_handler old = _cur;
	_cur = p;
	return old;
}
namespace Other
{
	void * operator new (size_t s)
	{
		void *p;
		try
		{
			p = ::operator new(s);
		}catch (::bad_alloc&){
			throw;
		}
		return p;
	}
}
void* X::operator new(size_t s)
{
	new_handler glob = ::set_new_handler(_cur);// register X::NoMoreMemory
	void * p = NULL;
	try
	{
		p = Other::operator new(s);
	}
	catch(std::bad_alloc&)
	{
		::set_new_handler(glob);
		throw;
	}
	::set_new_handler(glob);
	return p;
}

class Base
{
public:
	virtual void foo(int i = 1){		//{2}
		SHOW_FUNC
		cout<<i<<endl;
	}
	virtual ~Base(){
		SHOW_FUNC
	}
};
class Derived : public Base
{
public:
	~Derived(){
		SHOW_FUNC
	}
	virtual void foo(int i = 2){		//{3}
		SHOW_FUNC
		cout<<i<<endl;
	}
	virtual void foo(double d){		//{4}
		SHOW_FUNC;
	}
};


int main()
{
	Base *pb = new Derived;
	pb->foo();
	Derived *pd = dynamic_cast<Derived*>(pb);
	pd->foo();
	delete pb;
	//char mm[sizeof(int)] = {1, 0, 0, 0};
	//XX* p = new((void*)mm) XX;
	//p->foo();

	/*X::set_new_handler(noMoreMemory);
	X * p = new X;
	try
	{
		X *p = new X;
	}
	catch (bad_alloc& ba)
	{
		cout<<"bad allock"<<endl;
	}
	catch (...)
	{
		cout<<"any error"<<endl;
	}*/
	return 0;
}