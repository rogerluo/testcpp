// testReflectionDll1.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "testReflectionDll1.h"


// ���ǵ���������һ��ʾ��
TESTREFLECTIONDLL1_API int ntestReflectionDll1=0;

// ���ǵ���������һ��ʾ����
TESTREFLECTIONDLL1_API int fntestReflectionDll1(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� testReflectionDll1.h
CtestReflectionDll1::CtestReflectionDll1()
{
	return;
}
