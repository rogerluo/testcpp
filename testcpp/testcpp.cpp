#include "stdafx.h"
#include "gtest\gtest.h"
#include "AmazonUT.hpp"
#include "StringOpUT.hpp"
#include "IOOperationUT.h"
#include <iostream>
using namespace std;
#if defined _DEBUG || defined DEBUG
#pragma comment (lib, "gtestd.lib")
#else
#pragma comment (lib, "gtest.lib")
#endif

int MyAdd(int lhs, int rhs)
{
	cout<<__FUNCSIG__<<endl;
	return lhs + rhs;
}
template <typename T1, typename T2>
auto MyAdd(T1 x, T2 y) -> decltype (x+y)
{
	cout<<__FUNCSIG__<<endl;
	return x + y;
}
TEST(MyAddTest, TestNormal)
{
	EXPECT_DOUBLE_EQ(2.0, MyAdd(1, 1.0));// EXPECT_DOUBLE_EQ(2.0, MyAdd<int, double>(1, 1.0)); wrong
}

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

