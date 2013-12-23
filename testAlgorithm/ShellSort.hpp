#pragma once
#include "ISort.hpp"
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Elem>
class ShellSort : public ISort<Elem>
{
public:
	virtual void sort(Elem arr[], int length);
	virtual const char * name() {return "ShellSort";}
	void show();
};

template <typename Elem>
void ShellSort<Elem>::sort(Elem arr[], int length)
{
	assert(arr != NULL && length > 0);
	int h = 1;
	while (h < length/3) h = 3*h + 1;
	while (h>=1)
	{
		for (int i = h; i < length; ++i)
		{
			for (int j = i; j >= h && less(arr[j], arr[j - h]); j -= h)
				exch(arr, j, j-h);
		}
		h = h / 3;
	}
}