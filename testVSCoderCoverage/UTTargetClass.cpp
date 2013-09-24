#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "testTargetClass.h"
#include "../testVSCodeCoverageDLL/testTargetClass.h"
#pragma comment (lib, "testVSCodeCoverageDLL.lib")

namespace testVSCoderCoverage
{
	TEST_CLASS(UTTargetClass)
	{
	public:
		
		TEST_METHOD(TestAddLocal)
		{
			testTargetClass tgt;
			Assert::AreEqual(2, tgt.Add(1, 1));
		}

		TEST_METHOD(TestAddExternal)
		{
			testVSCoderCoverageDLL::testTargetClass tgt;
			Assert::AreEqual(2, tgt.Add(1, 1));
		}
	};
}