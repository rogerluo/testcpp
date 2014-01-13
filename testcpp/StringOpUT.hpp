#pragma once
#include "gtest\gtest.h"
#include "StringOp.hpp"
using namespace StringOP;
namespace StringOpUT
{
	TEST(URLReplaceUT, testNormal)
	{
		{
			char * psz = "hello world";
			char dst[256] = {0};
			memset(dst, 0, sizeof(dst));
			URLReplace(psz, dst, " #");
			EXPECT_STREQ(dst, "hello%20world");
			EXPECT_EQ(false, HasChar(dst, ' '));
			EXPECT_EQ(false, HasChar(dst, '#')); 
		}

		{
			char * psz = " helloworld ";
			char dst[256] = {0};
			memset(dst, 0, sizeof(dst));
			URLReplace(psz, dst, " #");
			EXPECT_STREQ(dst, "%20helloworld%20");
			EXPECT_EQ(false, HasChar(dst, ' '));
			EXPECT_EQ(false, HasChar(dst, '#')); 
		}

		{
			char * psz = "hello=world";
			char dst[256] = {0};
			memset(dst, 0, sizeof(dst));
			URLReplace(psz, dst, " #=");
			EXPECT_STREQ(dst, "hello%3dworld");
			EXPECT_EQ(false, HasChar(dst, ' '));
			EXPECT_EQ(false, HasChar(dst, '#')); 
			EXPECT_EQ(false, HasChar(dst, '='));
		}

		{
			char * psz = "key=hello world";
			char dst[256] = {0};
			memset(dst, 0, sizeof(dst));
			URLReplace(psz, dst, " #=");
			EXPECT_STREQ(dst, "key%3dhello%20world");
			EXPECT_EQ(false, HasChar(dst, ' '));
			EXPECT_EQ(false, HasChar(dst, '#')); 
			EXPECT_EQ(false, HasChar(dst, '='));
		}
		{
			char * psz = "hello world";
			char dst[10] = {0};
			memset(dst, 0, sizeof(dst));
			URLReplaceS(psz, dst, sizeof(dst), " #=");
			EXPECT_STREQ(dst, "hello%20w");
			EXPECT_EQ(false, HasChar(dst, ' '));
			EXPECT_EQ(false, HasChar(dst, '#')); 
		}

		{
			char * psz = "hello world";
			char dst[7] = {0};
			memset(dst, 0, sizeof(dst));
			URLReplaceS(psz, dst, sizeof(dst), " #=");
			EXPECT_STREQ(dst, "hello");
			EXPECT_EQ(false, HasChar(dst, ' '));
			EXPECT_EQ(false, HasChar(dst, '#')); 
		}
	}

	TEST(URLReplaceFinalUT, testNormal)
	{
		{
			char buf[256] = {"hello world"};
			URLReplaceFinal(buf,sizeof(buf), " #=");
			EXPECT_STREQ(buf, "hello%20world");
			EXPECT_EQ(false, HasChar(buf, ' '));
			EXPECT_EQ(false, HasChar(buf, '#')); 
		}
		{
			char buf[256] = {" hello world"};
			URLReplaceFinal(buf,sizeof(buf), " #=");
			EXPECT_STREQ(buf, "%20hello%20world");
			EXPECT_EQ(false, HasChar(buf, ' '));
			EXPECT_EQ(false, HasChar(buf, '#')); 
		}
		{
			char buf[256] = {"helloworld"};
			URLReplaceFinal(buf,sizeof(buf), " #=");
			EXPECT_STREQ(buf, "helloworld");
			EXPECT_EQ(false, HasChar(buf, ' '));
			EXPECT_EQ(false, HasChar(buf, '#')); 
		}
		{
			char buf[] = {"hello world"};
			URLReplaceFinal(buf,sizeof(buf), " #=");
			EXPECT_STREQ(buf, "hello world");
			EXPECT_EQ(true, HasChar(buf, ' '));
			EXPECT_EQ(false, HasChar(buf, '#')); 
		}
		{
			char buf[256] = {" hello   world "};
			URLReplaceFinal(buf,sizeof(buf), " #=");
			EXPECT_STREQ(buf, "%20hello%20%20%20world%20");
			EXPECT_EQ(false, HasChar(buf, ' '));
		}
	}
}