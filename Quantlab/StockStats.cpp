#include <string>
#include "StockStats.h"

StockStats::StockStats()
{
	stockSymbol = "";
	maxTimeGap = 0;
	previousTime = 0;
	totalQuantity = 0;
	weightedAvgPrice = 0;
	maxPrice = 0;
}

StockStats::StockStats(std::string shareSymbol, long long maxTimeGap, long long previousTime, int totalQuantity, int weightedAvgPrice, int maxPrice)
{
	this->stockSymbol = stockSymbol;
	this->maxTimeGap = maxTimeGap;
	this->previousTime = previousTime;
	this->totalQuantity = totalQuantity;
	this->weightedAvgPrice = weightedAvgPrice;
	this->maxPrice = maxPrice;
}

std::string StockStats::getStockSymbol()
{
	return stockSymbol;
}

void StockStats::setStockSymbol(std::string stockSymbol)
{	
	this->stockSymbol = stockSymbol;
}


int StockStats::getMaxTimeGap()
{
	return maxTimeGap;
}

void StockStats::setMaxTimeGap(int maxTimeGap)
{
	this->maxTimeGap = maxTimeGap;
}

int	StockStats::getPreviousTime()
{
	return previousTime;
}

void StockStats::setPreviousTime(int previousTime)
{
	this->previousTime = previousTime;
}

int StockStats::getTotalQuantity()
{
	return totalQuantity;
}
void StockStats::setTotalQuantity(int totalQuantity)
{
	this->totalQuantity = totalQuantity;
}

double StockStats::getWeightedAvgPrice()
{
	return weightedAvgPrice;
}
void StockStats::setWeightedAvgPrice(double weightedAvgPrice)
{
	this->weightedAvgPrice = weightedAvgPrice;
}

int StockStats::getMaxPrice()
{
	return maxPrice;
}
void StockStats::setMaxPrice(int maxPrice)
{
	this->maxPrice = maxPrice;
}

