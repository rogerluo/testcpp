// testReflectionDll2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "testReflectionDll2.h"


// ���ǵ���������һ��ʾ��
TESTREFLECTIONDLL2_API int ntestReflectionDll2=0;

// ���ǵ���������һ��ʾ����
TESTREFLECTIONDLL2_API int fntestReflectionDll2(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� testReflectionDll2.h
CtestReflectionDll2::CtestReflectionDll2()
{
	return;
}
