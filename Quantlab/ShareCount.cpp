#include "ShareCount.h"

ShareCount::ShareCount()
{
	shareCountVal = 0;
}

ShareCount::ShareCount(int inputShareCountVal)
{
	shareCountVal = inputShareCountVal;
}
int ShareCount::getShareCountVal()
{
	return shareCountVal;
}

void ShareCount::setShareCountVal(int inputShareCountVal)
{
	shareCountVal = inputShareCountVal;
}

void ShareCount::incrementCount(int incrementCountBy)
{

}

