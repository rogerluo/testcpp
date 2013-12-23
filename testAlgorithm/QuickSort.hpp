#pragma once
#include "ISort.hpp"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class QuickSort : public ISort<Elem>
{
public:
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return "QuickSort";}
	void show();
private:
	void sort(Elem arr[], int lo, int hi);
	int partition(Elem arr[], int lo, int hi);
};

template <typename Elem>
void QuickSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	sort(arr, 0, length - 1);
}

template <typename Elem>
void QuickSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo) return;
	int j = partition(arr, lo, hi);
	sort(arr, lo, j - 1);
	sort(arr, j + 1, hi);
}

template <typename Elem>
int QuickSort<Elem>::partition(Elem arr[], int lo, int hi)
{
	int i = lo, j = hi + 1;
	Elem v(arr[lo]);
	while (true)
	{
		while (less(arr[++i], v)) if (i==hi) break;
		while (less(v, arr[--j])) if (j==lo) break;
		if (i>=j) break;
		exch(arr, i, j);
	}
	exch(arr, lo, j);
	return j;
}