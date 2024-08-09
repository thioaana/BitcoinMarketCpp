#include "Headers/MarketQuote.h"

using namespace std;

MarketQuote::MarketQuote(string timestamp,string product, ExchangeType transaction,
                                     double price, double amount){
    this->timestamp = timestamp;
    this->product = product;
    this->transaction = transaction;
    this->price = price;
    this->amount = amount;
}

ExchangeType MarketQuote::stringToExcType(string s){
    if (s == "ask") return ask;
    else if (s == "bid") return bid;
    else return unknown;
}
