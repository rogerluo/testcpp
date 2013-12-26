#pragma once
#include "IRandGenerator.hpp"
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;
template <typename Elem>
class PartionOrderRandGenerator : public IRandGenerator<Elem>
{
public:
	virtual void getRandArray(Elem arr[], int length, unsigned int seed);
	virtual bool IsDistinct(Elem arr[], int length);
};

template <typename Elem>
void PartionOrderRandGenerator<Elem>::getRandArray(Elem arr[], int length, unsigned int seed)
{
	for (int i = 0; i < length; ++i)
		arr[i] = i;
	default_random_engine dre(seed);
	int lo = max((int)(length * 0.9), 0), hi = length - 1;
	for (int i = 0; i < 100; ++i)
		shuffle(arr + lo, arr + hi, dre);
}

template <typename Elem>
bool PartionOrderRandGenerator<Elem>::IsDistinct(Elem arr[], int length)
{
	return true;
}