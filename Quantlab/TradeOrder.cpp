#include "TradeOrder.h"
TradeOrder::TradeOrder()
{
	this->timeStamp = 0;
	this->stockSymbol = "";
	this->quantity = 0;
	this->price = 0;
}
TradeOrder::TradeOrder(int timeStamp, std::string stockSymbol, int quantity, int price)
{
	this->timeStamp = timeStamp;
	this->stockSymbol = stockSymbol;
	this->quantity = quantity;
	this->price = price;
}

int TradeOrder::getTimeStamp()
{
	return timeStamp;
}
void TradeOrder::setTimeStamp(double inputTimeStamp)
{
	timeStamp = inputTimeStamp;
}

std::string TradeOrder::getStockSymbol()
{
	return stockSymbol;
}

void TradeOrder::setStockSymbol(std::string inputStockSymbol)
{
	stockSymbol = inputStockSymbol;
}

int TradeOrder::getQuantity()
{
	return quantity;
}

void TradeOrder::setQuantity(double inputQuantity)
{
	quantity = inputQuantity;
}

int TradeOrder::getPrice()
{
	return price;
}

void TradeOrder::setPrice(double inputPrice)
{
	price = inputPrice;
}