#pragma once
#include <functional>

template <typename Elem>
class ISort
{
public:
	typedef bool (*Pred)(const Elem&, const Elem&);
	ISort(bool asc = true) : _asc(asc), _cmp(0), _exch(0){}
	bool IsAsc() const {return _asc;}
	virtual void sort(Elem arr[], int length) = 0;
	virtual void exch(Elem arr[], int i, int j);
	bool compareTo(const Elem& lhs, const Elem& rhs);
	bool less(const Elem& lhs, const Elem& rhs);
	bool IsSorted(Elem arr[], int length);
	virtual const char * name() = 0;
	long long CmpTime() const {return _cmp;}
	long long ExchTime() const {return _exch;}
	void Reset() {_cmp = 0; _exch = 0;}
private:
	bool _asc;
	Pred _pred;
	long long _cmp;
	long long _exch;
};

template <typename Elem>
void ISort<Elem>::exch(Elem arr[], int i, int j)
{
	++_exch;
	swap(arr[i], arr[j]);
}

template <typename T>
bool ISort<T>::compareTo(const T& lhs, const T& rhs)
{
	if (IsAsc())
		return lhs < rhs;
	else
		return !(lhs < rhs) && !(lhs == rhs);
}

template <typename Elem>
bool ISort<Elem>::IsSorted(Elem arr[], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		if (!(arr[i] <= arr[i+1]))
			return false;
	}
	return true;;
}

template <typename Elem>
bool ISort<Elem>::less(const Elem& lhs, const Elem& rhs)
{
	++_cmp;
	return lhs < rhs;
}