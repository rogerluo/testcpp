#pragma once
#include <vector>

class SortAlgorithm
{
public:
	SortAlgorithm();
	~SortAlgorithm();
	void PrepareRandomVector(std::vector<int>& v, int min, int max, int len);
	void CompareNth(int nth, int len);
};

