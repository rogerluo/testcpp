#pragma once
#include <iostream>
using namespace std;
template <typename Elem>
class IRandGenerator
{
public:
	virtual void getRandArray(Elem arr[], int length, unsigned int seed) = 0;
	virtual bool IsDistinct(Elem arr[], int length) = 0;
	void show(Elem arr[], int length);
protected:
};

template <typename Elem>
void IRandGenerator<Elem>::show(Elem arr[], int length)
{
	for (int i = 0; i < length; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}