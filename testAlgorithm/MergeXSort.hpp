#pragma once
#include "ISort.hpp"
#include "MergeSort.hpp"
#include "InsertSort.hpp"
#include "Constants.h"
template <typename Elem>
class MergeXSort : public MergeSort<Elem>
{
public:
	MergeXSort(int curoff = 15):_cutoff(curoff), _hit(0){}
	virtual const char * name() {return SortConstant::MERGEXSORT;}
	virtual void show(int t);
protected:
	virtual void sort(Elem arr[], int lo, int hi);
	int _cutoff;
	InsertSort<Elem> _insrt;
	int _hit;
};

template <typename Elem>
void MergeXSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo + _cutoff - 1)
	{
		_insrt.sort(arr + lo, hi - lo + 1);
		return;
	}
	int mid = lo + (hi - lo)/2;
	sort(arr, lo, mid);
	sort(arr, mid + 1, hi);

	if (less(arr[mid+1], arr[mid]))
		merge(arr, lo, mid, hi);
	else 
		_hit++;
}

template <typename Elem>
void MergeXSort<Elem>::show(int t)
{
	cout<<name()<<" average using "<< ((long double)_cmp / t) <<" compare, using "<<((long double)_exch / t)<<" exchage and hit "<<(long double)_hit / t<<" each time"<<endl;
}