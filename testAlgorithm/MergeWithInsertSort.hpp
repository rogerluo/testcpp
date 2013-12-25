#pragma once
#include "ISort.hpp"
#include "MergeSort.hpp"
#include "InsertSort.hpp"
#include "Constants.h"
template <typename Elem>
class MergeWithInsertSort : public MergeSort<Elem>
{
public:
	MergeWithInsertSort(int sublen = 15):_sublen(sublen){}
	virtual const char * name() {return SortConstant::MERGEWITHINSERTSORT;}
protected:
	virtual void sort(Elem arr[], int lo, int hi);
	int _sublen;
	InsertSort<Elem> _insrt;
};

template <typename Elem>
void MergeWithInsertSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo + _sublen - 1)
	{
		_insrt.sort(arr + lo, hi - lo + 1);
		return;
	}
	int mid = lo + (hi - lo)/2;
	sort(arr, lo, mid);
	sort(arr, mid + 1, hi);
	merge(arr, lo, mid, hi);
}
