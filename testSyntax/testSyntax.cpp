// testSyntax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "OverloadedOperator.h"
//#include "VirtualFunction.h"
//#include "FunctionPoint.h"

//class Base
//{
//public:
//	Base() {cout << "Base" << endl;}
//	~Base() {cout << "~Base" << endl;}
//};

int Fun1(int i)
{
	int j = i;
	return ++j;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Test Overloaded Operator 
	//OverLoadOperator::OverloadedOperator overloadOperator;
	//overloadOperator.TestAddressOperator();

//	PrintVirutalFucAddr();	
	//RunFunctionPoint();
	//Base * p = new Base;
	//free((void*)p);
	//p = (Base*)malloc(sizeof(Base));
	//delete p;

	int i = Fun1(2);
	return 0;
}

