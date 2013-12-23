// testAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "SortAlgorithm.h"
#include "ISort.hpp"
#include "InsertSort.hpp"
#include "SelectSort.hpp"
#include "ShellSort.hpp"
#include "QuickSort.hpp"


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

template <typename T>
void getRandArray(T* arr, int length)
{
	std::default_random_engine generator((unsigned int)time(0));
	if (typeid(T) == typeid(short) ||
		typeid(T) == typeid(int) ||
		typeid(T) == typeid(long) ||
		typeid(T) == typeid(long long))
	{
		std::uniform_int_distribution<int> distribution(0, length);
		for (int i = 0; i < length; ++i)
			arr[i] = distribution(generator);
	}
	else if(typeid(T) == typeid(float) ||
			typeid(T) == typeid(double) ||
			typeid(T) == typeid(long double))
	{
		std::uniform_real_distribution<double> distribution(0.0,1.0);
		for (int i = 0; i < length; ++i)
			arr[i] = distribution(generator) * length;
	}
}

template <typename T>
long RunSingle(ISort<T>* pInst, T * arr, int length)
{
	getRandArray(arr, length);
	clock_t sw = clock();
	pInst->sort(arr, length);
	sw = clock() - sw;
	if (!pInst->IsSorted(arr, length))
		cout<<"Failed to sort"<<endl;
	return sw;
}

template <typename T>
void Run(ISort<T>* pInst, int t, int n)
{
	long tot = 0;
	T * arr = new T[n];
	for (int i = 0; i < t; ++i)
	{
		tot += RunSingle(pInst, arr, n);
	}
	delete[] arr;
	cout<<pInst->name()<<" average using "<< ((double)tot / t) <<" miniseconds to sort "<<n<<" number"<<endl;
	cout<<pInst->name()<<" average using "<< ((long double)pInst->CmpTime() / t) <<" compare, using "<<((long double)pInst->ExchTime() / t)<<" exchage"<<endl;
	pInst->Reset();
}

template <typename T>
void Compare(int t, int n)
{
	ISort<T> * pInst = NULL;
	pInst = new QuickSort<T>();
	Run(pInst, t, n);
	delete pInst;
	pInst = new ShellSort<T>();
	Run(pInst, t, n);
	delete pInst;
	//pInst = new InsertSort<T>();
	//Run(pInst, t, n);
	//delete pInst;
	//pInst = new SelectSort<T>();
	//Run(pInst, t, n);
	//delete pInst;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Compare<int>(100, 100);
	Compare<int>(100, 1000);
	Compare<int>(100, 10000);
	Compare<int>(10, 100000);
	Compare<int>(10, 1000000);
	Compare<int>(5, 10000000);
	cout<<"=========="<<endl;
	Compare<double>(100, 100);
	Compare<double>(100, 1000);
	Compare<double>(100, 10000);
	Compare<double>(10, 100000);
	Compare<double>(10, 1000000);
	Compare<double>(5, 10000000);
	
	return 0;
}

