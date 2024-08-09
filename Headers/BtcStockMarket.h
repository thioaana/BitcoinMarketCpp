#pragma once
#include "MarketQuote.h"
#include <vector>


class BtcStockMarket{
    private:
        vector <MarketQuote> market;
    public:
        void addQuote(const MarketQuote) ;
};