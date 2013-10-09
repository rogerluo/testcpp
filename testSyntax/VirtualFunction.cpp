#include "stdafx.h"
#include "VirtualFunction.h"
#include <cstdio>

void PrintVirutalFucAddr()
{
	B1 b1;
	cout << "虚函数表地址：" << (int*)(&b1) << endl;
	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b1) << endl;
	typedef void (B1::*FUN)(void);
	FUN pvfun = (int*)(*(int*)(&b1));
	FUN pfun = &B1::f1;
	(b1.*pfun)();
	//cout << "执行第一个虚函数：" << (b1.*pfun)() << endl;
	
	
}

