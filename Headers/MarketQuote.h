#pragma once
#include <string>

enum ExchangeType {bid, ask, unknown};
using namespace std;

class MarketQuote{
    private:
        string timestamp;
        string product;
        ExchangeType transaction;
        double price;
        double amount;

    public:
        MarketQuote(string, string, ExchangeType, double, double);
        static ExchangeType stringToExcType(string s);
};