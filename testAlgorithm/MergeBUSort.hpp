#pragma once
#include "ISort.hpp"
#include "Constants.h"
#include "MergeSort.hpp"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class MergeBUSort : public MergeSort<Elem>
{
public:
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return SortConstant::MERGEBUSORT;}
};

template <typename Elem>
void MergeBUSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	if (_length < length)
	{
		_length = length;
		if (_arr) 
		{
			delete[] _arr;
			_arr = NULL;
		}
		_arr = new Elem[_length];
	}
	if (_arr)
	{
		int sz = 1, t = 1;
		while (t < length)
		{
			sz = t;
			t = sz<<1;
			int  lo = 0;
			while (lo + t < length)
			{
				merge(arr, lo, lo + sz - 1, lo + t - 1 );
				lo += t;
			}
			if (lo + sz < length)
			{
				merge(arr, lo, lo + sz - 1, length - 1);
			}
		}
	}
}
