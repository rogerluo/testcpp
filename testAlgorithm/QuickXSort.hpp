#pragma once
#include "ISort.hpp"
#include "QuickSort.hpp"
#include "InsertSort.hpp"
#include "Constants.h"
template <typename Elem>
class QuickXSort : public QuickSort<Elem>
{
public:
	QuickXSort(int cutoff = 15):_cutoff(cutoff){}
	virtual void show(int t);
protected:
	virtual void sort(Elem arr[], int lo, int hi);
	int _cutoff;
	InsertSort<Elem> _insr;
};

template <typename Elem>
void QuickXSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo + _cutoff) {
		_insr.sort(arr + lo, hi - lo + 1);
		return;
	}
	int j = partition(arr, lo, hi);
	sort(arr, lo, j - 1);
	sort(arr, j + 1, hi);
}

template <typename Elem>
void QuickXSort<Elem>::show(int t)
{
	cout<<name()<<" average using "<< ((long double)_cmp / t) <<" compare, using "<<((long double)_exch / t)<<" exchage"<<endl;
}