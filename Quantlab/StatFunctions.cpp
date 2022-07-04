#include "StatFunctions.h"

long long StatFunctions::max(long long num1, long long num2)
{	
	if (num1 > num2) return num1;
	else			 return num2;
}

double StatFunctions::weightedAvg(double previousWeightedAvg, int newNumberOfItems, int price, int total)
{
	double previousWeightedTotal = previousWeightedAvg * (total - newNumberOfItems);

	return ((previousWeightedTotal + (newNumberOfItems * price)) / total);
}