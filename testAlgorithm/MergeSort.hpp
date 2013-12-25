#pragma once
#include "ISort.hpp"
#include "Constants.h"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class MergeSort : public ISort<Elem>
{
public:
	MergeSort():_arr(NULL), _length(0){}
	virtual ~MergeSort(){ if (_arr) delete[] _arr; _arr = NULL;}
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return SortConstant::MERGESORT;}
	virtual void show(int t);
protected:
	virtual void sort(Elem arr[], int lo, int hi);
	void merge(Elem arr[], int lo, int mid, int hi);
	Elem* _arr;
	int _length;
};

template <typename Elem>
void MergeSort<Elem>::sort(Elem arr[], int length)
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

template <typename Elem>
void MergeSort<Elem>::show(int t)
{
	cout<<name()<<" average using "<< ((long double)_cmp / t) <<" compare, using "<<((long double)_exch / t)<<" exchage"<<endl;
}