#pragma once
#include <functional>
template <typename Elem>
class ISort
{
public:
	ISort(bool asc = true) : _asc(asc){}
	bool IsAsc() const {return _asc;}
	void sort(Elem arr[], int length);
	virtual void exch(Elem arr[], int i, int j);
	bool compareTo(const Elem& lhs, const Elem& rhs);
	bool IsSorted(Elem arr[], int length) = 0;
	virtual void show() = 0;
private:
	virtual void sort(Elem arr[], int length, bool Pred(const Elem&, const Elem&)) = 0;
	bool _asc;
};

template <typename Elem>
void ISort::sort(Elem arr[], int length)
{
	if (IsAsc())
		sort(arr, length, less);
	else
		sort(arr, length, less);
}

template <typename Elem>
void ISort::exch(Elem arr[], int i, int j)
{
	swap(arr[i], arr[j]);
}


template <typename ELem>
bool ISort::compareTo(const Elem& lhs, const Elem& rhs)
{
	if (IsAsc())
		return lhs < rhs;
	else
		return !(lhs < rhs) && !(lhs == rhs);
}

template <typename Elem>
bool ISort::IsSorted(Elem arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		if (!compareTo(arr[i], arr[j]))
			return false;
	}
	return true;;
}