#include "Stock.h"
using namespace std;
//constructor that will be edited later
Stock::Stock(const string& stockSymbol, double stockPrice, int stockQuantity) {
    this->symbol = stockSymbol;
    this->price = stockPrice;
    this->quantity = stockQuantity;
}


//Getter method

double Stock::get_Price() const {

    return price;  //returning a placeholder for right now
}

//Getter method 

int Stock::get_Quantity() const {

    return quantity;
}


void Stock::set_Symbol(const std::string& symbol) {
    this->symbol = symbol;  // Set the stock symbol
}

//Getter method to retrieve the symbol
std::string Stock::get_Symbol() const {

    return symbol;  //placeholder
}

//setter methods which has void return type 

void Stock::set_Price(double p) {
     price = p;
}

//for setting the quantity 

void Stock::set_Quantity(int q) {
    quantity = q;
}

