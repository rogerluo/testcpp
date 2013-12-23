#pragma once
#include "ISort.hpp"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class InsertSort : public ISort<Elem>
{
public:
	virtual void sort(Elem arr[], int length);
	void show();
};

template <typename Elem>
void InsertSort::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0 && compareTo(a[j], a[j - 1]); j--)
			exch(a[j], a[j - 1]);
	}
}