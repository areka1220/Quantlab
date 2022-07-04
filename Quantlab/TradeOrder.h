#pragma once
#include <string>
/*
	This class is the object that holds on to all the information we're looking for on a particular trade.
	The timestamp, symbol, quantity purchased and price
*/
class TradeOrder
{
	private:
		int			timeStamp;
		std::string stockSymbol;
		int			quantity ;
		int			price;
	public:
		TradeOrder();
		TradeOrder(int timeStamp, std::string stockSymbol, int quantity, int price);
		int			getTimeStamp();
		void		setTimeStamp(double inputTimeStamp);
		std::string getStockSymbol();
		void		setStockSymbol(std::string inputStockSymbol);
		int			getQuantity();
		void		setQuantity(double inputQuantity);
		int			getPrice();
		void		setPrice(double inputPrice);

};