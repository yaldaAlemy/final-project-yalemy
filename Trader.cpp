#include "Trader.h"
using namespace std;
#include <iostream>

Trader::Trader() {
    name = "";
    balance = 0.0;
}


//get Trader's name
std::string Trader::fetch_Name() const {
    return name;

 }

//setter method for the Trader's name
//
void Trader::set_Name(const std::string &name) {
    //return nothing
    this->name = name;
 }


//setter for setting the Trader's balance
void Trader::set_Balance(double bal) {
     balance = bal;
     
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
    if (amount > balance) {
        cout << "Insufficient funds, withdraw failed!" << endl;
     } else if (amount > 0 && amount <= balance) {
         this->balance -= amount;
         cout <<"Withdrew this amount: $" << fixed << setprecision(2) << amount << endl;
         cout << "Your balance now is: $" << fixed << setprecision(2) << balance << endl;
     } else {
         cout << "Amount requested to withdraw was negative!" << endl;
     }
}


//getter method to fetch balance
double Trader::fetch_Balance() const {
    return balance;   //just a placeholder
}

double Trader::calculate_Port(const std::vector<Stock> &s) const {
    return 0.0; //placeholder for total port value
}

void Trader::add_Stock(const Stock& stock, int quantity) {
}

void Trader::remove_Stock(const std::string& stockSymbol, int quantity) {
}


