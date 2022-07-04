#include "pch.h"
#include "CppUnitTest.h"
#include "UpdateStockStats.h"
#include "StockStats.h"
#include "StatFunctions.h"
#include "TradeOrder.h"
#include "StockStatFind.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMax)
		{
			StatFunctions statFunc;
			long long maxVal = 0;
			maxVal = statFunc.max(99, 8);
			Assert::IsTrue(maxVal == 99);
		}

		TEST_METHOD(TestWeightedAvg)
		{
			StatFunctions statFunc;
			double weightedAvg = 0;
			weightedAvg = statFunc.weightedAvg(10, 7, 7, 20);
			Assert::IsTrue(weightedAvg == 8.95);
		}

		//Empty StockStat being updated with a TradeOrder make sure it gets created with the right StockSymbol
		TEST_METHOD(TestUpdateStockStatSymbolName)
		{
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			TradeOrder tradeInfo(61300796005, "bag", 13, 43);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			Assert::IsTrue(stockStat->getStockSymbol() == "bag");
		}

		//Put 3 TradeOrders for the same stock symbol and see if the max time gap is updated properly if the largest 
		//gap is of the last two
		TEST_METHOD(TestUpdateStockStatMaxTimeGap)
		{
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			TradeOrder tradeInfo(61300796005, "bag", 13, 43);
			TradeOrder tradeInfo2(61300806005, "bag", 5, 47);
			TradeOrder tradeInfo3(61400806005, "bag", 6, 57);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo3);
			Assert::IsTrue(stockStat->getMaxTimeGap() == (61400806005 - 61300806005));
		}

		//Put 2 TradeOrders for the same stock symbol and see if the total quantity is as expected
		TEST_METHOD(TestUpdateStockStatTotalQuantity)
		{
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			TradeOrder tradeInfo(61300796005, "aaa", 13, 43);
			TradeOrder tradeInfo2(61300806005, "aaa", 5, 47);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			Assert::IsTrue(stockStat->getTotalQuantity() == (13+5));
		}

		//Put 2 TradeOrders for the same stock symbol and see if the max price is as expected
		TEST_METHOD(TestUpdateStockStatMaxPrice)
		{
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			TradeOrder tradeInfo(61300796005, "aaa", 12, 43);
			TradeOrder tradeInfo2(61300806005, "aaa", 56, 47);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			Assert::IsTrue(stockStat->getMaxPrice() == 47);
		}

		//Put 3 TradeOrders for the same stock symbol and see if the weighted average is calculated correctly
		TEST_METHOD(TestUpdateStockStatWeightedAverage)
		{
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			TradeOrder tradeInfo(61300796005, "okl", 5, 122);
			TradeOrder tradeInfo2(61300806005, "okl", 77, 52);
			TradeOrder tradeInfo3(61300806005, "okl", 53, 666);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo3);
			double weightedAvg = ((5.0 * 122) + (77 * 52) + (53 * 666)) / (5 + 77 + 53);
			Assert::IsTrue(stockStat->getWeightedAvgPrice() == weightedAvg);
		}

		//Put 2 TradeOrders for the same stock symbol and try to update the StockStat with a TradeOrder of a diff stock symbol
		//Make sure that the StockStat isn't modified with info from the TradeOrder of a different StockSymbol
		TEST_METHOD(TestUpdateStockStatWrongTradeSymbol)
		{
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			TradeOrder tradeInfo(61300796005, "aaa", 13, 43);
			TradeOrder tradeInfo2(61300806005, "aaa", 5, 50);
			TradeOrder tradeInfo3(61300406005, "bbb", 33, 67);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo3);

			double weightedAvg = ((13.0 * 43) + (5 * 50))/ (13+5);

			Assert::IsTrue(stockStat->getStockSymbol() == "aaa");
			Assert::IsTrue(stockStat->getMaxTimeGap() == (61300806005 - 61300796005));
			Assert::IsTrue(stockStat->getMaxPrice() == 50);
			Assert::IsTrue(stockStat->getWeightedAvgPrice() == weightedAvg);
		}

		//Put 2 StockStat into a vector and see if the second one that was added can be found by the stock symbol
		TEST_METHOD(TestFindStockStatBySymbolTrue)
		{
			std::vector <StockStats*> allStocksStat;
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			StockStats* singleStat;
			bool found = false;

			TradeOrder tradeInfo(61300796005, "aaa", 13, 43);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			allStocksStat.push_back(stockStat);

			stockStat = new StockStats();
			TradeOrder tradeInfo2(61300406005, "bbb", 33, 67);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			allStocksStat.push_back(stockStat);

			StockStatFind statFind;
			found = statFind.findStockStatBySymbol(allStocksStat, "bbb", singleStat);

			Assert::IsTrue(found);
			Assert::IsTrue(singleStat == allStocksStat[1]);
		}

		//Put 2 StockStat into a vector and try to find one (based on stock symbol) that isn't there and make sure it's not found
		TEST_METHOD(TestFindStockStatBySymbolFalse)
		{
			std::vector <StockStats*> allStocksStat;
			StockStats* stockStat = new StockStats();
			UpdateStockStats testUpdate;
			StockStats* singleStat;
			bool found = false;

			TradeOrder tradeInfo(61300796005, "aaa", 13, 43);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo);
			allStocksStat.push_back(stockStat);

			stockStat = new StockStats();
			TradeOrder tradeInfo2(61300406005, "bbb", 33, 67);
			testUpdate.updateStockStatWithNewTrade(*stockStat, tradeInfo2);
			allStocksStat.push_back(stockStat);

			StockStatFind statFind;
			found = statFind.findStockStatBySymbol(allStocksStat, "ccc", singleStat);

			Assert::IsTrue(!found);
		}

	};

}
