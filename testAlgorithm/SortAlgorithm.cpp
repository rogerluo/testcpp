#include "stdafx.h"
#include "SortAlgorithm.h"

#include <algorithm>
#include <iostream>
// for random data prepare
#include <random>


SortAlgorithm::SortAlgorithm()
{
}


SortAlgorithm::~SortAlgorithm()
{
}


void SortAlgorithm::PrepareRandomVector(std::vector<int>& v, int min, int max, int len)
{
	v.clear(); v.reserve(len);

	std::default_random_engine dre; //mt19937
	std::uniform_int_distribution<int> di(min, max);
	
	for (int i = 0; i < len; ++i) v.push_back(di(dre));

	for (auto elem : v) std::cout << elem << " ";
	std::cout << std::endl;
}


void SortAlgorithm::CompareNth(int nth, int len)
{
	if (nth > len) nth = len;

	std::vector<int> v;
	PrepareRandomVector(v, 0, 10000, len);

	std::nth_element(v.begin(), v.begin() + nth, v.end());

	for (int i = 0; i < nth; i++) std::cout << v[i] << std::endl;
}