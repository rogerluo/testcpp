// testReflectionDll2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "testReflectionDll2.h"


// 这是导出变量的一个示例
TESTREFLECTIONDLL2_API int ntestReflectionDll2=0;

// 这是导出函数的一个示例。
TESTREFLECTIONDLL2_API int fntestReflectionDll2(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 testReflectionDll2.h
CtestReflectionDll2::CtestReflectionDll2()
{
	return;
}
