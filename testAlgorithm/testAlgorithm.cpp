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
#include "MergeSort.hpp"
#include "QuickSort.hpp"

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
	else if (stricmp(pszAlg, SortConstant::QUICKSORT) == 0)
	{
		*pAlg = new QuickSort<T>();
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
	Run(pAlg1, t, n);
	Run(pAlg2, t, n);
	delete pAlg1;
	delete pAlg2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 5)
	{
		cout<<"Invalid arguments!"<<endl<<"testAlgorithm.exe alg1 alg2 times length"<<endl;
		return 1;
	}

	Compare<double>(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));

	return 0;
}

