#pragma once
#include "ShareStatistics.h"
class ShareCount : public StatCount
{
private:
	int shareCountVal;

public:
	ShareCount();
	ShareCount(int inputShareCountVal);
	int getShareCountVal();
	void setShareCountVal(int inputShareCountVal);
	void incrementCount(int incrementCountBy);
};