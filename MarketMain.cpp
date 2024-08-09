#include "Headers/MarketMain.h"

MarketMain::MarketMain()
{
}

void MarketMain::init(){
    orders = CSVReader::readCSV("BtcData.csv");

    int input;
    while (true){
        this->printMenu();
        input = this->getUserOption();
        this->processUserOption(input);


    }
}

void MarketMain::printMenu()
{
  cout << "1: print help " << endl;
  cout << "2: Print market stats " << endl;
  cout << "3: make an ask " << endl;
  cout << "4: make a bid " << endl;
  cout << "5: print wallet " << endl;
  cout << "6: Exit " << endl;

  cout << "============== " << endl;
  cout << "Type in 1-6" << endl;

//   std::cout << "Current time is " << currentTime << std::endl;
}



int MarketMain::getUserOption(){
  int userOption = 0;
  string line;
//   cout << "Type 1-6" << endl;
  getline(cin, line);
  try {userOption = stoi(line);  }
  catch (const std::exception &e)  { }

  cout << "You chose " << userOption << endl;
  return userOption;
}


void MarketMain::processUserOption(int userOption){
    switch(userOption){
        case 6:
            this->exitProject();
            break;
        case 2:
            this->printMarketStats();
            break;
        default:
            exit(0);
            break;
    }
}


void MarketMain::printMarketStats(){
    cout <<"Order book contains " << this->orders.size() << " orders." << endl;
    this->pressButtonToCont();
}

void MarketMain::exitProject(){
    cout << "Time to exit";
    exit(3);
}

void MarketMain::pressButtonToCont(){
    char s = '\0';
    cout << "press a button to continue ...";
    cin >> s;
}