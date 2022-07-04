#include "StockStatSort.h"

//This will sort based the vector list of StockStats by the stock symbol in alphabetical order
void StockStatSort::sortByStockSymbolAsc(std::vector <StockStats*> &allStocksStat)
{
		std::sort(allStocksStat.begin(), allStocksStat.end(), StockStatSort::stockStatSymbolCompare);
}

