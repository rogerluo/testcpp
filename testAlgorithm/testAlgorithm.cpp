// testAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "SortAlgorithm.h"


void TestIntQuickSort()
{
	int v[20] = {};
	std::default_random_engine dre;
	std::uniform_int_distribution<int> uid(1, 2000);

#define NUMINVECTOR 2000
	//std::vector<int> v1, v2;
	//v1.reserve(NUMINVECTOR);
	//v2.reserve(NUMINVECTOR);
	//std::clock_t s1 = 0, s2 = 0, tmp;
	//for (int i = 2; i <= NUMINVECTOR; ++i)
	//{
	//	v1.clear(); v2.clear();
	//	for (int j = 0; j < i; ++j)
	//	{
	//		int tmp = uid(dre);
	//		v1.push_back(tmp);
	//		v2.push_back(tmp);
	//	}
	//	tmp = std::clock();
	//	qs(v1, 0, v1.size() - 1);
	//	s1 += (std::clock() - tmp);
	//	if (!std::is_sorted(v1.begin(), v1.end())) 
	//	{
	//		for (int elem : v1) std::cout<<elem<<" ";
	//		std::cout<<std::endl;
	//		std::cout<<"Not sorted"<<std::endl;
	//		break;
	//	}
	//	
	//	tmp = std::clock();
	//	std::sort(v2.begin(), v2.end());
	//	s2 += (std::clock() - tmp);
	//	if (!std::is_sorted(v2.begin(), v2.end())) 
	//	{
	//		for (int elem : v2) std::cout<<elem<<" ";
	//		std::cout<<std::endl;
	//		std::cout<<"Not sorted"<<std::endl;
	//		break;
	//	}

	//}
	//std::cout<<"Using "<<s1<<" Miniseconds"<<std::endl;
	//std::cout<<"Using "<<s2<<" Miniseconds"<<std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SortAlgorithm sortIst;
	//sortIst.CompareNth(10, 1000);
	TestIntQuickSort();
	return 0;
}

