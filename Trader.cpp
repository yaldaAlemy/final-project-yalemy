#include "Trader.h"
using namespace std;
#include <iostream>

Trader::Trader() {
    name = "";
    balance = 0.0;
}


//get Trader's name
std::string Trader::fetch_Name() const {
    return "";

 }

//setter method for the Trader's name
//
void Trader::set_Name(const std::string &name) {
    //return nothing
    //
 }


//setter for setting the Trader's balance
void Trader::set_Balance(double bal) {
     //return nothing
     //
}

//display Trader's portfolio 
void Trader::show_Portfolio() const {
     //returns nothing
     if (portfolio.empty()) {
         cout << endl;
         cout << "Your porfolio is currently empty." << endl;
         return;
     }

}

void Trader::deposit_money(double amount) {

    //deposits and returns nothing
}

void Trader::withdraw_money(double amount) {
    // Placeholder
}


//getter method to fetch balance
double Trader::fetch_Balance() const {
    return 0.0;   //just a placeholder
}

double Trader::calculate_Port(const std::vector<Stock> &s) const {
    return 0.0; //placeholder for total port value
}

void Trader::add_Stock(const Stock& stock, int quantity) {
}

void Trader::remove_Stock(const std::string& stockSymbol, int quantity) {
}


