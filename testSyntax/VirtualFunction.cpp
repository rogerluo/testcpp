#include "stdafx.h"
#include "VirtualFunction.h"
#include <cstdio>

void PrintVirutalFucAddr()
{
	B1 b1(1), b2(2); D1 d1(3), d2(4);
	B1 * pd1 = &d1, * pd2 = &d2;
	cout << "b1对象地址：" << &b1 << endl;
	cout << "b2对象地址：" << &b2 << endl;
	cout << "d1对象地址：" << &d1 << endl;
	cout << "d2对象地址：" << &d2 << endl;
	cout << "pd1对象地址：" << pd1 << endl;
	cout << "pd2对象地址：" << pd2 << endl;
	cout << "b1虚函数表地址：" << (int*)*(int*)(&b1) << endl;
	cout << "b2虚函数表地址：" << (int*)*(int*)(&b2) << endl;
	cout << "d1虚函数表地址：" << (int*)*(int*)(&d1) << endl;
	cout << "d2虚函数表地址：" << (int*)*(int*)(&d2) << endl;
	cout << "pd1虚函数表地址：" << (int*)*(int*)(pd1) << endl;
	cout << "pd2虚函数表地址：" << (int*)*(int*)(pd2) << endl;
	cout << "b1虚函数表  — 第一个函数地址：" << (int*)*((int*)*(int*)(&b1) + 0) << endl;
	cout << "b2虚函数表  — 第一个函数地址：" << (int*)*((int*)*(int*)(&b2) + 0) << endl;
	cout << "d1虚函数表  — 第一个函数地址：" << (int*)*((int*)*(int*)(&d1) + 0) << endl;
	cout << "d2虚函数表  — 第一个函数地址：" << (int*)*((int*)*(int*)(&d2) + 0) << endl;
	cout << "pd1虚函数表 — 第一个函数地址：" << (int*)*((int*)*(int*)(pd1) + 0) << endl;
	cout << "pd2虚函数表 — 第一个函数地址：" << (int*)*((int*)*(int*)(pd2) + 0) << endl;
	cout << "b1虚函数表  — 第二个函数地址：" << (int*)*((int*)*(int*)(&b1) + 1) << endl;
	cout << "b2虚函数表  — 第二个函数地址：" << (int*)*((int*)*(int*)(&b2) + 1) << endl;
	cout << "d1虚函数表  — 第二个函数地址：" << (int*)*((int*)*(int*)(&d1) + 1) << endl;
	cout << "d2虚函数表  — 第二个函数地址：" << (int*)*((int*)*(int*)(&d2) + 1) << endl;
	cout << "pd1虚函数表 — 第二个函数地址：" << (int*)*((int*)*(int*)(pd1) + 1) << endl;
	cout << "pd2虚函数表 — 第二个函数地址：" << (int*)*((int*)*(int*)(pd2) + 1) << endl;

	
	typedef void (*VFUN)(void);

	cout << "b1 与 d1 执行第一个函数地址" << endl;
	VFUN pv1 = (VFUN)*((int*)*(int*)(&b1));
	VFUN pv2 = (VFUN)*((int*)*(int*)(&d1));
	pv1();
	pv2();
	cout << "b1 与 d1 执行第二个函数地址" << endl;
	pv1 = (VFUN)*((int*)*(int*)(&b1) + 1);
	pv2 = (VFUN)*((int*)*(int*)(&d1) + 1);
	pv1();
	pv2();
	cout << "b1 与 d1 执行第四个函数地址" << endl;
	pv1 = (VFUN)*((int*)*(int*)(&b1) + 3);
	pv2 = (VFUN)*((int*)*(int*)(&d1) + 3);
	//pv1(); error
	//pv2(); error
	typedef void (*VFUN2)(B1*);
	VFUN2 pv3 = (VFUN2)*((int*)*(int*)(&b1) + 3);
	VFUN2 pv4 = (VFUN2)*((int*)*(int*)(&d1) + 3);
	pv3(&b1);
	pv4(&d1);
	
	
	cout << "sizeof(int*): " << sizeof(int*) << endl;
	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(float): " << sizeof(float) << endl;
	cout << "sizeof(unsigned long): " << sizeof(unsigned long) << endl;
	cout << "sizeof(long): " << sizeof(long) << endl;
	cout << "sizeof(unsigned int): " << sizeof(unsigned int) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(unsigned short): " << sizeof(unsigned short) << endl;
	cout << "sizeof(short): " << sizeof(short) << endl;
}

