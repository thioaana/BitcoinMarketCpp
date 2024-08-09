#pragma once

#include <iostream>
#include <vector>
#include "CSVReader.h"
#include "MarketQuote.h"

using namespace std;

class MarketMain{
    private:
        vector <MarketQuote> orders;
        void printMenu();
        int getUserOption();
        void processUserOption(int u);
        void printMarketStats();
        void exitProject();
        void pressButtonToCont();

    public:
        MarketMain();
        void init();
};