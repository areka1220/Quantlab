#pragma once
#include <string>
/*
	This class is the object that holds on to all the information we're looking for on a particular stock symbol. 
	The stock symbol, max time gap, total quantity (volume), weighted average price, max price
*/
class StockStats
{
	public:
		StockStats();
		StockStats(std::string stockSymbol, long long maxTimeGap, long long previousTime, int totalQuantity, int weightedAvgPrice, int maxPrice);
		std::string		getStockSymbol();
		void			setStockSymbol(std::string stockSymbol);
		int				getMaxTimeGap();
		void			setMaxTimeGap(int maxTimeGap);
		int				getPreviousTime();
		void			setPreviousTime(int previousTime);
		int				getTotalQuantity();
		void			setTotalQuantity(int totalQuantity);
		double			getWeightedAvgPrice();
		void			setWeightedAvgPrice(double weightedAvgPrice);
		int				getMaxPrice();
		void			setMaxPrice(int maxPrice);

	private:
		std::string stockSymbol;
		int maxTimeGap;
		int previousTime;
		int totalQuantity;
		double weightedAvgPrice;
		int maxPrice;
};