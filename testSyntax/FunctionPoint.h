#pragma once
#include <iostream>
using namespace std;
void gFunc(int num);

class FunctionPoint
{
public:
	FunctionPoint(void);
	~FunctionPoint(void);
	static void sFunc(int num);
	void Func(int num);
	virtual void vFunc(int num);
};

class FunctionPointD : public FunctionPoint
{
public:
	virtual void vFunc(int num);
};

void RunFunctionPoint();