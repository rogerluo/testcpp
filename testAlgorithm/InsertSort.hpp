#pragma once
#include "ISort.hpp"
#include "Constants.h"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class InsertSort : public ISort<Elem>
{
public:
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return SortConstant::INSERTSORT;}
	virtual void show(int t);
};

template <typename Elem>
void InsertSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	for (int i = 1; i < length; ++i)
	{
		for (int j = i; j > 0 && less(arr[j], arr[j - 1]); --j)
			exch(arr, j, j-1);
	}
}

template <typename Elem>
void InsertSort<Elem>::show(int t)
{
	cout<<name()<<" average using "<< ((long double)_cmp / t) <<" compare, using "<<((long double)_exch / t)<<" exchage"<<endl;
}