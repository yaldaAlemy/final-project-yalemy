#include "Trader.h"
using namespace std;
#include <iostream>
#include <iomanip>

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
        cout << "Your portfolio is currently empty." << endl;
        return;
    }

    double tot = 0.0;
    for (size_t i = 0; i < portfolio.size(); i++) {
        const Stock& stock = portfolio[i];
        int quantity = quantities[i];
        double value = stock.get_Price() * quantity;

        cout << "Stock: " << stock.get_Symbol()
                  << ", Price: $" << fixed << setprecision(2) << stock.get_Price()
                  << ", Quantity: " << quantity
                  << ", Value: $" << value << endl;

        tot += value;
    }

    cout << "Total Portfolio Value: $" << std::fixed << std::setprecision(2) << tot << endl;
}

void Trader::deposit_money(double amount) {
    if (amount <= 0) {
        cout << "Deposit amount must be greater than 0." << endl;
        return;
    }
    
    balance += amount;
    cout << "Deposited $" << fixed << setprecision(2) << amount 
              << ". New balance: $" << balance << "." << endl;
}


void Trader::withdraw_money(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds, withdraw failed!" << endl;
     } else if (amount > 0 && amount <= balance) {
         this->balance -= amount;
         cout << "Withdrew this amount: $" << fixed << setprecision(2) << amount << endl;
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
        double total = 0.0;

    for (size_t i = 0; i < s.size(); i++) {
        total += s[i].get_Price() * quantities[i];
    }

    return total;
}


void Trader::add_Stock(const Stock& stock, int quantity) {
     for (size_t i = 0; i < portfolio.size(); i++) {
         if (portfolio[i].get_Symbol() == stock.get_Symbol()) {
            quantities[i] += quantity;  // Increase quantity if stock exists
            return;
        }
    }

    portfolio.push_back(stock);  
    quantities.push_back(quantity);
   
    }
bool Trader::remove_Stock(const std::string& stockSymbol, int quantity) {
// Logic to check if the stock exists and can be removed
    for (size_t i = 0; i < portfolio.size(); i++) {
        if (portfolio[i].get_Symbol() == stockSymbol) {
            if (quantities[i] >= quantity) {
                quantities[i] -= quantity; // Decrease quantity
                balance += portfolio[i].get_Price() * quantity; // Add to balance
                return true; // Successfully removed stock
            }
        }
    }
    return false; // Stock not found or insufficient quantity
}



