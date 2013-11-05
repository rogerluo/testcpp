#include "stdafx.h"
#include "FunctionPoint.h"


FunctionPoint::FunctionPoint(void)
{
}


FunctionPoint::~FunctionPoint(void)
{
}


void gFunc(int num)
{
	cout << "gFunc: " << num << endl;
}


void FunctionPoint::sFunc(int num)
{
	cout << "sFunc: " << num << endl;
}

void FunctionPoint::Func(int num)
{
	cout << "Func: " << num << endl;
}


void FunctionPoint::vFunc(int num)
{
	cout << "vFunc: " << num << endl;
}


void FunctionPointD::vFunc(int num)
{
	cout << "vFuncD: " << num << endl;
}


void RunFunctionPoint()
{
	typedef void (*pFun) (int);
	pFun p1 = gFunc;
	p1(1);

	p1 = FunctionPoint::sFunc;
	p1(2);

	typedef void (FunctionPoint::*pFunMem) (int);
	pFunMem p2 = &FunctionPoint::Func;

	FunctionPoint inst1;
	(inst1.*p2)(3);

	FunctionPoint * pinst2 = new FunctionPoint;
	(pinst2->*p2)(4);
	delete pinst2;

	p2 = &FunctionPoint::vFunc;
	pinst2 = new FunctionPointD;
	(pinst2->*p2)(5);
	delete pinst2;
}