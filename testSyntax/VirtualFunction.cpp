#include "stdafx.h"
#include "VirtualFunction.h"
#include <cstdio>

Top::~Top()
{
	printf("%s\n", __FUNCTION__);
}

void Top::speackClearly()
{
	printf("%s\n", __FUNCTION__);
}

Diamond1* Diamond1::pure()
{
	return this;
}