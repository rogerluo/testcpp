#pragma once
#include "ISort.hpp"
#include "Constants.h"
#include "QuickSort.hpp"
template <typename Elem>
class DijkstraSort : public QuickSort<Elem>
{
public:
	virtual const char * name() {return SortConstant::DIJKSTRASORT;}
protected:
	virtual void sort(Elem arr[], int lo, int hi);
	int compareTo(const Elem&, const Elem&);
};

template <typename Elem>
void DijkstraSort<Elem>::sort(Elem arr[], int lo, int hi)
{
	if (hi <= lo) return;
	int lt = lo, i = lo + 1, gt = hi;
	Elem v(arr[lo]);
	while (i <= gt)
	{
		int cmp = compareTo(arr[i], v);
		if (cmp < 0) exch(arr, lt++, i++);
		else if (cmp > 0) exch(arr, i, gt--);
		else i++;
	}
	sort(arr, lo, lt - 1);
	sort(arr, gt + 1, hi);
}

template <typename Elem>
int DijkstraSort<Elem>::compareTo(const Elem& lhs, const Elem& rhs)
{
	_cmp++;
	if (lhs < rhs) return -1;
	else if (lhs == rhs) return 0;
	else return 1;
}
