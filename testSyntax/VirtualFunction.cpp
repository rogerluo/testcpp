#include "stdafx.h"
#include "VirtualFunction.h"
#include <cstdio>

void PrintVirutalFucAddr()
{
	B1 b1;
	cout << "�麯�����ַ��" << (int*)(&b1) << endl;
	cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b1) << endl;
	typedef void (B1::*FUN)(void);

	FUN pfun = &B1::f1;
	(b1.*pfun)();
	//cout << "ִ�е�һ���麯����" << (b1.*pfun)() << endl;
	
	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(float): " << sizeof(float) << endl;
	cout << "sizeof(unsigned long): " << sizeof(unsigned long) << endl;
	cout << "sizeof(long): " << sizeof(long) << endl;
	cout << "sizeof(unsigned int): " << sizeof(unsigned int) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(unsigned short): " << sizeof(unsigned short) << endl;
	cout << "sizeof(short): " << sizeof(short) << endl;
}

