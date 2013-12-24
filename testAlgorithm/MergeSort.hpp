#pragma once
#include "ISort.hpp"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class MergeSort : public ISort<Elem>
{
public:
	MergeSort():_arr(NULL), _length(0){}
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return SortConstant::MERGESORT;}
private:
	void sort(Elem arr[], int lo, int hi);
	void merge(Elem arr[], int lo, int mid, int hi);
	Elem* _arr;
	int _length;
};

template <typename Elem>
void MergeSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	_length = length;
	_arr = new Elem[_length];
	sort(arr, 0, length - 1);
}

template <typename Elem>
void MergeSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo) return;
	int mid = lo + (hi - lo)/2;
	sort(arr, lo, mid);
	sort(arr, mid + 1, hi);
	merge(arr, lo, mid, hi);
}

template <typename Elem>
void MergeSort<Elem>::merge(Elem arr[], int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; ++k)
		_arr[k] = arr[k];
	for (int k = lo; k <= hi; ++k)
	{
		if (i > mid)						arr[k] = _arr[j++];
		else if (j > hi)					arr[k] = _arr[i++];
		else if (less(_arr[j], _arr[i]))	arr[k] = _arr[j++];
		else								arr[k] = _arr[i++];
	}
}