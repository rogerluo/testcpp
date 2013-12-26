#pragma once
#include <string>
#include <functional>
using namespace std;
template <typename T>
//struct lessNoCaseCompare : public binary_function<T,T,bool>
//{
//	bool operator()(const T& lhs, const T& rhs) const 
//	{
//		return _wcsicmp(lhs.c_str(), rhs.c_str()) < 0 ? 1 : 0;   
//	}
//};
template <typename T>
std::function<bool(const T&, const T&) lessNoCaseCompare(){
	return [](const T& lhs, const T&rhs)->bool{
		return lhs == rhs;   
	}
}
//#ifdef _MSC_VER
//#	if _MSC_VER > 1600
//		template <typename T>
//		function<bool(const T&, const T&)> lessNoCaseCompare = [](const T& lhs, const T& rhs)->bool{
//			return _wcsicmp(lhs.c_str(), rhs.c_str()) < 0 ? 1 : 0;   
//		}
//#	else
//		template <typename T>
//		struct lessNoCaseCompare : public binary_function<T,T,bool>
//		{
//			bool operator()(const T& lhs, const T& rhs) const 
//			{
//				return _wcsicmp(lhs.c_str(), rhs.c_str()) < 0 ? 1 : 0;   
//			}
//		};
//#	endif
//#endif
//