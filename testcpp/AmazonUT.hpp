#pragma once
#include "gtest\gtest.h"
#include "Amazon.hpp"
#include <random>
using namespace std;

TEST(StackTest, InLenghtEqOutLength)
{
	char in1[] = {"1,2,3,4"}, out1[] = {"4,3,2,1"};
	char * ret1 = Amazon::RunUT2(in1, out1);
	EXPECT_STREQ("push1|push2|push3|push4|pop4|pop3|pop2|pop1", ret1);
	free(ret1);

	char in2[] = {"1,2,3,4"}, out2[] = {"1,2,3,4"};
	char * ret2 = Amazon::RunUT2(in2, out2);
	EXPECT_STREQ("push1|pop1|push2|pop2|push3|pop3|push4|pop4", ret2);
	free(ret2);	
}

TEST(StackTest, InLenghtGtOutLength)
{
	{
		char in[] = {"1,2,3,4,5,6"}, out[] = {"1,2,3,4"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ("push1|pop1|push2|pop2|push3|pop3|push4|pop4|push5|push6", ret);
		free(ret);
	}

	{
		char in[] = {"1,2,3,4,5,6"}, out[] = {"4,3,2,1"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ("push1|push2|push3|push4|pop4|pop3|pop2|pop1|push5|push6", ret);
		free(ret);
	}

	{
		char in[] = {"1,2,3,4,5,6"}, out[] = {"3,4,2,1"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ("push1|push2|push3|pop3|push4|pop4|pop2|pop1|push5|push6", ret);
		free(ret);
	}
}

TEST(StackTest, InLenghtLtOutLength)
{
	{
		char in[] = {"1,2,3,4"}, out[] = {"1,2,3,4,1,2"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ(NULL, ret);
		free(ret);
	}

	{
		char in[] = {"1,2,3,4"}, out[] = {"4,3,2,1,4,3"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ(NULL, ret);
		free(ret);
	}
}

TEST(StackTest, InMult)
{
	{
		char in[] = {"1,1,2,3,4"}, out[] = {"1,2,3,4"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ("push1|pop1|push1|push2|pop2|push3|pop3|push4|pop4", ret);
		free(ret);
	}
	
	{
		char in[] = {"1,1,3,2,3,4"}, out[] = {"1,2,3,4"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ("push1|pop1|push1|push3|push2|pop2|pop3|push3|push4|pop4", ret);
		free(ret);
	}

	{
		char in[] = {"1,1,2,1,3,1"}, out[] = {"1,3,1,2,1,1"};
		char * ret = Amazon::RunUT2(in, out);
		EXPECT_STREQ("push1|pop1|push1|push2|push1|push3|pop3|pop1|pop2|pop1|push1|pop1", ret);
		free(ret);
	}
}

TEST(DifferTest, DifferTestNormal)
{
	{
		char in[] = {"Hadoop in practice"}, out[] = {"Hadoop in practice"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(0, ret);
	}

	{
		char in[] = {"Hadoop in practice"}, out[] = {"practice in Hadoop"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(0, ret);
	}

	{
		char in[] = {"Hadoop in practice"}, out[] = {"Hadoop operations"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(2, ret);
	}

	{
		char in[] = {"practice in Hadoop"}, out[] = {"Hadoop operations"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(2, ret);
	}
	
	{
		char in[] = {"Hadoop cookbook"}, out[] = {"Hadoop operations"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(1, ret);
	}

	{
		char in[] = {"Hadoop cookbook"}, out[] = {"Hadoop in operations"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(2, ret);
	}

	{
		char in[] = {"Ruby in action"}, out[] = {"Hadoop operations"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(3, ret);
	}

	{
		char in[] = {"Kindle Fire HD Tablet"}, out[] = {"Kindle Fire HD 8.9\" 4G LTE Wireless Tablet"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(4, ret);
	}

		{
		char in[] = {"Kindle Fire HD Tablet Roger"}, out[] = {"Kindle Fire HD 8.9\" 4G LTE Wireless Tablet"};
		int ret = Amazon::differ(in, out);
		EXPECT_EQ(4, ret);
	}
}

TEST(MMChessTest, MMChessTest1)
{
	using namespace std;
	{
		int n[] = {1,2,1,2};
		vector<int> Nscores(n, n + sizeof(n)/sizeof(int));
		int m[] = {1,2};
		vector<int> Mnumbers(m, m+ sizeof(m)/sizeof(int));
		EXPECT_EQ(5, Amazon::MMchess(Nscores, Mnumbers));
	}

	{
		int n[] = {1,2,1,2,1};
		vector<int> Nscores(n, n + sizeof(n)/sizeof(int));
		int m[] = {1,2,1};
		vector<int> Mnumbers(m, m+ sizeof(m)/sizeof(int));
		EXPECT_EQ(6, Amazon::MMchess(Nscores, Mnumbers));
	}
}

TEST(GetMaxLineTest, GetMaxLineNormal)
{
	{
		int v[5][5] = {0};
		std::srand(time(NULL));
		cout<<"random chess board:"<<endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				v[i][j] = std::rand() % 3;
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
		int val = Amazon::GetMaxLine(v, 5, 5);
		cout<<"the max value in line is:"<<val<<endl;
	}
}