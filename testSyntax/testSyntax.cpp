// testSyntax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OverloadedOperator.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// Test Overloaded Operator 
	OverLoadOperator::OverloadedOperator overloadOperator;
	overloadOperator.TestAddressOperator();
	return 0;
}

