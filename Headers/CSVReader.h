#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "MarketQuote.h"

using namespace std;

class CSVReader{
    private:
        static vector <string> tokenise(const string csvLine, const char separator);
        static MarketQuote stringsToMQ (const vector <string> tokens);

    public:
        CSVReader();
        static vector <MarketQuote> readCSV(string csvFileName);
        
};  