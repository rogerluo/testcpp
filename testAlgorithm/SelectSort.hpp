#pragma once
#include "ISort.hpp"
#include "Constants.h"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class SelectSort : public ISort<Elem>
{
public:
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return SortConstant::SELECTSORT;}
	virtual void show(int t);
};

template <typename Elem>
void SelectSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; ++j)
			if (less(arr[j], arr[min])) min = j;
		exch(arr, i, min);
	}
}

template <typename Elem>
void SelectSort<Elem>::show(int t)
{
	cout<<name()<<" average using "<< ((long double)_cmp / t) <<" compare, using "<<((long double)_exch / t)<<" exchage"<<endl;
}