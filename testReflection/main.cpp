#include "ObjectBuilder.hpp"
template <typename T>
struct Value
{
	T val;
};
int main()
{
	template<typename T>
	auto f = [](Value<T> t){
		int i = 0;
		++i;
	};
	return 0;
}