#include "stdafx.h"
#include "VirtualFunction.h"
#include <cstdio>

void PrintVirutalFucAddr()
{
	B1 b1;
	cout << "�麯�����ַ��" << (int*)(&b1) << endl;
	cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b1) << endl;
	typedef void (B1::*FUN)(void);
	FUN pvfun = (int*)(*(int*)(&b1));
	FUN pfun = &B1::f1;
	(b1.*pfun)();
	//cout << "ִ�е�һ���麯����" << (b1.*pfun)() << endl;
	
	
}

