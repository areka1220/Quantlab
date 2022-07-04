#pragma once
#include <string>
#include <vector>
#include "StockStats.h"

/*
	This class could be expanded to have find functions based on by certain values such as "find the stock with a max price of x"
	or "find the stock with the weighted average of y"
*/

class StockStatFind
{
	public:
		bool findStockStatBySymbol(std::vector <StockStats*>& allStocksStat, std::string stockSymbol, StockStats* &singleStockStat);
};