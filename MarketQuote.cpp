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
