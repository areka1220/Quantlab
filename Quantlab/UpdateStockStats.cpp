#include "UpdateStockStats.h"
#include "StockStats.h"
#include "TradeOrder.h"
#include "StatFunctions.h"
#include <iostream>

//will upate all the statistical functions we want for a particular stock symbol max time gap, total quantity(volume), weighted average price, 
//max price given a trade order

void UpdateStockStats::updateStockStatWithNewTrade(StockStats &stockStatObj, TradeOrder tradeOrderObj)
{
	bool rightStockStat = false;
	StatFunctions statFuncObj;

	//The StockStat object being passed in will be initalized to a blank StockSymbol if it's new and needs need to set the Stock Symbol 
	//to the Trade passed in
	if (stockStatObj.getStockSymbol().compare("") == 0)
	{
		stockStatObj.setStockSymbol(tradeOrderObj.getStockSymbol());
		rightStockStat = true;
	}
	//only time the max time gap needs to be updated if this isn't the first one because then there's a previous time to compare to 
	//also need to make sure the stock symbols are the same otherwise it'll mess up the statistics for another stock symbol
	else if (stockStatObj.getStockSymbol() == tradeOrderObj.getStockSymbol())
	{
		stockStatObj.setMaxTimeGap(statFuncObj.max(tradeOrderObj.getTimeStamp() - stockStatObj.getPreviousTime(), stockStatObj.getMaxTimeGap()));
		rightStockStat = true;
	}
	
	//update the rest of the statistical values as well only if the user passed in the right TradeOrder stock symbol to the corresponding StockStat
	if (rightStockStat)
	{
		// Need to hold on to the time stamp so next iteration for this stock symbol it can be referenced and find max time gap
		stockStatObj.setPreviousTime(tradeOrderObj.getTimeStamp()); 
		stockStatObj.setTotalQuantity(stockStatObj.getTotalQuantity() + tradeOrderObj.getQuantity());
		stockStatObj.setMaxPrice(statFuncObj.max(stockStatObj.getMaxPrice(), tradeOrderObj.getPrice()));
		stockStatObj.setWeightedAvgPrice(statFuncObj.weightedAvg(stockStatObj.getWeightedAvgPrice(), tradeOrderObj.getQuantity(), tradeOrderObj.getPrice(), stockStatObj.getTotalQuantity()));

	}
}