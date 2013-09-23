#include "stdafx.h"
#include "OverloadedOperator.h"
#include <iostream>
#include <cstdio>
#include <cassert>

namespace OverLoadOperator
{
	void rename(char ** ppdst, const char * src)
	{
		assert(*ppdst); assert(src);
		if (*ppdst) delete[](*ppdst);
		int len = strlen(src);
		*ppdst = new char[len + 1]{};
		strcpy(*ppdst, src);
	}


	Person::Person(const char * psz, int age)
		: szName(new char[strlen(psz) + 1]{}), strName(psz), Age(age)
	{
		strcpy(szName, psz);
	}


	Person::~Person()
	{
		if (szName) delete[] szName;
	}


	char ** Person::operator&() { return &szName; }


	OverloadedOperator::OverloadedOperator()
	{
	}


	OverloadedOperator::~OverloadedOperator()
	{
	}


	void OverloadedOperator::TestAddressOperator()
	{
		Person p("roger luo", 25);
		char ** ppsz = &p;
		std::cout << *ppsz << std::endl;
		// rename
		rename(&p, "dingjia.luo");
		std::cout << p.szName << std::endl;
	}
}