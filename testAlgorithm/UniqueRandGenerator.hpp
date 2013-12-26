#pragma once
#include "IRandGenerator.hpp"
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;
template <typename Elem>
class UniqueRandGenerator : public IRandGenerator<Elem>
{
public:
	virtual void getRandArray(Elem arr[], int length, unsigned int seed);
	virtual bool IsDistinct(Elem arr[], int length);
};

template <typename Elem>
void UniqueRandGenerator<Elem>::getRandArray(Elem arr[], int length, unsigned int seed)
{
	for (int i = 0; i < length; ++i)
		arr[i] = i;
	default_random_engine dre(seed);
	for (int i = 0; i < 100; ++i)
		shuffle(arr, arr + length - 1, dre);
}

template <typename Elem>
bool UniqueRandGenerator<Elem>::IsDistinct(Elem arr[], int length)
{
	return true;
}