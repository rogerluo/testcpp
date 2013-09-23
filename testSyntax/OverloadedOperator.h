#pragma once
#include <string>

namespace OverLoadOperator
{
	void rename(char ** ppdst, const char * src);
	struct Person
	{
		char*			szName;
		std::string		strName;
		int				Age;
		Person(const char * psz, int age);
		~Person();
		char ** operator&();
	};

	class OverloadedOperator
	{
	public:
		OverloadedOperator();
		~OverloadedOperator();
		void TestAddressOperator();
	};
}
