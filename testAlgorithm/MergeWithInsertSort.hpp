#pragma once
#include "ISort.hpp"
#include "InsertSort.hpp"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class MergeWithInsertSort : public ISort<Elem>
{
public:
	MergeWithInsertSort(int sublen = 15):_sublen(sublen){}
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return SortConstant::MERGEWITHINSERTSORT;}
private:
	void sort(Elem arr[], int lo, int hi);
	void merge(Elem arr[], int lo, int mid, int hi);
	int _sublen;
	InsertSort<Elem> _insrt;
};

template <typename Elem>
void MergeWithInsertSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	sort(arr, 0, length - 1);
}

template <typename Elem>
void MergeWithInsertSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo + _sublen << 1) return;
	int mid = lo + _sublen;
	sort(arr, lo, mid);
	sort(arr, mid + 1, hi);
	merge(arr, lo, mid, hi);
}

template <typename Elem>
void MergeWithInsertSort<Elem>::merge(Elem arr[], int lo, int mid, int hi)
{
	_insrt.sort(arr + lo, hi - lo);
}