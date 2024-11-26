#ifndef TRADER_H
#define TRADER_H



#include <string>
#include <vector>
#include "Stock.h"

class Trader {

    private:
        std::string name;
        double balance;
        std::vector<Stock> portfolio; 
        std::vector<int> quantities;

    public: 

        Trader();

        std::string fetch_Name() const;

        void set_Name(const std::string &name1)

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


};


