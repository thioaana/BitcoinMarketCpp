#include "Headers/CSVReader.h"

// using namespace std;

CSVReader::CSVReader(){

}


vector <MarketQuote> CSVReader::readCSV(string csvFileName){
    vector <MarketQuote> entries;
    string csvLine;
    
    // 1. Open the file as input 
    ifstream ifs(csvFileName);

    if (ifs.is_open()) {
        // 2. Read the file per line. 
        while (getline(ifs, csvLine)){
            try {
                MarketQuote tempMQ = stringsToMQ(tokenise(csvLine, ','));
                entries.push_back(tempMQ);
            }
            catch (const exception& e){
                cout << "From csvReader::readCSV - BAD DATA : " <<endl;
            }
        } // end of while

    } // end if
    else {
        cout << "Cannot open the file " << endl;
        exit(3);
    }

    return entries;
}


vector <string> CSVReader::tokenise(const string csvLine, const char separator){
    int start=0;
    int end = 0;
    string token;
    vector<string> tokens;

    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start); // Find next separator after start.
        
        if (start == csvLine.length() || start == end) break;

        // Implement token
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token  = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token); // Fills vector tokens
        start = end + 1;
    }while (end>0);

    return tokens;
}


MarketQuote CSVReader::stringsToMQ (vector <string> tokens){
    double amount= 0.0;
    double price = 0.0;
    
    // Check if strs contains 5 fields else throw an exception
    if (tokens.size() != 5) {
        cout << "Problem in Number of fields : "  << tokens.size() <<endl;
        throw exception();
    }
    
    // Check if 4th and 5th fields ate double else continue to the next one
    try {
        amount = stod(tokens[3]);
        price = stod(tokens[4]);            
    }
    catch (const exception e) {
        cout << "Problem in Amount : " << tokens[3] << endl;
        cout << "or in Price : " << tokens[4] << endl; 
        throw;}
    
    MarketQuote tempMQ(tokens[0], tokens[1],
                        MarketQuote::stringToExcType(tokens[2]), 
                        amount, price);

    return tempMQ;
}