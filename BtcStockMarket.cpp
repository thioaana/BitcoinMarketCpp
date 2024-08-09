#include "Headers/BtcStockMarket.h"

void BtcStockMarket::addQuote(const MarketQuote m){
    this->market.push_back(m);
}