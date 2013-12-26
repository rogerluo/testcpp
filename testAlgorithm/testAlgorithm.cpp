// testAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
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
#include "MergeSort.hpp"
#include "MergeBUSort.hpp"
#include "MergeWithInsertSort.hpp"
#include "MergeXSort.hpp"
#include "QuickSort.hpp"
#include "QuickXSort.hpp"
#include "DijkstraSort.hpp"

#include "IRandGenerator.hpp"
#include "UniqueRandGenerator.hpp"
#include "PartionOrderRandGenerator.hpp"

template <typename T>
void getRandArray(T* arr, int length, unsigned int seed)
{
	std::default_random_engine generator(seed);
	if (typeid(T) == typeid(short) ||
		typeid(T) == typeid(int) ||
		typeid(T) == typeid(long) ||
		typeid(T) == typeid(long long))
	{
		//std::uniform_int_distribution<int> distribution(0, length);
		//for (int i = 0; i < length; ++i)
		//	arr[i] = distribution(generator);

		//UniqueRandGenerator<T> urg;
		//urg.getRandArray(arr, length, seed);
		
		PartionOrderRandGenerator<T> pog;
		pog.getRandArray(arr, length, seed);
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
long RunSingle(ISort<T>* pInst, T * arr, int length, unsigned int seed)
{
	getRandArray(arr, length, seed);
	clock_t sw = clock();
	pInst->sort(arr, length);
	sw = clock() - sw;
	if (!pInst->IsSorted(arr, length))
		cout<<"Failed to sort"<<endl;
	return sw;
}

template <typename T>
void Run(ISort<T>* pInst1, ISort<T>* pInst2, int t, int n)
{
	long tot1 = 0, tot2 = 0;
	T * arr = new T[n];
	for (int i = 0; i < t; ++i)
	{
		//clock_t ct = clock();
		unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
		tot1 += RunSingle(pInst1, arr, n, seed);
		tot2 += RunSingle(pInst2, arr, n, seed);
	}
	delete[] arr;
	cout<<pInst1->name()<<" average using "<< ((double)tot1 / t) <<" miniseconds to sort "<<n<<" number"<<endl;
	pInst1->show(t);
	pInst1->Reset();
	cout<<pInst2->name()<<" average using "<< ((double)tot2 / t) <<" miniseconds to sort "<<n<<" number"<<endl;
	pInst2->show(t);
	pInst2->Reset();
	cout<<pInst1->name()<<" / "<<pInst2->name()<<" : "<< (double)tot1/tot2 <<" times"<<endl;
}

template <typename T>
void GenerateSort(ISort<T>** pAlg, char * pszAlg)
{
	if (stricmp(pszAlg, SortConstant::SELECTSORT) == 0)
	{
		*pAlg = new SelectSort<T>();
	} 
	else if (stricmp(pszAlg, SortConstant::INSERTSORT) == 0)
	{
		*pAlg = new InsertSort<T>();
	}
	else if (stricmp(pszAlg, SortConstant::SHELLSORT) == 0)
	{
		*pAlg = new ShellSort<T>();
	}
	else if (stricmp(pszAlg, SortConstant::MERGESORT) == 0)
	{
		*pAlg = new MergeSort<T>();
	}
	else if (stricmp(pszAlg, SortConstant::MERGEBUSORT) == 0)
	{
		*pAlg = new MergeBUSort<T>();
	}
	else if (stricmp(pszAlg, SortConstant::MERGEWITHINSERTSORT) == 0)
	{
		int sublen = 0;
		cout<<"Please set the length for sub array:";
		cin>>sublen;
		*pAlg = sublen == 0 ? new MergeWithInsertSort<T>() : 
			new MergeWithInsertSort<T>(sublen);
	}
	else if (stricmp(pszAlg, SortConstant::MERGEXSORT) == 0)
	{
		int sublen = 0;
		cout<<"Please set the length for sub array:";
		cin>>sublen;
		*pAlg = sublen == 0 ? new MergeXSort<T>() : 
			new MergeXSort<T>(sublen);
	}
	else if (stricmp(pszAlg, SortConstant::QUICKSORT) == 0)
	{
		*pAlg = new QuickSort<T>();
	}
	else if (stricmp(pszAlg, SortConstant::QUICKXSORT) == 0)
	{
		int sublen = 0;
		cout<<"Please set the length for sub array:";
		cin>>sublen;
		*pAlg = sublen == 0 ? new QuickXSort<T>() : 
			new QuickXSort<T>(sublen);
	}
	else if (stricmp(pszAlg, SortConstant::DIJKSTRASORT) == 0)
	{
		*pAlg = new DijkstraSort<T>();
	}
}

template <typename T>
void Compare(char * pszAlg1, char * pszAlg2, int t, int n)
{
	ISort<T> * pAlg1 = NULL, *pAlg2 = NULL;
	GenerateSort(&pAlg1, pszAlg1);
	GenerateSort(&pAlg2, pszAlg2);
	if (pAlg1 == NULL || pAlg2 == NULL) 
	{
		cout<<"Failed to generate algorithm as invalid algrithm name."<<endl;
		return;
	}
	Run(pAlg1, pAlg2, t, n);
	delete pAlg1;
	delete pAlg2;
}

void Compare(char * pszType, char * pszAlg1, char * pszAlg2, int t, int n)
{
	if (stricmp(pszType, "int") == 0)
	{
		Compare<int>(pszAlg1, pszAlg2, t, n);
	}
	else if (stricmp(pszType, "double") == 0)
	{
		Compare<double>(pszAlg1, pszAlg2, t, n);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 6)
	{
		cout<<"Invalid arguments!"<<endl<<"testAlgorithm.exe elemtype alg1 alg2 times length"<<endl;
		cout<<"Sample: testAlgorithm.exe int quicksort mergesort 100 10000"<<endl;
		return 1;
	}

	Compare(argv[1], argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));

	return 0;
}

