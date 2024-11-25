#include "Stock.h"

//constructor that will be edited later
Stock::Stock() {}


//Getter method

double Stock::get_Price() const {

    return 0.0;
}

//Getter method 

int get_Quantity() const {

    return 0;
}

//Getter method to retrieve the symbol
std::string Stock::get_Symbol() const {

    return "blank";
}

//setter methods which has void return type 

void Stock::set_Price(double p) {
     price = p;
}

//for setting the quantity 

void Stock::set_Quantity(int q) {
    quantity = q;
}

iii
