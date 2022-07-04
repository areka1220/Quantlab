#pragma once
#include "StockStats.h"
#include <vector>
#include <algorithm>
/*
	This class could be expanded to sort by other attributes such as "sort by total quantity ascending" or "sort by weighted average descending"
*/
class StockStatSort
{
	public:
		void sortByStockSymbolAsc(std::vector <StockStats*>& allStocksStat);
		static bool stockStatSymbolCompare(StockStats* a, StockStats* b)
		{
			return (a->getStockSymbol() < b->getStockSymbol());
		}
};