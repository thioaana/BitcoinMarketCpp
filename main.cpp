#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Headers/BtcStockMarket.h"

using namespace std;

/** Read BtcMarket.csv file and save all rows in a vector */
void readDataFile(string, vector <string> & );

/** Fill the object myMarket with the string data read by readDataFile */
void fillStockMarket(vector<string> &, BtcStockMarket &);

vector<string> tokenize(string, char);


int main(){
    vector<string> allData;
    readDataFile("BtcData.csv", allData);

    BtcStockMarket myMarket;
    fillStockMarket(allData, myMarket);
    // for (string & v: allData){
    //     cout << v << endl;
    // }

    return 0;
}

void readDataFile(const string fileName, vector <string> & strData){
    ifstream ifs(fileName);
    
    // Check if the file is opened properly, or else show a message and exit the program 
    if (ifs.is_open()){
        cout << "File is opened properly" << endl;
    }
    else {
        cout << "Cannot open the file " << endl;
        exit(3);
    }
    
    // Read the file per line. Save it in vector.
    string line;
    while (getline(ifs, line)){
        strData.push_back(line);
    }
}

void fillStockMarket(vector<string> & strData, BtcStockMarket & classData){
    for (string & v: strData){
        // Tokenize each Row string
        vector<string> temp;
        temp = tokenize(v, ',');

        // Check if temp contains 5 fields else continue to the next one
        if (temp.size() != 5) continue;
        
        // Check if 4th and 5th fields ate double else continue to the next one
        double amount= 0.0;
        double price = 0.0;

        try {
            amount = stod(temp[3]);
             price = stod(temp[4]);            
        }
        catch (exception e) {continue;}
    
    ExchangeType tr = bid;
    if (temp[2] == "ask") tr = ask;
    
    MarketQuote m(temp[0], temp[1], tr, amount, price);
    classData.addQuote(m);
    cout << "All is fine... " << endl;
    exit(3);

    }
}

vector<string> tokenize(string s, char sep){
    int start=0;
    int end = 0;
    string token;
    vector<string> tokens;

    start = s.find_first_not_of(sep, 0);
    do {
        end = s.find_first_of(sep, start); // Find next separator after start.
        
        if (start == s.length() || start == end) break;

        // Implement token
        if (end >= 0) token = s.substr(start, end - start);
        else token  = s.substr(start, s.length() - start);

        tokens.push_back(token);

        start = end + 1;
    }while (end>0);

    return tokens;
}