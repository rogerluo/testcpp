#include "stdafx.h"
#include "VirtualFunction.h"
#include <cstdio>

void PrintVirutalFucAddr()
{
	B1 b1(1), b2(2);
	cout << "b1对象地址：" << &b1 << endl;
	cout << "b2对象地址：" << &b2 << endl;
	cout << "b1虚函数表地址：" << (int*)(&b1) << endl;
	cout << "b2虚函数表地址：" << (int*)(&b2) << endl;
	cout << "b1虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b1) << endl;
	cout << "b2虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b2) << endl;

	typedef void (B1::*FUN)(void);
	typedef void (*VFUN)(int*);

	//FUN pfun = &B1::f1;
	//(b1.*pfun)();
	VFUN pv1 = (VFUN)*((int*)*(int*)(&b1));
	b1.v1();
	pv1((int*)&b1);
	VFUN pv2 = (VFUN)*((int*)*(int*)(&b1)+1);
	pv2((int*)&b1);
	VFUN pv3 = (VFUN)*((int*)*(int*)(&b1)+2);
	pv3((int*)&b1);
	//cout << "执行第一个虚函数：" << (b1.*pfun)() << endl;
	
	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(float): " << sizeof(float) << endl;
	cout << "sizeof(unsigned long): " << sizeof(unsigned long) << endl;
	cout << "sizeof(long): " << sizeof(long) << endl;
	cout << "sizeof(unsigned int): " << sizeof(unsigned int) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(unsigned short): " << sizeof(unsigned short) << endl;
	cout << "sizeof(short): " << sizeof(short) << endl;
}

