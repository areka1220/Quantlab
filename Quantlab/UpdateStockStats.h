#pragma once
#include "StockStats.h"
#include "TradeOrder.h"

/*
	This class could be expanded to update the StockStat with maybe just the quantity for a particular StockStat or other attributes
*/
class UpdateStockStats
{
	public:
		void updateStockStatWithNewTrade(StockStats &stockStatObj, TradeOrder tradeOrderObj);

}; 
