#ifndef TRADER_H
#define TRADER_H
#include <string>
#include <vector>
#include "Stock.h"
using namespace std;
class Trader {

    private:
        string name;
        double balance;
        vector<Stock> portfolio; 
        vector<int> quantities;

    public: 

        Trader();

        string fetch_Name() const;

        void set_Name(const string &name1);

        double fetch_Balance() const;

        void set_Balance(double bal);
  

        //show portfolio
        //
        void show_Portfolio() const;

        //deposit money
        void deposit_money(double amount);


        //withdraw money
        //
        void withdraw_money(double amount);

        double calculate_Port(const vector<Stock> &s) const;

        void add_Stock(const Stock& stock, int quantity);

        void remove_Stock(const string& stockSymbol, int quantity);
};

#endif
