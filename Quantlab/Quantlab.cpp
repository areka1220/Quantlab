// Quantlab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StockStats.h"
#include "UpdateStockStats.h"
#include "TradeOrder.h"
#include "StockStatSort.h"
#include "StockStatFind.h"
#include "StatFunctions.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector <StockStats*> allStocksStat; //has all the different stock symbols and the associated statistics we need

void processTrade(std::vector <std::string> tradeInfo)
{
    if (tradeInfo.size() == 4) //it has to have 4 attributes otherwise it's not a valid order
    {
        StockStats*         singleStockStat = NULL;
        UpdateStockStats    updateStat;
        StockStatFind       statFind;
        bool                foundStockStat = false;

        //break up the vector and get the different attributes into variables 
        long long timeStamp = std::stoll(tradeInfo[0]);
        std::string stockSymbol = tradeInfo[1];
        int quantity = std::stoi(tradeInfo[2]);
        int  price = std::stoi(tradeInfo[3]);

        TradeOrder singleTrade(timeStamp, stockSymbol, quantity, price); //create the TradeOrder object

        //find out if there's already statistics on a particular stock symbol if there is we'll update it if not then create it
        foundStockStat = statFind.findStockStatBySymbol(allStocksStat, singleTrade.getStockSymbol(), singleStockStat);

        if (!foundStockStat) //whoops didn't find it need to create another StockStats object on the a particular stock symbol
        {
            singleStockStat = new StockStats();
            allStocksStat.push_back(singleStockStat); 
        }

        //whether we created a new StockStats object or not the statistical info needs to be updated with the new TradeOrder
        updateStat.updateStockStatWithNewTrade(*singleStockStat, singleTrade);

    }
}

void outputToFile(std::vector <StockStats*> &allStocksStat)
{
    std::ofstream processOutput("output.csv");
   
    for (StockStats* eachStockStat : allStocksStat)
    {
        std::string outputLine = "";
        int WeightedAvgPrice = eachStockStat->getWeightedAvgPrice(); //needs to be truncated to a whole number

        outputLine = outputLine + eachStockStat->getStockSymbol() + "," +
                     std::to_string(eachStockStat->getMaxTimeGap()) + "," +
                     std::to_string(eachStockStat->getTotalQuantity()) + "," +
                     std::to_string(WeightedAvgPrice) + "," +
                     std::to_string(eachStockStat->getMaxPrice());    

        processOutput << outputLine << std::endl;
    }

    processOutput.close();
}

int main()
{
    StockStatSort sortStats;
    std::ifstream processInput("input.csv");

    //tokenize each line into a vector that holds on to the four different attributes of a trade
    for (std::string line; std::getline(processInput, line); )
    {
        std::vector<std::string> tradeInfo;
        std::string token;
        std::stringstream inputLineStream(line);
      
        while (std::getline(inputLineStream, token, ','))
        {
            tradeInfo.push_back(token);
        }

        //pass the vector off to be processed into a TradeOrder object
        processTrade(tradeInfo);
    }

    sortStats.sortByStockSymbolAsc(allStocksStat);
    
    outputToFile(allStocksStat);
}



