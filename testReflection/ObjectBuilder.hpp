#pragma once
#include "Reflection\IObject.hpp"
#include "util\stringext.hpp"
#include <string>
#include <map>
using namespace std;
namespace Reflection
{
	class ObjectBuilder
	{
	public:
		typedef IObject* (*CreateObject)(const wstring& name);
		typedef map<wstring, CreateObject, lessNoCaseCompare<wstring> > objmap;
	};
}