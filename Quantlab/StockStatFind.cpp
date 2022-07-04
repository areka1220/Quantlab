#include "StockStatFind.h"

//Goes through a vector list that has all the StockStat objects and look for a particular StockStat given a stock symbol
//The last parameter will point to the StockStat object that was found in the vector list so the user can reference it

bool StockStatFind::findStockStatBySymbol(std::vector <StockStats*>& allStocksStat, std::string stockSymbol, StockStats* &singleStockStat)
{
    for (StockStats* eachStockStat : allStocksStat)
    {

        if (eachStockStat->getStockSymbol() == stockSymbol)
        {
            singleStockStat = eachStockStat;
            return true;
        }
    }

    return false;
}